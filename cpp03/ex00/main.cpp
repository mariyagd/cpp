/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:12:43 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/14 17:04:42 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iomanip>

void	print_line( void ) {	
	std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;
}

void	test_constructors( void )
{
	std::cout << "Constructor tests:" << std::endl;
	print_line();

	ClapTrap	zero;
	ClapTrap	first("Bob");
	ClapTrap	second("James");
	ClapTrap	third(second);
	ClapTrap	forth = first;

	std::cout 	<< std::endl
				<< "zero  : " << zero
				<< "first : " << first
				<< "second: " << second
				<< "third : " << third
				<< "forth : " << forth
				<< std::endl;
	
	forth = third;
	std::cout<< "forth : " << forth << std::endl;
}

void dead_test( void )
{
	std::cout << "Dead tests: 0 hit points" << std::endl;
	print_line();

	ClapTrap	henry("Henry");

	std::cout << std::endl << henry << std::endl;

	henry.takeDamage(15);
	std::cout << henry << std::endl;
	
	henry.beRepaired(15);
	henry.attack("Someone");
	henry.takeDamage(5);
	std::cout << std::endl;
}

void energy_test( void )
{
	std::cout << "Energy tests: 0 energy points" << std::endl;
	print_line();

	ClapTrap	lucas("Lucas");

	std::cout << std::endl << lucas << std::endl;
	
	for (int i = 0; i < 10; i++)
		lucas.attack("Bart");
	std::cout << lucas << std::endl;

	lucas.attack("Someone");
	std::cout << lucas << std::endl;

	lucas.beRepaired(15);
	std::cout << lucas << std::endl;

	lucas.takeDamage(2);
	std::cout << lucas << std::endl;
}

void repairing_test( void )
{
	std::cout << "Attack tests: repairing" << std::endl;
	print_line();

	ClapTrap	arnold("Arnold");

	std::cout << std::endl << arnold << std::endl;

	arnold.beRepaired(15);
	std::cout << arnold << std::endl;
		
	arnold.takeDamage(3);
	std::cout << arnold << std::endl;
	
	arnold.beRepaired(15);
	std::cout << arnold << std::endl;
}

int	main( void )
{
	test_constructors();
	print_line();

	dead_test();
	print_line();
	
	energy_test();
	print_line();
	
	repairing_test();
	print_line();
}
