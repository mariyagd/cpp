#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

/*
 * Un attribut membre est une variable que je vais
 * avoir dans ma classe et que je pourrai utiliser
 * à partir d'une instance.
 *
 * Ici la variable foo est un attribut membre. Elle existera
 * et sera différente pour chaque instance de la classe.
 *
 * La fonction membre appartient à la classe et peut être
 * utilisée depuis une instance de la classe. Elle peut avoir
 * un type de retour.
 *
 * Ici la fonction bar a un paramètre et non zéro comme
 * le nom void le laisse sous-entendre. Par défaut en cpp
 * le premier paramètre est un pointeur vers une instance courante.
 */

class Sample {

public:

	int		foo;			// attribut membre
	Sample(void);			//constructeur - la class est instancié
	~Sample(void);			//destructeur - la class est détruite

	void	bar( void );	// fonction membre
};

#endif