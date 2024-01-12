# Exercice 01 : Premiers pas vers une classe utile

### suffixe `f`
En C++ (et dans certains autres langages de programmation), le suffixe f après un nombre décimal indique que le nombre est un littéral de type float. Sans le suffixe f, le nombre serait traité comme un littéral de type double par défaut.

Par exemple, dans l'expression 42.42f, le f indique explicitement que le nombre 42.42 doit être traité comme un float. En l'absence du f, le nombre serait par défaut considéré comme un double.

```c+
float nombreFloat = 42.42f;  // Utilisation du suffixe f pour indiquer que c'est un float
double nombreDouble = 42.42;  // Par défaut, sans suffixe, le nombre est considéré comme un double
```

### puissance 2

1 << nombre est équivalent à 2^nombre.
