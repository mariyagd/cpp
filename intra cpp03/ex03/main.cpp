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
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include <iomanip>

void	print_line( void ) {
	std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;
}

void	printDiamondTrap(DiamondTrap& diamond)
{
	std::cout << diamond;
	diamond.whoAmI();
	std::cout << std::endl;
}

void	test_init( void )
{
	std::cout << "Initialisation test:" << std::endl;
	print_line();

	DiamondTrap	bob("Bob");
	std::cout << std::endl;

	printDiamondTrap(bob);

	bob.highFivesGuys();
	bob.guardGate();

	std::cout << std::endl;
}

void	test_constructors( void )
{
	std::cout << "Constructor tests:" << std::endl;
	print_line();

	DiamondTrap	zero;
	printDiamondTrap(zero);

	DiamondTrap	first("Bob");
	printDiamondTrap(first);

	DiamondTrap	second(first);
	printDiamondTrap(second);

	zero = second;
	printDiamondTrap(zero);
}

void attack_test1( void )
{
	std::cout << "Attack test between a DiamondTrap and a ScavTrap:" << std::endl;
	print_line();

	ScavTrap	arnold("Arnold");
	std::cout << arnold << std::endl;

	DiamondTrap	roger("Roger");
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

	roger.guardGate();
	std::cout << std::endl;
}

void attack_test2( void )
{
	std::cout << "Attack test between a DiamondTrap and a ClapTrap:" << std::endl;
	print_line();

	ClapTrap	arnold("Arnold");
	std::cout << arnold << std::endl;

	DiamondTrap	roger("Roger");
	printDiamondTrap(roger);

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
	std::cout << "Attack test between a DiamondTrap and a FragTrap:" << std::endl;
	print_line();

	FragTrap	arnold("Arnold");
	std::cout << arnold << std::endl;

	DiamondTrap	roger("Roger");
	printDiamondTrap(roger);

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

void attack_test4( void )
{
	std::cout << "Attack test between two DiamondTraps:" << std::endl;
	print_line();

	DiamondTrap	arnold("Arnold");
	printDiamondTrap(arnold);

	DiamondTrap	roger("Roger");
	printDiamondTrap(roger);

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

int	main( void )
{
	test_init();
	print_line();

	test_constructors();
	print_line();

	attack_test1();
	print_line();
	
	attack_test2();
	print_line();

	attack_test3();
	print_line();

	attack_test4();
	print_line();

}
