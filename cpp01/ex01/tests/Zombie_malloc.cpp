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
# include <stdlib.h>

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
	int N = 5;
	Zombie* zombieHorde = static_cast<Zombie*>(malloc (sizeof (Zombie) * N));

	for (int i = 0; i < N; i++)
		zombieHorde[i].initialize("Bob");

	for (int i = 0; i <  N; i++)
		zombieHorde[i].announce();

	free (zombieHorde);

	return 0;
}
