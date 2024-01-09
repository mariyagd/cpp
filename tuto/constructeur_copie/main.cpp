/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:12:33 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/09 19:15:23 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


class Sample
{
public:
	int		_a;

	Sample(void) : _a(0) {
		std::cout << "Constructor called" << std::endl;
		return;
	}

	~Sample(void) {
		std::cout << "Destructor called" << std::endl;
		return;
	}

	Sample (int const a) : _a(a) {
		std::cout << "Parametrized constructor called" << std::endl;
		return;
	}

	Sample(Sample const& original) {
		std::cout << "Copy constructor called" << std::endl;
		*this = original;
		return;
	}

	void	bar(void) const {
		std::cout << "this->_a = " << this->_a << std::endl;
		return;
	}
};

void	foo(Sample instance) {
	instance.bar();
	return;
}

int		main(void)
{
	Sample		instance1;
	Sample		instance2(42);
	Sample		instance3(instance2);  //appel au constructeur par copie (1)
	Sample		instance4 = instance2; //appel au constructeur par copie (2)

	instance1.bar();
	instance2.bar();
	instance3.bar();
	instance4.bar();

	foo(instance4); //appel au constructeur par copie  (3)
	instance4 = instance1;  //operateur d'affectation
//	instance4(instance1); instance4 a deja ete instancie donc on ne peut par rappeler le constructeur par copie
	instance4.bar();
	return (0);
}
