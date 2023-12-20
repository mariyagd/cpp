## Exercice 01 : My Awesome
PhoneBook

<details><summary>

#### classe Contact

</summary>

Doit contenir des variables **privées** de type `std::string` pour chaque information d'un contact :
```c++
private:
int 		_index;
std::string	_firstName;
std::string     _lastName;
std::string     _nickName;
std::string     _phoneNumber;
std::string	_darkestSecret;
```

La classe `PhoneBook` va devoir accéder à ces variables pour les lire ou modifier. Cependant, elles sont privées.

Il faut donc créer des fonctions publiques dans la classe `Contact` qui vont être appelées par `PhoneBook` pour pouvoir y accéder.

J'ai donc utilisé des fonctions "getters" et "setters" - une fonction getter et une fonction setter par variable.

```c++
        void		        setIndex(int i);
	std::string&	        setFirstName( void );
	std::string&	        setLastName( void );
	std::string&            setNickName( void );
	std::string&	        setPhoneNumber( void );
	std::string&	        setDarkestSecret( void );

	int			getIndex( void ) const;
	std::string		getFirstName( void ) const;
	std::string		getLastName( void ) const;
	std::string		getNickName( void ) const;
	std::string		getPhoneNumber( void ) const;
	std::string		getDarkestSecret( void ) const;
```

Lors de l'enregistrement du contact, on ne peut pas laisser les champs vides. Dans mon cas, la classe `Contact` va vérifier seule si une des variables est vide et va le signaler à `PhoneBook`avec `true` ou `false`. Si le signal est `false`, `PhoneBook` réinvitera l'utilisateur de remplir le champ.
```c++
	bool			isValidFirstName( void ) const;
	bool			isValidLastName( void ) const;
	bool			isValidNickName( void ) const;
	bool			isValidPhoneNumber( void ) const;
	bool			isValidDarkestSecret( void ) const;
```

La fonction `isValidPhoneNumber()` vérifie non seulement si le champ est vide, mais aussi vérifie que le champ ne contient que des chiffres. A noter que ce champ peut commencer par `+` comme il est usage pour les numéros de téléphone.

Lorsqu'on est dans le menu de recherche de contact, on doit afficher un "preview" de tous les contacts enregistrés et raccourcir les informations à au maximum 10 caractères.
J'ai donc implémentés des fonctions qui vont retourner cette nouvelle chaîne tronquée:

```c++
	std::string		truncFirstName( void ) const;
	std::string		truncLastName( void ) const;
	std::string		truncNickName( void ) const;
```

</details>

<details><summary>

#### classe PhoneBook 

</summary>

- Tous les membres (attributs ou méthodes) sont en privés puisque l'utilisateur ne doit pas pouvoir y accéder.

- Contient un tableau de contacts. Chaque contact va donc appeler son propre constructeur et destructeur de la class `Contact`.

    ```c++
    Contact		_contact[8];
    ```
- une fonction qui affichera en continu le menu du programme (les commandes ADD, SEARCH et EXIT):

    ```c++
  	void 		_userInput( void ) ;
    ```

- fonction qui exécutera la commande ADD

    ```c++
    void		_addContact( void ) ;
    ```

    Cette fonction utilisera des fonctions helpers. Chaque helper invitera l'utilisateur de remplir le champ et vérifiera que le champ n'est pa vide:
    ```c++
	    void		_addFirstName ( void );
	    void		_addLastName ( void );
	    void		_addNickName ( void );
	    void		_addPhoneNumber ( void );
	    void		_addDarkestSecret ( void );
    ```

- fonction qui exécutera la commande SEARCH

    ```c++
	    void		_searchContact( void ) const ;
    ```
    
    Lorsque l'utilisateur est invité de choisir un index pour afficher un contact, je vais vérifier que l'utilisateur a bel et bien saisi un chiffre avec la fonction `_isNumber()`:

    ```c++
       int 		_isNumber( std::string str, int tableSize ) const;
    ```

</details>