/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 05:20:51 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/21 05:20:53 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.h"

int main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		std::cerr << BOLD << "Please open this program without any arguments." << RESET << std::endl;
		return 1;
	}
	PhoneBook	PhoneBook;
	return 0;
}
