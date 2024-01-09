/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:12:06 by mdanchev          #+#    #+#             */
/*   Updated: 2024/01/09 13:17:46 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

int main() {

	Sample instance1;   				//constructeur par defaut
	Sample instance2( 42 );				//constructeur parametrique
	Sample instance3( instance1 );     	//constructeur de copie

	std::cout << instance1 << std::endl;
	std::cout << instance2 << std::endl;
	std::cout << instance3 << std::endl;

	instance3 = instance2;				//operateur d'assignation
	std::cout << instance3 << std::endl;

	return 0;
}
