#include "PmergeMe.hpp"

// Coplien's form------------------------------------------------------------------------------------------------------

PmergeMe::PmergeMe( void ) : _s(""),  _t() {

	return;
}

PmergeMe::~PmergeMe( void ) {

	return;
}

PmergeMe::PmergeMe( PmergeMe const & src ) : _s(src._s), _t(src._t) {

	return;
}

PmergeMe &	PmergeMe::operator=( const PmergeMe & src ) {

	if ( this != &src )
	{
		if ( !this->_s.empty( ) )
			this->_s.clear( );
		this->_s = src._s;
		this->_t = src._t;
	}
	return *this;
}

// Parametrized constructor---------------------------------------------------------------------------------------------

PmergeMe::PmergeMe( std::string s ) : _s("") {

	while (std::isspace(s[s.size() - 1] ))		// delete the white spaces at the end
		s.pop_back();								// useful for the use of iss

	for ( size_t i = 0; i < s.size(); ++i)
	{
		for (; std::isspace(s[i]); ++i );

		if (s[i] == '+')
			i++;

		if (!std::isdigit( s[i]) )
			throw std::runtime_error ("Invalid input");
	}
	this->_s = s;
	return;
}

PmergeMe::PmergeMe( char **av ) : _s("") {

	std::string s = "";
	int i = 1;

	while (av[i])
	{
		s += std::string(av[i]) + " ";
		++i;
	}
//	std::cout <<"[" << s << "]" << std::endl;
	while (std::isspace(s[s.size() - 1] ))		// delete the white spaces at the end
		s.pop_back();								// useful for the use of iss

	for ( size_t i = 0; i < s.size(); ++i)
	{
		for (; std::isspace(s[i]); ++i );

		if (s[i] == '+')
			i++;

		if (!std::isdigit( s[i]) )
			throw std::runtime_error ("Invalid input");
	}
	this->_s = s;
	return;
}

// Time-----------------------------------------------------------------------------------------------------------------

void PmergeMe::printTime( size_t size ) {

	std::cout << GREEN_BOLD << "Time to process a range of " << size << " elements: ";

	float time = (float) this->_t / CLOCKS_PER_SEC;
	if (time < 1 )
		std::cout << time * 1000  << " miliseconds" << END << std::endl;
	else
		std::cout << time << " seconds" << END << std::endl;
}
