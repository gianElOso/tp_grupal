#ifndef AYED_TPG_1C2024_HEAP_HPP
#define AYED_TPG_1C2024_HEAP_HPP

#include <vector>
#include <cstdlib>
#include <exception>

class heap_exception : public std::exception {
};

template<typename T, bool comp(T, T)>
class heap {
private:
    std::vector<T> datos;

    // Pre: Ambos índices deben ser menor que la cantidad de datos.
    // Post: Intercambia de lugar los datos de los indices indicados.
    void swap(size_t indice_1, size_t indice_2);

    // Pre: Ambos índices deben ser menor que la cantidad de datos.
    // Post: Realiza un "upheap" sobre los índices indicados.
    // (El dato "sube" en el heap.)
    void upheap(size_t& indice);

    // Post: El índice debe ser menor que la cantidad de datos.
    // Post: Realiza un "downheap" sobre el índice indicado.
    // (El dato "baja" en el heap, intercambiándose con el menor/mayor dato.)
    void downheap(size_t& indice);

    // NOTA: No es necesario que lancen excepciones en estos métodos porque son privados.
    // Deberían siempre asegurar que los índices pasados por parámetros son válidos.
    // Consideren cada caso con detenimiento.
    // Adicionalmente, tengan cuidado con el casteo de las variables, porque son size_t.
    // Hacer, por ejemplo, size_t i = 0; i - 1; produce un underflow.
public:
    // Constructor.
    heap();

    // Pre: -
    // Post: Agrega el dato al heap.
    void alta(T dato);

    // Pre: El heap no puede estar vacío.
    // Post: Elimina y devuelve el primer dato.
    T baja();

    // Método para el informe de complejidad algorítmica. Devuelve la cantidad de "upheaps".
    size_t alta_complejidad(T dato);

    // Método para el informe de complejidad algorítmica. Devuelve la cantidad de "downheaps".
    size_t baja_complejidad();

    // Pre: El heap no puede estar vacío.
    // Post: Devuelve el primer dato.
    T primero();

    // Pre: -
    // Post: Devuelve true si el heap está vacío.
    bool vacio();

    // Pre: -
    // Post: Devuelve la cantidad de datos en el heap.
    size_t tamanio();

    // Destructor.
    ~heap();
};

template<typename T, bool (* comp)(T, T)>
heap<T, comp>::heap() {

}

template<typename T, bool (* comp)(T, T)>
void heap<T, comp>::swap(size_t indice_1, size_t indice_2) {

}

template<typename T, bool (* comp)(T, T)>
void heap<T, comp>::upheap(size_t& indice) {

}

template<typename T, bool (* comp)(T, T)>
void heap<T, comp>::downheap(size_t& indice) {

}

template<typename T, bool (* comp)(T, T)>
void heap<T, comp>::alta(T dato) {

}

template<typename T, bool (* comp)(T, T)>
T heap<T, comp>::baja() {

}

template<typename T, bool (* comp)(T, T)>
size_t heap<T, comp>::alta_complejidad(T dato) {

}

template<typename T, bool (* comp)(T, T)>
size_t heap<T, comp>::baja_complejidad() {

}

template<typename T, bool (* comp)(T, T)>
T heap<T, comp>::primero() {

}

template<typename T, bool (* comp)(T, T)>
bool heap<T, comp>::vacio() {

}

template<typename T, bool (* comp)(T, T)>
size_t heap<T, comp>::tamanio() {

}

template<typename T, bool (* comp)(T, T)>
heap<T, comp>::~heap() {

}

#endif