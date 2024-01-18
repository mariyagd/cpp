/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:43:47 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/17 14:21:48 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

void	printLine( void )
{
	std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;;
}

int	main(void)
{

	// check for leaks
	const Animal* j = new Dog();
	std::cout << BLUE <<  "-----" << END << std::endl;

	const Animal* i = new Cat();
	std::cout << BLUE <<  "-----" << END << std::endl;

	delete j;
	std::cout << BLUE <<  "-----" << END << std::endl;

	delete i;
	std::cout << BLUE <<  "-----" << END << std::endl;


//	use this test
//	test_subject();
//	printLine();


//	test_brain();
//	printLine();


	return 0;
}
