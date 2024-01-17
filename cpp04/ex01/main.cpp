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
/*
	// check for leaks
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;	
*/

/*	
	test_subject();  //check for leaks
	printLine();
*/


	test_brain();  //check for leaks
	printLine();


	return 0;
}
