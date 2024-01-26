# Exercise 00: Conversion of scalar types

- conversion avec C++98 et sans fonctions C

-  enum `enum	typeEnum { CHAR, CHAR_ISSPACE, INT, FLOAT, DOUBLE };` où
  `CHAR_ISSPACE` représente les caractères de `std::isspace` -> `\t, \n, \f, \v, \r, ' '`

1) Tous les espaces blancs au début et à la fin de la string sont supprimés


2) Définir le type `CHAR, CHAR_ISSPACE, INT, FLOAT, DOUBLE`


3) Traiter les cas de chiffres entre 0 et 9 : p.ex. `'9'` est un `char` et `9` est un int.
3) 
4) Traiter les cas des whites spaces `\t, \n, \f, \v, \r, ' '`


3) `+inf`, `-inf`,  `nan`, `+inff`, `-inff`, `nanf` -> il faut seulement définir s'il s'agit d'un `double` ou d'un `float`.
La conversion de, p.ex. `+inff` en `+inf`, se fera automatiquement lors du casting.


4) Utiliser les fonctions de la bibliothèque `stdexcept` pour _throw exception_ en cas d'argument invalide. 

[ stdexcept voir ici](https://en.cppreference.com/w/cpp/header/stdexcept)

```c++
throw (std::overflow_error("your custom message"))     // -> en cas d'overflow

throw (std::invalid_argument("your custom message"))   // -> en cas d'argument invaldie
```


5) Streamer la string dans le bon type avec `std::istringstream iss;` sauf si c'est le type est `CHAR_ISSPACE` (dans ce cas traîter différemment)

```c++
std::istringstream(s);

if (type == FLOAT)
    s >> float f;
```

6) Si `iss.fail() == true` sa veut dire qu'il y a une erreur d'overflow -> throw exception


7) Caster explicitement au cas par cas en évitant les overflow. 
J'ai fait un flag que si on s'attend à un overflow, la valeur est mise à 0.
Ensuite je compare si la valeur du double >= 1 -> imprimer impossible.
si la valeur du double est 0 -> toutes les variables ont la valeur 0.



### 1. Convertir un `char` :

```c++
./prog z           // ./prog 4 -> 4 est considéré un int

./prog "'z'"
./prog "'4'"       // ->  4 est considéré comme un char
```

- Pour convertir les white spaces `\t, \n, \f, \v, \r`:

 ```c++
./prog \\t


./prog "'\t'"
```

- Pour convertir un espace :
```c++
./prog " "

./prog "' '"
```

### 2. Pour convertir un `float` :

comme `f` sert d'identifiant, j'ai considéré qu'il n'est pas obligatoire d'avoir un point décimal!

```c++
./prog 42.0f 

./prog 42f              //  -> valide ok

./prog 42.f            //  -> valide ok

./prog .42f            //  -> valide ok
```

### 3. Pour convertir un `double` :

Le point décimal est obligatoire!!!

```c++
./prog 42.0 

./prog 42             //  -> valide ok

./prog 42.            //  -> valide ok

./prog .42            //  -> valide ok
```

### 4. Notation scientifique :

J'ai geré la notation scientifique pour pouvoir comparer les valeurs `min` et `max` de `float` et `double`.
Le point décimal n'est pas obligatoire !

```c++
./prog 2147483647           // INT MAX 
./prog -2147483648          // INT MIN 

./prog 3.40282e+38          // FLOAT MAX 
./prog 1.17549e-38          // FLOAT MIN
./prog -3.40282e+38         //FLOAT LOWEST
        
./prog 1.79769e+308         // DOUBLE MAX 
./prog 2.22507e-308         // DOUBLE MIN
./prog -1.79769e+308        // DOUBLE LOWEST

```

#### Le point décimal n'est pas obligatoire !

```c++
./prog 10e+1                // 10e+1 est considéré comme double

./prog 10e+1f               // 10e+1f est considéré comme float


./prog 10.0e+1               

./prog 10.e+1               // valide ok

./prog .10e+1               // valide ok
```


### TESTS


```c++
./prog 0.05
./prog 2147483648   // int overflow -> error
./prog -21474836
./prog 325328645386453877645318684584653138651465.0 
./prog -1.17550e+38
./prog -0.00005 
./prog +0.956
./prog "'a'"
./prog "'9'"
./prog "'\t'"
./prog \\n
./prog 1e+1
./prog -1.2e+1
```

### 5. Max and min values

- attention: `float` et `double` ont des valeurs `min` et `max` POSITIVES et `lowest` pour la valeur minimale NEGATIVE.

```c++
max char                       127
min char                      -128

max int                 2147483647
min int                -2147483648

max float              3.40282e+38      
min float              1.17549e-38
lowest float          -3.40282e+38

max double            1.79769e+308
min double            2.22507e-308
lowest double        -1.79769e+308
```

### Fonctions utiles dans `<cctype>`:

```c++

int std::isprint( int ch );

// --> space is printable 
// --> \f, \n, \r, \t, \v  not printable
```
```c++
int std::isspace( int ch );

// space (' ')
// form feed ('\f')
// line feed ('\n')
// carriage return ('\r')
// horizontal tab ('\t')
// vertical tab ('\v')
```
```c++
int std::isprint( int ch );

// digits (0123456789)
// uppercase letters (ABCDEFGHIJKLMNOPQRSTUVWXYZ)
// lowercase letters (abcdefghijklmnopqrstuvwxyz)
// punctuation characters (!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~)
// space ( )  <---------- !!!
```

