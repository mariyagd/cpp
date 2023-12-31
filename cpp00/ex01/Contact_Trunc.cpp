/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_Trunc.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 05:20:11 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/21 05:20:12 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.h"

std::string Contact::truncFirstName() const{

	std::string str;

	str = this->_firstName.substr(0,10);
	if (str.length() == 10)
		str.back() = '.';
	return str;
}

std::string Contact::truncLastName() const {

	std::string str;

	str = this->_lastName.substr(0,10);
	if (str.length() == 10)
		str.back() = '.';
	return str;
}

std::string Contact::truncNickName() const {

	std::string str;

	str = this->_nickName.substr(0,10);
	if (str.length() == 10)
		str.back() = '.';
	return str;
}
