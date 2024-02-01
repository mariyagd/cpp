/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:44:13 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:44:14 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PROJECT_H
# define PROJECT_H


# include "AMateria.hpp"
# include "Cure.hpp"
# include "Ice.hpp"
# include "Character.hpp"
# include <iostream>
# include <iomanip>
# include "Colors.h"
# include "MateriaSource.hpp"

void	test_materia_cloning( void );
void	print_materia_address( AMateria &materia );
void	print_small_line( void );
void	print_line( void );
void	print_title( std::string title );
void	print_char_name( Character &character );
void	print_materia_type( AMateria &materia );
void	test_char_equip_unequip( void );
void	test_materia_source_inventory( void );

#endif
