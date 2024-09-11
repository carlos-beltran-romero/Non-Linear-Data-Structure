//
// Created by carlo on 13/08/2024.
//

#ifndef GRAFOS_EJERCICIO4_H
#define GRAFOS_EJERCICIO4_H
//parte trabajo es un vector tal que {7,4,7,5,4} es decir el reocrrido hasta la ciudad 0 y la vueta a la capital se hace
//7 veces, el reocrrido para la ciudad 2 se hace 4 veces....
#include "../alg_grafoPMC.h"
#include <iostream>
#include <vector>
template <typename tCoste>
unsigned distanciaCamiones(const GrafoP<tCoste>& G,vector<size_t>parte_trabajo ,typename GrafoP<tCoste>::vertice C )
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    vector<vertice> P;
    vector<tCoste> capital_ciudades= Dijkstra(G,C,P);
    vector<tCoste> ciudades_capital= DijkstraInv(G,C,P);
    unsigned km=0;
    for(int i=0;i<G.numVert();i++){
        km+=parte_trabajo[i]*(capital_ciudades[i]+ciudades_capital[i]);
    }
    return km;




}


#endif //GRAFOS_EJERCICIO4_H
