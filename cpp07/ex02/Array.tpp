#include "Array.hpp"

template< typename T >
Array< T >::Array( void ) : array( nullptr ), sizeArray(0) {
	return;
}

template< typename T >
Array< T >::~Array( void ) {

	if (this->array)
	{
		delete [] this->array;
		this->array = 0;
	}
	return;
}

template< typename T >
Array< T >::Array( unsigned int n ) : array(new T [n]), sizeArray(n) {

	for (unsigned int i = 0; i < n; i++)
		array[i] = T();
	return;
}

template< typename T >
Array< T >::Array(const Array< T > &src) : array(nullptr), sizeArray(src.sizeArray) {

	if (src.array == nullptr)
		return;
	this->array = new T [this->sizeArray];
	for ( unsigned int i = 0; i < this->sizeArray; i++)
		this->array[i] = src.array[i];
	return;
}

template< typename T >
Array< T > &	Array< T >::operator=(const Array< T > &src) {

	if (this == &src)
		return *this;
	if (this->array)
		delete [] this->array;
	this->sizeArray = src.sizeArray;
	this->array = new T [this->sizeArray];
	for ( unsigned int i = 0; i < this->sizeArray; i++)
		this->array[i] = src.array[i];
	return *this;
}

template< typename T >
T & Array< T >::operator[]( unsigned int i){
	if (i >= this->sizeArray)
		throw std::out_of_range("Exception thrown: Out of range");
	return this->array[i];
}

template< typename T >
unsigned int	Array< T >::size( void ) {

	return this->sizeArray;
}

template< typename T >
T *	Array< T >::getArray( void )
{
	return this->array;
}