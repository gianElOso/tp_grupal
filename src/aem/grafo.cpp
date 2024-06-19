#include <iostream>
#include "grafo.hpp"

grafo::grafo(size_t cantidad_vertices) {
    matriz_adyacencia = matriz(cantidad_vertices, INFINITO);
    for (size_t i = 0; i < matriz_adyacencia.columnas(); i++) {
        matriz_adyacencia.elemento(i, i) = 0;
    }
}

void grafo::agregar_vertice() {
    size_t vertices = matriz_adyacencia.columnas() + 1;
    matriz_adyacencia.redimensionar(vertices, vertices);
    for (size_t i = 0; i < vertices - 1; i++) {
        eliminar_arista(vertices - 1, i);
        eliminar_arista(i, vertices - 1);
    }
}

void grafo::modificar_arista(size_t origen, size_t destino, int peso) {
    size_t vertices = matriz_adyacencia.columnas();
    if (origen < vertices && destino < vertices) {
        matriz_adyacencia.elemento(origen, destino) = peso;
    } else {
        std::cout << "ERROR: Los vértices no son válidos. No se cambió el camino." << std::endl;
    }
}

void grafo::eliminar_arista(size_t origen, size_t destino) {
    modificar_arista(origen, destino, INFINITO);
}

void grafo::aislar_vertice(size_t vertice) {
    size_t vertices = matriz_adyacencia.columnas();
    if (vertice < vertices) {
        for (size_t i = 0; i < vertices; i++) {
            if (i != vertice) {
                eliminar_arista(i, vertice);
                eliminar_arista(vertice, i);
            }
        }
    } else {
        std::cout << "ERROR: El vértice no es válido. No se aisló." << std::endl;
    }
}

grafo::grafo(const grafo& grafo1) {
    matriz_adyacencia = grafo1.matriz_adyacencia;
}

grafo& grafo::operator=(const grafo& grafo1) {
    if (this != &grafo1) {
        matriz_adyacencia = grafo1.matriz_adyacencia;
    }
    return *this;
}

std::vector<arista> grafo::obtener_aem() {
    //TODO: Implementar.
}