# Exercise 04: Sed is for losers

[Openclassrooms](https://openclassrooms.com/fr/courses/1894236-apprenez-a-programmer-en-c/7534171-lisez-et-modifiez-des-fichiers)

- Commande pour vérifier :

```c++
grep -Eo 'word[^[:space:]]*' file 
```

<details><summary>

## Entrée/sortie avec des fichiers : `ofstream`, `ifstream`, `fstream`

</summary>



</details>

<details><summary>

## `ofstream` pour ecrire dans un fichier

</summary>

`#include <fstream>` -> correspond à "file stream" ou "flux vers les fichiers".

- les flux sont en réalité des objets.
- On déclare un flux exactement de la même manière qu'une variable, une variable dont le type serait `ofstream`, et dont la valeur serait le chemin d'accès du fichier à lire. Le chemin est absolu ou relatif. 
- Si le fichier n'existait pas, le programme le créerait automatiquement ! Par contre, il faut que le dossier existe. P.ex., le dossier `C:/Nanoc/C++/Fichiers` doit exister. Si ce n'est pas le cas, rien ne sera écrit.
- Si le nom du fichier est contenu dans une chaîne de caractères `string`, il faut utiliser la fonction `c_str()` lors de l'ouverture du fichier :

```c++
string const nomFichier("C:/Nanoc/scores.txt");

ofstream monFlux(nomFichier.c_str());
//Déclaration d'un flux permettant d'écrire dans un fichier.
```

- Pour tester si l'ouverture s'est bien passée, on utilise la syntaxe `if(monFlux)`

```c++
ofstream monFlux("C:/Nanoc/scores.txt");  //On essaye d'ouvrir le fichier

if(monFlux)  //On teste si tout est OK
{
    //Tout est OK, on peut utiliser le fichier
}
else
{
    cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
}
```

- Si le fichier existe déjà, il sera supprimé et remplacé par ce que vous écrivez, ce qui est problématique si l'on souhaite ajouter des informations à la fin d'un fichier préexistant. Pour pouvoir écrire à la fin d'un fichier, il faut le spécifier lors de l'ouverture en ajoutant un deuxième paramètre à la création du flux :

```c+++
ofstream monFlux(nomFichier.c_str(), ios::app);
```
(`app` est raccourci pour append)

</details>


<details><summary>

## Lire un fichier

</summary>

- utiliser un ifstream au lieu d'un ofstream  . Il faut également tester l'ouverture, afin d'éviter les erreurs

```c++
ifstream monFlux("C:/Nanoc/C++/data.txt");  //Ouverture d'un fichier en lecture

if(monFlux)
{
    //Tout est prêt pour la lecture.
}
else
{
    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
}
```

- Il y a trois manières différentes de lire un fichier :

-- Ligne par ligne, en utilisant `getline()` (sans le dernier `\n`) 
-- Mot par mot, en utilisant les chevrons `>>`  
-- Caractère par caractère, en utilisant `get()`

### 1. Lecture d'un fichier ligne par ligne avec `getline()`

```c++
string ligne;
getline(monFlux, ligne); //On lit une ligne complète
```

### 2. Lecture d'un fichier mot par mot avec les chevrons  `>>`

```c++
double nombre;
monFlux >> nombre; //Lit un nombre à virgule depuis le fichier
string mot;
monFlux >> mot;    //Lit un mot depuis le fichier
```

Cette méthode lit ce qui se trouve entre l'endroit où l'on se situe dans le fichier et l'espace suivant. Ce qui est lu est alors traduit en double  , int ou string  , selon le type de variable dans lequel on écrit.

pour lecture jusqu'à la fin du fichier: `while (monFlux >> mot)`

### 3. Lecture d'un fichier caractère par caractère avec  `get()`

```c++
char a;
monFlux.get(a);
```

- Si on veut changer de mode de lecture: il faut utiliser `cin.ignore()` lorsqu'on passe de la lecture mot par mot à la lecture ligne par ligne. 

```c++
ifstream monFlux("C:/Nanoc/C++/data.txt");

string mot;
monFlux >> mot;          //On lit un mot depuis le fichier

monFlux.ignore();        //On change de mode

string ligne;
getline(monFlux, ligne); //On lit une ligne complète
```

- Lire un fichier en entier: Pour savoir si l'on peut continuer à lire, il faut utiliser la valeur renvoyée par la fonction `getline()`.

En plus de lire une ligne, cette fonction renvoie un `bool` indiquant si l'on peut continuer à lire. Si la fonction renvoie `true`, tout va bien, la lecture peut continuer. Si elle renvoie `false`, c'est qu'on est arrivé à la fin du fichier ou qu'il y a eu une erreur. Dans les deux cas, il faut s'arrêter de lire. 

```c++
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

int main()
{
   ifstream fichier("C:/Nanoc/fichier.txt");

   if(fichier)
   {
      //L'ouverture s'est bien passée, on peut donc lire

      string ligne; //Une variable pour stocker les lignes lues

      while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
      {
         cout << ligne << endl;
         //Et on l'affiche dans la console
         //Ou alors on fait quelque chose avec cette ligne
         //À vous de voir
      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }

   return 0;
}
```

- Une fois que l'on a récupéré les lignes dans une variable string  , on peut facilement travailler dessus grâce aux fonctions utilisables sur les chaînes de caractères.

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
| `tellg()`       | `tellp()`       |

```c++
ofstream fichier("C:/Nanoc/data.txt");

int position = fichier.tellp(); //On récupère la position

cout << "Nous nous situons au " << position << "eme caractere du fichier." << endl;
```

### Déplacez-vous dans un fichier


| Pour `ifstream` | Pour `ofstream` |
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
