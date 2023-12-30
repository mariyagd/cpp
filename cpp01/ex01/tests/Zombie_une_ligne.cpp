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
	Zombie zombieHorde[5] = {Zombie("Bob"), Zombie("Dylan"), Zombie("Rick"), Zombie("Leona"), Zombie("Marta")};

	for (int i = 0; i < 5; i++)
		zombieHorde[i].announce();
}
