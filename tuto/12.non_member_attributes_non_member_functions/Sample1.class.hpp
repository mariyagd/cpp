#ifndef SAMPLE1_CLASS_H
# define SAMPLE1_CLASS_H

/*
 * une fonction et un attribut membre est qqch
 * qui existe lorsqu'on a instancié une classe.
 * Chaque attribut sera différent dans chaque instance.
 *
 * static = non membre
 */

struct Sample1 {

public:

	Sample1( void );
	~Sample1( void );

	static int		getNbInst( void );

private:

	static int _nbInst;
};

#endif