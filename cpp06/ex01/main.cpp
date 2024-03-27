#include "Serializer.hpp"
#include <iostream>
#include <iomanip>

#define BLUE	"\033[1;34m"
#define END		"\033[0m"

void	print_line( void )
{
	std::cout << std::setw(100) << std::setfill('-') << "" << std::endl;
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

void	print_data( Data *&data, uintptr_t raw , Data *&deserialized)
{
	std::cout << "Original:              " << data << "     ";
	print_data_values(data);

	std::cout << "Serialized:            " << raw << std::endl;

	std::cout << "Deserialized:          " << deserialized << "     ";
	print_data_values(deserialized);
}

 int	main( void )
{

	std::cout << BLUE << "Pointer                Points to          Data                         Address of pointer" << END << std::endl;


	print_line();
	Data *data = new Data(42, 56.78f, 'a');
	Data *deserialized = 0;

	uintptr_t raw = Serializer::serialize(data);
	deserialized = Serializer::deserialize(raw);
	print_data(data, raw, deserialized);

	std::cout << BLUE << std::endl << "Change values of deserialized pointer" << std::endl << "-----" << END << std::endl;

	deserialized->_n = 21;
	deserialized->_f = 12.34f;
	deserialized->_c = 'b';
	print_data(data, raw, deserialized);

	print_line();

	Data *dataAddr1 = 0;
	Data *dataAddr2 = 0;
	uintptr_t raw1 = Serializer::serialize(dataAddr1);
	dataAddr2 = Serializer::deserialize(raw1);
	print_data(dataAddr1, raw1, dataAddr2);
	print_line();

}
