//
// Created by carlo on 22/08/2024.
//

#ifndef GRAFOS_EJERCICIO13_H
#define GRAFOS_EJERCICIO13_H

#include "../alg_grafoPMC.h"
#include <iostream>

#endif //GRAFOS_EJERCICIO13_H

template<typename tCoste>
vector <typename GrafoP<tCoste>::vertice> ejercicio13(const GrafoP<tCoste> I1, const GrafoP<tCoste>I2,const GrafoP<tCoste>I3, vector <typename GrafoP<tCoste>::vertice> c1,vector <typename GrafoP<tCoste>::vertice> c2,vector <typename GrafoP<tCoste>::vertice> c3)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    matriz<tCoste> i1,i2,i3;
    matriz<vertice> P1,P2,P3;
    i1= Floyd(I1,P1);
    i2= Floyd(I2,P2);
    i3= Floyd(I3,P3);
    vertice mejor1,mejor2,mejor3;
    tCoste aux=0;
    tCoste costeMin= GrafoP<tCoste>::INFINITO;
    for (int i = 0; i <c1.size() ; ++i) {
        aux=0;
        for (int j = 0; j < I1.numVert(); ++j) {
            if(i1[i][j]!= GrafoP<tCoste>::INFINITO)aux+=i1[i][j];
            if(i1[j][i]!= GrafoP<tCoste>::INFINITO)aux+=i1[j][i];


        }
        if (aux<costeMin){
            costeMin=aux;
            mejor1=i;

        }

    }
    costeMin=GrafoP<tCoste>::INFINITO;
    aux=0;

    for (int i = 0; i <c2.size() ; ++i) {
        aux=0;
        for (int j = 0; j < I2.numVert(); ++j) {
            if(i2[i][j]!= GrafoP<tCoste>::INFINITO)aux+=i2[i][j];
            if(i2[j][i]!= GrafoP<tCoste>::INFINITO)aux+=i2[j][i];


        }
        if (aux<costeMin){
            costeMin=aux;
            mejor2=i;

        }

    }
    costeMin=GrafoP<tCoste>::INFINITO;
    aux=0;

    for (int i = 0; i <c3.size() ; ++i) {
        aux=0;
        for (int j = 0; j < I3.numVert(); ++j) {
            if(i3[i][j]!= GrafoP<tCoste>::INFINITO)aux+=i3[i][j];
            if(i3[j][i]!= GrafoP<tCoste>::INFINITO)aux+=i3[j][i];


        }
        if (aux<costeMin){
            costeMin=aux;
            mejor3=i;

        }

    }
    vector<vertice> salida={mejor1,mejor2,mejor3};
    return salida;









}
