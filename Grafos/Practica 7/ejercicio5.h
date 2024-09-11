//
// Created by carlo on 21/08/2024.
//

#ifndef GRAFOS_EJERCICIO5_H
#define GRAFOS_EJERCICIO5_H

#include "../alg_grafoPMC.h"
#include <iostream>
using namespace std;
//La estrategia es, primero descartar los destinos a los que se pueden llegar con ese transporte
//al que es alergico. Segundo aplicar dijkstra en los otros dos e intorducir en nuestra lista definitiva
//aquellas ciuades cuyo costo sea menor que la cant disponible y mas barato entre los dos transportes.
//Entiendo que querria ir solo a una ciudad y no a varias ( no restar cant dinero)

template<typename tCoste>
vector<tCoste>calculoViaje(GrafoP<tCoste>& A, GrafoP<tCoste>& B, typename GrafoP<tCoste>::vertice o )
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    vector<tCoste> a,b,def;
    vector <vertice> Pa,Pb;
    a= Dijkstra(A,o,Pa);
    b= Dijkstra(B,o,Pb);
    for(vertice i=0; i<A.numVert();i++)
    {
        if(a[i]<=b[i])def[i]=a[i];
        else def[i]=b[i];

    }
    return def;



}



template<typename tCoste>
Lista< typename GrafoP<tCoste>::vertice> alergico( GrafoP<tCoste>& C, GrafoP<tCoste>& T, GrafoP<tCoste>& A,tCoste cant,typename GrafoP<tCoste>::vertice o,int alergico)
{
    //Carretera 0 Tren 1 Avion 2
    vector<tCoste> costes;
    typedef typename GrafoP<tCoste>::vertice vertice;

    switch (alergico) {
        case 0:
            costes=calculoViaje(T,A,o);
            break;
        case 1:
            costes=calculoViaje(C,A,o);
            break;
        case 2:
            costes=calculoViaje(C,T,o);
            break;
    }
    Lista<vertice> L;
    for(vertice i=0;i<T.numVert();i++)
    {
        if ( i!=o &&costes[i]<=cant ) L.insertar(i, L.primera());

    }




}

#endif //GRAFOS_EJERCICIO5_H
