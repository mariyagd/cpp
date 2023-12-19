#ifndef DUREE_H
#define DUREE_H

class Duree
{
public:


	Duree(int heures = 0, int minutes = 0, int secondes = 0);
	~Duree();

private:

	int m_heures;
	int m_minutes;
	int m_secondes;

};

#endif