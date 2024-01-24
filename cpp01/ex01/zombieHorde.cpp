/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:28:46 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/29 20:20:30 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 0)
	{
		std::cerr << "N must be positive. Could not create zombieHorde." << std::endl;
		return nullptr;
	}
	Zombie* zombieHorde = new Zombie[N]; 				// allocate N Zombie objects in a single allocation

	for (int i = 0; i < N; i++)
		zombieHorde[i] = Zombie(name);					//  initialize the zombies, giving each one of them the name passed as parameter
	return zombieHorde;
}
