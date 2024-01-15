#include <iostream>

// Classe de base A
class A {
public:
    int valueA;

    A(int val) : valueA(val) {}
};

// Classe B héritant virtuellement de A
class B : virtual public A {
public:
    B(int val) : A(val) {}
};

// Classe C héritant virtuellement de A
class C : virtual public A {
public:
    C(int val) : A(val) {}
};

// Classe D héritant de B et C
class D : public B, public C {
public:
    // Constructeur de D, qui appelle le constructeur de A avec la valeur 42
    D() : A(42), B(1), C(2) {}
};

int main() {
    // Création d'un objet de la classe D
    D dObject;

    // Accès à la valeurA via la classe D
    std::cout << "Value of A in D: " << dObject.valueA << std::endl;

    return 0;
}
