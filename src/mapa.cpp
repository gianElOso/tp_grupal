#include "mapa.hpp"
#include <iostream>
#include <random>
#include <stack>

mapa::mapa(){
    this->tablero = new matriz<Casilleros>(18,24, Casilleros::OCUPADO);
    
    coordenada casilleros_libres[] = {
        {0,4},{0,5},{0,6},{0,7},{0,8},{0,9},{0,10},{0,11},{0,12},{0,13},{0,14},{0,15},
        {1,4},{1,5},{1,6},{1,7},{1,8},{1,9},{1,10},{1,11},{1,12},{1,13},{1,14},{1,15},
        {2,4},{2,5},{2,6},{2,14},{2,15},
        {3,4},{3,5},{3,14},{3,15},
        {4,4},{4,5},{4,14},{4,15},
        {5,4},{5,5},{5,14},{5,15},{5,16},{5,19},{5,20},
        {6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{6,14},{6,15},{6,16},{6,17},{6,18},{6,18},{6,19},{6,20},{6,21},
        {7,0},{7,1},{7,2},{7,3},{7,4},{7,5},{7,6},{7,7},{7,8},{7,9},{7,10},{7,14},{7,15},{7,16},{7,17},{7,20},{7,21},
        {8,0},{8,1},{8,4},{8,5},{8,6},{8,7},{8,8},{8,9},{8,10},{8,15},{8,16},{8,17},{8,20},{8,21},
        {9,0},{9,1},{9,4},{9,5},{9,6},{9,9},{9,10},{9,15},{9,16},{9,17},{9,20},{9,21},
        {10,0},{10,1},{10,4},{10,5},{10,6},{10,9},{10,10},{10,14},{10,15},{10,16},{10,17},{10,20},{10,21},
        {11,0},{11,1},{11,2},{11,3},{11,4},{11,5},{11,6},{11,7},{11,8},{11,9},{11,10},{11,11},{11,12},{11,13},{11,14},{11,15},{11,16},{11,17},{11,18},{11,19},{11,20},{11,21},{11,22},{11,23},
        {12,0},{12,1},{12,2},{12,3},{12,4},{12,5},{12,6},{12,7},{12,8},{12,9},{12,10},{12,11},{12,12},{12,13},{12,14},{12,15},{12,16},{12,17},{12,18},{12,19},{12,20},{12,21},{12,22},{12,23},
        {13,4},{13,5},{13,6},{13,7},{13,8},{13,9},{13,10},{13,17},{13,18},{13,19},{13,20},{13,21},
        {14,4},{14,5},{14,6},{14,7},{14,8},{14,9},{14,10},
        {15,4},{15,5},
        {16,3},{16,4},{16,5},
        {17,3},{17,4},{17,5}
    };
    
    for (auto& coord : casilleros_libres) {
        int x = coord.x();
        int y = coord.y();
        this->tablero->elemento(x, y) = Casilleros::LIBRE;
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    size_t tamanio_coordenadas = sizeof(casilleros_libres) / sizeof(casilleros_libres[0]);

    std::uniform_int_distribution<size_t> dist(0,tamanio_coordenadas - 1);
        
    size_t coordenada_inicio = dist(gen);
    size_t coordenada_final;

    do{ 
        coordenada_final = dist(gen);
    }while(coordenada_final == coordenada_inicio);
    
    this->inico = casilleros_libres[coordenada_inicio];
    this->final = casilleros_libres[coordenada_final];

    tablero->elemento(this->inico.x(), this->inico.y()) = Casilleros::INICIO;
    tablero->elemento(this->final.x(), this->final.y()) = Casilleros::FINAL;
    
}
bool mapa::es_vecino_valido(coordenada posicion) {
    // TODO: Implementar.
    return true;
}
void mapa::imprimirTablero() const {
    for (size_t i = 0; i < tablero->filas(); ++i) {
        for (size_t j = 0; j < tablero->columnas(); ++j) {
            if (tablero->elemento(i, j) == Casilleros::LIBRE) {
                std::cout << "  "; // L representa un casillero libre
            } else if(tablero->elemento(i,j) == Casilleros::INICIO){
                std::cout << "I "; 
            } else if(tablero->elemento(i,j) == Casilleros::FINAL){
                std::cout << "F ";
            } else {
                std::cout << "O "; // O representa un casillero ocupado
            }
        }
        std::cout << '\n';
    }
}
