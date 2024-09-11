//
// Created by carlo on 26/08/2024.
//

#ifndef GRAFOS_EJERCICIO3_H
#define GRAFOS_EJERCICIO3_H

#include "../alg_grafoPMC.h"



template <typename tCoste>
GrafoP<tCoste> KruskallMAX(const GrafoP<tCoste>& G)
// Devuelve un árbol generador de coste maximo
// de un grafo no dirigido ponderado y conexo G.
{
    assert(!G.esDirigido());

    typedef typename GrafoP<tCoste>::vertice vertice;
    typedef typename GrafoP<tCoste>::arista arista;
    const tCoste INFINITO = GrafoP<tCoste>::INFINITO;
    const size_t n = G.numVert();
    GrafoP<tCoste> g(n);   // Árbol generador de coste maximo.
    Particion P(n);   // Partición inicial del conjunto de vértices de G.
    Apo<arista> A(n*n);    // Aristas de G ordenadas por costes.

    // Copiar aristas del grafo G en el APO A.
    for (vertice u = 0; u < n; u++)
        for (vertice v = u+1; v < n; v++)
            if (G[u][v] != INFINITO)
                A.insertar(arista(u, v, G[u][v]));

    size_t i = 1;
    while (i <= n-1) {   // Seleccionar n-1 aristas.
        arista a = A.cima(); // arista de menor coste
        A.suprimir();
        vertice u = P.encontrar(a.orig);
        vertice v = P.encontrar(a.dest);
        if (u != v) { // Los extremos de a pertenecen a componentes distintas
            P.unir(u, v);
            // Incluir la arista a en el árbol g
            g[a.orig][a.dest] = g[a.dest][a.orig] = a.coste;
            i++;
        }
    }
    return g;
}

template <typename tCoste>
GrafoP<tCoste> KruskallMAX(const GrafoP<tCoste>& G)
// Devuelve un árbol generador de coste mínimo
// de un grafo no dirigido ponderado y conexo G.
{
    assert(!G.esDirigido());

    typedef typename GrafoP<tCoste>::vertice vertice;
    typedef typename GrafoP<tCoste>::arista arista;
    const tCoste INFINITO = GrafoP<tCoste>::INFINITO;
    const size_t n = G.numVert();
    GrafoP<tCoste> g(n);   // Árbol generador de coste mínimo.
    Particion P(n);   // Partición inicial del conjunto de vértices de G.
    vector<arista> A(n*n);    // Aristas de G ordenadas por costes.

    // Copiar aristas del grafo G en el vector A.
    for (vertice u = 0; u < n; u++)
        for (vertice v = u+1; v < n; v++)
            if (G[u][v] != INFINITO)
                A.insertar(arista(u, v, G[u][v]));
    std::sort(A.begin(),A.end(),std::greater<arista>());

    size_t i = 1;
    while (i <= n-1) {   // Seleccionar n-1 aristas.
        arista a = A.begin(); // arista de mayor coste
        A.erase(A.begin());
        vertice u = P.encontrar(a.orig);
        vertice v = P.encontrar(a.dest);
        if (u != v) { // Los extremos de a pertenecen a componentes distintas
            P.unir(u, v);
            // Incluir la arista a en el árbol g
            g[a.orig][a.dest] = g[a.dest][a.orig] = a.coste;
            i++;
        }
    }
    return g;
}







#endif //GRAFOS_EJERCICIO3_H
