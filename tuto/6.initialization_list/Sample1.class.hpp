#ifndef SAMPLE1_CLASS_H
# define SAMPLE1_CLASS_H

/*
 * La classe Sample1 a trois attributs
 * et le destructeur prend trois paramètres.
 */

class Sample1 {

public:

	char	a1;
	int		a2;
	float	a3;

	Sample1( char p1, int p2, float p3 );	//constructeur - la class est instancié
	~Sample1( void );						//destructeur - la class est détruite

};

#endif