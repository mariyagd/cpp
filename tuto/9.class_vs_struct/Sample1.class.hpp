#ifndef SAMPLE1_CLASS_H
# define SAMPLE1_CLASS_H

/*
 * La structure est la même chose qu'une classe.
 * Mais on n'a pas les mots clés public et private.
 *
 * Par défaut, une structure est publique.
 * Une classe est par défaut privée.
 *
 * Tout ce qu'on peut faire avec une structure en C,
 * on peut le faire en C++ avec classe.
 */

struct Sample1 {

	int		foo;

	Sample1( void );
	~Sample1( void );

	void	bar( void ) const;
};

#endif