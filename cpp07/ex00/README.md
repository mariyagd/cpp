La fonction `swap` est définie dans la bibliothèque standard C++ pour `std::string` et aussi
dans le fichier Whatever.hpp. Alors le compilateur ne peut déterminer quelle fonction `swap`
utiliser (erreur d'ambiguïté).

Pour résoudre ce problème, vous pouvez soit renommer votre fonction swap définie dans 
Whatever.hpp pour éviter le conflit de nom, soit utiliser l'opérateur de résolution 
de portée (`::`) pour spécifier laquelle utiliser.

Avec cette expression, je spécifie au compilateur que je souhaite utiliser la version
`swap` définie dans l'espace de nom global.
```c++
::swap<std::string>( a, b );
```