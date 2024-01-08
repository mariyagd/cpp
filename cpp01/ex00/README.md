# Exercise 00: BraiiiiiiinnnzzzZ

### `Zombie* newZombie( std::string name );` 

- crée une `Zombie` sur le tas (heap)
- retourne un pointeur
- gestion manuelle de la mémoire : la mémoire doit être libéré avant la fin du programme avec `delete` et le pointeur doit être remis à _null_
- utilisez l'allocation sur le tas lorsque la durée de vie du zombie doit dépasser la portée de la fonction qui le crée.

### `void randomChump( std::string name );` 

- crée un `Zombie` sur la pile (stack)
- l'objet est automatiquement détruit à la fin des scopes dans lequel il est défini
- utilisez l'allocation sur la pile lorsque la durée de vie du zombie est limitée à la portée de la fonction dans laquelle il est créé.