/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:43:47 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/18 11:43:33 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

void	printLine( void )
{
	std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;;
}

void	subject_test( void )
{
	std::cout << BLUE << BOLD << "Subject test" << END << std::endl;
	printLine();
	
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << meta->getType() << ": ";
	meta->makeSound();
	
	std::cout << dog->getType() << "   : ";
	dog->makeSound(); 
	
	std::cout << cat->getType() << "   : ";
	cat->makeSound();

	std::cout << std::endl;

	delete meta;
	delete dog;
	delete cat;
}

void	subject_wrongTest( void )
{
	std::cout << BLUE << BOLD << "Subject wrong test" << END << std::endl;
	printLine();
	
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* cat = new WrongCat();

	std::cout << std::endl;
	std::cout << meta->getType() << ": ";
	meta->makeSound();
	
	std::cout << cat->getType() << "   : ";
	cat->makeSound();

	std::cout << std::endl;

	delete meta;
	delete cat;
}

int	main(void)
{
//	test_constructors();
//	printLine();

//	subject_test();				//check for leaks
//	printLine();

//	subject_wrongTest();		//check for leaks
//	printLine();

//	test_references();
//	printLine();

//	test_pointers();
//	printLine();

//	heterogeneous_collection();  // check for leaks
//	printLine();

//	test_casting();
//	printLine();

	Cat	cat1;
	Cat	cat2(cat1);

	cat2.makeSound();
	return 0;
}
