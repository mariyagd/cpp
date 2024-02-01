/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:44:18 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:44:19 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("") {

//	std::cout << ITALIC << DIM << "AMateria's Default constructor called" << END << std::endl;
	return ;
}

AMateria::~AMateria( void ) {

//	std::cout << ITALIC << DIM << "AMateria's Destructor called" << END << std::endl;
	return ;
}

AMateria::AMateria( AMateria const &src ) : _type(src._type){

	std::cout << ITALIC << DIM << src.getType() << " was copied successfully." << END << std::endl;
//	std::cout << ITALIC << DIM << "AMateria's Copy constructor called" << END<< std::endl;
	return ;
}

AMateria& AMateria::operator=( AMateria const &rhs ) {

//	std::cout << ITALIC << DIM << "AMateria's Assignment operator called" << END<< std::endl;
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	std::cout << ITALIC << DIM << rhs.getType() << " was assigned successfully." << END << std::endl;
	return (*this);
}

AMateria::AMateria(std::string const &type) : _type(type) {

//	std::cout << ITALIC << DIM << "AMateria's Parametrized constructor called" << END << std::endl;
	return ;
}

std::string const&	AMateria::getType() const {

	return (this->_type);
}

void	AMateria::use(ICharacter &target) {

	(void)target;
	return ;
}
