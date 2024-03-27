
### `dynamic_cast`

- Safely converts pointers and references to classes up, down, and sideways along the inheritance hierarchy.
- Est principalement utilisé pour les conversions entre des classes de base et des classes dérivées polymorphiques
(au moins une fonction virtuelle).
- Dans un langage de programmation orienté objet, une variable peut se référer à un objet de son propre type 
ou à un objet d'un type dérivé. La "vérification dynamique des types" est le processus par lequel le langage 
détermine le type réel de l'objet auquel une variable se réfère à un moment donné lors de l'exécution du programme.

Ne peut pas être utilisé sur des pointeurs nulls, parce qu'il n'y a pas d'objet réel sur lequel effectuer la conversion :
```c++
	if (p == nullptr)
	{
		std::cout << "Null pointer doesn't point to an instance of a class" << std::endl;
		return;
	}
```

### `static_cast`
A downcast can also be performed with `static_cast`, which avoids the cost of the runtime check,
but **it's only safe if the program can guarantee** (through some other logic) that the object
pointed to by expression is definitely Derived.


### Fonction `identify( Base &p )`
- Lorsque `dynamic_cast` est utilisé pour convertir des références et que la conversion échoue, 
il lance une exception de type `std::bad_cast`.


```c++
	try 
	{
	    (void) dynamic_cast<A &>(p);
		// ...
	}
	catch (const std::bad_cast &e) {}
```

Dans ce cas, si on ne met pas `(void)`, le compilateur émettra un message d'avertissement
que le résultat de la conversion n'est pas utilisé, c'est-à-dire, il n'est pas stocké dans un variable.

Pour éviter cet avertissement, on peut soit utiliser `(void)` soit stocker le résultat dans une variable :

```c++
	try {
	    A a = dynamic_cast<A &>(p);
		// ...
	}
	catch (const std::bad_cast &e) {}
```

Le résultat de la conversion est stocké dans la variable `a`.
Celle-ci existe uniquement à l'intérieur du scope de `try`.


### Fonction `identify( Base *p )`
 - Deux possibilités :

En cas d'échec `dynamic_cast` retourne `nullptr`.

```c++
	if (dynamic_cast<A *>(p) != nullptr) {
	    // ...
	}
```

