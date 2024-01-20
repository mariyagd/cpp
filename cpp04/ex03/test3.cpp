#include "Project.h"

void	test_materia_source_inventory( void )
{
	std::cout << BLUE << BOLD << "Tests on MateriaSource' inventory (file test3)" << END << std::endl;
	print_line();

	print_title("Create MateriaSource *materiaSource with new");
	MateriaSource *materiaSource = new MateriaSource();
	std::cout << *materiaSource;
	print_small_line();

	print_title("materiaSource creates \"ice\" with it's emtpy inventory");
	materiaSource->createMateria("ice");
	print_small_line();

	print_title("Create cure with new");
	Cure *cure =  new Cure;
	print_materia_type(*cure);
	print_materia_address(*cure);
	print_small_line();

	print_title("materiaSource learns cure");
	materiaSource->learnMateria(cure);
	std::cout << *materiaSource;
	print_small_line();

	print_title("Compare addresses");
	std::cout << "cure:          " << cure << std::endl;
	std::cout << "materiaSource: " << materiaSource->getAddress(0) << std::endl;
	print_small_line();

	print_title("materiaSource learns the same cure with the same address");
	materiaSource->learnMateria(cure);
	std::cout << *materiaSource;
	print_small_line();

	print_title("materiaSource learns a null pointer");
	materiaSource->learnMateria(0);
	std::cout << *materiaSource;
	print_small_line();

	print_title("materiaSource creates a materia that is not in the inventory");
	std::cout << "Current: " << *materiaSource;
	materiaSource->createMateria("ice");
	print_small_line();

	print_title("materiaSource learns a new materia \"ice\" with new Ice()");
	materiaSource->learnMateria(new Ice());
	std::cout << *materiaSource;
	print_small_line();

	print_title("Create a AMateria *materia from materiaSource");
	AMateria *materia = materiaSource->createMateria("cure");
	print_materia_type(*materia);

	std::cout << "Compare addresses" << std::endl;
	std::cout << "*materia:          " << materiaSource << std::endl;
	std::cout << "materiaSource[0]:  " << materiaSource->getAddress(0) << std::endl;

	print_title("Delete AMateria *materia because it was dynamically allocated");
	delete materia;
	print_small_line();


	print_title("Learn more materias than its inventory capacity");
	std::cout << "Current: " << *materiaSource;
	for (size_t i = 2; i < 6; i++) {
		materiaSource->learnMateria(new Cure());
		print_small_line();
	}
	std::cout << *materiaSource;

	print_title("Constructors tests");
	print_line();

	print_title("Create source2 as a copy of materiaSource");
	MateriaSource source2 = *materiaSource;
	std::cout << "source2: " << source2;

	print_title("Create source3 as a copy assignment of materiaSource");
	MateriaSource source3;
	source3 = *materiaSource;
	std::cout << "source3 " << source3;
	print_small_line();

	print_title("Delete materiaSource because it was dynamically allocated");
	// no need to delete Cure because it is deleted in materiaSource destructor
	delete materiaSource;
	materiaSource = 0;

	print_small_line();
}