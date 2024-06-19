#ifndef AYED_TPG_1C2024_DICCIONARIO_HPP
#define AYED_TPG_1C2024_DICCIONARIO_HPP

#include <exception>
#include <cstdlib>
#include <vector>
#include <queue>
#include "nodo.hpp"

class diccionario_exception : public std::exception {
};

template<typename c, typename T, bool comp(c, c)>
class diccionario {
private:
    // comp es la función de comparación para las claves.
    // La clave debe implementar el operator==().
    nodo<c, T, comp>* raiz;
    std::size_t cantidad_datos;
public:
    // Constructor.
    diccionario();

    // Pre: La clave no puede existir en el árbol.
    // Post: Agrega el dato asociado a la clave al árbol. Si no hay datos, crea una nueva raíz.
    void alta(c clave, T dato);

    // Pre: -
    // Post: Elimina el dato asociado a la clave del árbol. Si no existe, no hace nada.
    // NOTA: El caso de baja con dos hijos se resuelve con sucesor inmediato. Se puede hacer swap del dato.
    void baja(c clave);

    // Pre: La clave debe existir en el árbol.
    // Post: Devuelve una referencia al valor asociado a la clave.
    T& operator[](c clave);

    // Pre: -
    // Post: Devuelve el recorrido inorder.
    std::vector<T> inorder();

    // Pre: -
    // Post: Devuelve el recorrido preorder.
    std::vector<T> preorder();

    // Pre: -
    // Post: Devuelve el recorrido postorder.
    std::vector<T> postorder();

    // Pre: -
    // Post: Devuelve el recorrido en ancho.
    std::vector<T> ancho();

    // Pre: -
    // Post: Ejecuta el método/función en cada valor del árbol.
    /* NOTA: No abusar de este método, está solamente para simplificar algunas cosas,
     * como liberar la memoria de los nodos de usar punteros o imprimir por pantalla el contenido.
     * Pueden usar cualquier recorrido. */
    void ejecutar(void funcion(T));

    // Pre: -
    // Post: Devuelve la cantidad de datos en el árbol.
    std::size_t tamanio();

    // Pre: -
    // Post: Devuelve true si el árbol está vacío.
    bool vacio();

    // El constructor de copia está deshabilitado.
    diccionario(const diccionario& abb) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const diccionario& abb) = delete;

    // Destructor.
    ~diccionario();
};

template<typename c, typename T, bool (* comp)(c, c)>
diccionario<c, T, comp>::diccionario() {

}

template<typename c, typename T, bool (* comp)(c, c)>
void diccionario<c, T, comp>::alta(c clave, T dato) {

}

template<typename c, typename T, bool (* comp)(c, c)>
void diccionario<c, T, comp>::baja(c clave) {

}

template<typename c, typename T, bool (* comp)(c, c)>
T& diccionario<c, T, comp>::operator[](c clave) {

}

template<typename c, typename T, bool (* comp)(c, c)>
std::vector<T> diccionario<c, T, comp>::inorder() {

}

template<typename c, typename T, bool (* comp)(c, c)>
std::vector<T> diccionario<c, T, comp>::preorder() {

}

template<typename c, typename T, bool (* comp)(c, c)>
std::vector<T> diccionario<c, T, comp>::postorder() {

}

template<typename c, typename T, bool (* comp)(c, c)>
std::vector<T> diccionario<c, T, comp>::ancho() {

}

template<typename c, typename T, bool (* comp)(c, c)>
void diccionario<c, T, comp>::ejecutar(void (* funcion)(T)) {

}

template<typename c, typename T, bool (* comp)(c, c)>
std::size_t diccionario<c, T, comp>::tamanio() {

}

template<typename c, typename T, bool (* comp)(c, c)>
bool diccionario<c, T, comp>::vacio() {

}

template<typename c, typename T, bool (* comp)(c, c)>
diccionario<c, T, comp>::~diccionario() {

}

#endif