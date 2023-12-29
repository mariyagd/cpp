#include <string>
#include <iostream>

class Student
{
	private:
		std::string _login;

	public:
		Student(std::string const& login) : _login(login)
		{
		}
		
		std::string&	getLoginRef()
		{
			return this->_login;
		}

		std::string const&	getLoginRefConst() const
		{
			return this->_login;
		}

		std::string* getLoginPtr()
		{
			return &(this->_login); //j'envoie l'adresse de _login
		}

		std::string const* getLoginPtrConst() const
		{
			return &(this->_login); // j'envoie l'adresse de _login
		}
};

int	main()
{
	Student bob = Student("bfubar");
	Student const jim = Student("jfubar");

	// je peux utiliser const sur les deux fonctions car je ne modifie pas l'objet
	std::cout << bob.getLoginRefConst() << " " << jim.getLoginRefConst() << std::endl;

	// la fonction getLoginPtrConst retourne une adresse constante
	// donc il faut le dereferncer avec *
	std::cout << *(bob.getLoginPtrConst()) << " " << *(jim.getLoginPtrConst()) << std::endl;

	// je ne peux pas modifier jim parce qu'il est const
	// ici je modifie bob par reference
	bob.getLoginRef() = "bobufar";
	std::cout << bob.getLoginRefConst() << std::endl;

	//ici je modifie bob par pointeur
	*(bob.getLoginPtr()) = "bobbyfubar";
	std::cout << bob.getLoginRefConst() << std::endl;

	return (0);
}
