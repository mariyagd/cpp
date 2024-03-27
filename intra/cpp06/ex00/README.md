# Exercise 00: Conversion of scalar types

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

./prog ' '
```

### 2. Pour convertir un `float` :

comme `f` sert d'identifiant, j'ai considéré qu'il n'est pas obligatoire d'avoir un point décimal !

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

./prog 42.            //  -> valide ok

./prog .42            //  -> valide ok
```

### 4. Notation scientifique :

J'ai geré la notation scientifique pour pouvoir comparer les valeurs `min` et `max` de `float` et `double`.
Le point décimal n'est pas obligatoire !

```c++
./prog 2147483647           // INT MAX 
./prog -2147483648          // INT MIN 

./prog 3.40282e+38f         // FLOAT MAX 
./prog -3.40282e+38f        // FLOAT LOWEST
./prog 1.17549e-38f         // FLOAT MIN DOESN'T WORk
        
./prog 1.79769e+308         // DOUBLE MAX 
./prog -1.79769e+308        // DOUBLE LOWEST
./prog 2.22507e-308         // DOUBLE MIN DOESN'T WORK

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
./prog 00000020000000000.5
```
