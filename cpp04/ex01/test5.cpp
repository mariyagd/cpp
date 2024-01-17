/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:06:53 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/17 15:32:06 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

static void	current_ideas( Animal const& animal )
{
	std::cout << std::endl;
	std::cout << BLUE << BOLD << "Current animal and ideas table------" << END << std::endl;
	std::cout << BLUE << BOLD << "-----" << END << std::endl;
	
	std::cout << std:: endl;
	std::cout << BLUE << "This Animal is of type:-----" << END << std::endl;
	std::cout << animal.getType();

	std::cout << std::endl;
	std::cout << BLUE << "This Animal makes sound:-----" << END << std::endl;
	animal.makeSound();

	std::cout << std::endl;
	std::cout << BLUE << "Print ideas table info:-----" << END << std::endl;
	animal.printBrainIdeas(std::cout);
}

static void	change_ideas( Animal const& animal )
{
	std::cout << std::endl;
	std::cout << BLUE << BOLD << "Change the ideas table-----" << END << std::endl;
	std::cout << BLUE << BOLD << "-----" << END << std::endl;

	std::cout << std::endl;
	std::cout << BLUE << "Adding ideas to the Brain:-----" << END << std::endl;
	animal.setBrainIdea(0, "Idea 0");
	animal.setBrainIdea(56, "Idea 56");
	animal.setBrainIdea(99, "Idea 99");
	animal.setBrainIdea(3, "Idea 3");
	
	std::cout << std::endl;
	std::cout << BLUE << "Print ideas table info:-----" << END << std::endl;
	animal.printBrainIdeas(std::cout);
	
	std::cout << std::endl;
}

void	test_brain( void )
{
	std::cout << BLUE << BOLD << "Ideas table Tests (file test5):-----" << END << std::endl;
	printLine();


// {{ Tests with Dog class with new /zc - zo
	
	std::cout << BLUE << BOLD << "Creating a Dog1:-----" << END << std::endl;
	Dog	dog1;
	current_ideas(dog1);
	change_ideas(dog1);
	printLine();
	
	std::cout << BLUE << BOLD << "Creating a new Dog2:-----" << END << std::endl;
	Dog*	dog2 = new Dog;
	std::cout << BLUE << BOLD << "Assign Dog1 to Dog2 :-----" << END << std::endl;
	*dog2 = dog1;

	std::cout << std::endl << BLUE << BOLD << "Verifying if Dog1 is assigned to Dog2 :-----" << END << std::endl;
	current_ideas(*dog2);
	printLine();

	std::cout << BLUE << BOLD << "Creating a Dog3 as a COPY os Dog1:-----" << END << std::endl;
	Dog	dog3(dog1);

	std::cout << std::endl << BLUE << BOLD << "Verifying if Dog1 is assigned to Dog2 :-----" << END << std::endl;
	current_ideas(dog3);
	printLine();

	std::cout << BLUE << BOLD << "Creating an animal AnimalDog by copying Dog1 :-----" << END << std::endl;
	Animal	*animalDog = new Dog(dog1);
	
	std::cout << std::endl << BLUE << BOLD << "Verifying if AnimalDog is a copy of Dog1 :-----" << END << std::endl;
	current_ideas(*animalDog);
	printLine();
	
	
	delete dog2;
	delete animalDog;

// }}

//  {{ Tests with Cat class /zc - zo
/*
	std::cout << BLUE << BOLD << "Creating a Cat1:-----" << END << std::endl;
	Cat	cat1;
	current_ideas(cat1);
	change_ideas(cat1);
	printLine();
	
	std::cout << BLUE << BOLD << "Creating a new Cat2:-----" << END << std::endl;
	Cat*	cat2 = new Cat;
	std::cout << BLUE << BOLD << "Assign Cat1 to Cat2 :-----" << END << std::endl;
	*cat2 = cat1;

	std::cout << std::endl << BLUE << BOLD << "Verifying if Cat1 is assigned to Cat2 :-----" << END << std::endl;
	current_ideas(*cat2);
	printLine();

	std::cout << BLUE << BOLD << "Creating a Cat3 as a COPY os Cat1:-----" << END << std::endl;
	Cat	cat3(cat1);

	std::cout << std::endl << BLUE << BOLD << "Verifying if Cat1 is assigned to Cat2 :-----" << END << std::endl;
	current_ideas(cat3);
	printLine();

	std::cout << BLUE << BOLD << "Creating an animal AnimalCat by copying Cat1 :-----" << END << std::endl;
	Animal	*animalCat = new Cat(cat1);
	
	std::cout << std::endl << BLUE << BOLD << "Verifying if AnimalCat is a copy of Cat1 :-----" << END << std::endl;
	current_ideas(*animalCat);
	printLine();
	
	
	delete cat2;
	delete animalCat;
*/
// }}
}
