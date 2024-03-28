#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span {

private:
	unsigned int	_n;
	std::vector< int >	_v;

public:
	Span( void );
	~Span( void );
	Span( const Span & src);
	Span & operator=( const Span & src);

	Span( unsigned int n );

	void						addNumber( int num );

	int							shortestSpan( void ) const;
	int 						longestSpan( void ) const;

	const std::vector< int > &	getVector( void ) const;
	const unsigned int & 		getMaxSize( void ) const;
	unsigned int 				getCurrentSize( void ) const;

	class SpanException {

	private:
		const char *_message;

	public:
		SpanException( const char *message );
		const char * what() const throw();
	};

	template< typename T>
	void addRange(T begin, T end);

};

std::ostream& operator<<( std::ostream &stream, const Span & src );

template< typename T >
void						addRange(T begin, T end);

#endif