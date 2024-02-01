## ****Typage des variables: statique et dynamique****

Chaque variable possède deux types -> statique et dynamique. 

- Le type statique est celui qu'on peut déterminer en lisant le code source.
- Le dynamique est le type réel.

P.ex. Ci-dessous, le type statique de `object` est `Animal*` et son type dynamique est `Dog*`.

```c
	const Animal* object = new Dog();

	delete dog;
```

## **Méthodes polymorphes**

- résolution statique des liens -> le lien entre l'appel à la fonction et sa definition est fait à la **compilation** en fonction du type **statique** de l'objet.
- la résolution dynamique des liens -> le lien entre l'appel à la fonction et sa definition est fait à l'**exécution** en fonction du type **réel** de l'objet.
- C'est le mot-clé `virtual` qui sert à déterminer la nature du lien à effectuer. `virtual` dans ce cas est un spécificateur de fonction.
- On dit qu’une telle **méthode a un comportement polymorphe.**

## Spécificateur de fonction `virtual`

- Le spécificateur `virtual` spécifie qu’une fonction membre **non-statique** est virtuelle et prend en charge la liaison dynamique.
- Pour utiliser la résolution dynamique des liens il nous faut :
  - Une méthode virtuelle.
  - Un pointeur ou une référence.
- Peut être utilisé uniquement dans la déclaration d’une fonction membre non-statique (c-à-d dans la définition de la classe).
- Les fonctions membres statiques et les fonctions non membres ne peuvent pas être virtuelles.
- La fonction héritée dans la classe dérivée est aussi virtuelle.
- Une méthode virtuelle est une fonction membre dont le comportement peut être substitué (redéfini) dans les classes dérivées. Contrairement aux fonctions non virtuelles, le comportement de substitution est préservé même s'il n'y a pas d'information au moment de la compilation sur le type réel de la classe. C'est-à-dire que si une classe dérivée est manipulée à l'aide d'un pointeur ou d'une référence, un appel à une fonction virtuelle redéfinie invoquerait le comportement défini dans la classe dérivée. Un tel appel de fonction est connu sous le nom d'appel de fonction virtuelle ou appel virtuel.
- Il n'est pas nécessaire de mettre `virtual` devant les méthodes des classes filles. Elles sont automatiquement virtuelles par héritage.
- Il ne faut pas mettre virtual dans le fichier .cpp, mais uniquement dans le .hpp
- Toutes les méthodes peuvent être héritées et avoir un comportement polymorphe si on le souhaite.
- Les constructeurs ne peuvent pas être virtuels.
- On ne peut pas appeler de méthode virtuelle dans un constructeur.
- Le destructeur doit toujours être virtuel si on utilise le polymorphisme. Même si les destructeurs ne sont pas hérités, si un destructeur est déclaré comme `virtual` dans la classe de base, le destructeur de la classe fille le substitue toujours. Les objets de type polymorphe alloués dynamiquement  et manipulés avec des pointeurs peuvent ainsi être supprimés correctement avec `delete`.
  - *Exemple*:

    p.ex. Cas de polymorphisme par substitution :

      ```c
          const Animal* dog = new Dog();
      
          delete dog;
      ```

    Ici, on utilise un pointeur de type `Animal*` pour pointer vers un objet de type `Dog`. Cela est possible, car `Dog` est dérivé de `Animal`. En utilisant ce polymorphisme, on peut appeler des méthodes virtuelles sur l'objet `Dog` (comme `makeSound()`) même si le pointeur est de type `Animal*`. L'exécution des méthodes sera résolue dynamiquement au moment de l'exécution en fonction du type réel de l'objet pointé.

    Si on ne déclare pas le destructeur comme `virtual`, lorsqu'on utilise `delete` le compilateur appellera le destructeur en fonction de type statique de l'objet (le type du pointeur ou de la référence) et non du type réel de l'objet (le type de l’objet pointé ou référencé). Dans ce cas, le compilateur appellera le destructeur de `Animal*`. Ceci entraînerait une mauvaise libération de la mémoire des ressources spécifiques de la classe dérivée.

    Il est crucial de déclarer le destructeur de la classe de base comme `virtual` lorsqu'on utilise du polymorphisme et qu'on alloue dynamiquement des objets. Cela garantit que le destructeur approprié de la classe dérivée est appelé lors de la suppression (utilisation de `delete`).

- L’usage est de déclarer le destructeur de toutes la classes de base comme `public` et `virtual` ou comme `protected` et non virtuel.
- L'appel de fonction virtuelle est supprimé à l’aide l'opérateur de résolution de portée **`::`**).
  - *Exemple:*

      ```cpp
      #include <iostream>
      
      //Class defintions-------------------------------
      class Animal {
      
      public :
          virtual void makeSound( void ) const;
      };
      
      class Dog : public Animal {
      
      public:
          void	makeSound( void ) const override; // override is optional C++11
      };
      
      //Function definitions----------------------------
      void	Animal::makeSound() const {
          std::cout << "Animal sound" << std::endl;
      }
      
      void	Dog::makeSound() const {
          std::cout << "Dog sound" << std::endl;
      }
      
      // main--------------------------
      int main( void )
      {
          Dog	dog;
      
          dog.makeSound();			// prints Dog sound
          dog.Animal::makeSound();	// prints Animal sound
      }
      ```

## Tableaux dynamiques

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

