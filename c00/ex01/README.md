## Exercice 01 : My Awesome
PhoneBook

#### classe Contact
Doit contenir des variables privées de type `std::string` pour chaque information d'un contact :
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

#### classe PhoneBook 
Doit contenir :
- un tableau de contact avec au maximum 8 contacts `Contact _contact[8]`
- méthode pour ajouter un contact au répertoire et remplir chaque information obligatoirement
- méthode pour rechercher un contact du répertoire, afficher un résumé de tous les contacts et un détaillé d'un contact que l'utilisateur doit spécifier


Au lancement du programme, le répertoire est vide et l’utilisateur peut entrer une
commande. 

### Commandes qui peuvent être entrées:
#### ADD
- first name (prénom), 
- last name (nom de famille)
- nickname (surnom)
- phone number (numéro de téléphone)
- darkest secret (son plus lourd secret). 

Détails : 
- On peut enregistrer des mots séparés par espace
- Les champs d’un contact enregistré ne peuvent pas être vides.
- Le numéro de téléphone doit contenir uniquement de chiffres, et peut commencer avec un seul `+`

#### SEARCH
- Affiche les contacts enregistrés sous la forme d’une liste de 4 colonnes : index, first name, last name et nickname.
- Chaque colonne doit faire 10 caractères de long et se termine par un pipe `|`.
- Si une information a une taille plus grande que 10 caractères, le 10ième caractère doit être remplacé par un point `.`

#### EXIT
- Le programme quitte et les contacts sont perdus à jamais !
- Appel au destructeur