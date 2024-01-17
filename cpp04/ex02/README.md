
### Fonctions/ Méthodes virtuelles pures

- Fonction qui n'a pas d'utilité dans la classe de base, mais est utilisée par les classes filles.
- il suffit d'ajouter `= 0` à la fin du prototype de la fonction **virtuelle** même si elle retourne `void`

p.ex. :
```c++
class Animal {

// ...
virtual void    makeSound ( void ) const = 0;

};
```
- la séquence `=0` est dite _pure specifier_

- Il n'y a pas besoin de définir une fonction virtuelle pure dans le fichier .cpp puisque justement, il n'y a pas d'utilité.
L'important est que son type soit présent dans le fichier .hpp

### Classes abstraites

[CPP reference](https://en.cppreference.com/w/cpp/language/abstract_class)

- Une classe qui possède **au moins une méthode virtuelle pure** est une classe abstraite. Dans l'exemple précédent, `Animal` est une classe abstraite.
- **On ne peut pas créer un d'instance d'une classe abstraite.** Si je pouvais créer un objet `Animal`, alors je pourrais essayer d'appeler la fonction virtuelle pure `makeSound` qui **n'a pas de corps** et ceci n'est pas possible.
- Il n'est non plus possible de déclarer des membres non-statiques de type classe abstraite.
- Par contre, il est possible de créer un pointeur de type classe abstraite. Après affectation d'une adresse d'une classe dérivée, je peux appeler la fonction `makeSound()` parce qu'elle est polymorphique !

p.ex. :
```c++
	
class Animal {

    void    makeSound ( void ) const = 0;
    // ...
};

int main(void)
{
    Dog     dog;

//  Animal  animal;         // -> donne erreur
    Animal* animal;         //-> oke

//  animal.makeSound();     // --> seg.fault

    animal = &dog;
    animal.makeSound();     // -> oke
}
```

p.ex. :
```c++
class Animal {

// ...
void    makeSound ( void ) const = 0;

};

classe Dog : public Animal {
	
//  Animal animal;         // -> donne erreur
    Animal* animal;         //-> oke
    // ...
};

```

- Si on crée une classe dérivée de la classe de base abstraite, la méthode virtuelle pure est héritée. Par conséquent, la classe dérivée sera aussi une classe abstraite.
Pour éviter ceci, il faut redéfinir la méthode virtuelle pure dans la classe dérivée.

### Utilisation des classes abstraites

- Les classes abstraites sont utilisées pour représenter des concepts généraux (p.ex. Animal, Forme)
qui peuvent être utilisés comme classe de base pour des classes plus spécifiques (p.ex. Chien, Chat, Rectangle, Cercle).
- 
