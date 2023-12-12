#ifndef SAMPLE1_CLASS_H
# define SAMPLE1_CLASS_H

/*
 * les mots-clé public et private vont nous permettre
 * de contrôler l'encapsulation des membres de notre classe.
 *
 * les attributs et fonctions membres qui seront visible
 * uniquement depuis l'intérieur de la classe ou bien
 * depuis l'extérieur.
 *
 * Public -> on peut accéder depuis l'intérieur de la classe
 * mais aussi depuis l'extérieur
 *
 * Private -> accès uniquement depuis l'intérieur de la classe
 * (masquer les détails de l'implémentation de la classe
 * et laisser visible aux utilisateurs seulement ce qui sera utile)
 */

class Sample1 {

public:

	int		publicFoo;

	Sample1( void );
	~Sample1( void );

	void	publicBar( void ) const;

private:

	int		_privateFoo;

	void	_privateBar( void ) const;
};

#endif