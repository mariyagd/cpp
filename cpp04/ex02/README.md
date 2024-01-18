[CPP reference](https://en.cppreference.com/w/cpp/language/abstract_class)

## **Fonctions/ Méthodes virtuelles pures**

- Fonction qui n'a pas d'utilité dans la classe de base, mais est utilisée par les classes filles.
- il suffit d'ajouter `= 0` à la fin du prototype de la fonction **virtuelle** même si elle retourne `void`

p.ex. :

```c
class Animal {

// ...
virtual void    makeSound ( void ) const = 0;
// virtual void    makeSound ( void ) const override = 0; // correct
};

```

- la séquence `= 0` est dite *pure specifier*
- La fonction virtuelle pure peut être définie dans le fichier .cpp mais ce n’est pas obligatoire. L'important est que son type soit présent dans le fichier .hpp
- Si on décide de définir la fonction virtuelle pure, la définition doit obligatoirement être en dehors de la définition de la classe:

    - *Exemple :*

      FAUX:

        ```cpp
        // FAUX 
        
        class Animal {
        
        public:
        	virtual void	 makeSound ( void ) const = 0 {
        		std::cout << "Animal sound" << std::endl;
        	}
        	// ...
        };
        ```

      JUSTE

        ```cpp
        // JUSTE
        
        class Animal {
        
        public:
        	virtual void	 makeSound ( void ) const = 0;
        	// ...
        };
        
        void	Animal::makeSound() const {
        	std::cout << "Animal sound" << std::endl;
        }
        ```

- Si la fonction virtuelle pure a été définie, alors elle peut être appelée depuis une classe dérivée à de l’opérateur de résolution `::`, si celle-ci .
    - *Exemple:*

        ```cpp
        #include <iostream>
        
        class Animal {
        
        public:
        	virtual void	 makeSound ( void ) const = 0;
        };
        
        class Dog : public Animal {
        public:
        	void	makeSound ( void ) const;
        };
        
        void	Animal::makeSound() const {
        		std::cout << "Animal sound" << std::endl;
        }
        
        void	Dog::makeSound() const {
        		Animal::makeSound();
        }
        
        int main(void)
        {
        		Dog  dog;
        
        		dog.makeSound();  // prints Animal sound
        }
        ```

- Par contre, si c’est le destructeur qui est une fonction virtuelle pure, sa méthode doit obligatoirement être définie.

## **Classes abstraites**

- Une classe qui possède **au moins une méthode virtuelle pure** est une classe abstraite. Dans l'exemple précédent, `Animal` est une classe abstraite.
- Les classes abstraites sont utilisées pour représenter des concepts généraux (p.ex. Animal, Forme) qui peuvent être utilisés comme classe de base pour des classes plus spécifiques (p.ex. Chien, Chat, Rectangle, Cercle).
- **On ne peut pas créer un d'instance d'une classe abstraite.** Si je pouvais créer un objet `Animal`, alors je pourrais appeler la fonction virtuelle pure `makeSound` qui **n'a pas de corps** et ceci n'est pas possible.
    - Par conséquent:
    - Il n’est pas possible de déclarer un objet de type classe abstrait
    - Il n'est non plus possible de déclarer des membres non-statiques de type classe abstraite.
    - Les types abstraits ne peuvent pas être utilisés comme types de paramètres ni comme types de retour de fonctions
- Par contre, il est possible de déclarer des pointeurs et des références à une classe abstraite.
    - Par conséquent:
    - Il est possible de déclarer un pointeur et une référence de type classe abstraite
    - Il est possible de déclarer des membres non-statiques de type classe abstraite s’ils sont des pointeurs ou des références .
    - Les pointeurs et les références de types abstraits peuvent être utilisés comme types de paramètres ou comme types de retour de fonctions
- *Exemple:*

  p.ex. : Après affectation d'une adresse d'une classe dérivée, je peux appeler la fonction `makeSound()` parce qu'elle est polymorphique !

    ```c
    #include <iostream>
    
    class Animal {
    
    public:
    	virtual void	 makeSound ( void ) const = 0;
    	// ...
    };
    
    class Dog : public Animal {
    public:
    	void	makeSound ( void ) const;
    	// ...
    };
    
    void	Dog::makeSound() const {
    	std::cout << "Dog sound" << std::endl;
    }
    
    int main(void)
    {
    	Dog     dog;
    //  Animal  animal;         // -> donne erreur
    
    	Animal *animal1 = &dog;         //-> oke
    	Animal &animal2 = *animal1;         //-> oke
    
    //  animal.makeSound();     // --> seg.fault
    	animal1->makeSound();     // --> oke
    	animal2.makeSound();     // --> oke
    	
    }
    ```

- Si on crée une classe dérivée de la classe de base abstraite, la méthode virtuelle pure est héritée. Par conséquent, la classe dérivée sera aussi une classe abstraite. Pour éviter ceci, il faut redéfinir la méthode virtuelle pure dans la classe dérivée.