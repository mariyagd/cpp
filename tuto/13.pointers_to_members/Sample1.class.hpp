#ifndef SAMPLE1_CLASS_H
# define SAMPLE1_CLASS_H

/*
 * Pointeurs sur membres et non membres
 */

struct Sample1 {

public:

	int		foo;

	Sample1( void );
	~Sample1( void );

	void	bar( void) const;
};

#endif