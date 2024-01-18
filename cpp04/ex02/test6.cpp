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

void	test_subject( void )
{
	size_t	size = 10;
	std::cout	<< BLUE << BOLD << "Creating animal tables---" << END << std::endl;
	Animal*	animals[size];

	std::cout << std::endl;

	for (size_t	i = 0; i < size / 2; i++)
	{
			std::cout	<< BLUE << BOLD << "Creating dog[" << i << "] ---" << END << std::endl;
			animals[i] = new Dog();
	}

	for (size_t	i = size / 2; i < size; i++) 
	{
			std::cout	<< BLUE << BOLD << "Creating cat[" << i << "] ---" << END << std::endl;
			animals[i] = new Cat();
	}

	for (size_t	i = 0; i < size; i++)
	{
		delete animals[i];
	}
}
