
### `dynamic_cast`

Safely converts pointers and references to classes up, down, and sideways along the inheritance hierarchy.


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


### Tests:
- Je vérifie si le pointeur est `nullptr` ;
- Si le pointeur est `nullptr`,je ne peux pas l'envoyer dans `indentify(Base &p)` ;
- Je vérifie le multiple héritage.

### Fonction `identify( Base &p )`
- Utiliser une des deux variantes :

```c++
	try {
	    (void) dynamic_cast<A &>(p);
		// ...
	}
	catch (std::exception &e) {}
```

Dans ce cas, si on ne met pas `(void)`, le compilateur émettra un message d'avertissement
que le résultat de la conversion n'est pas utilisé, c'est-à-dire, il n'est pas stocké dans un variable.

Pour éviter cet avertissement on peut soit utiliser `(void)` soit stocker le résultat dans une variable :

```c++
	try {
	    A a = dynamic_cast<A &>(p);
		// ...
	}
	catch (std::exception &e) {}
```

Le résultat de la conversion est stocké dans la variable `a`.
Celle-ci existe uniquement à l'intérieur du scope de `try`.


### Fonction `identify( Base *p )`
 - Deux possibilités :

En cas d'échec `dynamic_cast` retourne `nullptr` ou une exception. On peut directement comparer un pointeur à `nullptr` :


```c++
	try {
	    (void) dynamic_cast<A *>(p);
		// ...
	}
	catch (std::exception &e) {}
```

ou

```c++
	if (dynamic_cast<A *>(p) != nullptr) {
	    // ...
	}
```

