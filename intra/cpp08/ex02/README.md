### Déclaration de la classe 'std::stack'

```c++
template<class T, class Container = std::deque< T> > class stack;
```
La classe `stack` utilise un conteneur sous-jacent pour stocker les éléments de la pile.
C'est un conteneur de séquence : `std::vector`, `std::vector<bool>`, `std::list` ou `std::deque`.

Par défaut, la classe `std::deque` est utilisée.

Donc on peut utiliser un conteneur de séquence pour itérer sur les éléments de la pile.


### Définition de la classe `std::stack`:

[voir ici](https://en.cppreference.com/w/cpp/header/stack)

```c++

namespace std 
{
  template<class T, class Container = deque<T>>
		  
  class stack 
  {
  public:
    using value_type      = typename Container::value_type;
    using reference       = typename Container::reference;
    using const_reference = typename Container::const_reference;
    using size_type       = typename Container::size_type;
    using container_type  = Container;
 
  protected:
    Container c;
 
  public:
    stack() : stack(Container()) {}   // constructeur par défaut
    explicit stack(const Container&); // constructeur de copie
	
    // les constructeurs de copie et d'affectation sont générés automatiquement
    // par le compilateur
	
    //...
	
  };
```

---
EXPLICATIONS: 
- La `class Contenainer` est une classe template-id (donc elle peut être `std::deque< T >`, `std::vector`, `std::list`, etc.)
- `protected: Container c;` -> le contenu du conteneur est stocké dans un attribut membre nommé `c`
- `using container_type  = Container;` -> `container_type` est un alias pour le template-id `class Container`
---

On voit qu'il est possible d'accéder au conteneur sous-jacent en utilisant l'attribut `c` de la classe `std::stack`.
Cependant, celui-ci est protégé et ne peut pas être accédé directement.

**Pour résoudre ce problème, on doit créer une classe qui hérite publiquement de `std::stack`. 
Cette classe doit être un template afin de pouvoir prendre en paramètre différents
types de données (`int`, `float`, etc.) mais également les différentes type de classes. Bien sûr il 
ne faut pas oublier de spécifier la classe par défaut `std::deque`!**

La classe sera donc définie comme suit:

```c++
template <class T, class Container = std::deque<T>>

class MutantStack : public std::stack< T, Container >
{
	//...
};

//ou
		
template <typename T, typename Container = std::deque<T>>

class MutantStack : public std::stack< T, Container >
{
    //...
};
```
`MutantStack` héritera le conteneur et les constructeurs de `std::stack`!
Donc il n'y a pas besoin de déclarer un attribut pour le conteneur!

Comme le destructeur et l'operateur d'affectation dans `stack` sont générés automatiquement 
par le compilateur, je ne les redéfinis pas dans `MutantStack`.

```c++
template <typename T, typename Container = std::deque< T > >
class MutantStack : public std::stack< T, Container >
{
public:

	MutantStack( void ) : std::stack<T, Container>() {}
	MutantStack( MutantStack const & src ) : std::stack<T, Container>( src ) {}

};
```

### Méthodes de manipulation du conteneur sous-jacent (code pris de `std::deque` [voir ici](https://en.cppreference.com/w/cpp/header/deque))

Dans une classe qui hérite de `std::stack`, on peut utiliser les méthodes suivantes pour 
manipuler le conteneur sous-jacent:

```c++
    // iterators
    iterator               begin() noexcept;
    const_iterator         begin() const noexcept;
    iterator               end() noexcept;
    const_iterator         end() const noexcept;
    reverse_iterator       rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    reverse_iterator       rend() noexcept;
    const_reverse_iterator rend() const noexcept;
 
    const_iterator         cbegin() const noexcept;
    const_iterator         cend() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend() const noexcept;
```

Ces méthodes retournent des itérateurs.

Normalement on accède aux itérateurs :

```c++
TYPE_CONTAINER::iterator it;

// p.ex.
std::deque<int>::iterator it;
std::vector<int>::iterator it;
std::list<int>::iterator it;
```

Dans notre cas, `TYPE_CONTAINER` est `std::stack<T>::container_type` où `container_type`
est un alias pour `Container`, le template-id de la classe de conteneur (voir plus haut);

L'accès à l'itérateur se fait comme suit:

```c++
std::stack<T>::container_type::iterator it;
```

`container_type` prendra une forme différente selon le type de conteneur utilisé dans `MutantStack`:

```c++
// par défaut -> deque

MutantStack<int> stack;
std::stack< T >::std::deque<T>::iterator it;

// vector

MutantStack<int, std::vector<int>> stack;
std::stack< T >::std::vector<T>::iterator it;

// list

MutantStack<int, std::list<int>> stack;
std::stack< T >::std::list<T>::iterator it;
```

Mais également on peut utiliser le template-id `typename Container` de la classe `MutantStack` pour accéder à l'itérateur:

```c++

template <typename T, typename Container = std::deque< T > >
class MutantStack : public std::stack< T, Container >
{
public:

	MutantStack( void ) : std::stack<T, Container>() {}
	~MutantStack() {}

	// use "iterator" as alias for "typename std::stack< T >::container_type::iterator"
	typedef typename std::stack< T >::container_type ::iterator iterator;
	
	// ou
	
	typedef typename Container::iterator iterator;

```

Le fait d'utiliser un alias grâce à `typedef` ne permettra d'accéder à l'itérateur de la manière suivante:

```c++
MutantStack<int>::iterator it = s.begin();
MutantStack<int>::iterator ite = s.end();
```

Maintenant on peut définir les méthodes `begin` et `end` pour accéder à l'itérateur:

```c++
template <typename T, typename Container = std::deque< T > >
class MutantStack : public std::stack< T, Container >
{
public:

	MutantStack( void ) : std::stack<T, Container>() {}
	~MutantStack() {}

//	typedef typename std::stack< T >::container_type ::iterator iterator;
	typedef typename Container::iterator iterator;

	iterator begin( void ) { return this->c.begin(); }
	iterator end( void ) { return this->c.end(); }

};
```


#### Member types

| Member type     | Definition                 |
|-----------------|----------------------------|
| container_type  | Container                  |
| value_type      | Container::value_type      |
| size_type       | Container::size_type      |
| reference       | Container::reference       |
| const_reference | Container::const_reference |

