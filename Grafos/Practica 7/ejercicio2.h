

#ifndef GRAFOS_EJERCICIO2_H
#define GRAFOS_EJERCICIO2_H

#include "../alg_grafoPMC.h"
#include <iostream>
#include <vector>
struct casilla{
    int fila,columna;
    casilla(int f,int c): fila(f),columna(c){}
};

struct pared{
    casilla c1,c2;
};

bool adyacente(const casilla& A, const casilla& B)
{
    return abs((A.fila-B.fila))+abs(A.columna-B.columna)==1;
}
template<typename tCoste>
casilla nodoToCasilla(typename GrafoP<tCoste>::vertice v, size_t n)
{
    casilla c(0,0);
    c.fila=v/n;
    c.columna=v%n;
    return c;
}

template<typename tCoste>
typename GrafoP<tCoste>::vertice casillaToNodo(casilla& c, int n){
    return c.fila*n+c.columna;
}

template<typename tCoste>
tCoste laberinto(size_t N,vector<pared> paredes,casilla E, casilla S, vector<casilla>& path)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    GrafoP<tCoste> G(N*N);
    // Rellenar con 1 las casillas adyacentes y con 0 la propia casilla
    for(vertice i=0; i<N;i++) {
        for (vertice j = 0; j < N; j++) {
            if (i == j) {
                G[i][j] = 0;
            } else if (adyacente(nodoToCasilla<tCoste>(i, N), nodoToCasilla<tCoste>(j, N)))
                G[i][j] = 1;

        }
    }
    //Quitamos un camino con pared de por medio
    for(auto & parede : paredes){
        G[casillaToNodo<tCoste>(parede.c1,N)][casillaToNodo<tCoste>(parede.c2,N)]=GrafoP<tCoste>::INFINITO;
        G[casillaToNodo<tCoste>(parede.c2,N)][casillaToNodo<tCoste>(parede.c1,N)]=GrafoP<tCoste>::INFINITO;



    }

    //Aplicamos Djikstra
    vector<vertice> P;
    vector <tCoste> costes= Dijkstra(G, casillaToNodo<tCoste>(E,N),P);

    return P;





}










#endif //GRAFOS_EJERCICIO2_H
