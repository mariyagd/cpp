/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:18:46 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/16 20:33:23 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

void	tables_Animal( void )
{
	std::cout << BLUE << BOLD << "Animal heterogeneous collection:" << END <<std::endl;
	std::cout << BLUE << BOLD << "Dynamic binding (file test4)" << END <<std::endl;
	printLine();

	std::cout << BLUE << "Creating a table of pointers listAnimals*:-----" << END << std::endl;
	std::vector<Animal*> listAnimals;

	std::cout << BLUE << "add Dog-----" << END << std::endl;
	listAnimals.push_back(new Dog);

	std::cout << BLUE << "add Cat-----" << END << std::endl;
	listAnimals.push_back(new Cat);

	std::cout << BLUE << "add Dog-----" << END << std::endl;
	listAnimals.push_back(new Dog);

	std::cout << BLUE << "add Dog-----" << END << std::endl;
	listAnimals.push_back(new Dog);

	std::cout << BLUE << "add Cat-----" << END << std::endl;
	listAnimals.push_back(new Cat);

	std::cout << BLUE << "add Cat-----" << END << std::endl;
	listAnimals.push_back(new Cat);


	std::cout << std::endl << BLUE << "call makeSound for each member of the list: " << END << std::endl;
	
	for (size_t i = 0; i < listAnimals.size(); ++i) {
		std::cout << "[" << i << "] ";
		listAnimals[i]->makeSound();
	}

	for (size_t i = 0; i < listAnimals.size(); ++i)
	{
		delete listAnimals[i];
		listAnimals[i] = 0;
	}
	std::cout << std::endl;
}


void	tables_WrongAnimal( void )
{
	std::cout << BLUE << BOLD << "Animal heterogeneous collection:" << END <<std::endl;
	std::cout << BLUE << BOLD << "Static binding (file test4)" << END <<std::endl;
	printLine();


	std::cout << BLUE << "Creating a table of pointers list WrongAnimals*:-----" << END << std::endl;
	std::vector<WrongAnimal*> listWrongAnimals;

	std::cout << BLUE << "add WrongCat-----" << END << std::endl;
	listWrongAnimals.push_back(new WrongCat);

	std::cout << BLUE << "add WrongCat-----" << END << std::endl;
	listWrongAnimals.push_back(new WrongCat);

	std::cout << BLUE << "add WrongCat-----" << END << std::endl;
	listWrongAnimals.push_back(new WrongCat);

	std::cout << std::endl << BLUE << "call makeSound for each member of the list: " << END << std::endl;
	
	for (size_t i = 0; i < listWrongAnimals.size(); ++i) {
		std::cout << "[" << i << "] ";
		listWrongAnimals[i]->makeSound();
	}

	for (size_t i = 0; i < listWrongAnimals.size(); ++i)
	{
		delete listWrongAnimals[i];
		listWrongAnimals[i] = 0;
	}

	std::cout << std::endl;
}

void	heterogeneous_collection( void )
{
	tables_Animal();
	printLine();

	tables_WrongAnimal();

}
