/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:43:56 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/30 23:21:09 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "HumanA.h"

class HumanA 
{
	private:
		std::string name;
		Weapon&		weapon;

	public:
		HumanA( std::string _name, Weapon& _weapon );
		~HumanA();
		void	attack( void );
};

#endif
