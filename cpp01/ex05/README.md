# Exercise 06: Harl filter

[CPP REFERENCE](https://en.cppreference.com/w/cpp/language/pointer)

<details><summary>

# Pointeurs

</summary>
- Il n'y a pas de pointeurs sur références. Une référence est déjà un alias pour une variable existante, et elle n'a pas d'adresse mémoire distincte.

Exemple incorrect :
```c++
int a = 10;
int &ref = a;
int *ptr = &ref; Incorrect : Pointeur vers une référence
```
- Pointeur sur pointeur est autorisé.
- Déréférencement : Opérateur d'indirection (*) ou "opérateur de déréférencement" est utilisé pour accéder à la valeur de l'objet auquel un pointeur pointe.

</details>

<details><summary>

## Déclaration d'un pointeur _ordinaire_

</summary>

```c++
* attr(optional) cv(optional) declarator
```
où `cv` = `const` / `volatile`.

P.ex. déclarer `D` comme pointeur sur le type déterminé par `S` :

```c++
S* D
```

</details>

<details><summary>

## Déclaration d'un pointeur sur membre

</summary>

```c++
nested-name-specifier* attr(optional) cv(optional) declarator	
```

P.ex. déclarer `D` comme pointeur sur un membre **non-statique** de la classe `C` et dont le type est déterminé par `S` :

```c++
S C::* D;
```

</details>

<details><summary>

## Pointeur sur fonction

</summary>

Un pointeur sur fonction peut être initialisé avec l'adresse d'une fonction non-membre ou une fonction membre statique. Dans ce cas l'opérateur _adress-of &_ est optionnel, parce qu'il y a une conversion:

```c++
#include <iostream>

void f(int);
void (*p1)(int) = &f;
void (*p2)(int) = f; // same as &f

void	f(int a)
{
	std::cout << a << std::endl;
}

int	main(void)
{
	int	a = 10;
	f(a);
	p1(a);
	p2(a);
	return 0;
}
```
OUTPUT :
```c++
10
10
10
```

- À la différence des fonctions et des références de fonction, **les pointeurs sur fonctions sont des objets** et donc peuvent être stockés dans des tableaux, copiés, assignés etc.

```c++
void (a[10])(int);  // Error: array of functions
void (&a[10])(int); // Error: array of references
void (*a[10])(int); // OK: array of pointers to functions
```

Exemple :
```c++
#include <iostream>

void f(int);
void (*p1[2])(int);
void (*p2[2])(int) = {f, f}; // same as &f

void	f(int a)
{
	std::cout << a << std::endl;
}

int	main(void)
{
	int	a = 10;
	p1[0] = &f;
	p1[1] = f;

	p1[0](a);
	p1[1](a);

	p2[0](a);
	p2[1](a);
	return 0;
}
```

OUTPUT :
```c++
10
10
10
10
```

- La déclaration de pointeur sur fonction peut être simplifiée avec des alias de types :

  - En C++11 avec le mot-clé `using` 

```c++
using identifier attr(optional) = type-id ;
```

```c++
// C++ 11
using F = void(int); // named type alias to simplify declarations
F a[10];  // Error: array of functions
F& a[10]; // Error: array of references
F* a[10]; // OK: array of pointers to functions
```

Exemple : (à compiler avec `-std=c++11`)
```c++
#include <iostream>

using F = void(int);

F f;
F* p1 = &f;             // same as void (*p1)(int) = &f;
F* p2[2] = {f, f};      // same as void (*p2[2])(int) = {f, f}; // same as &f

void	f(int a)
{
	std::cout << a << std::endl;
}

int	main(void)
{
	int	a = 10;
	p1(a);
	p2[0](a);
	p2[1](a);
	return 0;
}
```

OUTPUT :
```c++
10
10
10
```

 - En C++98 avec `typedef`

Exemple :
```c++
#include <iostream>

typedef void F(int);
F f;
F* p1 = &f;             // same as void (*p1)(int) = &f;
F* p2[2] = {f, f};      // same as void (*p2[2])(int) = {f, f}; // same as &f

void	f(int a)
{
	std::cout << a << std::endl;
}

int	main(void)
{
	int	a = 10;
	p1(a);
	p2[0](a);
	p2[1](a);
	return 0;
}
```

OUTPUT :
```c++
10
10
10
```

- On peut déréférencer une fonction ce qui résultera en la lvalue de la fonction pointée

```c++
int f();
int (*p)() = f;  // pointer p is pointing to f
int (&r)() = *p; // the lvalue that identifies f is bound to a reference
r();             // function f invoked through lvalue reference
(*p)();          // function f invoked through the function lvalue
p();             // function f invoked directly through the pointer
```

- On peut utiliser des opérateurs de comparaison sur des pointeurs sur fonctions. Deux pointeurs sur fonctions sont égaux s'ils pointent sur la même fonction.

</details>

<details><summary>

## Pointeurs sur variables membres d'une classe

</summary>

- Un pointeur sur un objet membre non-statique `m` qui est membre de la classe `C` peut être initialisé avec l'expression `&C::m`.
Des expressions comme `&(C::m)` ou `&m` ne forme pas un pointeur vers le membre.

```c++
#include <iostream>

class C
{
public:
	int m;
	C() : m(10) {};
	~C() {};
};

int main(void)
{
	C c;

	int	C::*p = &C::m;
	std::cout << c.*p << std::endl;     // prints 10
}
```

- On peut utiliser ces pointeurs avec les opérateurs d'accès (_pointer-to-member access operators_) `operator.*` et `operator->*`.

Exemple :

```c++
struct C { int m; };
 
int main()
{
    int C::* p = &C::m;          // pointer to data member m of class C
    C c = {7};
    std::cout << c.*p << '\n';   // prints 7
    C* cp = &c;
    cp->m = 10;
    std::cout << cp->*p << '\n'; // prints 10
}
```

</details>

<details><summary>

## Pointeurs sur fonctions membres d'une classe

</summary>

Un pointeur sur une fonction membre non-statique `f` qui est membre de la class `C` peut être initialisé avec l'expression `&C::f`.
Les expressions `&(C::f)` ou `&f` ne forment pas de pointeurs sur fonctions membres.

On peut utiliser ces pointeurs avec les opérateurs d'accès (pointer-to-member access operators) `operator.*` et `operator->*`.

```c++
#include <iostream>

class C
{
public:
	C() {};
	~C() {};
	void f(int n) { std::cout << n << '\n'; }

};

int main(void)
{
	void	(C::*p)(int) = &C::f;
	C	c;
	C*	cp = &c;

	(c.*p)(1);      //prints 1
	(cp->*p)(2);    // prints 2
}
```

</details>

<details><summary>

## Pointeurs null

</summary>

Les pointeurs de tous les types ont une valeur spéciale _null pointer value_. Un pointeur dont la valeur est _null_ ne pointe sur aucun objet ou fonction.
Le comportement lors d'un déréférencement d'un pointeur _null_ est indéfini.
Un pointeur _null_ peut être comparé avec les opérateurs de comparaison.

En général si une fonction reçoit un pointeur comme argument, elle doit vérifier presque toujours si la valeur du pointeur est _null_ et gérer ce cas différemment. 

On peut initialiser un pointer à la valeur _null_ avec:

- un littéral entier zéro
```c++
int* ptr = 0;
```
Cette forme était couramment utilisée avant l'introduction de nullptr (à partir de C++11).

- à partir de C++11 avec `nullptr`, qui est une valeur spéciale de type `std::nullptr_t`.

```c++
int* ptr = nullptr;
```

`nullptr` est conçu pour représenter la valeur nulle de manière plus explicite et sans ambiguïté.

- avec la macro `NULL` qui est une constante symbolique :

```c++

#define NULL 0
//since C++11
#define NULL nullptr
```

Le remplacement de cette macro dépend de l'implémentation.

```c++
int* ptr = NULL;  
```

Il est à noter que l'utilisation de `NULL` est plus courante en C, et en C++, l'utilisation de `nullptr` (introduit à partir de C++11) est préférée pour représenter la valeur nulle des pointeurs, car `nullptr` est spécifiquement conçu à cet effet et évite certaines ambiguïtés liées à `NULL`. Cependant, le remplacement de `NULL` par `nullptr` dépend de la version du langage C++ que vous utilisez.

</details>

<details><summary>

## Const

</summary>

- `cv` = `const` / `volatile`

Dans la déclaration de pointeur :
- Si `cv` apparaît avant `*`, alors `cv` s'applique à l'objet pointé
- Si `cv` apparaît après `*`, alors `cv` s'applique au pointeur déclaré

| syntax | description |
|--------|-------------|
|`const T*` <=> `T const*`|pointeur sur objet constant|
|`T* const`|pointeur constant sur objet|

</details>