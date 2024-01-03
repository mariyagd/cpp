/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:39:27 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/30 16:20:35 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void ) : type("") {

	return;
}

Weapon::Weapon( std::string _type ) : type(_type) {

	return;
}

Weapon::~Weapon( void ) {

	return;
}

const std::string&	Weapon::getType( void ) const {

	return this->type;
}


void	Weapon::setType( std::string newType ) {

	this->type = newType;
}
