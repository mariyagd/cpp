
Lorsqu'on parle de "Un entier pour stocker la valeur du nombre en virgule fixe", cela signifie généralement la partie après la virgule dans le nombre à virgule fixe.

Supposons que vous ayez un nombre à virgule fixe avec 8 bits pour la partie fractionnaire. Cela signifie que lorsque vous stockez un nombre, par exemple 42.75, la partie fractionnaire après la virgule est représentée avec une précision de 8 bits.

Pour comprendre comment cela fonctionne, pensez aux bits comme à des puissances de 2. Si vous avez 8 bits pour la partie fractionnaire, vous pouvez représenter jusqu'à 2^8 différentes valeurs fractionnaires.

Exemple : 42.75
La partie entière (avant la virgule) serait stockée comme d'habitude (par exemple, avec un entier).
La partie fractionnaire serait représentée en utilisant 8 bits. Pour 0.75, cela pourrait être quelque chose comme 11000000 (en binaire).
Ainsi, la valeur du nombre à virgule fixe serait la combinaison de la partie entière et de la partie fractionnaire, et lorsqu'on veut récupérer la valeur réelle, on diviserait la partie fractionnaire par 2^8 pour obtenir la valeur réelle en décimal.

### suffixe `f`
En C++ (et dans certains autres langages de programmation), le suffixe f après un nombre décimal indique que le nombre est un littéral de type float. Sans le suffixe f, le nombre serait traité comme un littéral de type double par défaut.

Par exemple, dans l'expression 42.42f, le f indique explicitement que le nombre 42.42 doit être traité comme un float. En l'absence du f, le nombre serait par défaut considéré comme un double.

```c+
float nombreFloat = 42.42f;  // Utilisation du suffixe f pour indiquer que c'est un float
double nombreDouble = 42.42;  // Par défaut, sans suffixe, le nombre est considéré comme un double
```

### puissance 2

1 << nombre est équivalent à 2^nombre.

### Définir un type de point fixe


Pour définir conceptuellement un type de point fixe, tout ce dont nous avons besoin sont deux paramètres :

1. La largeur de la représentation numérique (dans cet exercice c'est `FixedPointNumber` - Un entier pour stocker la valeur du nombre en virgule fixe
2. La position du point binaire à l'intérieur du nombre = Un entier constant statique pour stocker le nombre de bits de la partie fractionnaire. Cela signifie que les 8 bits les moins significatifs de l'entier stocké représentent la partie fractionnaire du nombre.

