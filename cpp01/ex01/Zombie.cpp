/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:25:29 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/18 11:44:39 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"


Zombie::Zombie( void ) : name ("") {

//	std::cout << ( this->name == "" ? "(no name)" : this->name ) << " zombie created" << std::endl;
	return ;
}

Zombie::Zombie( std::string _name ) : name(_name) {

	std::cout << ( this->name == "" ? "(no name)" : this->name ) << " zombie created" << std::endl;
	return ;
}

Zombie::~Zombie( void ) {

	std::cout << ( this->name == "" ? "(no name)" : this->name )  << ": destroyed by destructor" << std::endl;
	return ;
}

void	Zombie::announce( void ) {

	std::cout << ( this->name == "" ? "(no name)" : this->name ) << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
