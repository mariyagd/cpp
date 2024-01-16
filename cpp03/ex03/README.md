
<details><summary> 

### Explications des points

</summary>

#### Energy Points
- nécessaires pour attaquer ou se réparer
- si un objet a 0 _energy points_ -> il ne peut pas attaquer ou se réparer mais il est toujours vivant.

#### Hit Points
- points de vie
- si un objet a 0 _hit points_, il est mort! donc il ne peut attaquer ni se réparer.

#### Damage Attack 

- si un objet A attaque un objet B avec X _damage points_, l'objet B subit X dégats, c'est-à-dire il perds X _hit points_.

</details>

<details><summary> 

### Initialisation des variables dans le constructeur paramétré de `DiamondTrap`

</summary>


| variable      | `ClapTrap` | `ScavTrap` | `FragTrap` | `DiamondTrap`  |
|---------------|------------|------------|------------|----------------|
| hit points    | 10         | 100        | 100        | `FragTrap` 100 |
| energy points | 10         | 50         | 100        | `ScavTrap` 50  |
| attack damage | 10         | 20         | 30         | `FragTrap` 30  |

<details><summary> 

#### Initialisation des membres communes et non-redéfinies

</summary>

Lorsqu'on crée un objet `DiamonTrap` on crée les sous-objets `ScavTrap` et `FragTrap`. L'ordre dans lequel l'héritage a lieu compte !

P. ex. pour la liste d'héritage suivante :

```c++
class DiamondTrap : public ScavTrap, public FragTrap {
	// ...
};
```
Les variables **non-redéfinies** dans `DiamondTrap` et partagées entre `FragTrap` et `ScavTrap` seront héritées par `FragTrap` car il est mentionné en dernier dans la liste d'héritage.

Donc pour le constructeur paramétré suivant :

```c++
DiamondTrap::DiamondTrap( std::string name) : ScavTrap(name), FragTrap(name) {

	std::cout << "DiamondTrap's Parametrized constructor called" << std::endl;
	return;
}

// main
Diamond bob("Bob");
std::cout << bob << std::endl;
```

OUTPUT:
```c++
ClapTrap's Default constructor called
ScavTrap's Parametrized constructor called
FragTrap's Parametrized constructor called
DiamondTrap's Parametrized constructor called

(no name) has 100 hit points, 100 energy points and 30 attack damage points.
Who am I? : My DiamondTrap name is (no_name) and my ClapTrap name is (no_name)

DiamondTrap's Destructor called
FragTrap's Destructor called
ScavTrap's Destructor called
ClapTrap's Destructor called

```

Les variables de `DiamondTrap` sont initialisées à 100 hit points, 100 energy points and 30 attack damage points exactement comme `FragTrap`.

</details>


<details><summary> 

#### Le constructeur par défaut de `ClapTrap`

</summary>


Mais on remarque qu'aucun nom n'a été affecté à `DiamondTrap`. Pourquoi ?

Comme `ScavTrap` et `FragTrap` héritent virtuellement de `ClapTrap`, **le compilateur appelle automatiquement en premier le constructeur par défaut de la classe de base** -> `ClapTrap` et non le constructeur paramétré.

```c++
Or, celui-ci initialise `_name` à une chaîne vide -> `_name ("")`.

```c++
// Initialisation des variables par défaut de ClapTrap

_name = ""
_hitPoints = 0
_energyPoints = 0
_attackDammage = 0

```

Ensuite le constructeur paramétré de `ScavTrap` est appelé et écrase certaines valeurs, mais pas toutes ! Il ne modifie pas `_name`.
**Même si `ScavTrap` appelle le constructeur paramétré de `ClapTrap`, ce dernier n'est pas appelé le compilateur ne l'appelle qu'une seule fois !**
Donc la valeur de `_name` reste inchangée.

```c++
// Affectation de nouvelles valeurs des variables par ScavTrap

_hitPoints = 100
_energyPoints = 50
_attackDammage = 30
```

Ensuite le constructeur paramétré de `FragTrap` est appelé et la même chose se produit (`_name` n'est pas modifié, les autres variables sont écrasées).

```c++
// Affectation de nouvelles valeurs des variables par FragTrap

_hitPoints = 100
_energyPoints = 100
_attackDammage = 50
```

Résultat final :
```c++
_name = ""
_hitPoints = 100
_energyPoints = 100
_attackDammage = 50
```

Pour affecter une valeur à la variable masqué `_name` de `ClapTrap`, on peut soit utiliser l'opérateur de portée de résolution `::` soit appeler explicitement son constructeur paramétré :

```c++
DiamondTrap::DiamondTrap( std::string name) : ScavTrap(name), FragTrap(name) {

	ClapTrap::_name = name.append("_clap_name");
	std::cout << "DiamondTrap's Parametrized constructor called" << std::endl;
	return;
}

// ou

DiamondTrap::DiamondTrap( std::string name) : ClapTrap(name + ".clap_name"), ScavTrap(name), FragTrap(name) {

	std::cout << "DiamondTrap's Parametrized constructor called" << std::endl;
	return;
}
```

</details>

</details>


<details><summary> 

### Multiple Inheritance and Virtual inheritance

</summary>

[Virtual inheritance](https://isocpp.org/wiki/faq/multiple-inheritance)

Une classe peut hériter de plusieurs classes de base.

<details><summary> 

#### Classe de base intermédiaire

</summary>

Si classe A est la classe de base de la classe B qui est la classe de base de la classe C, alors B est la classe de base intermédiaire.

Chemin d'héritage :
```c++
class A <---- class B <---- class C
```

</details>

<details><summary> 

####  Appel aux constructeurs

</summary>

Les constructeurs de la classe dérivée doivent appeler les constructeurs des classes de base dans le même ordre dans lequel elles sont déclarées dans le fichier header.

```c++
class DiamondTrap : public virtual ScavTrap, public virtual FragTrap {
    // ...
};

DiamondTrap::DiamondTrap( void ) : ScavTrap(), FragTrap() {
    // ...
}
```

</details>

<details><summary> 

#### The diamond problem / Dreaded diamond / Deadly diamond of death

</summary>

Ce problème se produit lorsque deux classes intermédiaires héritent de la même classe de base. 

```c++
         A                 D hérite de B et C
       /   \               C et B héritent de A
      /     \
     B       C             -> D hérite deux fois A
      \     /              -> forme de diamant
       \   /
         D	    
```

Dans cet exercice le diamant est le suivant :

```c++
                       class ClapTrap 
                        /          \
                       /            \
                      /              \
                     /                \
       class ScavTrap                  class FragTrap
                     \                 /
                      \               /
                       \             /
                        \           / 
                      class DiamondTrap  

```
Pour un objet de la classe `DiamondTrap` :
 - `ClapTrap` est la classe grand-mère (classe de base)
 - `ScavTrap` est `FragTrap` sont des classes mère (classes de base intermédiaires)
 - `DiamondTrap` est la classe fille (classe dérivée)

Si on déclare un objet `DiamondTrap`, il héritera deux fois les méthodes et les attributs de l'ancêtre commun `ClapTrap` créant ainsi une ambiguïté. Le compilateur ne sait pas lequel des membres communs utiliser _(p.ex. si on veut afficher ou modifier un attribut, le compilateur ne sait pas lequel choisir)_.

En CPP ce problème peut être résolu de deux manières :

<details><summary> 

#### 1) avec l'opérateur de résolution de portée `::`

</summary>

Exemple : deux fonctions avec la même signature
La classe `FragTrap` hérite la fonction `attack()` de `ClapTrap`.
La classe `ScavTrap` a sa propre fonction `attack()`.

Laquelle des deux fonctions devrait appeler un objet `DiamondTrap`?

Pour spécifier laquelle choisir, on utilisera l'opérateur de résolution de portée :

```c++
void	DiamondTrap::attack( std::string& target ) {

	ScavTrap::attack(target);
	return;
}
```

</details>

<details><summary> 

#### 2) avec le mot-clé `virtual` lors de la déclaration d'héritage des classes intermédiaires. 

</summary>

```c++
          A                 D hérite de B et C
        /   \               C et B héritent de A
       /     \
virtual	      virtual 
      B       C             -> D hérite A une seule fois
       \     /              -> problème de diamant résolu
        \   /
          D	    
```

Lorsqu'on utilise l'héritage virtuel avec le mot-clé `virtual`, l'ancêtre commun n'est partagé qu'une seule fois par la classe dérivée. 

```c++
class ScavTrap : public virtual ClapTrap {
	// ...
};

class FragTrap : public virtual ClapTrap {
	// ...
};

class DiamondTrap : public ScavTrap, public FragTrap {
    // ...
};
```
Le mot-clé `virtual` doit être spécifié dans la déclaration d'héritage des classes intermédiaires, et non dans celle de la classe dérivée.
En d'autres termes, nous devons savoir à l'avance que ces classes vont nous servir pour créer une classe dérivée.

**Important :** Lorsqu'on utilise le mot-clé `virtual`, le constructeur par défaut de la classe _grad-mère_ est automatiquement invoqué, même si les classes mères appellent explicitement le constructeur paramétré.

En général, il n'est pas autorisé d'appeler directement le constructeur de la classe grand-mère. Il doit être appelé par les classes mère.
Cependant, si on utilise le mot-clé `virtual`, on peut appeler le constructeur de la classe grand-mère directement !

```c++
// Si le virtual n'est pas utilisé
DiamondTrap::DiamondTrap( void ) : ScavTrap(name), FragTrap(name) {
    // ...
}

// Si virtual est utilisé, on peut écrire de cette manière :
DiamondTrap::DiamondTrap( void ) : ClapTrap(name) {
// ...
}
```

</details>

</details>


<details><summary>

#### note:

</summary>


- En général, on utilise les classes virtuelles lorsque les classes virtuelles et la classe qui en dérive, sont abstraite et contiennent très peu d'informations.
- pour caster, il faut utiliser `dynamic_cast`

</details>


<details><summary>

#### Ordres des appels des constructeurs et des destructeurs

</summary>

- **Les constructeurs**

Les premiers constructeurs exécutés sont ceux des classes de base virtuelles peu importe leur position dans la hiérarchie d'héritage. 
C'est un appel caché _(hidden call)_ dont l'ordre est de gauche à droite de la liste d'héritage.
Une fois leur exécution terminée, l'ordre de construction suit généralement la séquence de la classe de base vers la classe dérivée.

Exemple :

B1 hérite virtuellement de A1

B2 hérite virtuellement de A1 et non-virtuellement de A2

C1 hérite de B1 -> hérite la virtualité de A1

C2 hérite de B2 et de A3 -> hérite la virtualité de A1

X hérite de C1 et C2

```c++
     
      A1   A2    A3
    v/ v\  /    /
    B1    B2   /
    |      \  /
    C1      C2             
    |      /
    |     /
    |    / 
    |   /
    |  /
    | /	
     X               

```

L'ordre d'appel des constructeurs est le suivant :

Appel des constructeurs virtuels :
1) Appel de B1 car virtuel -> appel de A1 via B1
2) Appel de B2 car virtuel -> (appel de A1 via B2 mais A1 a déjà été appelé !) -> appel A2 via B2

Appel des constructeurs non virtuels :
3) Appel de X -> appel de C1 via X qui appelle de la séquence 1) -> appel de C2 via X -> appel de B2 qui appelle la séquence 2)-> appel de A3 via C2

Donc l'ordre d'exécution des constructeurs est:
A1 -> B1 -> C1 -> A2 -> B2 -> A3 -> C2 -> X

P. ex. pour la classe `DiamondTrap` :
```c++
class DiamondTrap : public ScavTrap, public FragTrap {
	// ...
};
```

- Tout d'abord les constructeurs des classes virtuelles sont appelés dans le même ordre dont leurs classes apparaissent dans la déclaration d'héritage : d'abord `ScavTrap`, ensuite `FragTrap`:
- Appel de `ScavTrap` car virtuel -> `ScavTrap` appel le constructeur par défaut de `ClapTrap` (c'est un appel automatique à cause du mot-clé `virtual`)
- Appel de `FragTrap` car virtuel -> _(`FragTrap` n'appelle pas `ClapTrap` car il a été déjà appelé)_
- Appel des constructeurs non virtuels sont appelés. Il y en a un seul - celui de `DiamondTrap`.

Donc l'ordre d'exécution des constructeurs est: `ClapTrap` -> `ScavTrap` -> `FragTrap` -> `DiamondTrap`

- **Les destructeurs**

D'abord les destructeurs des classes non virtuelles sont appelés. Après cela, les classes de base virtuelles sont gérées. Les destructeurs de ces classes de base virtuelles sont exécutés dans l'ordre inverse dans lequel ils apparaissent dans la déclaration d'héritage.

P. ex. pour la classe `DiamondTrap` :
```c++
class DiamondTrap : public ScavTrap, public FragTrap {
	// ...
};
```

- Tout d'abord, les destructeurs non virtuels sont appelés. Il y en a un seul - celui de `DiamondTrap`.
- Ensuite, les destructeurs des classes virtuelles sont appelés dans l'ordre inverse dont leurs classes apparaissent dans la déclaration d'héritage : d'abord `FragTrap`, ensuite `ScavTrap`.
- Le dernier destructeur appelé est celui de `ScavTrap`, qui appelle à son tour le destructeur de `ClapTrap`.

</details>

