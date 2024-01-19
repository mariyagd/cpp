#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include <iostream>
#include <iomanip>
#include "Colors.h"
#include "MateriaSource.hpp"

void	print_small_line( void )
{
	std::cout << BLUE << "-----" << END << std::endl;
}

void	print_line( void )
{
	std::cout << BLUE << std::setfill('-') << std::setw(50) << " " << END << std::endl;
}

void	test_materia_cloning( void )
{
	std::cout << BOLD << BLUE << "Tests cloning AMateria derived classes:---" << END << std::endl;
	print_line();

	std::cout << BOLD << BLUE << "Create Cure cure" << END << std::endl;
	Cure	cure;
	std::cout << "---> Type: " << cure.getType() << std::endl;
	print_small_line();

	std::cout << BOLD << BLUE << "Create AMateria *materia = cure.clone()" << END << std::endl;
	AMateria	*materia = cure.clone();
	std::cout << "---> Type: "<< materia->getType() << std::endl;
	print_small_line();

	std::cout << BOLD << BLUE << "Delete *materia" << END << std::endl;
	delete materia;

	print_line();

	std::cout << BOLD << BLUE << "Create Ice ice" << END << std::endl;
	Ice	ice;
	std::cout << "---> Type: "<< ice.getType() << std::endl;
	print_small_line();

	std::cout << BOLD << BLUE << "Create AMateria *materia2 = ice.clone()" << END << std::endl;
	AMateria *materia2 = ice.clone();
	std::cout << "---> Type: "<< materia2->getType() << std::endl;
	print_small_line();

	std::cout << BOLD << BLUE << "Delete *materia" << END << std::endl;
	delete materia2;
	print_small_line();

}

int	main( void )
{

//	test_materia_cloning();
//	print_line();

	IMateriaSource* src = new MateriaSource();
	print_small_line();

	src->learnMateria(new Ice());
	print_small_line();

	src->learnMateria(new Cure());
	print_small_line();

	ICharacter* me = new Character("me");
	print_small_line();

	AMateria* tmp;
	tmp = src->createMateria("ice");
	print_small_line();

	me->equip(tmp);
	print_small_line();

	tmp = src->createMateria("cure");
	print_small_line();

	me->equip(tmp);
	print_small_line();

	ICharacter* bob = new Character("bob");
	print_small_line();

	me->use(0, *bob);
	print_small_line();

	me->use(1, *bob);
	print_small_line();

	delete bob;
	print_small_line();

	delete me;
	print_small_line();


	return 0;
}