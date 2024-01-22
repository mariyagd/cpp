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
#include <iomanip>

#define BLUE		"\033[0;34m"
#define END			"\033[0m"
#define BOLD		"\033[1m"
#define ITALIC		"\033[3m"
#define GREEN		"\033[0;32m"

void print_line( void ) {
	std::cout << BLUE << std::setw(50) << std::setfill('-') << "" << END << std::endl;
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		std::cout << "This program doesn't require arguments." << std::endl;
		return (1);
	}
	std::string 	stringVar("HI THIS IS BRAIN");
	std::string*	stringPtr;											// create pointer without initialization
//	std::string&	stringRef;  										// cannot create reference without initialization
	std::string&	stringRef = stringVar;  							// cannot create reference without initialization, cannot change reference

	stringPtr = &stringVar;

	std::cout << std::endl << BLUE << "Initialize stringVar, stringPTR and stringREF" << END << std::endl;
	print_line();

	std::cout 	<< GREEN << "stringVar    : " << &stringVar  << "    " << stringVar << END << std::endl
				<< "stringPTR    : " << stringPtr   << "    " << *stringPtr << "    " << stringPtr << std::endl
				<< "stringREF    : " << &stringRef  << "    " << stringRef << std::endl;


	std::cout 	<< std::endl
				<< BLUE		<< "stringREF = stringVar2" << std::endl
				<< ITALIC	<< "(stringRef is not changing its reference." << std::endl
							<< "This expression assigns the value of stringVar2 " << std::endl
							<< "to the object referenced by stringRef." << std::endl
							<<  "The reference and the object are always connected.)" << END << std::endl;
	print_line();

	std::string stringVar2("THIS IS SECOND BRAIN");
	stringVar = stringVar2;
	std::cout	<< "stringVar2   : " << &stringVar2 << "    " << GREEN << stringVar2 << std::endl << END
				<< "stringVar    : " << &stringVar  << "    " << GREEN << stringVar  << std::endl << END
				<< "stringPTR    : " << stringPtr   << "    " << GREEN << *stringPtr << std::endl << END
				<< "stringVar    : " << &stringVar  << "    " << GREEN << stringVar  << std::endl << END
				<< "stringREF    : " << &stringRef  << "    " << GREEN << stringRef  << std::endl << END;


	std::cout	<< std::endl
				<< BLUE		<< "stringPTR = &stringVar3" << std::endl
				<< ITALIC 	<< "(This action does NOT affect the value stringVar and stringREF)" << END << std::endl;
	print_line();

	std::string stringVar3("THIS IS THIRD BRAIN");
	stringPtr = &stringVar3;
	std::cout	<< "stringVar3   : " << GREEN << &stringVar3 << "    " << stringVar3 << END << std::endl
				<< "stringVar2   : " << &stringVar2 << "    " << stringVar2 << std::endl
				<< "stringVar    : " << &stringVar  << "    " << stringVar << std::endl
				<< "stringPTR    : " << GREEN << stringPtr  << "    " <<  *stringPtr << END << std::endl
				<< "stringVar    : " << &stringVar  << "    " << stringVar << std::endl
				<< "stringREF    : " << &stringRef  << "    " << stringRef << std::endl;


	std::cout	<< BLUE		<< std::endl << "stringPTR = NULL | stringPtr = 0 | stringPtr = nullptr" << std::endl
				<< ITALIC	<< "(You cannot affect directly NULL or nullptr to references!" << std::endl
				<< " stringRef = nullptr is incorrect.  A reference is always connected" << std::endl
				<< " to an existing object and can never be NULL or nullptr.)" << END << std::endl;

	stringPtr = 0;
	std::cout	<< "stringVar3   : " << &stringVar3 << "    " << stringVar3 << std::endl
				<< "stringVar2   : " << &stringVar2 << "    " << stringVar2 << std::endl
				<< "stringVar    : " << &stringVar  << "    " << stringVar << std::endl
				<< "stringPTR    : " << GREEN << stringPtr  << "            " << (stringPtr == 0 ? "(null)" : *stringPtr) << END << std::endl
//				<< "stringPTR    : " << GREEN << (stringPtr == 0 ? "(null)     " : "not null") << "    " <<  (stringPtr == 0 ? "(null)" : *stringPtr) << END << std::endl
				<< "stringVar    : " << &stringVar  << "    " << stringVar << std::endl
				<< "stringREF    : " << &stringRef  << "    " << stringRef << std::endl;

	std::cout	<< BLUE		<< std::endl << "Expressiong like std::string someString = nullptr or std::string someString = NULL" << std::endl
					<< "are not a valid. nullptr and NULL are not valid types for initializing a std::string." << std::endl
					<< "A reference is not a pointer; it has the same type as the object that it references." << std::endl
					<< "In this case stringRef is of type std::string. So you cannot assign NULL ou nullptr to it." << END << std::endl;

	return (0);
}
