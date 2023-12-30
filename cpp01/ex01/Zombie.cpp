/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:25:29 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/29 18:40:43 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

/*
	std::cout << this->name << "Dummy constructor called" << std::endl;
 */

Zombie::Zombie( void ) : name ("") {
	
	return ;
}

/*
	std::cout << this->name << "Parametrized constructor called" << std::endl;
 */

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
