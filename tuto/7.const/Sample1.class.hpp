#ifndef SAMPLE1_CLASS_H
# define SAMPLE1_CLASS_H

/*
 * En C le seul moyen d'assigner une valeur
 * à une constante c'était lors de son initialisation
 * (donc sur la même ligne).
 *
 * p.ex. int const a = 42;
 *
 * Dans cette classe l'attribut pi est une constante
 * mais imaginons qu'on veut qu'il soit initialisé
 * grâce à une valeur qu'on passera au constructeur.
 * Donc au moment de la déclaration du pi, on ne connaît
 * pas sa valeur.
 *
 * On pourra initialiser une constance dans une classe
 * grâce à la liste d'initialisation.
 *
 * 	void	bar( void ) const; -> le const à la fin est utilisé
 * 	pour signifier au compilateur que la fonction membre bar
 * 	ne modifiera jamais l'instance courante. Ca veut dire que
 * 	nulle part dans le code j'aurais une assignation du type:
 * 	this->pi = valeur.
 */

class Sample1 {

public:

	float const	pi;
	int			qd;

	Sample1( float const f );
	~Sample1( void );

	void	bar( void ) const;
};

#endif