## Exercice 00 : Mégaphone

- nom de programme `./megaphone`


- Si le programme n'a pas d'arguments j'affiche le message `* LOUD AND UNBEARABLE FEEDBACK NOISE *`
    
    Exemple:
    ```c++
       > ./megaphone
  
        OUTPUT:
        * LOUD AND UNBEARABLE FEEDBACK NOISE *
    ```
  
- Les arguments du programme `av` sont concaténés dans un objet `args` de type `std::string` et un espace est ajouté entre chaque argument:

    ```c++
    std::string args(av[1]);  
    for (int i = 2; i < ac; i++)
	        args += std::string(" ") + std::string(av[i]);
    ```
  
    Les arguments du programme sont de type `char *` et sont convertis en objets de type `std::string` (
  [  _voir ici comment faire la conversion_](https://www.geeksforgeeks.org/convert-char-to-string-in-cpp/) ).


- Un itérateur `it` parcourt chaque caractère de l'objet `args`. Il commence au début de la chaîne `args.begin()` et continue jusqu'à la fin `args.end()`.

  ```c++
  	for (std::string::iterator it = args.begin(); it != args.end(); it++)
	            std::cout << (char)std::toupper(*it);
  ```

  À chaque itération de la boucle, le caractère actuel pointé par l'itérateur it est converti en majuscule à l'aide de la fonction `std::toupper`. Le résultat est ensuite affiché sur la sortie standard (`std::cout`). Le `(char)` avant `std::toupper(*it)` assure que le résultat est traité comme un caractère. 

   Il est important de noter que le code utilise la fonction `std::toupper` pour convertir **temporairement** chaque caractère en majuscule lors de l'affichage, mais il **ne** modifie **pas** les caractères d'origine dans la chaîne `args`.