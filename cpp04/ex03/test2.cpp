/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:44:55 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:44:56 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Project.h"
# include "AMateria.hpp"
# include "Cure.hpp"
# include "Ice.hpp"
# include "Character.hpp"
# include <iostream>
# include <iomanip>
# include "Colors.h"
# include "MateriaSource.hpp"


void	test_char_equip_unequip( void )
{
	std::cout << std:: endl << BLUE << BOLD << "Tests character's equip and unequip (file test2)" << END << std::endl;
	print_line();

	print_title("Create Character mariya");
	Character mariya("Mariya");
	print_char_name(mariya);
	std::cout << mariya;

	print_title("Unquip mariya's empty inventory");
	mariya.unequip(0);

	print_title("Use mariya's empty inventory");
	mariya.use(0, mariya);

	print_title("Create dynamic Ice ice");
	Ice *ice = new Ice;
	print_materia_type(*ice);
	print_materia_address(*ice);

	print_title("Create dynamic Cure cure");
	Cure *cure = new Cure;
	print_materia_type(*cure);
	print_materia_address(*cure);

	print_title("Equip mariya 2 times with the same ice");
	for (size_t i = 0; i < 2; i++)
	{
		std::cout << "Equip inventory [" << i << "] : " << std::endl;
		mariya.equip(ice);
		std::cout << mariya;
		print_small_line();
	}

	print_title("Equip mariya 2 times with the same cure");
	for (size_t i = mariya.getInventorySize(); i < mariya.getInventorySize() + 1; i++)
	{
		std::cout << "Equip inventory [" << i << "] : " << std::endl;
		mariya.equip(cure);
		std::cout << mariya;
		print_small_line();
	}

	print_title("Compare addresses");
	print_materia_address(*ice);
	print_materia_address(*cure);
	std::cout << "Mariya's addresses are: ";
	mariya.printInventoryAdresses();

	print_title("Equip mariya with null pointer");
	mariya.equip(0);
	print_small_line();


	print_title("Use mariya's materia in inventory");
	std::cout << mariya;
	print_small_line();
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << "Use inventory [" << i << "] : " << std::endl;
		mariya.use(i, mariya);
		print_small_line();
	}

	print_title("Unquip mariya's inventory with at empty index (2)");
	mariya.unequip(2);

	print_title("Unquip mariya's inventory with at an invalid index (-10)");
	mariya.unequip(-10);

	print_title("Unquip mariya's inventory at index 0");
	std::cout << "Before: " << mariya;
	mariya.unequip(0);
	std::cout << mariya;
	print_small_line();
	std::cout << "After: " << "Mariya's NEW addresses are: ";
	mariya.printInventoryAdresses();


	print_title("Unquip mariya's inventory at index 0");
	std::cout << "After: " << mariya;
	mariya.unequip(0);
	std::cout << mariya;
	print_small_line();

	print_title("Tests on copy constructor and assignment operator");
	print_line();

	std::cout << "Current inventory: " << mariya;
	print_title("Create a mariyaCopy1 to copy mariya's empty inventory");
	Character mariyaCopy1(mariya);
	std::cout << "mariyaCopy1: " << mariyaCopy1;

	print_title("Fill mariya's inventory");
	mariya.equip(new Ice);
	print_small_line();
	mariya.equip(new Cure);
	print_small_line();
	mariya.equip(new Ice);
	print_small_line();
	std::cout << "Current new inventory: " << mariya;

	print_title("Create a mariyaCopy2 to copy mariya's filled inventory");
	Character mariyaCopy2(mariya);
	std::cout << "mariyaCopy2: " << mariyaCopy2;

	print_title("Compare addresses between mariya and mariyaCopy2 inventory");
	std::cout << "mariya's addresses are:    ";
	mariya.printInventoryAdresses();
	std::cout << "mariyaCopy2 addresses are: ";
	mariyaCopy2.printInventoryAdresses();

	print_title("Assign mariya to mariyaCopy2");
	mariyaCopy2 = mariya;
	std::cout << "mariyaCopy2: " << mariyaCopy2;

	print_title("Compare addresses between mariya and mariyaCopy2 inventory");
	std::cout << "mariyaCopy1 addresses are:    ";
	mariyaCopy1.printInventoryAdresses();
	std::cout << "mariyaCopy2 addresses are:    ";
	mariyaCopy2.printInventoryAdresses();
	print_small_line();
}

