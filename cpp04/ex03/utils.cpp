/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:45:03 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:45:05 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Project.h"

void	print_small_line( void )
{
	std::cout << BLUE << "-----" << END << std::endl;
}

void	print_line( void )
{
	std::cout << BLUE << std::setfill('-') << std::setw(50) << " " << END << std::endl;
}

void	print_title( std::string title )
{
	std::cout << std::endl << BOLD << BLUE_UL << title << "    " << END << std::endl;
}

void print_char_name( Character &character )
{
	std::cout << "This character's name is " << character.getName() << std::endl;
}

void	print_materia_type( AMateria &materia )
{
	std::cout << "Materia type: " << materia.getType() << std::endl;
}

void	print_materia_address( AMateria &materia )
{
	std::cout << "Materia address: " << &materia << std::endl;
}
