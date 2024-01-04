# Exercise 04: Sed is for losers

[Openclassrooms](https://openclassrooms.com/fr/courses/1894236-apprenez-a-programmer-en-c/7534171-lisez-et-modifiez-des-fichiers)

- Commande pour vérifier :

```c++
grep -Eo 'word[^[:space:]]*' file 
```

<details><summary>

## Entrée/sortie avec des fichiers : `ofstream`, `ifstream`, `fstream`

</summary>

C++ a trois classes pour la manipulation des entrées et des sorties vers/depuis des fichiers :

| `ofstream`              | `ifstream`      | `fstream`      |
|-------------------------|-----------------|----------------|
| écrire dans un fichier  | lire un fichier | lire et écrire |


Ces classes sont dérivées directement ou indirectement des classes `istream` et `ostream`.
Or, nous avons déjà utilisé des objets dont les types étaient ces classes : `cin` est un objet de la classe `istream` et `cout` est un objet de la classe `ostream`.
Nous pouvons donc utiliser les flux de fichiers de la même manière que nous utilisons déjà `cin` et `cout`, avec la seule différence que nous devons associer ces flux à des fichiers physiques. Voyons un exemple :

```c++
#include <iostream>
#include <fstream>

int main () 
{
  std::ofstream myfile;
  myfile.open ("example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}
```

</details>


<details><summary>

## Ouvrir un fichier

</summary>

La première opération qu'on performe sur un objet de ces classes est de les associer à des vrais fichiers existants. C'est ce qu'on appelle "ouvrir un fichier".
Dans un programme, un fichier ouvert est représenté par un "flux" (c-à-d un objet de ces classes, dans l'exemple précédent le flux est `myfile`) et toute opération d'entrée ou de sortie effectuée sur cet objet de flux sera appliquée au fichier physique qui lui est associé.

Afin d'ouvrir un fichier avec un objet de flux (_stream object_) on utilise sa fonction membre `open`:

```c++
open(filename, mode);

// declaration c++98
void open (const   char* filename, ios_base::openmode mode = ios_base::out);

// declaration c++11
void open (const string& filename, ios_base::openmode mode = ios_base::out);

```

où:

- `filename` est un `char *` qui représente le nom du fichier à ouvrir. Si le nom du fichier est stocké dans un objet `std::string` alors il faut utiliser la fonction `c_str()` pour le convertir en `char *` avec la terminaison `\0`.

Exemple avec c++98:
```c++
#include <fstream>

int main() 
{
    // Utilisation avec const char*
    const char* fileName1 = "example.txt";
    std::ifstream inputFile1(fileName1);

    // Utilisation avec std::string et c_str()
    std::string fileName2 = "example.txt";
    std::ifstream inputFile2(fileName2.c_str());

    // ...

    return 0;
}
```

- `mode` est un paramètre optionnel qui doit être utilisé avec en combinaison avec un des flags suivants:

| flag               | descritpion                                                                                                                                   |
|--------------------|-----------------------------------------------------------------------------------------------------------------------------------------------|
| `std::ios::in`     | Ouvrir pour des opérations d'entrée                                                                                                           |
| `std::ios::out`    | Ouvrir pour des opérations d'sortie                                                                                                           |
| `std::ios::binary` | Ouvrir en mode binaire                                                                                                                        |
| `std::ios::ate`    | Définir la position initiale à la fin du fichier (EOF). Si ce drapeau n'est pas activé, la position initiale est le début du fichier.         |
| `std::ios::app`    | Toutes les opérations de sortie sont effectuées à la fin du fichier, ajoutant le contenu à celui actuellement présent dans le fichier.        |                                                                                                                  
| `std::ios::trunc`  | Si le fichier est ouvert pour des opérations de sortie et qu'il existait déjà, son contenu précédent est supprimé et remplacé par le nouveau. |           


Tous ces flags peuvent être combinés avec l'opérateur OR `|`.

La fonction membre `open` des classes `ofstream`, `ifstream` et `fstream` a un mode par défaut qui est utulisé si le fichier est ouvert sans préciser l'argument `mode`:

| classe     | mode par défaut       | type           |
|------------|-----------------------|----------------|
| `ofstream` | `ios::out`            | écrire         |
| `ifstream` | `ios::in`             | lire           |
| `fstream`  | `ios::in \| ios::out` | lire et écrire |


Comme la tâche principale qui est effectuée sur un flux de fichier (_file stream_) est d'ouvrir le fichier, ces trois classes incluent un constructeur qui automatiquement appelle la fonction membre `open` avec les mêmes paramètres.

Constructeur par défaut:
```c++
ofstream();
```

Constructeur d'intialization:
```c++
explicit ofstream (const char* filename, ios_base::openmode mode = ios_base::out);
```

Il est donc possible de déclarer un objet `myfile` et d'ouvrir le fichier en appelant la fonction membre `open` de la classe ou bien en appelant le constructeur :

```c++
ofstream myfile;
myfile.open ("example.bin", ios::out | ios::app | ios::binary);

// ou

ofstream myfile ("example.bin", ios::out | ios::app | ios::binary);
```

Les deux manières d'ouvrir un fichier sont valides et équivalentes.

</details>

<details><summary>

## Vérifier l'ouverture d'un fichier

</summary>

- avec la fonction membre `is_open()`

Pour vérifier si un flux a ouvert un fichier avec succès, on peut appeler la fonction membre `is_open`. Cette fonction retourne un booléen `bool`. `true` si l'objet de flux (_stream object_) est associé à un fichier ouvert, ou `false` si ce n'est pas le cas :

```c++
std::ofstream myFile ("text.txt")

if (myFile.is_open()) 
{
	// ok, proceed with output 
}
else
{
    // handle errors	
}
```

- avec l'opérateur de conversion vers `bool` de l'objet

L'opérateur de conversion vers `bool` teste l'état de l'objet. Il est défini dans la classe de base `std::ios_base`.
Si l'objet est dans un état valide (par exemple, si l'ouverture du fichier s'est déroulée avec succès), il retourne `true`. Sinon, il retourne `false`.

```c++
std::ofstream myFile ("text.txt")

if (myFile) 
{
	// ok, proceed with output 
}
else
{
    // handle errors	
}
```

</details>


<details><summary>

## Fermer un fichier

</summary>

Lorsqu'on a terminé avec les opérations d'entrée et de sortie sur un fichier, on doit le fermer afin que le système d'exploitation soit notifié et que ses ressources deviennent à nouveau disponibles.

Pour faire ça, on appelle la fonction membre `close` qui vide les tampons associés et ferme le fichier :

```c++
myfile.close();
```

Une fois cette fonction appelée, le _stream object_ peut être réutilisé pour ouvrir un autre fichier, et le fichier initial est disponible pour l'ouverture par d'autre processus.

Dans le cas où un objet est détruit pendant qu'il est toujours associé à un fichier ouvert, le destructeur va automatiquement appeler la fonction `close`.

Ceci veut dire qu'on peut fermer un fichier soit en appelant la fonction `close` soit en atteignant la destruction de l'objet!

</details>


<details><summary>

## Fichiers text

</summary>

Les flux de fichiers text sont ceux qui n'ont pas précisé le flag `ios::binary` à leur mode d'ouverture.
Ces fichiers sont conçus pour stocker du text et donc toutes les valeurs qui y sont entrées ou sorties peuvent subir certaines transformations de format, qui ne correspondent pas nécessairement à leur valeur binaire littérale.

</details>


<details><summary>

## Position du curseur dans le text : _put_ et _get positions_

</summary>

Tous les _stream objects_ gardent au moins une position interne :

- `ifstream` (lire) comme `istream` (utilisé par `cin`) conserve sa **get position** ou position de lecture qui indique l'endroit dans le fichier où la prochaine opération de lecture doit s'effectuer.
- `ofstream` (écrire) comme `ostream` (utilisé par `cout`) conserve sa **put position** ou position d'écriture qui indique l'endroit dans le fichier où l'élément prochain doit être écrit.
- `fstream` conserve les deux **put** et **get position** comme `iostream`.

Ces positions indiquent l'endroit dans le flux où la prochaine opération d'écriture ou de lecture doit être effectuée. Ces positions peuvent être observées ou modifiées avec une des fonctions membres suivantes :

#### 1. Position actuelle du curseur = position actuelle de lecture ou d'écriture :
- `tellg()` -> `ifstream` -> la **get position** (position de lecture) actuelle 
- `tellp()` -> `ofstream` -> la **put position** (position d'écriture) actuelle

#### 2. Déplacer le curseur

Déplacer la position de lecture ou d'écriture à une position donnée `position` en comptant à partir du début du fichier :

- `seekg( position )` -> `ifstream` -> modifier la **get position** (position de lecture) 
- `seekp( position )` -> `ofstream` -> modifier la **put position** (position d'écriture) 

#### 3. Déplacer le curseur en _offset_ 

Déplacer la position de lecture ou d'écriture `nbCaractères` à partir d'un point `pointDepart` :

- `seekg( nbCaracteres, pointDepart )` -> `ifstream` -> modifier la **get position** (position de lecture)
- `seekp( nbCaracteres, pointDepart )` -> `ofstream` -> modifier la **put position** (position d'écriture)


où `pointDepart` détermine le point à partir duquel on compte le `nbCaracteres`:

| direction  | descritpion                          |
|------------|--------------------------------------|
| `ios::beg` | offset depuis le début du flux     |
| `ios::cur` | offset depuis la position actuelle |
| `ios::end` | offset depuis la fin du flux       |


Exemple d'utilisation :

```c++
#include <iostream>
#include <fstream>
#include <string>

int	main(void)
{
	std::ifstream  monFlux("text.txt");
	if (!monFlux)
	{
		std::cerr << "Erreur lors de l'ouverture" << std::endl;
		return (1);
	}

	std::streampos current;

	current = monFlux.tellg();
	std::cout << "A l'ouverture du fichier le curseur se trouve à: " << current << std::endl;

	monFlux.seekg(10);
	current = monFlux.tellg();
	std::cout << "Apres déplacement de 10 octets, le curseur se trouve à: " << current << std::endl;

	monFlux.seekg(20, std::ios::beg);
	current = monFlux.tellg();
	std::cout << "Apres déplacement de 20 octets depuis le debut, le curseur se trouve à: " << current << std::endl;
	return 0;
}
```

OUTPUT:

```c++
A l'ouverture du fichier le curseur se trouve à: 0
Apres déplacement de 10 octets, le curseur se trouve à: 10
Apres déplacement de 20 octets depuis le debut, le curseur se trouve à: 20
```

</details>


<details><summary>

## Obtenir la taille d'un fichier

</summary>

On peut utiliser les fonctions `tellg`, `tellp`, `seekp`, `seekg` pour obtenir la taille d'un fichier (nombre de caractères).

On place le curseur à la fin du fichier avec `seekg` ou `seekp` puis on y soustrait la position actuelle du curseur :

```c++
#include <iostream>
#include <fstream>
#include <string>

int main(void)
{
	// open a file for reading
	std::ifstream myFile("text.txt");
	std::streampos begin, end, size;

	begin = myFile.tellg();
	std::cout << "Current get position: " << begin << std::endl;

	//change the get position
	myFile.seekg(0, std::ios::end);

	end = myFile.tellg();
	std::cout << "Current get position: " << end << std::endl;

	size = end - begin;
	std::cout << "Size of file is: " << size << std::endl;

	myFile.close();
	return 0;

}
```

</details>


<details><summary>

## Tampons et synchronisation

</summary>

Lorsque vous manipulez des flux en programmation, vous travaillez généralement avec des tampons (buffers). Les tampons sont des zones de mémoire temporaires utilisées pour stocker des données en transit entre le programme et le fichier. Les opérations de lecture et d'écriture ne sont pas nécessairement effectuées directement sur le fichier physique à chaque appel. Au lieu de cela, elles interagissent avec le tampon, et c'est seulement à des moments spécifiques, tels que la fermeture du fichier ou l'appel explicite à une fonction de vidage (flush), que le contenu du tampon est synchronisé avec le fichier. Cela permet d'optimiser les performances en minimisant les accès au fichier physique.


Lorsque le buffer est vidé, toutes les données du buffer sont écrites dans le fichier si c'est un flux de sortie. Ce processus est appelé **synchronisation** et a lieu sous certaines circonstances :

La synchronisation est un processus de mise à jour de l'état du fichier physique pour refléter les modifications apportées dans le tampon. La synchronisation a lieu :

- lorsque le fichier est fermé : avant de fermer un fichier, tous les buffers qui n'ont pas encore été vidés sont synchronisés et les données sont lues ou écrites dans le fichiers.
- lorsque le buffer est plein : les buffers ont une certaine taille. Lorsqu'un buffer est plein, il est automatiquement synchronisé.
- explicitement avec des manipulateurs t.q. `flush` et `endl`.
- explicitement avec la fonction membre `sync()`.


</details>


<details><summary>

## Lire un fichier

</summary>

- Utiliser `ifstream` pour lire un fichier. Il faut également tester l'ouverture, afin d'éviter les erreurs.

- Il y a trois manières différentes de lire un fichier :

  - Ligne par ligne, en utilisant `getline()` (prend toute la ligne sans le dernier `\n`) 
  - Mot par mot, en utilisant les chevrons `>>` (ne prends pas les _white spaces_ `\n` y compris)
  - Caractère par caractère, en utilisant `get()` (prends tous les caractères y compris les _white spaces_ et le dernier `\n`)

### 1. Lecture d'un fichier ligne par ligne avec `getline()`

```c++
string ligne;
getline(monFlux, ligne); //On lit une ligne complète
```

Pour lire jusqu'à la fin du fichier, utiliser `while (getline(monFlux, ligne))` :

```c++
#include <iostream>
#include <fstream>
#include <string>

int	main(void)
{
	std::ifstream  monFlux("text.txt");
	if (!monFlux)
	{
		std::cerr << "Erreur lors de l'ouverture" << std::endl;
		return (1);
	}

	std::string ligne;
	while (getline(monFlux, ligne))
		std::cout << ligne << std::endl;
	return 0;
}
```

Ne pas oublier que le dernier `\n` de la ligne n'est pas pris en compte. C'est pourquoi on ajoute `std::endl;`.

En plus de lire une ligne, la fonction `getline()` renvoie un `bool` indiquant si l'on peut continuer à lire. Si la fonction renvoie `true`, tout va bien, la lecture peut continuer. Si elle renvoie `false`, c'est qu'on est arrivé à la fin du fichier ou qu'il y a eu une erreur. Dans les deux cas, il faut s'arrêter de lire.


### 2. Lecture d'un fichier mot par mot avec les chevrons  `>>`

```c++
double nombre;
monFlux >> nombre; //Lit un nombre à virgule depuis le fichier
string mot;
monFlux >> mot;    //Lit un mot depuis le fichier
```

Cette méthode lit ce qui se trouve entre l'endroit où l'on se situe dans le fichier et l'espace suivant. Ce qui est lu est alors traduit en double  , int ou string  , selon le type de variable dans lequel on écrit.

Pour lecture jusqu'à la fin du fichier: `while (monFlux >> mot)`

```c++
#include <iostream>
#include <fstream>
#include <string>

int	main(void)
{
	std::ifstream  monFlux("text.txt");
	if (!monFlux)
	{
		std::cerr << "Erreur lors de l'ouverture" << std::endl;
		return (1);
	}

	std::string mot;
	while (monFlux >> mot)
		std::cout << mot << std::endl;
	return 0;
}
```

Ici les _white spaces_ y compris les `\n` ne sont pas capturé. On affichera un mot par ligne à cause de `std::endl;`  

### 3. Lecture d'un fichier caractère par caractère avec  `get()`

```c++
char a;
monFlux.get(a);
```

Pour lire chaque caractère jusqu'à la fin du fichier, utiliser `while (monFlux.get(c))` :

```c++
#include <iostream>
#include <fstream>

int	main(void)
{
	std::ifstream  monFlux("text.txt");
	if (!monFlux)
	{
		std::cerr << "Erreur lors de l'ouverture" << std::endl;
		return (1);
	}

	char c;
	while (monFlux.get(c))
		std::cout << c;
	return 0;
}
```

On affiche tous les caractères, y compris le dernier `\n`.

### 4. Changer de mode de lecture 

Lorsqu'on veut passer de la lecture mot par mot à la lecture ligne par ligne, il faut utiliser `nomDuFlux.ignore()` : 

```c++
#include <iostream>
#include <fstream>
#include <string>

int	main(void)
{

	std::ifstream  monFlux("text.txt");
	if (!monFlux)
	{
		std::cerr << "Erreur lors de l'ouverture" << std::endl;
		return (1);
	}

	std::string mot;
	monFlux >> mot;
	std::cout << mot << std::endl;

	monFlux.ignore();

	std::string ligne;
	getline(monFlux, ligne);
	std::cout << ligne << std::endl;
	
	return 0;
}
```

</details>


<details><summary>

## `open` et `close`

</summary>

- Les fichiers ouverts sont automatiquement refermés lorsque l'on sort du bloc où le flux est déclaré.

```c++
void f()
{
   ofstream flux("C:/Nanoc/data.txt");  //Le fichier est ouvert

   //Utilisation du fichier

}  //Lorsque l'on sort du bloc, le fichier est automatiquement refermé
```

- Pour fermer le fichier avant sa fermeture automatique, il faut utiliser la fonction `close()` des flux.

```c++
void f()
{
   ofstream flux("C:/Nanoc/data.txt");  //Le fichier est ouvert

   //Utilisation du fichier

   flux.close();  //On referme le fichier
                  //On ne peut plus écrire dans le fichier à partir d'ici
}
```

- De la même manière, il est possible de retarder l'ouverture d'un fichier après la déclaration du flux, en utilisant la fonction `open()` :

```c++
void f()
{
   ofstream flux;  //Un flux sans fichier associé

   flux.open("C:/Nanoc/data.txt");  //On ouvre le fichier C:/Nanoc/data.txt

   //Utilisation du fichier

   flux.close();  //On referme le fichier
                  //On ne peut plus écrire dans le fichier à partir d'ici
}
```
Certaines personnes aiment utiliser `open()` et `close()`, alors que ce n'est pas nécessaire. On peut ainsi mieux voir où le fichier est ouvert et où il est refermé. C'est une question de goût, à vous de voir ce que vous préférez.


</details>


<details><summary>

## Déplacez le curseur dans le fichier

</summary>

Lorsque l'on écrit la ligne suivante : `ifstream fichier("C:/Nanoc/scores.txt")` le fichier `C:/Nanoc/scores.txt` est ouvert, et le curseur est placé tout au début du fichier. 

### Trouvez la position du curseur

Il existe une fonction permettant de savoir à quel octet du fichier on se trouve. Autrement dit, elle permet de savoir à quel caractère du fichier on se situe.

| Pour `ifstream` | Pour `ofstream` |
|-----------------|-----------------|
| `tellg()`       | `tellp()`       |

```c++
ofstream fichier("C:/Nanoc/data.txt");

int position = fichier.tellp(); //On récupère la position

cout << "Nous nous situons au " << position << "eme caractere du fichier." << endl;
```

### Déplacez-vous dans un fichier


| Pour `ifstream` | Pour `ofstream` |
|-----------------|-----------------|
| `seekg()`       | `seekp()`       |

Ces fonctions reçoivent deux arguments :
- Une position dans le fichier.
- Et un nombre de caractères à ajouter à cette position :

```c++
flux.seekp(nombreCaracteres, position);
```

Les trois positions possibles sont :
- Le début du fichier : `ios::beg`
- La fin du fichier : `ios::end`
- La position actuelle : `ios::cur`

- Si, par exemple, je souhaite me placer 10 caractères après le début du fichier, j'utilise `flux.seekp(10, ios::beg);`. 
- Si je souhaite aller 20 caractères plus loin que l'endroit où se situe le curseur, j'utilise `flux.seekp(20, ios::cur);`.

## Trouvez la taille d'un fichier

Pour connaître la taille d'un fichier, on se déplace à la fin et on demande au flux de nous dire où il se trouve:

```c++
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fichier("C:/Nanoc/meilleursScores.txt");  //On ouvre le fichier
    fichier.seekg(0, ios::end);  //On se déplace à la fin du fichier

    int taille;
    taille = fichier.tellg();
    //On récupère la position qui correspond donc à la taille du fichier !

    cout << "Taille du fichier : " << taille << " octets." << endl;

    return 0;
}
```


</details>
