/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:21:05 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/17 09:07:34 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iomanip>
#include <vector>


#define BLUE	"\033[0;34m"
#define END		"\033[0m"
#define BOLD	"\033[1m"

void	test_references( void );
void	printLine( void );
void	test_pointers( void );
void	test_constructors( void );
void	heterogeneous_collection( void );
void	test_casting( void );


#endif
