#include "Data.hpp"

// Coplien's form-------------------------------------------------------------------------------------------------------
Data::Data( void ) : _date(""), _rate(0.0f), _error_msg("") {

	return;
}

Data::~Data( void ) {

	return;
}

Data::Data( Data const & src ) : _date(src._date), _rate(src._rate), _error_msg(src._error_msg) {

	return;
}

Data &	Data::operator=( Data const & src ) {

	if (this != &src)
	{
		this->_date = src._date;
		this->_rate = src._rate;
		this->_error_msg = src._error_msg;
	}
	return *this;
}

// Process (init) with parametrized constructor or function ----------------------------------------------------------------------
Data::Data( std::string s_date, std::string & s_rate ) : _date(""), _rate(0.0f), _error_msg("") {

	if ( isValidDate(s_date) )
		isValidRate(s_rate);
	return;
}

void			Data::process( std::string s_date, std::string & s_rate ) {

	if ( isValidDate(s_date) )
		isValidRate(s_rate);
	return;
}

// Validity-------------------------------------------------------------------------------------------------------------
bool			Data::isValid( void ) const {

	if ( this->_error_msg.empty() )
		return true;
	return false;
}

// Date Checking main function -----------------------------------------------------------------------------------------

bool			Data::isValidDate( std::string & s_date ) {

	int						year, month, day = 0;
	char					hyphen1, hyphen2 = 0;
	std::istringstream 		iss(s_date);

	iss >> year >> hyphen1 >> month >> hyphen2 >> day;

	if (iss.fail() || hyphen1 != '-' || hyphen2 != '-')
	{
		this->_error_msg = "Error: Invalid input => " + s_date;
		return false;
	}

	switch (0)
	{
		case 0:
			if (!isNotNegativeOrNull(year, month, day)) {
				this->_error_msg += s_date;
				return false;
			}
		case 1:
			if (!isValidMonth(month)) {
				this->_error_msg += s_date;
				return false;
			}
		case 2:
			if (!isValidDay(year, month, day)) {
				this->_error_msg += s_date;
				return false;
			}
		case 3:
			if (!isInRange(year, month, day)) {
				this->_error_msg += s_date;
				return false;
			}
		default:
			this->_date = s_date;
			return true;
	}
}

// Date checking helpers -----------------------------------------------------------------------------------------------

bool			Data::isNotNegativeOrNull( int & year, int & month, int & day) {

	if (year <= 0 || month <= 0 || day <= 0)
	{
		this->_error_msg = "Error: Invalid date ( negative or null ) => ";
		return false;
	}
	return true;
}

bool			Data::isLeapYear( int & year ) {

	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		return true;
	return false;
}

bool			Data::isValidMonth( int & month ) {

	if (month < 1 || month > 12)
	{
		this->_error_msg = "Error: Invalid month => ";
		return false;
	}
	return true;
}

bool			Data::isValidDay( int & year, int & month, int & day ) {

	int daysInMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31,  30, 31,30, 31};

	if ( month != 2 && day > daysInMonth[month - 1] )
	{
		this->_error_msg = "Error: Invalid days [max " + std::to_string(daysInMonth[month - 1]) + " days] => ";
		return false;
	}
	if ( month == 2 && day > 28 && !isLeapYear(year) )
	{
		this->_error_msg = "Error: Invalid days [max 28 days] => ";
		return false;
	}
	if ( month == 2 && day > 29 && isLeapYear(year) )
	{
		this->_error_msg = "Error: Invalid days [max 29 days] => ";
		return false;
	}
	return true;
}

bool			Data::isInRange( int & year, int & month, int & day  ) {

	std::tm date_tm = {};
	date_tm.tm_year = year - 1900;
	date_tm.tm_mon = month - 1;
	date_tm.tm_mday = day;
	date_tm.tm_hour = 0;
	date_tm.tm_min = 0;
	date_tm.tm_sec = 0;

	time_t	date_time_t = std::mktime(&date_tm);

	if (date_time_t == -1)
	{
		this->_error_msg = "Error: Invalid date format => ";
		return false;
	}

	time_t epoch_time = 0;
	time_t current_time = time(0);
	localtime(&current_time);

	if (date_time_t > current_time)
	{
		this->_error_msg = "Error: Future date => ";
		return false;
	}
	if (date_time_t < epoch_time)
	{
		this->_error_msg = "Error: Date before epoch => ";
		return false;
	}
	return true;
}

// Rate checking---------------------------------------------------------------------------------------------------

bool			Data::isValidRate( std::string & s_rate ) {

	std::istringstream iss(s_rate);
	float rate;

//	std::cout << "\"" << s_rate << "\"" << std::endl;

	if ( !hasOnlyDigits( s_rate ))
		return false;

	iss >> rate;
	if (iss.fail() || rate < 0)
	{
		this->_error_msg = "Error: Invalid rate ( negative ) =>" + s_rate;
		return false;
	}
	if (rate > 1000)
	{
		this->_error_msg = "Error: Invalid rate ( too high [1000 max] )=>" + s_rate;
		this->_rate = std::stof(s_rate);
		return false;
	}
	this->_rate = std::stof(s_rate);
	return true;
}

bool		Data::hasOnlyDigits( std::string & s_rate )
{
	int point = 0;
	size_t i = 0;

	if (s_rate [i] == ' ')
		i++;
	if (s_rate [i] == '+' || s_rate [i] == '-')
		i++;
	for (; i < s_rate.size(); i++)
	{
		if (s_rate[i] == '.')
			point++;
		if ( ( !isdigit(s_rate[i]) && s_rate[i] != '.' ) || point > 1 )
		{
			this->_error_msg = "Error: Invalid rate ( not a number ) =>" + s_rate;
			return false;
		}
	}
	return true;
}

// Getters---------------------------------------------------------------------------------------------------------

const std::string &		Data::getDate( void ) const {

	return this->_date;
}

const float &		Data::getRate( void ) const {

	return this->_rate;
}

const std::string &		Data::getErrorMsg( void ) const {

	return this->_error_msg;
}

// Clear error message------------------------------------------------------------------------------------------------

void			Data::clearErrorMsg( void ) {

	this->_error_msg = "";
}

// Comparison operators----------------------------------------------------------------------------------------------

bool			Data::operator<( const Data & other ) const {

	if ( this->isValid() )
		return this->_date < other._date;
	return false;
};

bool			Data::operator>( const Data & other ) const {

	if ( this->isValid() )
		return this->_date > other._date;
	return false;
};

bool			Data::operator<=( const Data & other ) const {

	if ( this->isValid() )
		return this->_date <= other._date;
	return false;
};

bool			Data::operator==( const Data & other ) const {

	if ( this->isValid() )
		return this->_date == other._date;
	return false;
};

bool			Data::operator!=( const Data & other ) const {

	if ( this->isValid() )
		return this->_date != other._date;
	return false;
};

// Arithmetic operators----------------------------------------------------------------------------------------------

Data &			Data::operator*=( const Data & other ) {

	if ( this->isValid() )
		this->_rate *= other._rate;
	return *this;
};

// Output operator---------------------------------------------------------------------------------------------------

std::ostream &	operator<<( std::ostream & stream, Data const & data ) {

	if (data.isValid())
		stream << data.getDate() << " " << data.getRate() << std::endl;
	else
		stream << data.getErrorMsg() << std::endl;
	return stream;
}