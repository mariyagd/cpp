#include <string.h>
#include <unistd.h> // access
#include <errno.h>
#include "BitcoinExchange.hpp"
#include "Data.hpp"


void	print_line( void )
{
	std::cout << BLUE_BG << std::setw(50) << std::setfill('-') << "" << END << std::endl;
}

void print_title( std::string title )
{
	std::cout << std::endl;
	print_line();
	std::cout << BLUE_BG << std::left << std::setw(50) << std::setfill(' ')<< title << END << std::endl;
	print_line();
	std::cout << std::endl;

}

int execute( const char *inputFile, const char *btcFile, BitcoinExchange *&btc )
{
	try
	{
		if (strstr(inputFile, ".csv" ) == NULL)
			throw std::invalid_argument("Invalid file extension" );

		if (access( inputFile, R_OK ) != 0 || access( btcFile, R_OK ) != 0)
			throw std::runtime_error( strerror(errno) );

		btc = new BitcoinExchange( inputFile, btcFile );
		btc->init();
	}
	catch (std::invalid_argument &e)
	{
		std::cerr << RED_BOLD << "Exception thrown: invalid_argument: " << e.what() << END << std::endl;
		return 1;
	}
	catch ( const std::runtime_error & e )
	{
		std::cerr << RED_BOLD << "Exception thrown: runtime_error: " << e.what() << END << std::endl;
		return 1;
	}
	return 0;
}

int	main( int ac, char **av ) {

	(void)av;
	if (ac != 2)
	{
		std::cerr << RED_BOLD << "Usage: " << av[0] << " <input_file.csv>" << END << std::endl;
		return 1;
	}
	{

		// Subject test
		print_title("Subject test");
		int ret = 0;

		BitcoinExchange *btc = nullptr;
		std::string btcFile = "data.csv";
		std::string inputFile(av[1]);

		ret = execute(inputFile.c_str(), btcFile.c_str(), btc);
		std::cout << DIM <<  "Exit status: " << ret << END << std::endl;

		if (ret != 1)
		{
			// Copy constructor test ------------------------------------------------------------------------------------------
			print_title("Test on copy constructor");
			BitcoinExchange copy(*btc);
			try {

				copy.init();
			}
			catch (std::invalid_argument &e) {
				std::cerr << RED_BOLD << "Exception type: invalid_argument: " << e.what() << END << std::endl;
			}
			catch (const std::runtime_error &e) {
				std::cerr << RED_BOLD << "Exception type: runtime_error: " << e.what() << END << std::endl;
			}

			// Assignment operator test ------------------------------------------------------------------------------------------
			print_title("Test on assignment operator");
			BitcoinExchange assign;
			assign = *btc;
			try {

				assign.init();
			}
			catch (std::invalid_argument &e) {
				std::cerr << RED_BOLD << "Exception type: invalid_argument: " << e.what() << END << std::endl;
			}
			catch (const std::runtime_error &e) {
				std::cerr << RED_BOLD << "Exception type: runtime_error: " << e.what() << END << std::endl;
			}

			print_title("Print set: 0 is not valid rate");
			btc->printSet();
		}

		if (btc)
			delete btc;

	}
	{
		print_title("Test on input file: all lines invalid");
		int ret = 0;

		BitcoinExchange *btc = nullptr;
		std::string btcFile = "data.csv";
		std::string inputFile = "./input_all_lines_invalid.csv";

		ret = execute(inputFile.c_str(), btcFile.c_str(),btc);
		std::cout << std::endl << std::endl << DIM <<  "Exit status: " << ret << END << std::endl;

		if (btc)
			delete btc;
	}
	{
		print_title("Test on input file: all lines are valid");
		int ret = 0;

		BitcoinExchange *btc = nullptr;
		std::string btcFile = "data.csv";
		std::string inputFile = "./input_all_lines_valid.csv";

		ret = execute(inputFile.c_str(), btcFile.c_str(), btc);
		std::cout << std::endl << DIM <<  "Exit status: " << ret << END << std::endl;

		if (btc)
			delete btc;
	}
	{
		print_title("Test on date out of data.csv bounds");
		int ret = 0;


		BitcoinExchange *btc = nullptr;
		std::string btcFile = "./data.csv";
		std::string inputFile = "./input_date_out_of_bounds.csv";

		ret = execute(inputFile.c_str(), btcFile.c_str(), btc);
		std::cout << std::endl << DIM <<  "Exit status: " << ret << END << std::endl;

		if (btc)
			delete btc;
	}
	{
		print_title("Test on all lines in data.csv are invalid");
		int ret = 0;


		BitcoinExchange *btc = nullptr;
		std::string btcFile = "./data_all_lines_invalid.csv";
		std::string inputFile = "./input.csv";

		ret = execute(inputFile.c_str(), btcFile.c_str(), btc);
		std::cout << std::endl << DIM <<  "Exit status: " << ret << END << std::endl;

		if (btc)
			delete btc;
	}
	{
		print_title("Test non existing input file");
		int ret = 0;


		BitcoinExchange *btc = nullptr;
		std::string btcFile = "./data.csv";
		std::string inputFile = "./INPUT_NO_EXIST.csv";

		ret = execute(inputFile.c_str(), btcFile.c_str(), btc);
		std::cout << std::endl << DIM <<  "Exit status: " << ret << END << std::endl;

		if (btc)
			delete btc;
	}
	{
		print_title("Test non existing data file");
		int ret = 0;


		BitcoinExchange *btc = nullptr;
		std::string btcFile = "./data_NOEXIST.csv";
		std::string inputFile = "./input.csv";

		ret = execute(inputFile.c_str(), btcFile.c_str(), btc);
		std::cout << std::endl << DIM <<  "Exit status: " << ret << END << std::endl;

		if (btc)
			delete btc;
	}
	{
		print_title("Test input file no permissions");
		int ret = 0;


		BitcoinExchange *btc = nullptr;
		std::string btcFile = "./data.csv";
		std::string inputFile = "./input_no_permissions.csv";

		ret = execute(inputFile.c_str(), btcFile.c_str(), btc);
		std::cout << std::endl << DIM <<  "Exit status: " << ret << END << std::endl;

		if (btc)
			delete btc;
	}
	{
		print_title("Test data file no permissions");
		int ret = 0;


		BitcoinExchange *btc = nullptr;
		std::string btcFile = "./data_no_permissions.csv";
		std::string inputFile = "./input.csv";

		ret = execute(inputFile.c_str(), btcFile.c_str(), btc);
		std::cout << std::endl << DIM <<  "Exit status: " << ret << END << std::endl;

		if (btc)
			delete btc;
	}
	{
		print_title("Test input invalid file format");
		int ret = 0;


		BitcoinExchange *btc = nullptr;
		std::string btcFile = "./data.csv";
		std::string inputFile = "./input_invalid_format.csv";

		ret = execute(inputFile.c_str(), btcFile.c_str(), btc);
		std::cout << std::endl << DIM <<  "Exit status: " << ret << END << std::endl;

		if (btc)
			delete btc;
	}
	{
		print_title("Test empty input file");
		int ret = 0;


		BitcoinExchange *btc = nullptr;
		std::string btcFile = "./data.csv";
		std::string inputFile = "./input_empty.csv";

		ret = execute(inputFile.c_str(), btcFile.c_str(), btc);
		std::cout << std::endl << DIM <<  "Exit status: " << ret << END << std::endl;

		if (btc)
			delete btc;
	}
	{
		print_title("Test empty data file");
		int ret = 0;


		BitcoinExchange *btc = nullptr;
		std::string btcFile = "./data_empty.csv";
		std::string inputFile = "./input.csv";

		ret = execute(inputFile.c_str(), btcFile.c_str(), btc);
		std::cout << std::endl << DIM <<  "Exit status: " << ret << END << std::endl;

		if (btc)
			delete btc;
	}


	return 0;
}

/*
 * 	try
	{
		std::string btcFile = "data.csv";

		if (ac != 2)
			throw std::invalid_argument("Invalid numbers of arguments");

		if (strstr(av[1], ".csv") == NULL)
			throw std::invalid_argument("Invalid file extension");

		if (access(av[1], R_OK) != 0 || access( btcFile.c_str(), R_OK) != 0)
			throw std::runtime_error( strerror(errno) );

		BitcoinExchange	btc( av[1], btcFile.c_str());
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
 */