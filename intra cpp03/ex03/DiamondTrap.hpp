/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:19:13 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/14 17:25:24 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

	private:
		std::string _name;
	public:
		DiamondTrap( void );
		DiamondTrap( std::string  name);
		DiamondTrap( DiamondTrap const& src );
		~DiamondTrap( void );
		DiamondTrap& operator=( DiamondTrap const& rhs );

		void whoAmI( void );

		void attack( const std::string& target );

};



#endif
