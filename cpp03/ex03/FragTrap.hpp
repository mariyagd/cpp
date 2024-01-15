/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:19:13 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/14 17:25:24 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {

	public:
		FragTrap( void );
		FragTrap( std::string  name);
		FragTrap( FragTrap const& src );
		~FragTrap( void );
		FragTrap& operator=( FragTrap const& rhs );

		void highFivesGuys( void ) const;

};

#endif
