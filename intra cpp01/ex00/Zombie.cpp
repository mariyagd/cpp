/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:25:29 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/29 17:46:22 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie( void ) : name ("") {
	
	return ;
}

Zombie::Zombie( std::string _name ) : name(_name) {

	return ;
}

Zombie::~Zombie( void ) {

	std::cout << this->name << ": destroyed by destructor" << std::endl;
	return ;
}

void	Zombie::announce( void ) {

	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
