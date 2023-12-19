#include "Duree.hpp"
#include <iostream>




Duree::Duree(int heures, int minutes, int secondes) : m_heures(heures),  m_minutes(minutes), m_secondes(secondes) {

	std::cout << "Heures: " << m_heures << std::endl;
	std::cout << "Minutes: " << m_minutes << std::endl;
	std::cout << "Secondes: " << m_secondes << std::endl;
}


Duree::~Duree(){

}