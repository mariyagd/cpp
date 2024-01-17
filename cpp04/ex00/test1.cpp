/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:36:25 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/16 17:56:13 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

void	test_animal_constructors( void )
{
	std::cout<< BLUE << BOLD << "Animal Constructors tests:" << END << std::endl;
	printLine();

	std::cout << BLUE << "default cor:-----" << END << std::endl;
	Animal	zero;
	std::cout << std::endl << BLUE << "copy cor:-----" << END << std::endl;
	Animal	first = zero;

	std::cout << std::endl << BLUE << "assign op: -----" << END << std::endl;
	Animal	third;
	third = first;

	std::cout << std::endl;
}

void	test_cat_constructors( void )
{
	std::cout << BLUE << BOLD << "Cat Constructors tests:" << END <<std::endl;
	printLine();

	std::cout << BLUE << "default cor:-----" << END << std::endl;
	Cat	zero;
	std::cout << std::endl << BLUE << "copy cor:-----" << END << std::endl;
	Cat	first = zero;

	std::cout << std::endl << BLUE << "assign op: -----" << END << std::endl;
	Cat	third;
	third = first;

	std::cout << std::endl;
}

void	test_dog_constructors( void )
{
	std::cout << BLUE << BOLD << "Dog Constructors tests:" << END << std::endl;
	printLine();

	std::cout << BLUE << "default cor:-----" << END << std::endl;
	Dog	zero;
	std::cout << std::endl << BLUE << "copy cor:-----" << END << std::endl;
	Dog	first = zero;

	std::cout << std::endl << BLUE << "assign op: -----" << END << std::endl;
	Dog	third;
	third = first;

	std::cout << std::endl;
}

void	test_constructors( void )
{
	test_animal_constructors();
	printLine();
	
	test_cat_constructors();
	printLine();
	
	test_dog_constructors();
}
