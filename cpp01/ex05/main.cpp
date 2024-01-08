/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:05:38 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/07 14:05:40 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr 	<< "Invalid numbers of arguments. Please write: "
					<< "./prog [level]" << std::endl;
		return 1;
	}
	Harl		harl;
	std::string	level = av[1];

	for (std::string::iterator it = level.begin(); it < level.end(); ++it)
			*it = std::toupper(*it);

	harl.complain(level);
	return 0;
}
