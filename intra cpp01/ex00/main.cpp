/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:09:33 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/18 11:46:12 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

void	print_line( void )
{
	std::cout << "--------------------------------------------" << std::endl;
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		std::cerr << "This program don't need any arguments." << std::endl;
		return (1);
	}

	Zombie Foo("Foo"); 					//Foo exists in the stack
	Foo.announce();
	print_line();

	Zombie* Bob = newZombie("Bob");		//Bob exists in the heap
	Bob->announce();
	print_line();

	randomChump("Chump");  				//Chump exists only in this function
	print_line();

	delete Bob;
	Bob = 0;

	return 0;
}
