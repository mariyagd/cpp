/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:46:47 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/10 15:33:59 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

/*
Les 6 opérateur de comparaison : >, <, >=, <=, == et !=.
• Les 4 opérateurs de arithmétiques : +, -, *, et /.
• Les 4 opérateurs d’incrémentation et de décrémentation (pré-incrémentation et
post-incrémentation, pré-décrémentation et post-décrémentation) qui diminueront
la valeur du nombre à virgule fixe d’unité ϵ tel que 1 + ϵ > 1.
*/

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

		// Opérateurs de comparaison
    bool operator>(Fixed const& rhs) const;
    bool operator<(Fixed const& rhs) const;
    bool operator>=(Fixed const& rhs) const;
    bool operator<=(Fixed const& rhs) const;
    bool operator==(Fixed const& rhs) const;
    bool operator!=(Fixed const& rhs) const;

    // Opérateurs arithmétiques
    Fixed operator+(Fixed const& rhs) const;
    Fixed operator-(Fixed const& rhs) const;
    Fixed operator*(Fixed const& rhs) const;
    Fixed operator/(Fixed const& rhs) const;

    // Opérateurs d'incrémentation et de décrémentation
    Fixed& operator++();    // Pré-incrémentation
    Fixed operator++(int);  // Post-incrémentation
    Fixed& operator--();    // Pré-décrémentation
    Fixed operator--(int);  // Post-décrémentation

    // Fonctions membres statiques min et max
    static Fixed const& min(Fixed const& a, Fixed const& b);
    static Fixed const& max(Fixed const& a, Fixed const& b);
};

std::ostream& operator<<( std::ostream& stream, Fixed const& src );

#endif
