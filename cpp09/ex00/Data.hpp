#ifndef DATA_HPP
#define DATA_HPP

# include <time.h>
# include <sstream>		// std::istringstream
# include <string>
# include <ctime>		// struct std::tm
# include <iostream>

class Data
{
private:

	std::string		_date;
	float			_rate;
	std::string		_error_msg;

public:
	Data( void );
	~Data( void );
	Data(std::string s_date, std::string & s_rate); ;

	void			process(std::string s_date, std::string & s_rate); ;

	bool			isValid( void ) const;
	bool			isValidDate( std::string & s_date );
	bool			isValidRate( std::string & s_rate );

	bool			isNotNegativeOrNull( int & year, int & month, int & day);
	bool			isLeapYear( int & year );
	bool			isValidMonth( int & month );
	bool			isValidDay( int & year, int & month, int & day );
	bool			isInRange( int & year, int & month, int & day  );

	std::string		getDate( void ) const;
	float			getRate( void ) const;
	std::string		getErrorMsg( void ) const;

	bool operator<( const Data & other ) const;
	bool operator<=( const Data & other ) const;
	Data & operator*=( const Data & other );

};

std::ostream &	operator<<( std::ostream & stream, Data const & data );

#endif