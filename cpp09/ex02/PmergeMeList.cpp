#include "PmergeMeList.hpp"

// Coplien's form------------------------------------------------------------------------------------------------------

PmergeMeList::PmergeMeList( void ) : PmergeMe(), _l(), _lSorted() {

	return;
}

PmergeMeList::~PmergeMeList( void ) {

	return;
}

PmergeMeList::PmergeMeList( const PmergeMeList & src ) : PmergeMe(src), _l(src._l), _lSorted(src._lSorted) {

	return;
}

PmergeMeList & PmergeMeList::operator=( const PmergeMeList & src ) {

	if ( this != &src )
	{
		*this = src;
		if ( !this->_l.empty() )
			this->_l.clear();
		if ( !this->_lSorted.empty() )
			this->_lSorted.clear();
		this->_l = src._l;
		this->_lSorted = src._lSorted;
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
	this->_lSorted = this->_l;		// used only for final checking
	this->_lSorted.sort();

	printList( "List BEFORE: ", this->_l );

	this->_t = clock();
	if ( !isSortedFinalList() && this->_l.size() != 1 )		//if the list is sorted or the size is 1, don't do sorting
		listSorting();;

	this->_t = clock() - this->_t;

	printList( "List AFTER: ", this->_l );

	std::cout << GREEN_BOLD << "List sorted successfully!" << END << std::endl;

	printTime( this->_l.size() );

	return;
}

void	PmergeMeList::initList( void ) {

	std::istringstream iss(this->_s );

	while ( iss.peek() != EOF)
	{
		int num = 0;
		iss >> num;
		if ( iss.fail() )
			throw std::runtime_error ("Not a int");
		this->_l.push_back(num);
	}
}

/*
 Before using merge sort, the list with larger numbers S should look like this:
 S = (x1, x2, x3,...) where every element xi and i >= 3 is associated with
 and element yi < xi, where yi is an element of the list with smallest numbers.
 */

void	PmergeMeList::listSorting( void ) {

	std::list< int > smallest;
	int straggler;
	(void)straggler;

	straggler= getStraggler(); 												// if the size of the list is odd, I extract ta last value in the smallest sublist
	pairwiseComparision(smallest );

//	for debugging
//	printList("highest before:  ", this->_l);
//	printList("smallest before: ", smallest);

	std::list<int>::iterator minIt = std::min_element(this->_l.begin(), this->_l.end());
	int minIndex = std::distance(this->_l.begin(), minIt);

	recursiveInsertionSort( this->_l );

	if ( !isSortedSublist( this->_l) )								// check just in case
		throw std::runtime_error ("Could not sort the sublists correctly :(");

	insertFrontOnHighest( minIndex, smallest );
	if (straggler > 0)
		smallest.push_back(straggler);

	classify(smallest);

//	for debugging
//	printList("highest after:  ", this->_l);
//	printList("smallest after: ",smallest);

	mergeSort( smallest );

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

void	PmergeMeList::insertFrontOnHighest( int index, std::list< int > & smallest ) {

	std::list< int >::iterator it = smallest.begin();
	std::advance(it, index);
	this->_l.push_front(*it);
	smallest.erase(it);
}

int	PmergeMeList::getStraggler( void ) {

	std::list< int >::iterator	ite = this->_l.end();
	int straggler = -1;

	if (this->_l.size() % 2 != 0)
	{
		--ite;
		straggler = *ite;
		this->_l.pop_back();
	}
	return straggler;
}

/*
 1) `std::min_element` and `std::max_element` return an iterator pointing to the element with the smallest/highest
 value in the range [first, last). Because `last` is excluded, I use std::next(std::next(it)) to be able to access
 the next adjacent element.

 2) I keep the larger numbers in `this->_l` and the smallest in `smallest`. `smallest` will be a temporary 'pend' list.
 This allows me to merge `smallest` directly into `this->_l` without needing to generate a third list. Before
 erasing the iterator with the min value `this->_l.erase(min);`, I store the distance, so I can properly increment
 the iterator with `std::advance(it, distance);`.
*/

void	PmergeMeList::pairwiseComparision( std::list< int > & smallest ) {

	std::list< int >::iterator	it = this->_l.begin();

	while ( it != this->_l.end() && std::next( it ) != this->_l.end( ) )
	{
		std::list< int >::iterator min = std::min_element( it, std::next(std::next( it ) ));	// 1)
		int distance = std::distance(this->_l.begin(), std::next( it ));							// 2)
		smallest.push_back( *min );
		this->_l.erase(min);
		it = this->_l.begin();
		std::advance(it, distance);
	}
	return;
}

/*
 * Recursive sorting is used to sort only the list with the largest values
 */
void	PmergeMeList::recursiveInsertionSort( std::list< int > & l )
{
	if (l.size() <= 1) return; 								// Cas de base

	int key = l.back();
	l.pop_back();

	recursiveInsertionSort(l); 							//recursion

	std::list<int>::iterator it = l.begin();

	while (it != l.end() && *it < key)
	{
		++it;
	}
	l.insert(it, key);								//insertion
}

/*
 * Classify is use only to sort the list with the smallest numbers
 * This is not how it should be done and this function doesn't help
 * to reduce the sorting time.
 */
void	PmergeMeList::classify(std::list< int > & smallest ) {

//	printList("smallest before ", smallest);

	if ( smallest.size() == 1 )
		return;

//	std::list< int >::iterator it = smallest.begin();

//	std::swap(*it, *std::next(it));

	if (smallest.size() < 3 )
		return;
	std::list< int > group_size;
	group_size.push_back(2);

	size_t sum_size = 2;
	size_t prev = 2;

//	std::cout << "size " << smallest.size() << std::endl;

	int i = 2;
	int power = 0;
	while (sum_size + 2 < smallest.size() )
	{
		sum_size += power;
		power = 0;
		power = pow( 2, i );
		int size = power - prev;
		if (sum_size + 2 < smallest.size())
			group_size.push_back(size);
/*
//		std::cout << "sum_size " << sum_size - prev << std::endl;
//		std::cout << "prev " << prev << std::endl;

		int power = pow( 2, i );

//		std::cout << "power " << power << std::endl;
//		std::cout << "power - prev " << power - prev << std::endl;

		group_size.push_back(power - prev);
		prev = power - prev;
		sum_size += power;

//		std::cout << "new sum size " << sum_size - prev << std::endl;

		i++;
//		std::cout << "i " << i << std::endl << std::endl;
*/
	}

//	std::list< int >::iterator it11 = group_size.begin();
//	std::list< int >::iterator ite11 = group_size.end();
//	for (;it11 != ite11; ++it11)
//		std::cout << *it11 << std::endl;
//	it = smallest.begin();

	std::list<int> tmp;
	std::list<int>::iterator it_group = group_size.begin();
	std::list<int>::iterator ite_group = group_size.end();
	std::list<int>::iterator it_smallest = smallest.begin();

	int start = 0;
	for (; it_group != ite_group; ++it_group)
	{
//		std::cout << "size " << *it_group << std::endl;
		int size = *it_group / 2;
		std::list<int>::iterator tmp1 = it_smallest;
		std::list<int>::iterator tmp2 = it_smallest;
		std::advance(tmp1, start);
		std::advance(tmp2, start + *it_group -1);



		for (int i = 0; i < size; ++i )
		{
//					std::cout << "tmp1 " << *tmp1 << std::endl;
//					std::cout << "tmp2 " << *tmp2 << std::endl;
					std::swap(*tmp1, *tmp2);
					++tmp1;
					--tmp2;
		}
		start += *it_group ;
//		printList("smallest after ", smallest);

	}
//	printList("smallest after ", smallest);





	/*
	std::list< int >::iterator it = smallest.begin();
	while ( it != smallest.end() && std::next(it) != smallest.end() )
	{
		std::swap( *it, *std::next(it) );
		++it;
		if (it != smallest.end() && std::next(it) != smallest.end() )
			++it;
		else
			return;
	}
	 */
}

void	PmergeMeList::binaryInsertion(std::list< int >::iterator & it, std::list< int >::iterator & start, std::list< int >::iterator & end)
{
	for (; start != end; ++start )
	{
		if (*it < *start )
		{
			if ( start == this->_l.begin() )
				this->_l.push_front(*it);
			else
				this->_l.insert(start, *it);
			return;
		}
	}
	this->_l.insert(end, *it);
}

void	PmergeMeList::mergeSort( std::list< int > & smallest )
{
	std::list< int >::iterator it = smallest.begin();
	for (; it != smallest.end(); ++it)
	{
		std::list< int >::iterator itH = this->_l.begin();		// beginning of the list with HIGHEST values
		std::list< int >::iterator itHE = this->_l.end();			// end of the list with HIGHEST values
		std::list< int >::iterator itHM = this->_l.begin();;		// middle of the list with HIGHEST values
		std::advance(itHM, this->_l.size() / 2);		// set middle of the list with HIGHEST values

		if ( *it == *itHM )
			this->_l.insert(itHM, *it);
		else if (*it > *itHM)
			binaryInsertion(it, itHM, itHE);
		else
			binaryInsertion(it, itH, itHM);
	}
}

// Verification---------------------------------------------------------------------------------------------------------

void	PmergeMeList::printList( const std::string & title, const std::list< int > & l) const {

	std::cout << BLUE << title;
	std::list< int >::const_iterator it = l.begin();
	std::list< int >::const_iterator ite = l.end();
	for (; it != ite; ++it )
	{
		std::cout << *it << " ";
	}
	std::cout << END << std::endl << std::endl;
}

bool	PmergeMeList::isSortedSublist( std::list< int > & l ) const {

	if (l.empty())
		return false;

	std::list<int>::const_iterator it = l.begin();
	std::list<int>::const_iterator prevIt = it;
	++it;
	while (it != l.end())
	{
		if (*it < *prevIt)
			return false;
		++it;
		++prevIt;
	}
	return true;
}

bool	PmergeMeList::isSortedFinalList( void ) const {


	if ( this->_l.size() != this->_lSorted.size() )
		return false;

	std::list< int >::const_iterator it = this->_lSorted.begin();
	std::list< int >::const_iterator ite = this->_lSorted.end();
	std::list< int >::const_iterator it1 = this->_l.begin();
//	std::list< int >::const_iterator ite1 = this->_l.end();

	for (; it != ite; ++it, ++it1)
	{
		std::cout << GREEN_BOLD << *it1 << " ";
		if (*it != *it1 )
		{
			return false;
		}
	}
	return true;
}