#include <iostream>

class Animal {

public :
	virtual void makeSound( void ) const;
};

class Dog : public Animal {

public:
	void	makeSound( void ) const;
};


void	Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Dog sound" << std::endl;
}

int main( void )
{
	Dog	dog;

	dog.makeSound();			// prints Dog sound
	dog.Animal::makeSound();	// prints Animal sound
}