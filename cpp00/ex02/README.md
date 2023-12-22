## Exercice 02 : L’emploi de vos rêves

<details><summary>
 
#### But

</summary>

Reconstruire le fichier Account.cpp depuis le le fichier Accoun.hpp et le fichier log.

</details>


<details><summary>

#### Explications

</summary>

Après analyse du fichier log, on peut déjà s'apercevoir de l'ordre dans lequel les fonctions sont appelées.

Les variables ci-dessous correspondent à l'index, l'avoir, nb dépôts et nb retraits pour un **compte individuel**.
Ce sont des variables statiques et seront partagées au sein de la classe et non au sein de l'instance.
```c++
	int		_accountIndex;
	int		_amount;
	int		_nbDeposits;
	int		_nbWithdrawals;
```

Ces variables sont accessibles grâce aux fonctions ci-dessous:
```c++
	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
```

Les variables ci-dessous correspondent à nb total de comptes, l'avoir total que la banque possède, le nb total dépôts effectués et le nb total retraits effectués de **tous les comptes de la banque**
```c++
	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;
```

Ces variables sont accessibles grâce aux fonctions ci-dessous.
```c++
	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
```

Voici l'exemple de `main`:

```c++
#include "Account.hpp"

int main(void)
{
	// CREATION DES COMPTES
	// Les comptes sont créés dans le constructeur
	// index : le numéro de création du compte
	// amount : argent déposé au moment de la création du compte
	// created: confirmer la création
	Account	account1(42);
	Account	account2(54);
	Account	account3(957);
	Account	account4(432);
	Account	account5(1234);
	Account	account6(0);
	Account	account7(754);
	Account	account8(16576);

	// AFFICHER LE BILAN DE TOUS LES COMPTES DE LA BANQUE
	// il faut utiliser les valeurs statiques:
	// account : nb accounts total dans la banque
	// total : le montant total de l'argent en banque
	// deposits : le nombre total des dépôts effectués
	// withdrawals : le nombre total des retraits d'argent effectués
	account1.displayAccountsInfos();

	// AFFICHER LE STATUS DE CHAQUE COMPTE INDIVIDUEL
	// index, amount, deposits, withdrawals
	account1.displayStatus();
	account2.displayStatus();
	account3.displayStatus();
	account4.displayStatus();
	account5.displayStatus();
	account6.displayStatus();
	account7.displayStatus();
	account8.displayStatus();

	// DEPOSER DE L'ARGENT POUR UN COMPTE INDIVIDUEL
	account1.makeDeposit(5);
	account2.makeDeposit(765);
	account3.makeDeposit(564);
	account4.makeDeposit(2);
	account5.makeDeposit(87);
	account6.makeDeposit(23);
	account7.makeDeposit(9);
	account8.makeDeposit(20);

	// AFFICHER LE BILAN DE TOUS LES COMPTES DE LA BANQUE
	account1.displayAccountsInfos();

	// AFFICHER LE STATUS DE CHAQUE COMPTE INDIVIDUEL
	// index, amount, deposits, withdrawals
	account1.displayStatus();
	account2.displayStatus();
	account3.displayStatus();
	account4.displayStatus();
	account5.displayStatus();
	account6.displayStatus();
	account7.displayStatus();
	account8.displayStatus();

	// RETIRER DE L'ARGENT D'UN COMPTE INDIVIDUEL
	// il faut poser une condition pour pouvoir retirer de l'argent
	// p.ex. si le compte a moins de 50 francs, il ne peut pas retirer
	// pour voir l'avoir d'un compte -> checkAmount()
	account1.makeWithdrawal(5);
	account2.makeWithdrawal(34);
	account3.makeWithdrawal(657);
	account4.makeWithdrawal(4);
	account5.makeWithdrawal(76);
	account6.makeWithdrawal(5);
	account7.makeWithdrawal(657);
	account8.makeWithdrawal(7654);

	// AFFICHER LE BILAN DE TOUS LES COMPTES DE LA BANQUE
	account1.displayAccountsInfos();
	
	// FERMETURE DE CHAQUE COMPTE INDIVIDUEL
	// avant la sortie du programme.
	// C'est donc le destructeur qui effectuera la fermeture des comptes
	
	return (0);

}

```

</details>



<details><summary> 

#### Horodatage

</summary>

Dans l'exercice ex01 on a vu la bibliothèque `<iomanip` qui contient la fonction `put_time`.

_Voir ici les liens:_  [iomanip](https://cplusplus.com/reference/iomanip/?kw=iomanip) et [put_time](https://cplusplus.com/reference/iomanip/put_time/)

définition de la fonction `std::put_time`
```c++
template <class charT>/*unspecified*/ put_time (const struct tm* tmb, const charT* fmt);

```

- Le pointeur `tmp` pointe vers un objet de type `struct_tm` qui contient des informations sur la date et l'heure 
- Le pointeur `fmt` définit le format dans lequel ces informations vont être affichés

Pour ce projet:
- `std::put_time(tmp,"%Y%m%d")`  affiche la date au format YYMMDD
- `std::put_time(tmp,"%H%M%S")` affiche l'heure au format HHMMSS

Le code est:

```c++
std::time_t tt = std::chrono::system_clock::to_time_t (std::chrono::system_clock::now());

struct std::tm* ptm = std::localtime(&tt);
std::cout << "[" << std::put_time(ptm,"%Y%m%d")
<< "_" << std::put_time(ptm,"%H%M%S") << "] ";
```
Explications:
- `std::chrono::system_clock::now()` est une fonction membre statique qui donne accès au temps actuel depuis l'horloge du système
- `std::chrono::system_clock::to_time_t` est fonction membre statique qui convertit la valeur obtenue en un objet std::time_t (représentation de en secondes écoulées depuis le 1er janvier 1970 UTC 00:00)
- `std::localtime(&tt);` convertit `time_t tt` en objet `tm`


```c++
struct tm * localtime (const time_t * timer);
```

</details>