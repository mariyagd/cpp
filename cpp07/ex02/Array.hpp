#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <iomanip>
#include <stdexcept>

template< typename T >
class Array {

private:
	T					*array;
	unsigned int		sizeArray;

public:
	Array( void );
	~Array( void );
	Array( unsigned int n );
	Array( Array const & src);
	Array & operator=( Array const & src);

	unsigned int	size( void );
	void			setElement(unsigned int i, T content);
	T *				getArray( void );
};

template< typename T >
std::ostream & operator<<( std::ostream & stream, Array< T > array)
{
	T * arrayCopy = array.getArray();
	if (!arrayCopy)
		stream << "(nullptr)";
	else
	{
		for (unsigned int i = 0; i < array.size(); i++)
		{
			stream << "[" << i << "] " << std::setw(3) << arrayCopy[i] << "   ";
		}
	}
	return stream;
}
#endif
