/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:05:44 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/07 14:07:39 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


Harl::Harl( void ) {

	return ;
}

Harl::~Harl ( void ) {

	return ;
}

void Harl::debug() {

	std::cout 	<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-specialketchup burger."
				<< "I really do!"
				<< std::endl;
}

void Harl::info() {

	std::cout 	<< "I cannot believe adding extra bacon costs more money."
				<< " You didn’t put enough bacon in my burger!"
				<< " If you did, I wouldn’t be asking for more!"
				<< std::endl;
}

void Harl::warning() {

	std::cout	<< "I think I deserve to have some extra bacon for free."
				<< " I’ve been coming for years whereas you started working here since last month."
				<< std::endl;
}

void Harl::error() {

	std::cout 	<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}

void Harl::complain(std::string level) {

	const int size = 4;
	typedef	void (Harl::*functionPtr) ( void );
	functionPtr tableFunctionPtr[size] = 	{ 	&Harl::debug,
												&Harl::info,
												&Harl::warning,
												&Harl::error
											};
	std::string levelType[size] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < size; i++)
	{
		if (level == levelType[i])
		{
			(this->*tableFunctionPtr[i])();
			return;
		}
	}
	std::cout << "Unknown level : " << level << std::endl;
}
