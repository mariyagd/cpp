#ifndef SAMPLE1_CLASS_H
# define SAMPLE1_CLASS_H

/*
 * Accesseurs:
 * des fonctions qui vont faire l'interface entre
 * l'utilisateur et l'attribut privé
 *
 * J'ai un attribut privé _foo et je ne veux
 * pas que l'utilisateur y ait accès. Mais je veux lui
 * donner un certain accès sur lequel je peux pouvoir
 * exercer du contrôle.
 */

struct Sample1 {

public:

	Sample1( void );
	~Sample1( void );

	int		getFoo( void ) const;
	void	setFoo( int v );

private:

	int _foo;
};

#endif