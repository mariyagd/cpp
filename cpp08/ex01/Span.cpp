#include "Span.hpp"

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
	return *this;
}

Span::Span( unsigned int n ) : _n(n){
	return;
}

void	Span::addNumber( int num ) {

	if ( this->_v.size() >= this->_n)
		throw SpanException("Exception thrown: Out of range");
	this->_v.push_back( num );
	return;
}

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

std::vector< int >	Span::getVector( void ) const {

	return this->_v;
}

std::ostream& operator<<( std::ostream &stream, const Span & span ) {

	std::vector< int > v = span.getVector();
	if (v.empty())
	{
		stream << "( empty )" << std::endl;
		return stream;
	}
	for ( std::vector< int >::iterator it = v.begin(); it != v.end(); it++)
	{
		stream << *it << " ";
	}
	return stream;
}