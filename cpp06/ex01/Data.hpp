
#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

struct Data {

	int		_n;
	float 	_f;
	char	_c;

	Data( void );
	~Data( void );
	Data( int n, float f, char c );

	void	print( void ) const;
};

#endif