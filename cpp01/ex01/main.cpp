/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:30:33 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/29 19:27:36 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

void createAndAnnounceZombieHorde(int N, std::string name)
{

	std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;
	std::cout << "Creating a zombie horde of " << N << " zombies named "
	<< (name.empty() ? "\"empty string\"" : name) << std::endl;
	Zombie* horde = zombieHorde(N, name);
	if (horde == nullptr)
	{
		std::cerr << "zombieHorde returned nullptr" << std::endl;
		return ;
	}
	for (int i = 0; i < N; i++)
		horde[i].announce();

	std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;
	std::cout << "Destroying the horde " 
	<< (name.empty() ? "\"empty string\"" : name) << std::endl;
	delete [] horde;
	return ;
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		std::cerr << "This program doesn't accept arguments." << std::endl;
		return 1;
	}


	createAndAnnounceZombieHorde(5, "Mariya");
	createAndAnnounceZombieHorde(0, "Manuel");
	createAndAnnounceZombieHorde(-1, "Jack");
	createAndAnnounceZombieHorde(-15, "JJ");
	createAndAnnounceZombieHorde(6, "");
	return 0;
	
}
