#include "Project.h"



int	main( void )
{

	test_materia_cloning();
	print_line();

	test_char_equip_unequip();
	print_line();

	test_materia_source_inventory();
	print_line();


//	IMateriaSource* src = new MateriaSource();
//	src->learnMateria(new Ice());
//	src->learnMateria(new Cure());
//	ICharacter* me = new Character("me");
//	AMateria* tmp;
//	tmp = src->createMateria("ice");
//	me->equip(tmp);
//	tmp = src->createMateria("cure");
//	me->equip(tmp);
//	ICharacter* bob = new Character("bob");
//	me->use(0, *bob);
//	me->use(1, *bob);
//	delete bob;
//	delete me;
//	delete src;
//	return 0;

}