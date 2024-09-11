//
// Created by carlo on 26/08/2024.
//

#ifndef GRAFOS_EJERCICIO4_H
#define GRAFOS_EJERCICIO4_H

#include "../alg_grafoPMC.h"
#include "ejercicio3.h"
#include <iostream>
template<typename tCoste>
struct canal{
    typename GrafoP<tCoste>::vertice vertice1, vertice2;
    tCoste longitud;
    canal( typename GrafoP<tCoste>::vertice v1,typename GrafoP<tCoste>::vertice v2,tCoste l): vertice1(v1),vertice2(v2),longitud(l){}
};
template<typename tCoste>
vector<canal<tCoste>> EMASAJER (GrafoP<tCoste>& G)
{
    vector<canal<tCoste>> canales;
    GrafoP<tCoste> C=KruskallMAX(G);
    for (int i = 0; i < C.numVert(); ++i) {
        for (int j = i+1; j < C.numVert(); ++j) {
            if (C[i][j]!= GrafoP<tCoste>::INFINITO) canales.push_back(canal(i,j,C[i][j]));

        }

    }
    return canales;




}





#endif //GRAFOS_EJERCICIO4_H
