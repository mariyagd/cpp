#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include "Colors.h"
#include <fstream>
#include <map>
#include <stdexcept>
#include <ios>
#include <iterator>
#include <sstream>
#include <utility>
#include <set>
//#include "MutantStack.hpp"

//struct	Date
//{
//	unsigned int	year;
//	unsigned int	month;
//	unsigned int	day;
//};

class Date
{
private:

	time_t 			_date_time_t;

public:

	std::string		date;
	std::string		error_msg;

	Date( void );
	Date(std::string s_date) ;
	Date(int year, int month, int day);


	bool operator<(const Date& other) const;
	bool operator>(const Date& other) const;
	bool operator<=(const Date& other) const;
	bool operator>=(const Date& other) const;
	bool operator==(const Date& other) const;
	bool operator !=(const Date& other) const;
};


class BitcoinExchange {

private:
	std::multimap< Date, Date > 				_exchange;
	std::multimap< Date, float >		 		_mmap;
	std::string									_inputFile;
	std::string									_btcFile;

public:
	BitcoinExchange( void );
	~BitcoinExchange( void );
	BitcoinExchange( BitcoinExchange const & src );
	BitcoinExchange & operator=( BitcoinExchange const & src );

	BitcoinExchange( char * & av);

	bool	noWhiteSpaces( std::string &  );
	Date	getDate( std::string &  );
	float	getRate( std::string & , Date & );

	void init();

};

std::ostream &	operator<<( std::ostream & stream, BitcoinExchange const & btc );

#endif