/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:48:27 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/30 23:26:25 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"


class HumanB
{
	private:
		std::string name;
		Weapon*		weapon;
		HumanB();

	public:
		HumanB( std::string _name );
		~HumanB();
		void	attack( void );
		void	setWeapon( Weapon& _weapon );
};

#endif
