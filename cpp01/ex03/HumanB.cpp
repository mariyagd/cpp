/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:47:47 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/03 12:17:10 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( void ) : name(""), weapon(nullptr) {

	return ;
}

HumanB::HumanB( std::string _name ) : name(_name) {

	return ;
}

HumanB::~HumanB( void ) {

	return;
}

void	HumanB::attack( void ) {

	std::cout 	<< this->name 
				<< " attacks with his " 
				<< this->weapon->getType() 
				<< std::endl;
	return;
}

void	HumanB::setWeapon( Weapon& _weapon ) {

	this->weapon = &_weapon;
	return;
}
