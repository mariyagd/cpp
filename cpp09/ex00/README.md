### map vs multimap
- Dans un map, chaque clé est unique. 
Cela signifie que chaque clé est associée à au plus une seule valeur.
- Dans un multimap, une même clé peut être associée à plusieurs valeurs différentes.

- Lorsque vous insérez une paire clé-valeur dans un map, 
si une clé identique existe déjà, elle est remplacée par la nouvelle valeur.
- Pour un multimap, toutes les insertions sont possibles sans 
remplacer les valeurs précédentes associées à la même clé.

- Vous pouvez accéder à une valeur dans un map en utilisant sa clé comme index, 
et l'accès se fait en temps logarithmique.
- Pour un multimap, il est possible d'accéder à toutes les valeurs associées 
à une clé donnée en utilisant les fonctions de recherche appropriées.

### `ifstream` gestion d'erreur après ouverture d'un fichier

La classe `ifstream` dérive de `std::ios_base`.
La dernière a une méthode membre publique `exceptions` ( [voir ici](https://cplusplus.com/reference/ios/ios/exceptions/) )

```c++
/* get (1) */  std::ios::iostate exceptions() const;
```

Cette méthode configure les exceptions à lancer lorsqu'une erreur se produit 
lors des opérations sur le flux et renvoie le masque d'exception actuelle définie pour le flux.

Le masque d'exception est un ensemble de bits que tous les flux ont et qui détermine 
quelles conditions d'erreur généreront une exception lors d'opérations sur le flux. 
Ces conditions d'erreur peuvent inclure des échecs de lecture, des échecs d'écriture, etc.

Le type de retour de la méthode `std::ios::exceptions()` est `std::ios::iostate`, dont la valeur est formée d'une
combinaison de l'état de ses membres - goodbit, eofbit, failbit, badbit.

Le membre goodbit ne jette pas d'exception. Le membre eof indique si on est arrivée à la fin du fichier,
mais nous ne voulons pas vérifier cela à l'ouverture, parce qu'on n'est pas en train de lire le fichier.

Donc, on peut utiliser la fonction de la manière suivante :

```c++
	std::ifstream	ifs( "filename" )
	ifs.exceptions( std::ifstream::failbit | std::ifstream::badbit  );
```

Il n'y a pas besoin de tester `ifs_isopen()`.

L'exception générée est de type `std::ios_base::failure` qui hérite de `std::system_error` 
qui hérite de `std::runtime_error` qui hérite de `std::exception`

Donc, on pourra capturer cette exception avec :

```c++
	//  All these are valid :
     
	    catch (const std::ifstream::failure & e)
	 	
		catch (const std::ios_base::failure & e)
	 	
		catch (const std::system_error & e)
	 	
		catch (const std::runtime_error & e)
	 	
		catch (const std::exception & e)

```

Pour extraire le code et le message d'erreur :

```c++
catch (const std::ifstream::failure & e)
	{
		std::cerr << RED_BOLD   << "libc++ error #"
				  << e.code().value() << " "
				  << e.code().message() << std::endl
				  << "libc error #"
				  << errno << " "
				  << ::strerror(errno) << END << std::endl;
		return 1;
	}
```

<details><summary>

### Explications sur `std::ios::iostate`

</summary> 

La `rdstate()` est une fonction membre qui renvoie l'état actuel du flux sous la forme d'une 
combinaison des valeurs goodbit, eofbit, failbit et badbit.

L'état de chaque membre peut être vérifié individuellement avec sa méthode correspondante ( `good()`, `eof()` etc...)

|iostate value <br/>(member constants) | indicates 	                            | good()  | eof()  | fail()	 | bad()  | rdstate()  |
|--------------------------------------|------------------------------------------|---------|--------|---------|--------|------------|
|goodbit                               | No errors (zero value iostate)	        | true	  | false  | false   | false  | goodbit    |
|eofbit	                             | End-of-File reached on input operation   | false	  | true   | false   | false  | eofbit     |
|failbit                               | Logical error on i/o operation	        | false	  | false  | true    | false  | failbit    |
|badbit	                             | Read/writing error on i/o operation      | false   | false  | true    | true   | badbit     |
                                         

`std::ios::badbit`, `std::ios::failbit`, `std::ios::eofbit`, etc., qui correspondent à 
différentes conditions d'erreur possibles.

</details>

### Extraire les données d'une string

```c++
#include <iostream>
#include <sstream>
#include <string>

int main() {
	std::string s = "2011-02-05 | 36";

	std::istringstream iss(s);

	int year, month, date, value;
	char pipe, hyphen1, hyphen2;

	iss >> year >> hyphen1 >> month >> hyphen2 >> date >> pipe >> value;

	std::cout << "year     " << year << std::endl
			  << "hyphen1  " << hyphen1 << std::endl
			  << "month    " << month << std::endl
			  << "hyphen2  " << hyphen2 << std::endl
			  << "date     " << date << std::endl
			  << "pipe     " << pipe << std::endl
			  << "value    " << value << std::endl;

	return 0;
}
```

### make_pair et pair

Pour créer une paire, on peut utiliser la fonction `std::make_pair` ou le constructeur de `std::pair` :

```c++

std::string     date = "2011-02-05";
foat            rate = 36.0;

// implicit type deduction
std::pair<std::string, float> f = std::make_pair(date, rate);

// explicit type deduction
std::pair<std::string, float> f = std::make_pair< std::string, float >(date, rate);

// using the pair constructor
std::pair<std::string, float> f(date, rate);

```

### Comparer des structures tm

Dans votre cas, vous utilisez std::tm comme clé dans votre std::map, mais le compilateur ne sait pas comment comparer deux structures std::tm. Pour résoudre ce problème, vous devez définir un prédicat de comparaison pour std::tm. Vous pouvez le faire en définissant une fonction de comparaison personnalisée et en l'utilisant lors de la création de votre std::map.

Voici un exemple de comment vous pourriez définir une fonction de comparaison pour std::tm :

```c++
struct CompareTm {
    bool operator()(const std::tm& lhs, const std::tm& rhs) const {
        if (lhs.tm_year < rhs.tm_year) return true;
        if (lhs.tm_year > rhs.tm_year) return false;
        if (lhs.tm_mon < rhs.tm_mon) return true;
        if (lhs.tm_mon > rhs.tm_mon) return false;
        return lhs.tm_mday < rhs.tm_mday;
    }
};

```

```c++
std::map<std::tm, float, CompareTm> _mmap;
```