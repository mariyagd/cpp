# Exercise 03: Unnecessary violence

`HumanA` prend une référence vers `weapon`. Une référence ne peut pas être réinitialisé une deuxième fois.
Ceci dit que lorsque `HumanA` prend un `weapon` il ne peut pas le changer. Effectivement, cette classe n'a pas de méthode de type `setWeapon` ou `changeWeapon`.

`HumanB` prend un pointeur vers `weapon`. Il pourra donc changer son arme et faire plusieurs fois appel à sa méthode`setWeapon`.
