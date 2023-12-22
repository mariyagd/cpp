/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_IsNumber.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 05:20:37 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/21 05:20:38 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.h"

int PhoneBook::_isNumber(std::string& str, int _tableSize) const {

	int i(0);
	std::string maxInt("2147483647");

	_eraseWhiteSpaces(str);
	if (str.empty()) {
		std::cout << "Empty input. ";
		return -1;
	}
	_transformToUpper(str);
	if (str == "EXIT")
		return -2;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!std::isdigit(str[i])) {
			std::cout << "Not a number or not a valid number. ";
			return -1;
		}
		i++;
	}
	if (str.length() >= maxInt.length() && str > maxInt) {
		std::cout << "Not a int. ";
		return -1;
	}
	if (str[0] == '0' && str.length() > 1) {
		std::cout << "Not a valid number. ";
		return -1;
	}
	if (std::stoi(str) >= _tableSize) {
		std::cout << "Index is not in the table. ";
		return -1;
	}
	return std::stoi(str);
}
