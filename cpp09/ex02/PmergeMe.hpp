#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <time.h>
#include "Colors.h"
#include <algorithm>
#include <iterator>
#include <tgmath.h>

class PmergeMe {

protected:
	std::string 		_s;
	clock_t 			_t;


public:
	PmergeMe( void );
	virtual ~PmergeMe( void );
	PmergeMe( PmergeMe const & src );
	PmergeMe &	operator=( PmergeMe const & src );

	PmergeMe( std::string s );
	PmergeMe( char **av );
	void	printTime( size_t size );

};

#endif


