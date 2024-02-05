#include "BitcoinExchange.hpp"

// Coplien's form------------------------------------------------------------------------------------------------

BitcoinExchange::BitcoinExchange( void ) : _exchange(),_mmap(), _inputFile(""), _btcFile("./Date.csv") {

	return;
}

BitcoinExchange::~BitcoinExchange( void ) {

	return;
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src ) :	_exchange(src._exchange),
																	_mmap(src._mmap),
																	_inputFile(src._inputFile),
																	_btcFile(src._btcFile) {

	return;
}

BitcoinExchange &	BitcoinExchange::operator=( BitcoinExchange const & src ) {

	if (this != &src)
	{
		if ( !this->_exchange.empty() )
			this->_exchange.erase(this->_exchange.begin(), this->_exchange.end());
		if ( !this->_inputFile.empty() )
			this->_inputFile.clear();

		this->_inputFile = src._inputFile;
		this->_exchange = src._exchange;
		this->_mmap = src._mmap;
	}
	return *this;
}

// Parametrized constructor--------------------------------------------------------------------------------------

BitcoinExchange::BitcoinExchange( char * & av) :	_exchange(),
													_mmap(),
													_inputFile( std::string(av) ),
													_btcFile ( "./data.csv") {

	return;
}

bool	BitcoinExchange::noWhiteSpaces( std::string & line ) {

	size_t i = 0;
	for (; i < line.size(); i++)
	{
		if (isspace(line[i]))
			return false;
	}
	return true;
}

//Date BitcoinExchange::getDate( std::string & s_date ) {
//
//	Date					date;
//	char					hyphen1, hyphen2;
//	std::istringstream 		iss(s_date);
//
//	date.date = s_date;
//	iss >> date.year >> hyphen1 >> date.month >> hyphen2 >> date.day;
//
//	if (iss.fail() || hyphen1 != '-' || hyphen2 != '-')
//	{
//		date.error_msg = "Error: bad input => " + s_date;
//		return date;
//	}
//
//	Date unixStart(1970, 1, 1);
//	if (date < unixStart)
//	{
//		date.error_msg = "Error: date out of range => " + s_date;
//		return date;
//	}
//
//	return date;
//}

float BitcoinExchange::getRate( std::string & s_rate, Date & date ) {

	float rate;

	std::istringstream iss(s_rate);
	iss >> rate;
	if (iss.fail() || rate < 0.0f || rate > 1000.0f || rate > std::numeric_limits<int>::max())
	{
		date.date = "Error: " + s_rate;
	}
	return rate;
}

void	BitcoinExchange::init( void ) {

	std::ifstream ifs(_btcFile.c_str());
	if (!ifs.is_open())
		throw std::runtime_error("Could not open file");

	std::string line;

	getline(ifs, line);
	if ( line != "date,exchange_rate")
		throw std::invalid_argument("Invalid file format");

	while ( getline(ifs, line) )
	{
		if ( noWhiteSpaces(line) == true && line.find(',') != std::string::npos )
		{
			std::istringstream iss(line);
			std::string s_date;
			std::string s_rate;
			getline(iss, s_date, ',');
			getline(iss, s_rate);

			Date date(s_date);
			float rate = getRate(s_rate, date);

			_mmap.insert(std::make_pair(date, rate));
			s_date.clear();
			s_rate.clear();
		}
		else
		{
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}

	ifs.close();
	std::multimap<Date, float >::iterator it = _mmap.begin();
	for (; it != _mmap.end(); ++it)
	{
			std::cout	<< std::left
						<< it->first.date
						<< std::setw(5) << ""
						<< it->second << std::endl;
	}
	std::cout << _mmap.size() << std::endl;
}



bool Date::operator<(const Date& other) const {

	if (this->date.find("Error") != std::string::npos || other.date.find("Error") != std::string::npos)
		return false;
	if (this->_date_time_t < other._date_time_t)
		return true;
	return false;
};

Date::Date( void ) : _date_time_t(), date(""), error_msg("")  {

	return;
}

Date::Date(std::string s_date) : _date_time_t(), date(s_date), error_msg("") {

	unsigned int			year, month, day = 0;
	char					hyphen1, hyphen2 = 0;
	std::istringstream 		iss(s_date);

	iss >> year >> hyphen1 >> month >> hyphen2 >> day;

	if (iss.fail() || hyphen1 != '-' || hyphen2 != '-')
	{
		this->date = "Error: bad input => " + s_date;
		return;
	}

	unsigned int daysInMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31,  30, 31,30, 31};

	if (month < 1 || month > 12) {
		this->date = "Error: Invalid month => " + s_date;
		return;
	}
	if (day < 0 || day > daysInMonth[month - 1])
	{
		this->date = "Error: Invalid days in month [max " + std::to_string(daysInMonth[month - 1]) + "] => " + s_date;
		return;
	}

	std::tm date_tm = {};
	date_tm.tm_year = year - 1900;
	date_tm.tm_mon = month - 1;
	date_tm.tm_mday = day;
	date_tm.tm_hour = 0;
	date_tm.tm_min = 0;
	date_tm.tm_sec = 0;

	this->_date_time_t = std::mktime(&date_tm);

	if (_date_time_t == -1)
	{
		this->date = "Error: Invalid date format => " + s_date;
		return;
	}


	std::time_t epoch_time = 0;
	std::time_t current_time = std::time(nullptr);

	if (this->_date_time_t > current_time)
	{
		this->date = "Error: Date is in the future => " + s_date;
		return;
	}
	else if (this->_date_time_t < epoch_time)
	{
		this->date = "Error: Date is before 1 Jan. 1900 => " + s_date;
		return;
	}
	return;
}

