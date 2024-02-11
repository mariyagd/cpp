#ifndef PMERGEMELIST_HPP
# define PMERGEMELIST_HPP

# include "PmergeMe.hpp"
# include <list>
# include <utility>

typedef std::list< std::pair<int, int> >				t_list;

class PmergeMeList : public PmergeMe {

private:
	t_list			_l;
	std::list<int>	_ExpectedSortedList;		// used only for verification of final sorting

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
	void	pairwiseComparision( t_list & main, t_list & pend );
	void	recursiveInsertionSort( t_list & main );
	void	reorganiseWeights( t_list & pend );
	void	merge(  t_list & main, t_list & pend );
	void	findMatchingIndex( t_list::iterator & it_main, t_list::iterator & ite_main, int index );
	void	binaryInsertion(t_list & main, t_list::iterator & itS, t_list::iterator & first, t_list::iterator & last);
	void	getFirstPair( t_list & main, t_list & pend );
//
//	// verification
	bool	isSortedFinalList( void ) const;
//	bool	isSortedSublist( t_list & l ) const;
//

	// printing
	void	printList( const std::string & title, const t_list & l ) const;
	void	printListFirstValueOnly( const std::string & title, const t_list & l) const;
	void	printPairedList( const std::string & title, const t_list & l ) const;

};

#endif