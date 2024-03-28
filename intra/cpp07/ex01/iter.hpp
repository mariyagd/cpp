#ifndef ITER_HPP
#define ITER_HPP

template< typename A, typename L, typename F >
void	iter( A * array, L const & length, F * ft) {

	if (!array)
	{
		std::cout << "array is a nullptr. Can't apply iter function" << std::endl;
		return;
	}
	if (!ft)
	{
		std::cout << "ft is a nullptr. Can't apply iter function" << std::endl;
		return;
	}
	if (length < 1)
	{
		std::cout << "length is smaller than 1. Can't apply iter function" << std::endl;
		return;
	}
	for (L i = 0; i < length; i++) {
		ft(array[i]);
	}
}

template< typename A, typename L >
void	print_array(A * array, L length ) {

	if (!array)
	{
		std::cout << "array is a nullptr" << std::endl;
		return;
	}
	for (L i = 0; i < length; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

template< typename I >
void	transform( I & i) {
	i = 65;
}

template< typename I >
void	transform_decimal( I & i) {
	i += 0.5;
}

#endif