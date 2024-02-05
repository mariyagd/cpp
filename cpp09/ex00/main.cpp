#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "BitcoinExchange.hpp"

int	main( int ac, char **av ) {

	try
	{
		if (ac != 2)
			throw std::invalid_argument("Invalid numbers of arguments");
		if (strstr(av[1], ".csv") == NULL)
			throw std::invalid_argument("Invalid file extension");
		if (access(av[1], R_OK) != 0 || access("./data.csv", R_OK) != 0)
			throw std::runtime_error(strerror(errno));
		BitcoinExchange	btc( av[1] );
		btc.init();
	}
	catch (std::invalid_argument &e)
	{
		std::cerr << RED_BOLD << "std::invalid_argument " << e.what() << END << std::endl;
		return 1;
	}
	catch ( const std::ifstream::failure & e )
	{
		std::cerr << RED_BOLD   << "libc++ error #"
				  << e.code().value() << " "
				  << e.code().message() << std::endl
				  << "libc error #"
				  << errno << " "
				  << ::strerror(errno) << END << std::endl;
		return 1;
	}
	catch ( const std::runtime_error & e )
	{
		std::cerr << RED_BOLD << "std::runtime_error: " << e.what() << END << std::endl;
		return 1;
	}
	return 0;
}