#ifndef SAMPLE1_CLASS_H
# define SAMPLE1_CLASS_H

/*
 * Fonctions membres dans les classes,
 * qui vont permettre de faire une comparaison
 * structurelles sur deux instance
 *
 * 	int		compare( Sample1 * other ) const;
 * 	Cette fonction fait une comparaison entre
 * 	l'instance courante et l'instance passée
 * 	en paramètre. Elle prend l'adresse de Sample1
 */

struct Sample1 {

public:

	Sample1( int v );
	~Sample1( void );

	int		getFoo( void ) const;
	int		compare( Sample1 * other ) const;

private:

	int _foo;
};

#endif