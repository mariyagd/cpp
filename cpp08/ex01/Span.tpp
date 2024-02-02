#include "Span.hpp"

// Add range-------------------------------------------------------------------------------------------------------------

// this->_v.size() is the current size, not the size max!

template< typename T>
void Span::addRange(T begin, T end)
{
	if (this->_v.size() + std::distance(begin, end) > this->_n)
		throw SpanException("Exception thrown: Range too big");
	this->_v.insert(this->_v.end(), begin, end);
}
