#include "BitcoinExchange.hpp"

// Coplien's form------------------------------------------------------------------------------------------------

BitcoinExchange::BitcoinExchange( void ) : _set(), _inputFile( NULL ), _btcFile( NULL ) {

	return;
}

BitcoinExchange::~BitcoinExchange( void ) {

	return;
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src ) :	_set(src._set),
																	_inputFile(src._inputFile),
																	_btcFile(src._btcFile) {

	return;
}

BitcoinExchange &	BitcoinExchange::operator=( BitcoinExchange const & src ) {

	if (this != &src)
	{
		if (this->_set.empty())
			this->_set.clear();
		this->_set = src._set;
		this->_btcFile = const_cast< char * >(src._btcFile);
		this->_inputFile = const_cast< char * >(src._inputFile);
	}
	return *this;
}

// Parametrized constructor--------------------------------------------------------------------------------------

BitcoinExchange::BitcoinExchange( const char * av, const char * btcFile) :	_set(),
																	_inputFile( av ),
																	_btcFile ( btcFile ) {

	return;
}

// Init ---------------------------------------------------------------------------------------------------

void	BitcoinExchange::init( void ) {

	initBtcFile();
	initInputFile();
}

void	BitcoinExchange::initBtcFile( void ) {

	std::ifstream ifs;

	openFile(this->_btcFile, ifs);
	checkTitle( "date,exchange_rate", ifs);

	std::string line;

	while ( getline(ifs, line) )
	{
		if ( validBtcDelimiter(line) )
		{
			Data data;
			processData( data, line, ',' );

			if (data.isValid())
				_set.insert(data);
		}
	}
	ifs.close();
}

void	BitcoinExchange::initInputFile( void ) {

	if ( this->_set.empty() )
		throw std::invalid_argument("Empty set");

	std::ifstream ifs;

	openFile(this->_inputFile, ifs);
	checkTitle( "date | value", ifs);

	std::string line;

	while ( getline(ifs, line) )
	{
		if (validInputDelimiter(line) )
		{
				Data data;
				processData(data, line, '|');
				findRate(data);
		}
		else
			std::cerr << RED << "Error: Invalid input => " << line << END << std::endl;
	}
	ifs.close();
}

void	BitcoinExchange::processData( Data & data, std::string & line, char delimiter ) {

	std::istringstream iss(line);
	std::string s_date;
	std::string s_rate;

	getline(iss, s_date, delimiter );
	getline(iss, s_rate);

	data.process( s_date, s_rate );
}

// Find rate---------------------------------------------------------------------------------------------------

void	BitcoinExchange::findRate( Data & data ) {

	if (data.isValid())
	{
		std::set<Data>::iterator it = _set.begin();
		for (; it != _set.end() && *it <= data; ++it);
		it--;
		data *= *it;
		std::cout << data;
	}
	else
		std::cerr << RED << data.getErrorMsg() << END << std::endl;
}

bool	BitcoinExchange::validBtcDelimiter( std::string & line ) {

	size_t i = 0;
	for (; i < line.size(); i++)
	{
		if (isspace(line[i]))
			return false;
	}
	if (line.find(',') != std::string::npos)
		return true;
	return false;
}

// Input delimiter checker

bool	BitcoinExchange::validInputDelimiter( std::string & line ) {

	size_t count = 0;
	size_t pos = 0;

	while ((pos = line.find(' ', pos)) != std::string::npos)
	{
		count++;
		pos++;
	}
	if (count == 2 && line.find(" | ") != std::string::npos)
		return true;
	return false;
}

void		BitcoinExchange::openFile( const char * & fileName, std::ifstream & ifs ) {

	ifs.open( fileName );

	if (!ifs.is_open())
		throw std::runtime_error("Could not open file");

	return ;

}

void	BitcoinExchange::checkTitle( const std::string & title, std::ifstream & ifs ) {

	std::string line;
	getline(ifs, line);

	if (line != title)
		throw std::invalid_argument("Invalid file format or empty file");

	return;
}


// for testing---------------------------------------------------------------------------------------------------

void	BitcoinExchange::printSet( void ) const {

	for (std::set<Data >::iterator it = _set.begin(); it != _set.end(); ++it)
		std::cout << *it;
}

