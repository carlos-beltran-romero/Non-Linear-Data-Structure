//
// Created by carlo on 21/08/2024.
//

#ifndef GRAFOS_EJERCICIO7_H
#define GRAFOS_EJERCICIO7_H

/* Tenemos que ver que renta mas si coger por cambio1 o por cambio2
 *Entiendo que no se cuenta la vuelta
 *
 *
 **/
#include "../alg_grafoPMC.h"
#include <iostream>

template<typename tCoste>
tCoste ejercicio7(GrafoP<tCoste>& T, GrafoP<tCoste>& A, typename GrafoP<tCoste>::vertice o,typename GrafoP<tCoste>::vertice d, vector<typename GrafoP<tCoste>::vertice>& camino1,vector<typename GrafoP<tCoste>::vertice>& camino2,typename GrafoP<tCoste>::vertice cambio1,typename GrafoP<tCoste>::vertice cambio2,typename GrafoP<tCoste>::vertice& x)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    vector<vertice> Po, Pd;
    vector<tCoste> Vo, Vd;
    Vo= Dijkstra(T,o,Po);
    Vd= DijkstraInv(A,d,Pd);
    tCoste res= std::min(Vo[cambio1]+Vd[cambio1],Vo[cambio2]+Vd[cambio2]);
    if (Vo[cambio1]+Vd[cambio1]<=Vo[cambio2]+Vd[cambio2])
        x=cambio1;
    else x=cambio2;
    return res;





}

#endif //GRAFOS_EJERCICIO7_H
