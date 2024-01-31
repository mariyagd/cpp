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
	Array< T >( void );
	~Array< T >( void );
	Array< T >( unsigned int n );
	Array< T >( Array< T > const & src);
	Array< T > & operator=( Array< T > const & src);

	T & operator[]( unsigned int i);

	unsigned int	size( void );
	T *				getArray( void );
};

template< typename T >
std::ostream & operator<<( std::ostream & stream, Array< T > array)
{
	T * arrayCopy = array.getArray();
	if (!arrayCopy)
	{
		stream << "(nullptr)";
	}
	else
	{
		for (unsigned int i = 0; i < array.size(); i++)
		{
			stream << std::setw(7) << arrayCopy[i];
		}
	}
	return stream;
}

template<>
std::ostream & operator<<( std::ostream & stream, Array< bool > array)
{
	bool * arrayCopy = array.getArray();
	if (!arrayCopy)
	{
		stream << "(nullptr)";
	}
	else
	{
		for (unsigned int i = 0; i < array.size(); i++)
		{
			stream << std::boolalpha << arrayCopy[i] << "   " ;
		}
	}
	return stream;
}
#endif
