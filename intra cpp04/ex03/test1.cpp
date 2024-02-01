/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:44:50 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:44:52 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Project.h"

void	test_materia_cloning( void )
{
	std::cout << std::endl << BOLD << BLUE << "Tests cloning AMateria derived classes (file test1)" << END << std::endl;
	print_line();

	print_title("Create Cure cure and AMateria *materia1 = cure.clone()");

	Cure	cure;
	print_materia_type(cure);
	print_materia_address(cure);
	print_small_line();

	AMateria	*materia1 = cure.clone();
	std::cout << "Type: "<< materia1->getType() << std::endl;
	std::cout << "Address: " << materia1 << std::endl;
	print_small_line();

	print_title("Delete *materia1 because it was dynamically allocated");
	delete materia1;

	print_title("Create Ice ice and AMateria *materia2 = ice.clone()");
	Ice	ice;
	print_materia_type(ice);
	print_materia_address(ice);
	print_small_line();

	AMateria	*materia2 = ice.clone();
	std::cout << "Type: "<< materia2->getType() << std::endl;
	std::cout << "Address: " << materia2 << std::endl;
	print_small_line();

	print_title("Delete *materia2 because it was dynamically allocated");
	delete materia2;
	print_small_line();

	print_title("Constructors tests");
	print_line();

	print_title("Create Ice ice2 as copy of ice");
	Ice	ice2(ice);
	print_materia_type(ice2);

	print_title("Create Ice ice3 and assign ice to it");
	Ice	ice3;
	ice3 = ice;
	print_materia_type(ice2);

	print_title("Create Amateria *materia3 as a copy of ice");
	AMateria	*materia3 = new Ice(ice);
	print_materia_type(*materia3);

	print_title("Assign cure to materia3");
	*materia3 = cure;
	print_materia_type(*materia3);

	print_title("Create Cure cure2 as copy of cure");
	Cure	cure2(cure);
	print_materia_type(cure2);

	print_title("Create Cure cure3 and assign cure to it");
	Cure	cure3;
	cure3 = cure;
	print_materia_type(cure2);

	print_small_line();
	delete (materia3);


}
