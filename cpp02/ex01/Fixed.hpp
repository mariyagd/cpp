/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:46:47 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/10 15:12:37 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

	private:
		static const int	nbFractionalBits = 8; //is nb bits avec the point
		int					fixedPointValue;

	public:
		Fixed( void );
		Fixed( Fixed const& fixedSrc );
		Fixed& operator=( Fixed const& fixedRhs );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		Fixed( int const intValue );
		Fixed ( float const floatValue );

		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream& operator<<( std::ostream& stream, Fixed const& src );

#endif
