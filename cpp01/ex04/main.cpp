/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:27:11 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/04 11:23:42 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	main(int ac, char **av)
{
	if ( ac != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	std::string	inFileName(av[1]);
	std::string	outFileName(inFileName + ".replace");
	std::string	wordSearch(av[2]);
	std::string	wordReplace(av[3]);
	
	std::ifstream inStream(inFileName.c_str());
	if(!inStream.is_open())
	{
		std::cerr << inFileName << ": Could not open file or file doesn't exist." << std::endl;
		return 1;
	}
	std::ofstream outStream(outFileName.c_str());
	if (!outStream.is_open())
	{
		std::cerr << outFileName << ": could not create file." <<  std::endl;
		outStream.close();
		return 1;
	}
	std::string line;
    while (getline(inStream, line))
    {
        size_t pos = 0;
	    while ((pos = line.find(wordSearch, pos)) != std::string::npos)
    	{
        	line.erase(pos, wordSearch.length());
        	line.insert(pos, wordReplace);
        	pos += wordReplace.length();
    	}
        outStream << line << std::endl;
    }
	inStream.close();
	outStream.close();
	return (0);
}
