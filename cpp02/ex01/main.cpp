/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:01:16 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/10 19:45:32 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>

void print_int(std::string name, int aValue, const Fixed &a)
{
	std::cout 	<< "| " << std::left
				 << std::setw(19)  << name << "| "
				 << std::setw(19) << aValue << "| "
				 << std::setw(22) << a.getRawBits() << "| "
				 << std::setw(19) << a.toInt() << "| "
				 << std::setw(19) << a.toFloat() << "|"
				 << std::endl;


	std::cout << std::setw(110) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
}

void print_float(std::string name, float aValue, const Fixed &a)
{
	std::cout 	<< "| " << std::left
				<< std::setw(19)  << name << "| "
				<< std::setw(19) << aValue << "| "
				<< std::setw(22) << a.getRawBits() << "| "
				<< std::setw(19) << a.toInt() << "| "
				<< std::setw(19) << a.toFloat() << "|"
				<< std::endl;


	std::cout << std::setw(110) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
}

void	print_table( void )
{
	std::cout << std::setw(110) << std::setfill('-') << "" << std::setfill(' ') << std::endl;

	std::cout	<< "|" << std::left
				<< std::setw(20) << " Object Name" << "|"
				<< std::setw(19) << " Number" << " |"
				<< std::setw(23) << " Fixed Point Number" << "|"
				<< std::setw(20) << " To int" << "|"
				<< std::setw(20) << " To float" << "|"
				<< std::endl;

	std::cout << std::setw(110) << std::setfill('-') << "" << std::setfill(' ') << std::endl;

}

int	main(void)
{
//	Fixed a;
//	Fixed const b( 10 );
//	Fixed const c( 42.42f );
//	Fixed const d( b );
//	a = Fixed( 1234.4321f );
//	std::cout << "a is " << a << std::endl;
//	std::cout << "b is " << b << std::endl;
//	std::cout << "c is " << c << std::endl;
//	std::cout << "d is " << d << std::endl;
//	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
//	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
//	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
//	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
//
//	Fixed e( 5.75f );
//	std::cout << "e is " << e << std::endl;
//	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
//	std::cout << "e is " << e.toFloat() << " as float" << std::endl;

	float	aValue = 1234.4321f;
	int 	bValue = 10;
	float 	cValue = 42.42f;
	float 	eValue = 26.56f;

	Fixed a;
	Fixed const b( bValue );
	Fixed const c( cValue );
	Fixed const d( b );
	a = Fixed( aValue );
	Fixed const e( eValue );

	print_table();
	print_float("a", aValue, a);
	print_int("b", bValue, b);
	print_float("c", cValue, c);
	print_int("d", bValue, d);
	print_float("e", eValue, e);

	return 0;
}
