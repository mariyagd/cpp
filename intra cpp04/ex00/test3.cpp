/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:14:03 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/16 20:31:47 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "Animal.h"

//notice its not WrongCat but WrongAnimal pointer!
static void	printWrongAnimalSound( WrongAnimal const* wrongAnimal )
{
	wrongAnimal->makeSound();
	std::cout << std::endl;
}

//notice its not Cat but Animal pointer!
static void	printAnimalSound( Animal const* animal )
{
	animal->makeSound();
	std::cout << std::endl;
}

void	test_pointers( void )
{
	std::cout << BLUE << BOLD << "Pointers test (file test3)" << END << std::endl;
	printLine();

	Cat			cat;

	std::cout << BLUE << std::endl << "Sound test: " << std::endl << "-----" << END << std::endl;
	std::cout << cat;

	std::cout << BLUE << "as obj: " << END;
	cat.makeSound();

	std::cout << BLUE << "as ptr: " << END;
	printAnimalSound(&cat);

	WrongCat	wrongCat;

	std::cout << BLUE << std::endl << "Sound test: " << std::endl << "-----" << END << std::endl;
	std::cout << wrongCat;

	std::cout << BLUE << "as obj: " << END;
	wrongCat.makeSound();

	std::cout << BLUE << "as ptr: " << END;
	printWrongAnimalSound(&wrongCat);
}
