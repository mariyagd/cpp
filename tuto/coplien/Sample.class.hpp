#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

#include <iostream>

class Sample
{
    public:
        Sample ( void );							// Constructeur par défaut
		Sample ( Sample const& src );				// Constructeur de recopie
        ~Sample ( void );							// Destructeur éventuellement virtuel
        Sample& operator=( Sample const& rhs );		// Operator d'assignation
				
        Sample( int const n );
		
		int getFoo( void ) const;
	
	private:
		int _foo;

};

// tres commun dans les classes
std::ostream& operator<<( std::ostream& o, Sample const& i );

#endif
