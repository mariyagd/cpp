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
		std::cerr << "N must be positive" << std::endl;
		return nullptr;
	}
	Zombie* zombieHorde = new(std::nothrow) Zombie[N];
	if (zombieHorde == nullptr)
    {
        std::cerr << "Memory allocation for zombie horde failed." << std::endl;
        return nullptr;
    }
	for (int i = 0; i < N; i++)
		zombieHorde[i] = Zombie(name);
	return zombieHorde;
}
