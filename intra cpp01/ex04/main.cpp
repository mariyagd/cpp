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
	
	std::ifstream inStream(inFileName.c_str());									// open the input file
	if(!inStream.is_open())															// if the file doesn't exist or can't be opened
	{																				// return an error message
		std::cerr << inFileName << ": Could not open file or file doesn't exist." << std::endl;
		return 1;
	}

	std::ofstream outStream(outFileName.c_str());								// open the output file or create it if it doesn't exist
	if (!outStream.is_open())														// if the file can't be created
	{																				// return an error message
		std::cerr << outFileName << ": could not create file." <<  std::endl;
		outStream.close();
		return 1;
	}

	std::string line;
    while (getline(inStream, line))										// read the input file line by line
    {
		size_t pos = 0;																// find wordSearch in the line and return its position.
	    while ((pos = line.find(wordSearch, pos)) != std::string::npos)		// If there is no wordSearch in the line, return npos
    	{																			// (e.g. npos = the end of the string)
        	line.erase(pos, wordSearch.length());								// if wordSearch is found, erase it and insert wordReplace
        	line.insert(pos, wordReplace);								// at the same position
        	pos += wordReplace.length();											// increment pos by the length of wordReplace
			pos = line.find(wordSearch, pos);									// find wordSearch in the line starting from pos
    	}
        outStream << line << std::endl;												// write the line in the output file
    }
	inStream.close();																// close the input file
	outStream.close();																// close the output file
	return (0);
}
