/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:45:33 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/24 09:45:34 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{

public:
	Ice( void );								// ok
	virtual ~Ice( void );						// ok
	Ice(Ice const &src);						// ok
	Ice& operator=(Ice const & rhs);			// ok

	virtual Ice*	clone( void ) const;		// override ok
	void			use( ICharacter &target );	// override

};
#endif
