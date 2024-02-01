/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:21:05 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/17 13:56:33 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>
# include <iostream>
# include <iomanip>
# include "Brain.hpp"
# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"


#define BLUE	"\033[0;34m"
#define END		"\033[0m"
#define BOLD	"\033[1m"

void	test_brain( void );
void	printLine( void );
void	test_subject( void );

#endif
