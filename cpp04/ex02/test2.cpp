/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test6.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:54:00 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/17 14:08:52 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

std::string create_idea(std::string type, size_t i)
{
	return ( type + "Idea [" + std::to_string(i) + "]");
}

Animal**	create_table( size_t const size )
{
	std::cout	<< BLUE << BOLD << "Creating animal tables---" << END << std::endl;

	std::cout << std::endl;

	Animal **animals = new Animal*[size];

	for (size_t	i = 0; i < size / 2; i++)
	{
		std::cout	<< BLUE << BOLD << "Creating dog[" << i << "] ---" << END << std::endl;
		animals[i] = new Dog();
		animals[i]->setBrainIdea(i, create_idea("dog" , i));
	}

	for (size_t	i = size / 2; i < size; i++)
	{
		std::cout	<< BLUE << BOLD << "Creating cat[" << i << "] ---" << END << std::endl;
		animals[i] = new Cat();
		animals[i]->setBrainIdea(i, create_idea("cat" , i));
	}
	return	animals;
}

void	print_ideas( Animal **animals, size_t const size )
{
	std::cout << BLUE << BOLD << "Print ideas table:-----" << END << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "animal [" << i << "] type " << animals[i]->getType() << std::endl;
		animals[i]->printBrainIdeas(std::cout);
		animals[i]->makeSound();
		std::cout << BLUE <<  "-----" << END << std::endl;
	}
}

Animal**	copy_animals( Animal** animals, size_t const size )
{
	Animal **copy = new Animal*[size];

	std::cout	<< BLUE << BOLD << "Creating a copy of animal tables---" << END << std::endl;

	std::cout << std::endl;

	for (size_t	i = 0; i < size / 2; i++)
	{
		std::cout	<< BLUE << BOLD << "Copy dog[" << i << "] ---" << END << std::endl;
		copy[i] = new Dog(*dynamic_cast<Dog*>(animals[i]));
	}

	for (size_t	i = size / 2; i < size; i++)
	{
		std::cout	<< BLUE << BOLD << "Copy cat[" << i << "] ---" << END << std::endl;
		copy[i] = new Cat(*dynamic_cast<Cat*>(animals[i]));
	};
	return copy;
}

void	test_subject( void )
{
	std::cout << std::endl << BLUE << BOLD << "Subject Tests (file test2):-----" << END << std::endl;
	printLine();

	size_t const	size = 10;
	Animal			**animals = create_table( size );
	print_ideas(animals, size);
	Animal			**copy = copy_animals(animals, size);

	print_ideas(copy, size);
	std::cout << BLUE <<  "-----" << END << std::endl;

	std::cout	<< BLUE << BOLD << "Delete animals table---" << END << std::endl;
	for (size_t	i = 0; i < size; i++)
	{
		std::cout	<< BLUE  <<"[" << i << "]--- "  << END << std::endl;
		delete animals[i];
	}
	delete [] animals;
	animals = 0;

	std::cout << std::endl	<< BLUE << BOLD << "Delete copy table---" << END << std::endl;
	for (size_t	i = 0; i < size; i++)
	{
		std::cout	<< BLUE  <<"[" << i << "]--- "  << END << std::endl;
		delete copy[i];
	}
	delete [] copy;
	copy = 0;
}
