
### Typage des variables: statiqye et dynamique

Chaque variable possède deux types -> statique et dynamique. Le type statique est celui qu'on peut déterminer en lisant le code source. Ly dynamique est le type réel.

P.ex. Ci-dessous, le type statique de `object` est `Animal*` et son type dynamique est `Dog*`.

```c+
	const Animal* object = new Dog();

	delete dog;
```

### Méthodes (fonctions) polymorphiques `makeSound()`

- les classes `WrongAnimal` et `WrongCat`
  - résolution statique des liens -> le lien entre l'appel à la fonction et sa definition est fait à la **compilation** en fonction du type **statique** de l'objet.

- les classes `Animal`, `Dog` et `Cat`
  - la résolution dynamique des liens -> le lien entre l'appel à la fonction et sa definition est fait à l'**exécution** en fonction du type **réel** de l'objet.
 - C'est le mot-clé `virtual` qui sert à déterminer la nature du lien à effectuer.
 - On dit que **la méthode `makeSound` a un comportement polymorphique.** 

### Résolution statique des liens
- Pour utiliser la résolution dynamique des liens il nous faut :
  - Une méthode virtuelle.
  - Un pointeur ou une référence.
- Il n'est pas nécessaire de mettre `virtual` devant les méthodes des classes filles. Elles sont automatiquement virtuelles par héritage.
- Il ne faut pas mettre virtual dans le fichier .cpp, mais uniquement dans le .hpp
- Toutes les méthodes peuvent être héritées et avoir un comportement polymorphique si on le souhaite.
- Les constructeurs ne peuvent pas être virtuels.
- On ne peut pas appeler de méthode virtuelle dans un constructeur.
- Le destructeur doit toujours être virtuel si on utilise le polymorphisme.

p.ex. Cas de polymorphisme par substitution :

```c+
	const Animal* dog = new Dog();

	delete dog;
```

Ici, on utilise un pointeur de type `Animal*` pour pointer vers un objet de type `Dog`. Cela est possible, car `Dog` est dérivé de `Animal`. En utilisant ce polymorphisme, on peut appeler des méthodes virtuelles sur l'objet `Dog` (comme `makeSound()`) même si le pointeur est de type `Animal*`. L'exécution des méthodes sera résolue dynamiquement au moment de l'exécution en fonction du type réel de l'objet pointé.

Si on ne déclare pas le déstructeur comme virtual, lorsqu'on utilise `delete` le compilateur appellera le déstructeur en fonction de type statique de l'objet pointeur et non du type réel de l'objet pointé ou de la référence à cet objet. Dans ce cas, le compilateur appellera le destructeur de `Animal*`. Ceci entraînerait une mauvaise libération de la mémoire des ressources spécifiques de la classe dérivée. 

Il est crucial de déclarer le destructeur de la classe de base comme `virtual` lorsqu'on utilise du polymorphisme et qu'on alloue dynamiquement des objets. Cela garantit que le destructeur approprié de la classe dérivée est appelé lors de la suppression (utilisation de delete).

### Tableaux dynamiques

Tableau dont la taille peut varier.

```c++
#include <vector>

std::vector <TYPE> NOM;
std::vector <TYPE> NOM(TAILLE);
std::vector <TYPE> NOM(TAILLE, VALEUR); // attribue `VALEUR` à tous les éléments du tableau
```

#### Changer la taille d'un tableau dynamique

- `push_back( VALEUR )` pour ajouter une case à la fin du tableau. La case contient `VALEUR`.
- `pop_back( void )` pour supprimer la dernière case du tableau. Un tableau ne peut pas contenir moins de 0 éléments.
- `size( void )` retourne la taille du tableau en `size_t` 
