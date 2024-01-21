/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:21:33 by mdanchev          #+#    #+#             */
/*   Updated: 2023/12/29 18:33:55 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>

class Zombie
{
private:
	std::string	name;

public:
	Zombie() : name ("") { std::cout << "Dummy constructor called" << std::endl; }
	Zombie( std::string _name) : name(std::move(_name)) { std::cout << "Parametrized constructor called" << std::endl; }
	~Zombie() { std::cout << "Destructor called" << std::endl; }

	void	initialize( std::string _name_ ) { this->name = _name_; }
	void	announce( void ) { std::cout << name << std::endl; }
};

int main(void)
{
	Zombie	Bob("Bob"), Dylan("Dylan"), Rick("Rick"), Leona("Leona"), Marta("Marta");

	Zombie* zombieHorde[] = {&Bob, &Dylan, &Rick, &Leona, &Marta, 0};

	int size = 0;
	for (int i = 0; zombieHorde[i]; i++)
		size++;
	std::cout << "Taille du tableau: " << size << std::endl;

	for (int i = 0; i < size; i++)
		zombieHorde[i]->announce();

	return 0;
}
