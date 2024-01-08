/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:08:21 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/29 15:46:21 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include "Zombie.hpp"
# include <iostream>
# include <string>

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
