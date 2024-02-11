#include "PmergeMeList2.hpp"

// Coplien's form------------------------------------------------------------------------------------------------------

PmergeMeList::PmergeMeList( void ) : PmergeMe(), _l(), _ExpectedSortedList() {

	return;
}

PmergeMeList::~PmergeMeList( void ) {

	return;
}

PmergeMeList::PmergeMeList( const PmergeMeList & src ) : PmergeMe(src), _l(src._l), _ExpectedSortedList(src._ExpectedSortedList) {

	return;
}

PmergeMeList & PmergeMeList::operator=( const PmergeMeList & src ) {

	if ( this != &src )
	{
		*this = src;
		if ( !this->_l.empty() )
			this->_l.clear();
		if ( !this->_ExpectedSortedList.empty() )
			this->_ExpectedSortedList.clear();
		this->_l = src._l;
		this->_ExpectedSortedList = src._ExpectedSortedList;
	}
	return *this;
}

// Parametrized constructor---------------------------------------------------------------------------------------------

PmergeMeList::PmergeMeList( char **av ) : PmergeMe(av) {

	return;
}

// Start sorting--------------------------------------------------------------------------------------------------------

void	PmergeMeList::startSortWithList( void ) {


	initList();
//	printPairedList("List BEFORE: ", this->_l );

	t_list::const_iterator it = this->_l.begin();
	t_list::const_iterator ite = this->_l.end();
	for ( ; it != ite; ++it )
	{
		this->_ExpectedSortedList.push_back( it->first );
		if ( it->second != -1 ) {
			this->_ExpectedSortedList.push_back( it->second );
		}
	}
	this->_ExpectedSortedList.sort();

	printList( "List BEFORE: ", this->_l );

	this->_t = clock();
	if ( !isSortedFinalList() && this->_l.size() != 1 )		//if the list is sorted or the size is 1, don't do sorting
		listSorting();;

	this->_t = clock() - this->_t;

	printListFirstValueOnly( "List AFTER: ", this->_l );


	std::cout << GREEN_BOLD << "List sorted successfully!" << END << std::endl;

	printTime( this->_l.size() );

	return;
}

void	PmergeMeList::initList( void ) {

	std::istringstream iss(this->_s );

	while ( iss.peek() != EOF)
	{
		int num1 = 0;
		int num2 = 0;
		iss >> num1;
		if ( iss.fail() )
			throw std::runtime_error ("Not a int");

		if ( iss.peek() != EOF )
		{
			iss >> num2;
			if ( iss.fail( ) )
				throw std::runtime_error( "Not a int" );
			this->_l.push_back( std::make_pair(num1, num2) );
		}
		else
			this->_l.push_back( std::make_pair(num1, -1) );		// straggler
	}
}

/*
 Before using merge sort, the list with larger numbers S should look like this:
 S = (x1, x2, x3,...) where every element xi and i >= 3 is associated with
 and element yi < xi, where yi is an element of the list with smallest numbers.
*/

void	PmergeMeList::listSorting( void ) {

	t_list & main = this->_l;
	t_list pend;
	
	pairwiseComparision(main, pend );

//	printPairedList("Main: ", main);
//	printPairedList("Pend: ", pend);

	recursiveInsertionSort( main );

//	printPairedList("Main after RecursiveSort: ", main);

//	if ( !isSortedSublist( this->_l) )								// check just in case
//		throw std::runtime_error ("Could not sort the sublists correctly :(");

	getFirstPair( main, pend );

//	printPairedList("Main after first pair : ", main);
//	printPairedList("Pend after first pair : ", pend);

//	reorganiseWeights( pend );

//	for debugging
//	printPairedList("Main after pend reorganisation  : ", main);
//	printPairedList("Pend after pend reorganisation : ", pend);

	merge( main, pend );
//	printPairedList("Main: ", main);
//	printListFirstValueOnly("Main after merge: ", main);
	if ( !isSortedFinalList() )									// check if the sorting is successful
		throw std::runtime_error ("Unsuccessful sorting :(");
	return;
}

/*
 From wikipedia: At the beginning of the list with the larger numbers _l,
 insert the element that was paired with the smallest number of _l

 To do so, I previously store the `index` position of the smallest number in _l,
 before recursively sorting it.
 Because `smallest` is not sorted, I can easily find it the corresponding pair.
*/

void	PmergeMeList::getFirstPair( t_list & main, t_list & pend ) {

	t_list::iterator it = pend.begin();
	t_list::iterator ite = pend.end();

	while ( it != ite )
	{
		if ( (*it).second == main.front().second )
		{
			main.push_front( std::make_pair( (*it).first, (*it).second ) );
			pend.erase(it);
			return;
		}
		++it;
	}
}

void	PmergeMeList::pairwiseComparision( t_list & main, t_list &pend ) {

	t_list::iterator	it = main.begin();
	t_list::iterator	ite = main.end();

	int i = 1;															// i will be index in it->second

	while ( it != ite )
	{
		if ( (*it).second != -1 ) 										// if not stragler
		{
			int min = std::min( ( *it ).first, ( *it ).second );
			int max = std::max( ( *it ).first, ( *it ).second );
			pend.push_back( std::make_pair( min, i ) );
			(*it).first = max;
		}
		(*it).second = i;												// set index + straggler set index
		++it;
		++i;
	}
	return;
}

/*
 * Recursive sorting is used to sort only the main list -> the list with the largest values
 */
void	PmergeMeList::recursiveInsertionSort( t_list & main )
{
	if (main.size() <= 1)
		return;

	int value = main.back().first;								// keep the same value with
	int weight = main.back().second;							// keep the same weight i.e. index
	main.pop_back();

	recursiveInsertionSort(main); 								//recursion

	t_list::iterator it = main.begin();

	while (it != main.end() && (*it).first < value)
	{
		++it;
	}
	main.insert(it, std::make_pair(value, weight));								//insertion
}

/*
 * Classify is use only to sort the list with the pend numbers
 * This is not how it should be done and this function doesn't help
 * to reduce the sorting time.
 */
void	PmergeMeList::reorganiseWeights(t_list & pend ) {

//	printPairedList("pend before ", pend);

	if ( pend.size() == 1 )
		return;

	std::list< int >		group_size;
	group_size.push_back(2);				// we start with two for the first 2 elements

	size_t sum_size = 2;
	size_t prev = 2;

	int i = 2;
	int power = 0;
	while (sum_size + power + 2 < pend.size() )
	{

		sum_size += power;
		power = 0;
		power = pow( 2, i );
		int size = power - prev;
		if (sum_size + 2 < pend.size())
			group_size.push_back(size);
//		else
//			group_size.push_back(pend.size() - sum_size + 2);
		prev = size;
		i++;
	}

//	std::cout << "size " << pend.size() << std::endl;

//	std::list<int>::iterator it_gr = group_size.begin();
//	std::list<int>::iterator ite_gr = group_size.end();
//	for (;it_gr != ite_gr; ++it_gr)
//		std::cout << *it_gr << std::endl;

	std::list<int>::iterator it_group = group_size.begin();
	std::list<int>::iterator ite_group = group_size.end();
	t_list::iterator it_pend = pend.begin();
	t_list::iterator it_tmp;
	t_list::iterator ite_tmp;

	int start = 0;
	for (; it_group != ite_group; ++it_group)
	{
		int size = *it_group / 2;
		it_tmp = it_pend;
		ite_tmp = it_pend;
		std::advance(it_tmp, start);
		std::advance(ite_tmp, start + *it_group - 1);

		for (int i = 0; i < size; ++i )
		{
					std::swap(*it_tmp, *ite_tmp);
					++it_tmp;
					--ite_tmp;
		}
		start += *it_group;

	}
//	printPairedList("pend after ", pend);

}
/*
void PmergeMeList::binaryInsertion(t_list& main, t_list::iterator& it, t_list::iterator& start, t_list::iterator& end) {


		for (; start != end; ++start )
		{
			if (it->first < start->first )
			{
				if ( start == this->_l.begin() )
					main.push_front(*it);
				else
					main.insert(start, *it);
				return;
			}
		}
	main.insert(end, *it);
}
*/

void PmergeMeList::binaryInsertion(t_list& main, t_list::iterator& it_pend, t_list::iterator& it_start, t_list::iterator& ite_end) {

	// Recherche dichotomique pour trouver le point d'insertion
	t_list::iterator low = it_start;
	t_list::iterator high = ite_end;

	while (low != high)
	{
		t_list::iterator mid = low;
		std::advance(mid, std::distance(low, high) / 2);

		if (it_pend->first < mid->first)
		{
			high = mid;
		}
		else
		{
			low = mid;
			++low;
		}
	}

	while (low != ite_end && it_pend->first > low->first)
	{
		++low;
	}
	main.insert(low, *it_pend);
}


void PmergeMeList::findMatchingIndex( t_list::iterator & it_main, t_list::iterator & ite_main, int index )
{
	for (; it_main != ite_main; ++it_main)
	{
		if ((*it_main).second == index)
			return;
	}
}

void	PmergeMeList::merge (  t_list & main, t_list & pend )
{
	t_list ::iterator it = pend.begin();
//	int first = main.front().first;
	for (; it != pend.end(); ++it)
	{
		t_list ::iterator itH = this->_l.begin();			// beginning of the list with HIGHEST values
		t_list ::iterator itHE = this->_l.end();			// end of the list with HIGHEST values
		t_list ::iterator itHM = this->_l.begin();					// middle of the list with HIGHEST values
		std::advance(itHM, this->_l.size() / 2);		// set middle of the list with HIGHEST values

		if ( it->first == itHM->first )
			this->_l.insert(itHM, *it);
		else if (it->first > itHM->first )
			binaryInsertion(main, it, itHM, itHE);
		else
			binaryInsertion(main, it, itH, itHM);
	}

}

//// Verification---------------------------------------------------------------------------------------------------------
//

//
//bool	PmergeMeList::isSortedSublist( t_list & l ) const {
//
//	if (l.empty())
//		return false;
//
//	std::list<int>::const_iterator it = l.begin();
//	std::list<int>::const_iterator prevIt = it;
//	++it;
//	while (it != l.end())
//	{
//		if (*it < *prevIt)
//			return false;
//		++it;
//		++prevIt;
//	}
//	return true;
//}


bool	PmergeMeList::isSortedFinalList( void ) const {

	if (this->_l.size() != this->_ExpectedSortedList.size())
		return false;

	std::list<int>::const_iterator it = this->_ExpectedSortedList.begin();
	std::list<int>::const_iterator ite = this->_ExpectedSortedList.end();
	t_list::const_iterator it_res = this->_l.begin();

	for (; std::next(it ) != ite; ++it, ++it_res)
	{
		if (*it != it_res->first )
		{
//			std::cout << "This [" << (*it_res).first << "] should be [" << it.first << "] " << std::endl;
			return false;
		}
	}
	return true;
}



// printing--------------------------------------------------------------------------------------------------------------

void	PmergeMeList::printList( const std::string & title, const t_list & l) const {

	std::cout << BLUE << title;
	t_list::const_iterator it = l.begin();
	t_list::const_iterator ite = l.end();
	for (; it != ite; ++it )
	{
		std::cout << it->first << " " << it->second << " ";
	}
	std::cout << END << std::endl << std::endl;
}

void	PmergeMeList::printListFirstValueOnly( const std::string & title, const t_list & l) const {

	std::cout << BLUE << title;
	t_list::const_iterator it = l.begin();
	t_list::const_iterator ite = l.end();
	for (; it != ite; ++it )
	{
		std::cout << it->first << " ";
	}
	std::cout << END << std::endl << std::endl;
}

void PmergeMeList::printPairedList( const std::string & title, const t_list & l) const {

	std::cout << BLUE << title;
	t_list::const_iterator it = l.begin();
	t_list::const_iterator ite = l.end();
	for (; it != ite; ++it )
	{
		std::cout << "(" << GREEN_BOLD << it->first << END << ", " << DIM << it->second << END << ") ";
	}
	std::cout << END << std::endl << std::endl;
}