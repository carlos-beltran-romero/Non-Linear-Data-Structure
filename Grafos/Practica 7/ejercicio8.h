//
// Created by carlo on 21/08/2024.
//

#ifndef GRAFOS_EJERCICIO8_H
#define GRAFOS_EJERCICIO8_H

#include "../alg_grafoPMC.h"
#include <iostream>
/*Primeramente, nos quedamos con el coste minimo entre viajar directamente en tren y viajar directamente en autobus*/
/*Luego vemos si haciendo un transbordo reducimos el costo de hacer el coste directo.*/
template <typename tCoste>
tCoste unSoloTransbordo(GrafoP<tCoste>& T, GrafoP<tCoste>& A,typename GrafoP<tCoste>::vertice o,typename GrafoP<tCoste>::vertice d)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    vector<vertice> Pt,Pa;
    vector<tCoste> OallA,OallT; //Desde el origen a todos en Autobus y en tren
    vector<tCoste>allD_A,allD_T;
    tCoste res;
    OallA= Dijkstra(A,o,Pa);
    OallT= Dijkstra(T,o,Pt);
    allD_A= DijkstraInv(A,d,Pa);
    allD_T= DijkstraInv(T,d,Pt);
    res= std::min(OallA[d],OallT[d]);
    for (vertice i = 0; i <T.numVert() ; ++i) {
        if(i!=d && i!=o ){
            if(OallA[i]+allD_T[i]<res)res=OallA[i]+allD_T[i];
            else if(OallT[i]+allD_A[i]<res) res=OallT[i]+allD_A[i];
        }


    }



}

#endif //GRAFOS_EJERCICIO8_H
