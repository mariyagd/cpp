#include <iostream>

class Animal {

public:
	virtual void	 makeSound ( void ) const = 0;
	// ...
};

class Dog : public Animal {
public:
	void	makeSound ( void ) const;
	// ...
};

void	Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

int main(void)
{
	Dog     dog;

	dog.makeSound();  // prints Animal sound
}