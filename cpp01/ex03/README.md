# Exercise 03: Unnecessary violence

`HumanA` prend une référence vers `weapon`. 
Une référence ne peut pas être réinitialisée une deuxième fois.
Ceci dit que lorsque `HumanA` prend une arme `Weapon` il ne peut pas la changer.
Effectivement, cette classe n'a pas de méthode de type `setWeapon` ou `changeWeapon`.
Ce qu'on peut faire c'est de changer le nom de l'arme `Weapon` déjà prise
avec la fonction `setType()` de `Weapon`. 
Mais il n'est pas possible d'affecter une nouvelle arme.

`HumanB` prend un pointeur vers `weapon`.
Il pourra donc changer son arme en faisant appel à sa méthode`setWeapon()`.
