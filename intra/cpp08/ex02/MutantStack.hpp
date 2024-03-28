#ifndef __MUTANTSTACK__HPP
# define __MUTANTSTACK__HPP

# include <iostream>
# include <stack>
#include <iostream>
#include <iomanip>
#include <stack>
#include <iterator>
#include <list>
#include <vector>

#define BLUE		"\033[1;34m"
#define END			"\033[0m"
#define BLUE_BG		"\033[44m"
#define RED			"\033[1;31m"


template <typename T, typename Container = std::deque< T > >
class MutantStack : public std::stack< T, Container >
{
public:

	MutantStack( void ) : std::stack<T, Container>() {}
	~MutantStack() {}
	MutantStack( MutantStack const & src ) : std::stack<T, Container>( src ) {}
	MutantStack& operator=( MutantStack const & src )  { std::stack<T, Container>::operator=( src ); return *this; }

//	typedef typename std::stack< T >::container_type ::iterator iterator;
	typedef typename Container::iterator iterator;

	iterator begin( void ) { return this->c.begin(); }
	iterator end( void ) { return this->c.end(); }

	typedef typename Container::const_iterator const_iterator;

	const_iterator begin( void ) const { return this->c.begin(); }
	const_iterator end( void ) const { return this->c.end(); }
};

// for testing --------------------------------------------------------------------------------------------------------------

template < typename Container >
void	print_sequence_container( Container & c, std::string name) {

	std::string title = "Print " + name;
	std::cout << BLUE << std::left << std::setw(25) << title<< END;

	for ( typename Container::iterator it = c.begin(); it != c.end(); it++ )
	{
		std::cout << *it << "  ";
	}
	std::cout << std::endl;
}

// for testing --------------------------------------------------------------------------------------------------------------

template < typename T , typename Container >
void	print_stack( std::stack< T, Container > & s ) {

	std::cout << BLUE << std::left << std::setw(25) << "Normal Stack" << END;

	while ( !s.empty() )
	{
		std::cout << s.top() << "  ";
		s.pop();
	}
	std::cout << std::endl;
}

// for testing --------------------------------------------------------------------------------------------------------------

template < typename T , typename Container>
void print_mutant_stack( MutantStack< T, Container > & s ) {

	std::cout << BLUE << std::left << std::setw(25) << "MutantStack" << END;

	typename Container::iterator it = s.begin();
	typename Container::iterator ite = s.end();

	while ( it != ite )
	{
		std::cout << *it << "  ";
		++it;
	}
	std::cout << std::endl;
}


#endif
