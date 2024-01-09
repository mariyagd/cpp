/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:19:06 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/09 15:13:43 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Sample
{
	public:

		Sample( void );
		~Sample( void );
		Sample ( int a );
		Sample (Sample const& src);
		Sample& operator=(Sample const& rhs);

		void	bar( void ) const;
	private:
		int	_foo;
};

Sample::Sample ( void ) : _foo( 0 ) {
	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample::~Sample ( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Sample::Sample( int a ) : _foo(a) {
	std::cout << "Parametrized constructor called" << std::endl;
}


Sample::Sample( Sample const& src )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_foo = src._foo;
}


Sample& Sample::operator=( Sample const& rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs) //verfie si les adresses memoire sont differentes
		this->_foo = rhs._foo;
	return *this;
}

void	Sample::bar( void ) const {
	std::cout << "Foo = " << this->_foo << std::endl;
}

int	main(void)
{
	Sample sample1(54);
	sample1.bar();
	Sample	sample2 = sample1;
	sample2.bar();
	Sample	sample3(sample1);
	sample3.bar();
}
