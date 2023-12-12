#ifndef SAMPLE2_CLASS_H
# define SAMPLE2_CLASS_H

/*
 * La classe Sample2 a trois attributs
 * et le destructeur prend trois paramètres.
 */

class Sample2 {

public:

	char	a1;
	int		a2;
	float	a3;

	Sample2( char p1, int p2, float p3 );	//constructeur - la class est instancié
	~Sample2( void );						//destructeur - la class est détruite

};

#endif