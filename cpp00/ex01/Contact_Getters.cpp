/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_Getters.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 05:19:51 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/21 05:19:55 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.h"

int Contact::getIndex( void ) const {

	return this->_index;
}

std::string Contact::getFirstName( void ) const {

	return this->_firstName;
};

std::string Contact::getLastName() const {

	return this->_lastName;
}

std::string Contact::getNickName() const {

	return this->_nickName;
}

std::string Contact::getPhoneNumber() const {

	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() const {

	return this->_darkestSecret;
}
