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
#include <string>

#include <string.h>  //strcpy

#include "Data.hpp"


class BitcoinExchange {

private:
	std::set < Data >				_set;
	const char *					_inputFile;
	const char *					_btcFile;

public:
	BitcoinExchange( void );
	~BitcoinExchange( void );
	BitcoinExchange( BitcoinExchange const & src );
	BitcoinExchange & operator=( BitcoinExchange const & src );

	BitcoinExchange( const char * intputFile, const char * btcFile );

	void				openFile( const char * & fileName, std::ifstream & ifs );
	void				checkTitle( const std::string  & title, std::ifstream & file );
	bool				validBtcDelimiter( std::string &  );
	bool				validInputDelimiter( std::string &  );

	void	init( void );
	void	initBtcFile( void );
	void	initInputFile( void );
	void	processData( Data & data, std::string & line, char delimiter );


	void	findRate( Data & data );

	// for testing
	void	printSet( void ) const;

};

std::ostream &	operator<<( std::ostream & stream, BitcoinExchange const & btc );

#endif