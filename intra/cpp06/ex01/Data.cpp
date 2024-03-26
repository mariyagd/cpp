#include "Data.hpp"

Data::Data( void ) : _n(0), _f(0), _c(0) {
	return;
};

Data::Data( int n, float f, char c ) : _n(n), _f(f), _c(c) {
	return;
};

Data::~Data( void ) {
	return;
};

void	Data::print( void ) const {
	std::cout << "Data: " << this->_n << ", " << this->_f << ", " << this->_c;
}