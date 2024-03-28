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

	unsigned int	size( void ) const;
	T *				getArray( void );
};

template< typename T >
std::ostream & operator<<( std::ostream & stream, Array< T > array);

template<>
std::ostream & operator<<( std::ostream & stream, Array< bool > array);

#endif
