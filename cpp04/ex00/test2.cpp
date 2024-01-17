/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:14:03 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/16 20:31:26 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "Animal.h"

//notice its not WrongCat but WrongAnimal reference!
static void	printWrongAnimalSound( WrongAnimal const& wrongAnimal )
{

	wrongAnimal.makeSound();
	std::cout << std::endl;
}

//notice its not Cat but Animal reference!
static void	printAnimalSound( Animal const& animal )
{
	animal.makeSound();
	std::cout << std::endl;
}

void	test_references( void )
{
	std::cout << BLUE << BOLD << "References test (file test2)" << END << std::endl;
	printLine();

	Cat			cat;
	std::cout << "Sound test: " << std::endl << "-----" << std::endl;
	std::cout << cat;
	std::cout << BLUE << "as obj: " << END;
	cat.makeSound();
	std::cout << BLUE << "as ref: " << END;
	printAnimalSound(cat);

	WrongCat	wrongCat;
	std::cout << "Sound test: " << std::endl << "-----" << std::endl;
	std::cout << wrongCat;
	std::cout << BLUE << "as obj: " << END;
	wrongCat.makeSound();
	std::cout << BLUE << "as ref: " << END;
	printWrongAnimalSound(wrongCat);
}
