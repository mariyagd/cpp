/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:09:33 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/29 15:43:11 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		std::cerr << "This program don't need any arguments." << std::endl;
		return (1);
	}

	Zombie Foo("Foo");
	Foo.announce();

	Zombie* Bob = newZombie("Bob");
	Bob->announce();

	randomChump("Chump");

	delete Bob;
	Bob = 0;

	return 0;
}
