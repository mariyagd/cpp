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
		static const int	nbFractionalBits;
		int					fixedPointNumber;

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

		bool	operator>(Fixed const& other) const;
		bool	operator<(Fixed const& other) const;
		bool	operator>=(Fixed const& other) const;
		bool	operator<=(Fixed const& other) const;
		bool	operator==(Fixed const& other) const;
		bool	operator!=(Fixed const& other) const;

		Fixed	operator+(Fixed const& other) const;
		Fixed	operator-(Fixed const& other) const;
		Fixed	operator*(Fixed const& other) const;
		Fixed	operator/(Fixed const& other) const;

		// pre-increment operators
		Fixed&	operator++( void );
		Fixed&	operator--( void );

		//post-increment operators
		Fixed	operator++( int );
		Fixed	operator--( int );

		static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(Fixed const& a, Fixed const& b);

	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(Fixed const& a, Fixed const& b);
};

std::ostream& operator<<( std::ostream& stream, Fixed const& src );

#endif
