#include "PmergeMe.hpp"
#include <list>

PmergeMe::PmergeMe( std::string s ) : _s(s) {

	initList();
//	(void)this->_s;
//	int tab[9] = {52, 46, 100, 44, 8, 11, 38, 45, 13};
//	for (size_t i = 0; i < 9; ++i)
//		this->_l.push_back(tab[i]);
	printList( "List before:\n", this->_l );
	listSorting();
	return;
}

void	PmergeMe::listSorting( void ) {

	size_t	middle = this->_l.size() / 2;
	( void )middle;	
	std::list< int >::iterator	it = this->_l.begin();
	std::list< int >::iterator	ite = this->_l.end();
	std::list< int >::iterator	it_middle = this->_l.begin();
	for (size_t i = 0; i < middle; ++i, ++it_middle);

	std::list< int > subList1, subList2;

	subList1.insert(subList1.begin(), it, it_middle);
	subList2.insert(subList2.begin(), it_middle, ite);

	this->_l.clear();
	insertionSort(subList1);
	insertionSort(subList2);

	if ( !isSortedList( subList1) || !isSortedList( subList2) )
		throw std::runtime_error ("Could not sort list substrings correctly :(");


//	for debugging
	printList("subList1: ", subList1);
	printList("subList2: ",subList2);

	mergeSort( subList1, subList2 );
	printList("List after:\n",this->_l);
	if ( !isSortedList(this->_l))
		throw std::runtime_error ("Could not sort final list correctly :(");
	else
		std::cout << "List sorted successfully!" << std::endl;
	return;
}

void	PmergeMe::insertionSort( std::list< int > & l )
{
	std::list< int >::iterator it = l.begin();
	std::list< int >::iterator ite = l.end();

	while ( it != ite )
	{
		std::list< int >::iterator it2 = it;
		while ( it2 != ite )
		{
			if ( *it > *it2 )
			{
				std::swap(*it, *it2);
				break;
			}
			++it2;
		}
		++it;
	}

	if ( !isSortedList(l))
		insertionSort(l);
}

void	PmergeMe::mergeSort( std::list< int > & l1, std::list< int > & l2 )
{
	std::list< int >::iterator it1 = l1.begin();
	std::list< int >::iterator ite1 = l1.end();

	std::list< int >::iterator it2 = l2.begin();
	std::list< int >::iterator ite2 = l2.end();

	if (l1.empty() && l2.empty())
		return;

	if (it1 != ite1 && it2 != ite2 && *it1 < *it2)
	{
		this->_l.push_back( *it1 );
		l1.pop_front();
		mergeSort(l1, l2);
	}
	else if (it1 != ite1 && it2 != ite2 && *it2 < *it1)
	{
		this->_l.push_back( *it2 );
		l2.pop_front();
		mergeSort(l1, l2);
	}
	else if (it1 != ite1 && it2 != ite2 && *it2 == *it1)
	{
		this->_l.push_back(*it1);
		this->_l.push_back(*it2);
		l1.pop_front();
		l2.pop_front();
		mergeSort(l1, l2);
	}
	else if (l1.empty() && !l2.empty() )
	{
		std::list< int >::iterator it = l2.begin();
		std::list< int >::iterator ite = l2.begin();

		for (; it != ite; ++it)
			this->_l.push_back(*it);
		return;
	}
	else if ( l2.empty() && !l1.empty() )
	{
		std::list< int >::iterator it = l1.begin();
		std::list< int >::iterator ite = l1.begin();

		for (; it != ite; ++it)
			this->_l.push_back(*it);
		return;
	}
}

void	PmergeMe::initList( void ) {

	std::istringstream iss(this->_s );

	while ( iss.peek() != EOF)
	{
		int num = 0;
		iss >> num;
		_l.push_back(num);
	}
}

void	PmergeMe::printList( const std::string & title, const std::list< int > & l) const {

	std::cout << title;
	std::list< int >::const_iterator it = l.begin();
	std::list< int >::const_iterator ite = l.end();
	for (; it != ite; ++it )
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;
}

bool	PmergeMe::isSortedList( std::list< int > & l ) const {

	if (l.empty())
	{
		std::cout << "Empty list :(" << std::endl;
		return false;
	}
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
