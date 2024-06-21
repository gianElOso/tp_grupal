#include "objetoA.hpp"
#include <iostream>

objetoA::objetoA() {
    uno = 1;
    dos = 2;
    numero = new objetoB();
}
int objetoA::get_a(){
    return this->dos;
};
int objetoA::get_b(){
    return this->uno;
}
int objetoA::calcular_suma() {
    return numero->suma(*this);
}
void objetoA::mostar(){
    int suma = calcular_suma();
    std::cout<<suma;
}
objetoA::~objetoA(){
    delete numero;
}