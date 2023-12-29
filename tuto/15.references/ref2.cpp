#include <string>
#include <iostream>

// ajoute " and ponies" a la string
// str est un pointeur vers une string
void	byPtr(std::string* str)
{
	*str += " and ponies";
}

// affiche la string
// str est un pointeur constant vers une string
void 	byConstPtr(std::string const* str)
{
	std::cout << *str << std::endl;
}

// ajoute " and ponies" a la string
// str est une reference vers une string
void	byRef(std::string& str)
{
	str += " and ponies";
}

// affiche la string
// str est une reference constante vers une string
// attention a la position du const
void 	byConstRef(std::string const& str) 
{
	std::cout << str << std::endl;
}

int main(void)
{
	std::string str = "i like butterflies";
	
	std::cout << str << std::endl;

	byPtr(&str);
	byConstPtr(&str);

	str = "i like otters";
	std::cout << str << std::endl;
	byRef(str);
	byConstRef(str);
	return (0);
}
