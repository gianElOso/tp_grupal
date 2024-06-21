#ifndef OBJETOA_HPP
#define OBJETOA_HPP

#include "objetoB.hpp"

class objetoB;

class objetoA{
private:
    int uno;
    int dos;
    objetoB *numero;

public:
    objetoA();
    int get_a();
    int get_b();
    int calcular_suma();
    void mostar();
    ~objetoA();
};
#endif