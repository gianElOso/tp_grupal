#ifndef AYED_TPG_1C2024_MAPA_HPP
#define AYED_TPG_1C2024_MAPA_HPP

#include "coordenada.hpp"
#include "matriz.hpp"
#include "a_estrella.hpp"
#include "vertice.hpp"
/* Esta clase es la encargada de decirle a a_estrella si la posición de un vecino es válida o no.
 * Queda a criterio del grupo como implementarla. La idea es que a_estrella no tenga detalles de
 * implementación de posibles casilleros, clientes, paredes, locales, etc.
 * Adicionalmente, la pueden utilizar para otras partes del TP.
 * TIP: Tienen una matriz ya implementada como parte de la plantilla del TP. */
enum class Casilleros {
    LIBRE,
    OCUPADO,
    INICIO,
    FINAL
};
class a_estrella;


class mapa {
private:
    matriz<Casilleros> *tablero;  
    coordenada inico;
    coordenada final;
    a_estrella recorrer;
    
public:
    mapa();
    // Pre: -
    // Post: Devuelve true si la posición del vecino es válida (es decir, es una coordenada válida y es caminable).
    bool es_vecino_valido(coordenada posicion);
    void encontrar_camino();
    void imprimirTablero() const;
    
};

#endif