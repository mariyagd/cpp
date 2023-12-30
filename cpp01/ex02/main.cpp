/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:32:09 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/30 13:46:09 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		std::cout << "This program doesn't require arguments." << std::endl;
		return (1);
	}
	std::string 	stringVar("HI THIS IS BRAIN");
	std::string*	stringPtr = &stringVar;
	std::string&	stringRef = stringVar;

	std::cout 	<< "The memory address of the stringVar  is : " 
				<< &stringVar << std::endl
				<< "The memory address held by stringPTR is : "
				<< stringPtr << std::endl
				<< "The memory address held by stringREF is : "
				<< &stringRef << std::endl
				<< "The value of the stringVar  is       : " 
				<< stringVar << std::endl
				<< "The value pointed to by stringPTR is : "
				<< *stringPtr << std::endl
				<< "The value pointed to by stringREF is : "
				<< stringRef << std::endl;
	return (0);
}
