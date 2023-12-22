/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_eraseWhiteSpaces.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:44:39 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/22 10:44:41 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.h"

/*
void	PhoneBook::_eraseWhiteSpaces(std::string &command) const {

	size_t startPos = command.find_first_not_of(" \t\n\r\f\v");
	if (startPos != std::string::npos)
		command.erase(0, startPos);
	else {
		command.clear();
		return ;
	}
	size_t endPos = command.find_last_not_of(" \t\n\r\f\v");
	if (endPos != std::string::npos)
		command.erase(endPos + 1);
}
*/

/*
void	PhoneBook::_eraseWhiteSpaces(std::string &command) const {

	size_t	i(0);

	if (command.empty())
		return ;
	while (i < command.length() && std::isspace(command[i]))
		i++;
	if (i != 0)
		command.erase(0, i);
	i = command.length();
	while (i > 0 && std::isspace(command[i - 1]))
		i--;
	if (i != command.length())
		command.erase(i);
}
*/
void	PhoneBook::_eraseWhiteSpaces(std::string &command) const {

	std::string::iterator it;

	if (command.empty())
		return ;

	for (it = command.begin(); it != command.end() && std::isspace(*it); it++);
	command.erase(command.begin(), it);
	for (it = command.end(); it != command.begin() && std::isspace(*(it - 1)); it--);
	command.erase(it, command.end());

}