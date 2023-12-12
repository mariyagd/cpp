#ifndef Sample2_CLASS_H
# define Sample2_CLASS_H

/*
 * Une classe est par défaut privée.
 * Comme ici je ne précise pas la
 * visibilité avec les mots-clé public et private,
 * cette classe sera private par défaut.
 */

struct Sample2 {

	int		foo;

	Sample2( void );
	~Sample2( void );

	void	bar( void ) const;
};

#endif