/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Duree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:24:20 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/09 17:34:17 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_DUREE
#define DEF_DUREE
 
class Duree
{
    public:
 
    Duree(int heures = 0, int minutes = 0, int secondes = 0) : m_heures(heures), m_minutes(minutes), m_secondes(secondes)
	{
 
	};
	
	void afficher() const { std::cout << m_heures << "h" << m_minutes << "m" << m_secondes << "s" << std::endl; }
	int	getHeures() const { return (m_heures); }
	int	getMinutes() const { return (m_minutes); }
	int	getSecondes() const { return (m_secondes); }

	void setHeures(int heures) { m_heures = heures; }
	void setMinutes(int minutes) { m_minutes = minutes; }
	void setSecondes(int secondes) { m_secondes = secondes; }

	bool estEgal(Duree const& b) const
	{
		if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes)
			return (true);
		return (false);
	}

	Duree&	operator+=(Duree const& a) {
/*		this->setHeures(this->getHeures() + a.getHeures());
		this->setMinutes(this->getMinutes() + a.getMinutes());
		this->setSecondes(this->getSecondes() + a.getSecondes());*/

		m_secondes += a.m_secondes;
		m_minutes += m_secondes / 60;
		m_secondes %= 60;
		m_minutes += a.m_minutes;
		m_heures += m_minutes / 60;
		m_minutes %= 60;
		m_heures += a.m_heures;
		return (*this);
	}

	void	afficher ( std::ostream& flux ) const {
		flux << m_heures << "h" << m_minutes << "m" << m_secondes << "s";
	}

    private:
 
    int m_heures;
    int m_minutes;
    int m_secondes;
};

// Prototypes des fonctions extérieures
// La fonction est en dehors de la classe, elle n'a donc pas accès aux membres privés
// Elle reçoit deux références constantes vers les objets à comparer
// et retourne un booléen pour indiquer si les deux objets sont identiques ou non

/* Avec accessors:
 *
bool	operator==(Duree const& a, Duree const& b)
{
	if (a.getHeures() == b.getHeures() && a.getMinutes() == b.getMinutes() && a.getSecondes() == b.getSecondes())
		return (true);
	return (false);
}
*/

bool	operator==(Duree const& a, Duree const& b)
{
	return (a.estEgal(b));
}

Duree	operator+(Duree const& a, Duree const& b)
{
/*	Duree result;

	result.setHeures(a.getHeures() + b.getHeures());
	result.setMinutes(a.getMinutes() + b.getMinutes());
	result.setSecondes(a.getSecondes() + b.getSecondes());
	return (result);
	*/

	Duree copie(a);
	copie += b;
	return (copie);

}

//flux sera cout
//La fonction doit récupérer les attributs qui l'intéressent dans l'objet,
//et les envoyer à l'objet flux  (qui n'est autre que cout  ).
//Ensuite, elle renvoie une référence sur cet objet, 
//ce qui permet de faire une chaîne :
//cout << duree1 << duree2;

//On passe donc le relais à une méthode à l'intérieur de la classe qui,
//elle, a le droit d'accéder aux attributs. La méthode prend en paramètre
//la référence vers l'objet flux pour pouvoir lui envoyer les valeurs 
//qui nous intéressent. Ce que l'on n'a pas pu faire dans 
//la fonction operator<<  , on le donne à faire à 
//une méthode de la classe Duree

std::ostream& operator<<( std::ostream &flux, Duree const& duree )
{
	duree.afficher( flux );
	return flux;
}

#endif
