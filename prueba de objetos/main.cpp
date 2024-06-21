#include <iostream>
#include "objetoA.hpp"

int main(){
    objetoA a;
    a.mostar();
    return 0;
}/*
#include <iostream>

class objetoA;  // Declaración anticipada de la clase objetoA

class objetoB {
public:
    int suma(objetoA& objeto);  // Declaración del método suma
};

class objetoA {
private:
    int uno = 2;
    int dos = 1;
    objetoB numero;

public:
    int get_a() {
        return this->dos;
    }

    int get_b() {
        return this->uno;
    }

    int calcularSuma() {
        return numero.suma(*this);  // Llama a suma pasando una referencia a sí mismo
    }

    void mostrar() {
        int suma = calcularSuma();  // Calcula la suma dentro del método mostrar
        std::cout << suma << std::endl;
    }
};

int objetoB::suma(objetoA& objeto) {
    return objeto.get_a() + objeto.get_b();
}

int main() {
    objetoA a;
    a.mostrar();
    return 0;
}*/