/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:19:13 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/14 15:47:30 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:
		ScavTrap( void );
		ScavTrap( std::string  name);
		ScavTrap( ScavTrap const& src );
		~ScavTrap( void );
		ScavTrap& operator=( ScavTrap const& rhs );

		void attack( const std::string& target );

		void guardGate( void ) const;
};

#endif
