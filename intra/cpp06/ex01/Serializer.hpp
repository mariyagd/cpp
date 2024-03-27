#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <cstdint>
# include <iostream>


class Serializer
{
private:
	Serializer( void );
	~Serializer( void );
	Serializer( Serializer const & src );
	Serializer& operator=( Serializer const & src );

public:
	static uintptr_t	serialize(Data* ptr);
	static Data* 		deserialize( uintptr_t raw );
};

#endif
