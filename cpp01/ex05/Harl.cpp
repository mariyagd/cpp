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

void Harl::debug( void ) {

	std::cout 	<< "[DEBUG] I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-specialketchup burger."
				<< "I really do!"
				<< std::endl;
}

void Harl::info( void ) {

	std::cout 	<< "[INFO] I cannot believe adding extra bacon costs more money."
				<< " You didn’t put enough bacon in my burger!"
				<< " If you did, I wouldn’t be asking for more!"
				<< std::endl;
}

void Harl::warning( void ) {

	std::cout	<< "[WARNING] I think I deserve to have some extra bacon for free."
				<< " I’ve been coming for years whereas you started working here since last month."
				<< std::endl;
}

void Harl::error( void ) {

	std::cout 	<< "[ERROR] This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}

void Harl::complain(std::string level) {

	const int size = 4;
	typedef	void (Harl::*functionPtr) ( void );														// create a type named functionPtr that is a pointer to a member function oh Harl
	functionPtr tableFunctionPtr[size] = 	{ 	&Harl::debug,									// create a static table of pointers to member functions
												&Harl::info,									// and initialize it with the member functions
												&Harl::warning,
												&Harl::error
											};
	std::string levelType[size] = {"DEBUG", "INFO", "WARNING", "ERROR"};  // create a static table of strings and initialize it
	for (int i = 0; i < size; i++)																	// with the same levels as in the table of pointers in the same order
	{																								// it will be used to compare the level passed as argument
		if (level == levelType[i])																	// with the levels in the table
		{																							// if the level is found,
			(this->*tableFunctionPtr[i])();															// call the member function at the same index
			return;
		}
	}
	std::cout << "Unknown level : " << level << std::endl;
}
