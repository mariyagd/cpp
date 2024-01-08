/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 05:19:15 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/08 19:23:43 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	std::string args(av[1]);
	for (int i = 2; i < ac; i++)
		args += std::string(" ") + std::string(av[i]);

	for (std::string::iterator it = args.begin(); it != args.end(); it++)
		std::cout << (char)std::toupper(*it);
	std::cout << std::endl;

	return 0;
}

/*
int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	int i(1);
	int j(0);

	while (av[i])
	{
		j = 0;
		if (i > 1)
			std::cout << " ";
		while (av[i][j] != '\0')
		{
			std::cout << (char)toupper(av[i][j]);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return 0;
}
*/
