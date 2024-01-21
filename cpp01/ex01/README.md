# Exercise 01: Moar brainz!

[How to initialize Array of objects with parameterized constructors in C++](https://www.geeksforgeeks.org/how-to-initialize-array-of-objects-with-parameterized-constructors-in-c/)

[Array Of Objects In C++](https://unstop.com/blog/array-of-objects-in-cpp)

Un tableau d'objets est une collection d'une séquence d'instances d'objets de la même classe. Chaque élément est un objet individuel avec ses propres attributs et méthodes.

## Méthodes de déclaration d'un tableau d'objets:

Pour une classe Zombie:

```c++
# include <string>
# include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie( void );
		Zombie( std::string _name);
		~Zombie( void );

		void	initialize( std::string _name_ );
		void	announce( void );
};

	Zombie::Zombie() : name ("") { 
		std::cout << "Dummy constructor called" << std::endl; 
	}
	
	Zombie::Zombie( std::string _name) : name(std::move(_name)) { 
		std::cout << "Parametrized constructor called" << std::endl; 
	}
	
	Zombie::~Zombie() { 
		std::cout << "Destructor called" << std::endl; 
	}

	void	Zombie::initialize( std::string _name_ ) { 
		this->name = _name_; 
	}
		
	void	Zombie::announce( void ) { 
		std::cout << name << std::endl; 
	}
```

### 1. Déclarer un tableau STATIQUE et l'initialiser en deux lignes en utilisant une fonction d'initialisation

```c++
int main(void)
{
	const int N = 5;
	Zombie zombieHorde[N];

	for (int i = 0; i < N; i++)
		zombieHorde[i].initialize("Bob");

	for (int i = 0; i < N; i++)
		zombieHorde[i].announce();

}
```

OUTPUT:

```c++
Dummy constructor called
Dummy constructor called
Dummy constructor called
Dummy constructor called
Dummy constructor called
Bob
Bob
Bob
Bob
Bob
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called

```

### 2. Déclarer un tableau statique et l'initialiser en une seule ligne

On peut utiliser cette méthode si on connaît à l'avance le nombre de `Zombie` qu'on veut créer. On peut attribuer un nom différent à chaque élément du tableau.

`Zombie("Bob")` crée un objet `Zombie` avec le nom `"Bob"` en utilisant le constructeur paramétrisé et ainsi de suite.

```c++
int main(void)
{
	const int   N = 5;
	Zombie zombieHorde[N] = { Zombie("Bob"), Zombie("Dylan"), Zombie("Rick"), Zombie("Leona"), Zombie("Marta") };

	for (int i = 0; i < N; i++)
		zombieHorde[i].announce();
}
```

OUTPUT:

```c++
Parametrized constructor called
Parametrized constructor called
Parametrized constructor called
Parametrized constructor called
Parametrized constructor called
Bob
Dylan
Rick
Leona
Marta
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
```

### 3. Déclarer un tableau statique de pointeurs

C'est un tableau de pointeurs qui pointent vers des objets `Zombie` préexistants. Ces objets (Bob, Dylan, Rick, Leona, Marta) sont des **instances** individuelles de la classe `Zombie` créées sur la pile, et non sur le tas (comme cela serait le cas avec `new`).

En ajoutant explicitement un pointeur nul (nullptr ou NULL ou 0) à la fin du tableau, on peut déterminer correctement la taille du tableau.



```c++
int main(void)
{
	Zombie	Bob("Bob"), Dylan("Dylan"), Rick("Rick"), Leona("Leona"), Marta("Marta");

	Zombie *zombieHorde[] = {&Bob, &Dylan, &Rick, &Leona, &Marta, 0};

	int size = 0;
	for (int i = 0; zombieHorde[i]; i++)
		size++;
	std::cout << "Taille du tableau: " << size << std::endl;

	for (int i = 0; i < size; i++)
		zombieHorde[i]->announce();

	return 0;
}
```

OUTPUT:

```c++
Parametrized constructor called
Parametrized constructor called
Parametrized constructor called
Parametrized constructor called
Parametrized constructor called
Taille du tableau: 5
Bob
Dylan
Rick
Leona
Marta
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
```

### 4. Déclarer un tableau dynamique avec le mot-clé `new`

#### 4.1 Créer un seul objet avec `new`

Par défaut `new` utilise le constructeur par défaut. Cependant, il est aussi possible d'utiliser le constructeur paramétré.
`new` alloue de l'espace dynamiquement sur le tas et donc il faut utiliser `delete` pour libérer cet espace. Avant la libération de l'espace, le destructeur est appelé.

Il faut tenir compte du fait que `new` retourne un pointeur. Donc pour appeler les méthodes de la classe, on doit utiliser `->` ou bien déréférencer le pointeur.

```c++
int main(void)
{

	Zombie* unZombie = new Zombie ("Bob");

	unZombie->announce();
	// ou (*unZombie).announce();

	delete unZombie;

	return 0;
}
```

OUTPUT:

```c++
Parametrized constructor called
Bob
Destructor called
```

#### 4.2 Créer un tableau d'objets avec `new` et une méthode d'initialisation

Les choses sont différentes lorsqu'on veut allouer un tableau d'objets. En effet, il n'est plus possible d'utiliser le constructeur paramétrisé. On ne peut pas écrire `Zombie* zombieHorde = new Zombie[N](name);`.

Ce qu'on peut faire c'est d'utiliser une méthode d'initialisation. On va d'abord allouer le tableau d'objets avec `new`. Le constructeur par défaut sera appelé. Ensuite, on appellera la méthode d'initialisation afin d'initialiser chaque élément du tableau.

Pour libérer l'espace alloué d'un tableau, il faut utiliser `delete [] nomTableau`

```c++
int main(void)
{
	const int N = 5;
	Zombie* zombieHorde = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombieHorde[i].initialize("Bob");

	for (int i = 0; i < N; i++)
		zombieHorde[i].announce();

	delete [] zombieHorde;

	return 0;
}
```

OUTPUT:

```c++
Dummy constructor called
Dummy constructor called
Dummy constructor called
Dummy constructor called
Dummy constructor called
Bob
Bob
Bob
Bob
Bob
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
```

#### 4.3 Créer un tableau d'objets avec `new` et le constructeur paramétrisé

On peut également utiliser directement le constructeur paramétrisé au lieu de la méthode d'initialisation.

- Dans ce cas, il est obligatoire d'avoir un constructeur par défaut. Il sera appellé lors de l'allocation du tableau `new Zombie[N]`. 
- Ensuite, on appellera le constructeur paramétrisé `Zombie("Bob")` avec l'opérateur d'assignation `=`. 
- Si la classe `Zombie` n'a pas défini explicitement un opérateur d'assignation, le compilateur le générera automatiquement.
- L'opérateur d'assignation crée un objet **temporaire** `Zombie("Bob")` et copie les données dans `zombieHorde[i]`.
- Une fois l'assignation terminée, l'objet temporaire `Zombie("Bob")` sera détruit par le destructeur, car il n'est plus nécessaire. C'est pourquoi on voit le message `"Destructor called"` entre les appels au constructeur paramétré. Il s'agit du destructeur de l'objet temporaire créé lors de l'initialisation.
- 'Zombie("Bob")' est un objet temporaire qui existe pendant l'évaluation de l'expression d'affectation.

**L'objet temporaire existe uniquement pour la durée de l'expression dans laquelle il est créé, dans ce cas précis, pour l'évaluation de l'opération d'assignation. Une fois cette évaluation terminée, le destructeur de l'objet temporaire est appelé, car il n'est plus nécessaire.**

On peut déclarer et initialiser un tableau d'objets en C++ en utilisant des pointeurs. 

```c++
int main(void)
{
	const int N = 5;
	Zombie* zombieHorde = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombieHorde[i] = Zombie("Bob");

	for (int i = 0; i <  N; i++)
		zombieHorde[i].announce();

	delete [] zombieHorde;

	return 0;
}
```

OUTPUT:

```c++
Dummy constructor called
Dummy constructor called
Dummy constructor called
Dummy constructor called
Dummy constructor called
Parametrized constructor called
Destructor called
Parametrized constructor called
Destructor called
Parametrized constructor called
Destructor called
Parametrized constructor called
Destructor called
Parametrized constructor called
Destructor called
Bob
Bob
Bob
Bob
Bob
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
```

#### 4.4 En utilisant `new` et des doubles pointeurs (concept de pointeur sur pointeur)

- Ici, on crée un pointeur qui pointer vers un tableau de pointeurs. 
- Chaque élément du tableau est un pointeur vers un objet `Zombie`. 
- On va d'abord allouer un tableau de `N` pointeurs vers des objets `Zombie` avec `new Zombie*[N]`. À ce stade, les objets `Zombie` eux-mêmes ne sont pas encore créés. 
- Pour chaque élément du tableau `zombieHorde`, on effectue une deuxième allocation dynamique avec `new Zombie("Bob")`. 
Cela crée un nouvel objet `Zombie` et l'adresse de cet objet est stockée dans l'élément correspondant du tableau.

Il est important de faire attention à la gestion de la mémoire. 
Tout d'abord, il faut libérer la mémoire de chaque objet `Zombie`, puis celle du tableau de pointeurs.

```c++
int main(void)
{
	const int N = 5;

	Zombie** zombieHorde = new Zombie*[N];

	for (int i = 0; i < N; i++)
		zombieHorde[i] = new Zombie("Bob");

	for (int i = 0; i < N; i++)
		zombieHorde[i]->announce();

	for (int i = 0; i < N; i++)
		delete zombieHorde[i];

	delete [] zombieHorde;
	return 0;
}
```

OUTPUT:

```c++
Parametrized constructor called
Parametrized constructor called
Parametrized constructor called
Parametrized constructor called
Parametrized constructor called
Bob
Bob
Bob
Bob
Bob
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called
```

### 5. En utilisant `malloc`

- On peut allouer un block de mémoire avec une taille spécifiée avec `malloc`.
- `malloc` retourne un pointeur `void` qui peut être casté. 
- Cette méthode n'appelle pas les constructeurs ni les destructeurs. 
- Ne pas oublier d'utiliser la bibliothèque `stdlib.h` et `free` à la fin du programme.

Il est important de noter qu'en général, il n'est pas une bonne idée d'utiliser `malloc` pour allouer de la mémoire pour des objets en C++. Il faut utiliser `new` et `delete` à la place.

```c++
# include <stdlib.h>

int main(void)
{
	int N = 5;
//	Zombie* zombieHorde = static_cast<Zombie*>(malloc (sizeof (Zombie) * N));
	Zombie* zombieHorde = (Zombie*)(malloc (sizeof (Zombie) * N));

	for (int i = 0; i < N; i++)
		zombieHorde[i].initialize("Bob");

	for (int i = 0; i <  N; i++)
		zombieHorde[i].announce();

	free (zombieHorde);

	return 0;
```

OUTPUT:

```c++
Bob
Bob
Bob
Bob
Bob
```