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
#include <random>

#define NO_F -1.235
#define NO_INT -1


float randomFloat()
{
	return (float)(rand()) / (float)(rand());
}

Fixed choose_constructor(int aInt, float aFloat)
{
	if (aInt == NO_INT && aFloat == NO_F)
		return Fixed(rand());
	if (aInt == NO_INT)
		return Fixed(aFloat);
	else
		return Fixed(aInt);
}

void	comparision(int aInt, float aFloat, int bInt, float bFloat)
{
	Fixed a = choose_constructor(aInt, aFloat);
	Fixed b = choose_constructor(bInt, bFloat);
	
	std::cout 	<< " a = " << a << " b = " << b << std::endl
				<< " a > b  ? "
				<< ( a > b ? "yes" : "no") << std::endl
				<< " a < b  ? "
				<< ( a < b ? "yes" : "no") << std::endl
				<< " a >= b ? "
				<< ( a >= b ? "yes" : "no") << std::endl
				<< " a <= b ? "
				<< ( a <= b ? "yes" : "no") << std::endl
				<< " a == b ? "
				<< ( a == b ? "yes" : "no") << std::endl
				<< " a != b ? "
				<< ( a != b ? "yes" : "no") << std::endl
				<< std::setw(25) << std::setfill('-') << " " << std::endl;
}

void	incr(int aInt, float aFloat)
{
	Fixed a = choose_constructor(aInt, aFloat);
	Fixed b;

	std::cout << "a = " << a.getRawBits() << std::endl << std::endl ;

	std::cout << "Pre-incrementation test:" << std::endl;
	std::cout << "a =  " << a.getRawBits() << std::endl;
	b = ++a;
	std::cout << "b = ++a" << std::endl;
	std::cout << "a = " << a.getRawBits() << std::endl;
	std::cout << "b = " << b.getRawBits() << std::endl << std::endl;

	std::cout << "Post-incrementation test:" << std::endl;
	std::cout << std::endl << "a = " << a.getRawBits() << std::endl;
	b = a++;
	std::cout << "b = a++" << std::endl;
	std::cout << "a = " << a.getRawBits() << std::endl;
	std::cout << "b = " << b.getRawBits() << std::endl << std::endl;

	std::cout << std::setw(25) << std::setfill('-') << " " << std::endl;

	std::cout << "a = " << a.getRawBits() << std::endl;
	for (int i = 0; i < 5; i++)
	{
		++a;
		std::cout 	<< "++a = "
					<< a.getRawBits()
					<< std::endl;
	}
	for (int i = 0; i < 5; i++)
	{
		a++;
		std::cout 	<< "a++ = "
					 << a.getRawBits()
					 << std::endl;
	}
	std::cout << std::setw(25) << std::setfill('-') << " " << std::endl;
}

void	decr(int aInt, float aFloat)
{
	Fixed a = choose_constructor(aInt, aFloat);

	std::cout << "a = " << a.getRawBits() << std::endl << std::endl;

	std::cout << "Pre-decrementation test:" << std::endl;
	std::cout << "a = " << a.getRawBits() << std::endl;
	Fixed b = --a;
	std::cout << "b = --a" << std::endl;
	std::cout << "a = " << a.getRawBits() << std::endl;
	std::cout << "b = " << b.getRawBits() << std::endl;

	std::cout << "Post-decrementation test:" << std::endl;
	std::cout << std::endl << "a = " << a.getRawBits() << std::endl;
	b = a--;
	std::cout << "b = a--" << std::endl;
	std::cout << "a = " << a.getRawBits() << std::endl;
	std::cout << "b = " << b.getRawBits() << std::endl << std::endl;

	std::cout << "a = " << a.getRawBits() << std::endl;
	for (int i = 0; i < 5; i++)
	{
		--a;
		std::cout 	<< "--a = "
					 << a.getRawBits()
					 << std::endl;
	}
	for (int i = 0; i < 5; i++)
	{
		a--;
		std::cout 	<< "a-- = "
					 << a.getRawBits()
					 << std::endl;
	}
	std::cout << std::setw(25) << std::setfill('-') << " " << std::endl;
}

void	arithmetics(int aInt, float aFloat, int bInt, float bFloat)
{
	Fixed a = choose_constructor(aInt, aFloat);
	Fixed b = choose_constructor(bInt, bFloat);

	std::cout 	<< " a = " << a << " b = " << b << std::endl
				<< " a + b = " << a + b << std::endl
				<< " a - b = " << a - b << std::endl
				<< " a * b = " << a * b << std::endl
				<< " a / b = " << a / b << std::endl;
	std::cout << std::setw(25) << std::setfill('-') << " " << std::endl;

}

void min_max(int aInt, float aFloat, int bInt, float bFloat)
{
	Fixed a = choose_constructor(aInt, aFloat);
	Fixed b = choose_constructor(bInt, bFloat);
	Fixed c = Fixed::min(a, b);
	Fixed d = Fixed::max(a, b);

	std::cout 	<< "Min max test on non const" << std::endl << std::endl
				<< "a = " << a << " b = " << b << std::endl
				<< "min = " << c << std::endl
				<< "max = " << d << std::endl;

	std::cout << std::setw(25) << std::setfill('-') << " " << std::endl;
}

void min_max_const(int aInt, float aFloat, int bInt, float bFloat)
{
	Fixed const a = choose_constructor(aInt, aFloat);
	Fixed const b = choose_constructor(bInt, bFloat);
	Fixed const c = Fixed::min(a, b);
	Fixed const d = Fixed::max(a, b);

	std::cout 	<< "Min max test on const" << std::endl << std::endl
				<< "const a = " << a << " const b = " << b << std::endl
				<< "const min = " << c << std::endl
				<< "const max = " << d << std::endl;

	std::cout << std::setw(25) << std::setfill('-') << " " << std::endl;
}

int	main(void)
{
	std::cout 	<< "I. Subject tests" << std::endl
				<< std::setw(25) << std::setfill('-') << " " << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << std::setw(25) << std::setfill('-') << " " << std::endl;

	comparision(rand(), NO_F, 25689, NO_F);
	comparision(0, NO_F, 0, NO_F);

	incr(5, NO_F);
	decr(NO_INT,randomFloat());

	arithmetics(8, NO_F, 2, NO_F);
	arithmetics(10, NO_F, 2,  NO_F);

	min_max(NO_INT, randomFloat(), NO_INT, randomFloat());
	min_max_const(968, NO_F, NO_INT, 968.56);

	return 0;
}

//	comparision(NO_INT, randomFloat(), NO_INT, randomFloat());
//	comparision(NO_INT, 25.62, NO_INT, 25.623);
//	comparision(rand(), NO_F, NO_INT, randomFloat());
//	comparision(5, NO_F, NO_INT, 5.00000);
//	comparision(NO_INT, randomFloat(), rand(), NO_F);
//	comparision(NO_INT, 12569.654, 12569, NO_F);
//	incr(NO_INT,randomFloat());
//	decr(rand(),NO_F);
//	arithmetics(8, NO_F, 2, NO_F);
//	arithmetics(NO_INT,0.5, 10, NO_F);
//	min_max(968, NO_F, NO_INT, 968.56);
//	min_max(12, NO_F, 6354,NO_INT);
//	min_max( NO_INT, randomFloat(), rand(),NO_F);

