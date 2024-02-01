/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:12:43 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/14 17:10:34 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iomanip>

void	print_line( void ) {	
	std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;
}

void	test_constructors( void )
{
	std::cout << "Constructor tests:" << std::endl;
	print_line();

	ScavTrap	zero;
	std::cout << zero << std::endl;

	ScavTrap	first("Bob");
	std::cout << first << std::endl;

	ScavTrap	second("James");
	std::cout << second << std::endl;

	ScavTrap	third(second);
	std::cout << third << std::endl;

	ScavTrap	forth;
	std::cout << forth << std::endl;
	
	forth = third;
	std::cout << forth << std::endl;
}

void attack_test1( void )
{
	std::cout << "Attack test between two ScavTraps:" << std::endl;
	print_line();

	ScavTrap	arnold("Arnold");
	std::cout << arnold << std::endl;

	ScavTrap	roger("Roger");
	std::cout << roger << std::endl;

	arnold.attack(roger.getName());
	roger.takeDamage(arnold.getAttackDammage());
	roger.attack(arnold.getName());
	arnold.takeDamage(roger.getAttackDammage());
	
	std::cout	<< std::endl
				<< arnold
				<< roger
				<< std::endl;

	roger.beRepaired(10);
	std::cout << roger << std::endl;

	roger.guardGate();
	std::cout << std::endl;
}

void attack_test2( void )
{
	std::cout << "Attack test between a ScavTraps and a ClapTrap:" << std::endl;
	print_line();

	ClapTrap	arnold("Arnold");
	std::cout << arnold << std::endl;

	ScavTrap	roger("Roger");
	std::cout << roger << std::endl;

	arnold.attack(roger.getName());
	roger.takeDamage(arnold.getAttackDammage());
	roger.attack(arnold.getName());
	arnold.takeDamage(roger.getAttackDammage());

	std::cout 	<< std::endl
				<< arnold
				<< roger 
				<< std::endl;

	roger.guardGate();

	std::cout << std::endl;
}

int	main( void )
{
	test_constructors();
	print_line();

	attack_test1();
	print_line();
	
	attack_test2();
	print_line();
}
