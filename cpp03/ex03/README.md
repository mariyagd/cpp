#### Energy Points
- nécessaires pour attaquer ou se réparer
- si un objet a 0 _energy points_ -> il ne peut pas attaquer ou se réparer mais il est toujours vivant.

#### Hit Points
- points de vie
- si un objet a 0 _hit points_, il est mort! donc il ne peut attaquer ni se réparer.

#### Damage Attack 

- si un objet A attaque un objet B avec X _damage points_, l'objet B subit X dégats, c'est-à-dire il perds X _hit points_.

#### _name 

La classe `ClapTrap` a la variable protégée `_name`.

La classe `DiamondTrap` a sa propre variable `_name` privée. Donc l'accès à `_name` de `ClapTrap` est masqué.
Pour y accéder, il faut utiliser l'opérateur de portée de résolution `::`.

```c++
this->ClapTrap::_name
```

### Multiple Inheritance and Virtual inheritance

[Virtual inheritance](https://isocpp.org/wiki/faq/multiple-inheritance)

Une classe peut hériter de plusieurs classes de base.

- Classe de base intermédiaire

Si classe A est la classe de base de la classe B qui est la classe de base de la classe C, alors B est la classe de base intermédiaire.

Chemin d'héritage :
```c++
class A <---- class B <---- class C
```

####  Appel aux constructeurs

Les constructeurs de la classe dérivée doivent appeler les constructeurs de classes de base dans le même ordre dans lequel elles sont déclarées dans le fichier header.

```c++
class DiamondTrap : public virtual ScavTrap, public virtual FragTrap {
    // ...
};

DiamondTrap::DiamondTrap( void ) : ScavTrap(), FragTrap() {
    // ...
}
```

#### The diamond problem / Dreaded diamond / Deadly diamond of death

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

#### 1) avec l'opérateur de résolution de portée `::`

Exemple : deux fonctions avec la même signature
La classe `FragTrap` hérite la fonction `attack()`  de `ClapTrap`.
La classe `ScavTrap` a sa propre fonction `attack()`.

Laquelle des deux fonctions devrait appeler un objet `DiamondTrap`?

Pour spécifier laquelle choisir, on utilisera l'opérateur de résolution de portée :

```c++
void	DiamondTrap::attack( std::string& target ) {

	ScavTrap::attack(target);
	return;
}
```

#### 2) avec le mot-clé `virtual` lors de la déclaration d'héritage des classes intermédiaires. 

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

#### note:

- En général, on utilise les classes virtuelles lorsque les classes virtuelles et la classe qui en dérive, sont abstraite et contiennent très peu d'informations.
- pour caster, il faut utiliser `dynamic_cast`

#### Ordres des appels des constructeurs et des destructeurs

- Les constructeurs 

Les premiers constructeurs exécutés sont ceux des classes de base virtuelles, peu importe leur position dans la hiérarchie d'héritage. Une fois leur exécution terminée, l'ordre de construction suit généralement la séquence de la classe de base vers la classe dérivée.

P. ex. pour la classe `DiamondTrap` :
```c++
class DiamondTrap : public ScavTrap, public FragTrap {
	// ...
};
```

- Tout d'abord le constructeur par défaut de la classe grand-mère est appelé (c'est un appel automatique à cause du mot-clé `virtual`)
- Ensuite, les constructeurs des classes virtuelles sont appelés dans le même ordre dont leurs classes apparaissent dans la déclaration d'héritage : d'abord `ScavTrap`, ensuite `FragTrap`.
- Ensuite les constructeurs non virtuels sont appelés. Il y en a un seul - celui de `DiamondTrap`.


- Les destructeurs

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

