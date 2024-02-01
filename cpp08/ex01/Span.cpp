#include "Span.hpp"

// Coplien form---------------------------------------------------------------------------------------------------------

Span::Span( void ) : _n(0) {
	return;
}

Span::~Span( void ) {
	return;
}

Span::Span(const Span &src) : _n(src._n), _v(src._v) {

	return;
}

Span&	Span::operator=(const Span &src) {

	if (this == &src)
		return *this;
	this->_v = src._v;
	this->_n = src._n;
	return *this;
}

// Parametrized constructor----------------------------------------------------------------------------------------------

Span::Span( unsigned int n ) : _n(n){
	return;
}

// Add number------------------------------------------------------------------------------------------------------------

void	Span::addNumber( int num ) {

	if ( this->_v.size() >= this->_n)
		throw SpanException("Exception thrown: Out of range");
	this->_v.push_back( num );
	return;
}


// Add range-------------------------------------------------------------------------------------------------------------

void	Span::addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {

	if (this->_v.size() + std::distance(begin, end) > this->_n)
		throw SpanException("Exception thrown: The range that you want to try to add is too big");
	this->_v.insert(this->_v.end(), begin, end);
	return;
}


// Shortest and longest span---------------------------------------------------------------------------------------------
int Span::shortestSpan( void ) const {

	if (this->_v.empty() || this->_v.size() == 1 )
		throw SpanException("Exception thrown: Empty span or only one number");
	std::vector< int > vv = this->_v;
	std::sort(vv.begin(), vv.end());
	int min_val;

	std::vector< int >::iterator it = vv.begin();
	min_val = std::abs(*it - *(it + 1));

	for (; it != vv.end() - 1; it++)
	{
		if (std::abs(*it - *(it + 1)) < min_val)
			min_val = std::abs(*it - *(it + 1));
	}
	return min_val;
}

int Span::longestSpan( void ) const {

	if (this->_v.empty() || this->_v.size() == 1 )
		throw SpanException("Exception thrown: Empty span or only one number");

	int max_val = *std::max_element(_v.begin(), _v.end());
	int min_val = *std::min_element(_v.begin(), _v.end());

	return max_val - min_val;
}

// Getters -----------------------------------------------------------------------------------------------------------

const std::vector< int >  & Span::getVector( void ) const {

	return this->_v;
}

 const unsigned int & Span::getMaxSize( void ) const {

	return this->_n;
}

 unsigned int Span::getCurrentSize( void ) const {

	return this->_v.size();
}

// Customized Exception handler------------------------------------------------------------------------------------------

Span::SpanException::SpanException(const char *message) : _message(message) {

	return;
}

const char * Span::SpanException::what() const throw() {

	return this->_message;
}

// Operator overload-----------------------------------------------------------------------------------------------------
std::ostream& operator<<( std::ostream &stream, const Span & span ) {

	std::vector< int > v = span.getVector();
	if (v.empty())
	{
		stream << "( empty )";
	}
	else
	{
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			stream << *it << " ";
		}
	}
	stream << "    | max size = " << span.getMaxSize() << "   current size = " << span.getCurrentSize() << std::endl;
	return stream;
}

