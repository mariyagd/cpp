/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:18:46 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/16 20:33:23 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "Animal.h"

static void printAnimalSound(Animal const* animal)
{
	std::cout << BLUE << " call function printAnimalSound(Animal const* animal):-----" << END << std::endl;
	animal->makeSound();
}

static void printWrongAnimalSound(WrongAnimal const* wrongAnimal)
{
	std::cout << BLUE << " call function  printWrongAnimalSound(WrongAnimal const* wrongAnimal):-----" << END << std::endl;
	wrongAnimal->makeSound();
}

static void printCatSound(Cat const* Cat)
{
	std::cout << BLUE << " call function printCatSound(Cat const* Cat):-----" << END << std::endl;
	Cat->makeSound();
}

static void printWrongCatSound(WrongCat const* wrongCat)
{
	std::cout << BLUE << " call function  printWrongCatSound(WrongCat const* wrongCat):-----" << END << std::endl;
	wrongCat->makeSound();
}

void	test_casting( void )
{
	std::cout << BLUE << BOLD << "Casting test (file test5)" << END << std::endl;
	printLine();

	std::cout << BLUE << "Create new Animal *animal as Cat:-----" << END << std::endl;
	Animal		*animal = new Cat;

	std::cout <<  BLUE << "Create new WrongAnimal *wrongAnimal as WrongCat:-----" << END << std::endl;
	WrongAnimal		*wrongAnimal = new WrongCat;

	std::cout << std::endl << BLUE << "-----" << END << std::endl;

	std::cout << std::endl << BLUE << "Use *animal to " << END;
	printAnimalSound(animal);

	std::cout << std::endl << BLUE << "Use *wrongAnimal to " << END;
	printWrongAnimalSound(wrongAnimal);

	std::cout << std::endl << BLUE << "-----" << END << std::endl;

	std::cout << std::endl << BLUE << "Use dynamic_cast<Cat*>(animal) to " << END;
	printCatSound(dynamic_cast<Cat*>(animal));

	std::cout << std::endl << BLUE << "Use static_cast<WrongCat*>(wrongAnimal) to " << END;
	printWrongCatSound(static_cast<WrongCat*>(wrongAnimal));

	std::cout << std::endl << BLUE << "-----" << END << std::endl;

	delete animal;
	delete wrongAnimal;


}