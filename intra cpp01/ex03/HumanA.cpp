/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:09:37 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/03 12:16:51 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string _name, Weapon& _weapon ) :	name(_name),
														weapon(_weapon) {
	return;
}

HumanA::~HumanA( void ) {

	return;
}

void	HumanA::attack( void ) 
{
	std::cout 	<< this->name  
				<< " attacks with his " 
				<< this->weapon.getType() 
				<< std::endl;
}


