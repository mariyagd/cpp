/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:25:29 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/09 17:36:05 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Duree.hpp"

int main(void)
{
	Duree chrono1;
	Duree chrono2(0,0,0);
	std::cout << "chrono1 = ";
	chrono1.afficher();
	std::cout << "chrono2 = ";
	chrono2.afficher();

	std::cout << "chrono1 == chrono2 ?" << std::endl;
	if (chrono1 == chrono2)
		std::cout << "Les durees sont identiques" << std::endl;
	else
		std::cout << "Les durees sont differentes" << std::endl;

	std::cout << std::endl;
	Duree chrono3(1,2,3);
	Duree chrono4(1,2,3);
	
	std::cout << "chrono3 = ";
	chrono3.afficher();
	std::cout << "chrono4 = ";
	chrono4.afficher();
	Duree chrono5 = chrono3 + chrono4;
	std::cout << "chrono5 = chrono3 + chrono4 = ";
	chrono5.afficher();
	chrono5 += Duree(0,61,61);
	std::cout << "chrono5 += Duree(0,61,61) = ";
	chrono5.afficher();

	std::cout << std::endl;
	Duree chrono6(chrono5);
	std::cout << "chrono6(chrono5) = ";
	chrono6.afficher();

	std::cout << "Test operator<< " << std::endl
		<<"chrono1 = " << chrono1 << std::endl
		<<"chrono2 = " << chrono2 << std::endl
		<<"chrono3 = " << chrono3 << std::endl
		<<"chrono4 = " << chrono4 << std::endl
		<<"chrono5 = " << chrono5 << std::endl
		<<"chrono6 = " << chrono6 << std::endl
		<< "Somme totale = " << chrono1 + chrono2 + chrono3 + chrono4 + chrono5 + chrono6
		<< std::endl;

}
