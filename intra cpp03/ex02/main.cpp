/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:12:43 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/14 17:26:44 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iomanip>

void	print_line( void ) {	
	std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;
}

void	test_constructors( void )
{
	std::cout << "Constructor tests:" << std::endl;
	print_line();

	FragTrap	zero;
	std::cout << zero << std::endl;

	FragTrap	first("Bob");
	std::cout << first << std::endl;

	FragTrap	second("James");
	std::cout << second << std::endl;

	FragTrap	third(second);
	std::cout << third << std::endl;

	FragTrap	forth;
	std::cout << forth << std::endl;
	
	forth = third;
	std::cout << forth << std::endl;
}

void attack_test1( void )
{
	std::cout << "Attack test between a FragTrap and a ScavTraps:" << std::endl;
	print_line();

	ScavTrap	arnold("Arnold");
	std::cout << arnold << std::endl;

	FragTrap	roger("Roger");
	std::cout << roger << std::endl;

	arnold.attack(arnold.getName());
	roger.takeDamage(arnold.getAttackDammage());
	roger.attack(arnold.getName());
	arnold.takeDamage(roger.getAttackDammage());
	
	std::cout	<< std::endl
				<< arnold
				<< roger
				<< std::endl;

	roger.beRepaired(10);
	std::cout << roger << std::endl;

	arnold.guardGate();
	std::cout << std::endl;

	roger.highFivesGuys();
	std::cout << std::endl;
}

void attack_test2( void )
{
	std::cout << "Attack test between a FragTrap and a ClapTrap:" << std::endl;
	print_line();

	ClapTrap	arnold("Arnold");
	std::cout << arnold << std::endl;

	FragTrap	roger("Roger");
	std::cout << roger << std::endl;

	arnold.attack(roger.getName());
	roger.takeDamage(arnold.getAttackDammage());
	roger.attack(arnold.getName());
	arnold.takeDamage(roger.getAttackDammage());

	std::cout 	<< std::endl
				<< arnold
				<< roger 
				<< std::endl;

	roger.highFivesGuys();
	std::cout << std::endl;
}

void attack_test3( void )
{
	std::cout << "Attack test between two FragTraps:" << std::endl;
	print_line();

	FragTrap	arnold("Arnold");
	std::cout << arnold << std::endl;

	FragTrap	roger("Roger");
	std::cout << roger << std::endl;

	arnold.attack(arnold.getName());
	roger.takeDamage(arnold.getAttackDammage());
	roger.attack(arnold.getName());
	arnold.takeDamage(roger.getAttackDammage());
	
	std::cout	<< std::endl
				<< arnold
				<< roger
				<< std::endl;

	roger.beRepaired(10);
	std::cout << roger << std::endl;

	arnold.highFivesGuys();
	std::cout << std::endl;

	roger.highFivesGuys();
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

	attack_test3();
	print_line();
}
