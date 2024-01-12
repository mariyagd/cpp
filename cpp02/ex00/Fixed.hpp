/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:46:47 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/10 12:09:32 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

	private:
		static const int	nbFractionalBits;
		int					FixedPointNumber;

	public:
		Fixed( void );
		Fixed( Fixed const& fixedSrc );
		Fixed& operator=( Fixed const& fixedRhs );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
