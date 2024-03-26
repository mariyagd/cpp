#include "Serializer.hpp"
#include <iostream>
#include <iomanip>

#define BLUE	"\033[1;34m"
#define END		"\033[0m"

void	print_line( void )
{
	std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;
}

void	print_title( std::string title )
{
	std::cout << BLUE << title << END << std::endl;
	print_line();
}

void	print_data_values( Data *&data ) {
	if (data)
		data->print();
	else
		std::cout << "        NULL";
	std::cout << "           " << &data << std::endl;
}

void	print_data( Data *&data, uintptr_t raw , Data *&another)
{
	std::cout << "Data *data:                     " << data << "     ";
	print_data_values(data);

	std::cout << "Data *data -> uintptr_t:        " << raw << std::endl;

	std::cout << "uintptr_t -> Data *another :    " << another << "     ";
	print_data_values(another);
}

 int	main( void )
{

	print_line();
		Data *data = new Data(42, 56.78f, 'a');
		Data *another = 0;

		uintptr_t raw = Serializer::serialize(data);
		another = Serializer::deserialize(raw);
		print_data(data, raw, another);

		std::cout << BLUE << std::endl << "Change values from another" << std::endl << "-----" << END << std::endl;

		another->_n = 21;
		another->_f = 12.34f;
		another->_c = 'b';
		print_data(data, raw, another);

		print_line();

		Data *dataAddr1 = 0;
		Data *dataAddr2 = 0;
		uintptr_t raw1 = Serializer::serialize(dataAddr1);
		dataAddr2 = Serializer::deserialize(raw1);
		print_data(dataAddr1, raw1, dataAddr2);
	print_line();

}
