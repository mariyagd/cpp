#ifndef PMERGEMELIST_HPP
# define PMERGEMELIST_HPP

# include "PmergeMe.hpp"
# include <list>

class PmergeMeList : public PmergeMe {

private:
	std::list< int >	_l;
	std::list< int >	_lSorted;		// used only for verification of final sorting

public:

	PmergeMeList( void );
	~PmergeMeList( void );
	PmergeMeList( PmergeMeList const & src );
	PmergeMeList &	operator=( PmergeMeList const & src );
	PmergeMeList( std::string s );
	PmergeMeList( char **av );


	void	startSortWithList( void );
	void	initList( void );
	void	listSorting( void );
	int		getStraggler( void );
	void	pairwiseComparision( std::list< int > & smallest );
	void	recursiveInsertionSort( std::list< int > & smallest );
	void	classify( std::list< int > & smallest );
	void	mergeSort( std::list< int > & smallest );
	void	binaryInsertion(std::list< int >::iterator & itS, std::list< int >::iterator & first, std::list< int >::iterator & last);
	void	insertFrontOnHighest( int index, std::list< int > & smallest );

	// verification
	bool	isSortedFinalList( void ) const;
	bool	isSortedSublist( std::list< int > & l ) const;

	// printing
	void	printList( const std::string & title, const std::list< int > & l ) const;
};

#endif