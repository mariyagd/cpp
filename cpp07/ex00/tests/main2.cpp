#include <iostream>

// classes et structures template
// Liste de classes

template< typename T >

class List {

public:

	List<T>( T const & content ) {
		// etc ...
	}

	List<T>( List<T> const & list ) {
		// etc ...
	}

	~List<T>( void ) {
		// etc...
	}

	// etc...

private:
	T *			_content;
	List<t> *	_next;
};

int main( void ) {

	List< int >				a( 42 );
	List< float >			b( 3.14f );
	List< List< int > >		c( a );				// Liste de liste (2 dimensions)

	// etc...

	return 0;
}