//
// Created by carlo on 26/08/2024.
//

#ifndef GRAFOS_EJERCICIO7_H
#define GRAFOS_EJERCICIO7_H

#include <iostream>
#include "../alg_grafoPMC.h"
#include <math.h>


#endif //GRAFOS_EJERCICIO7_H

struct ciudad{
    double x,y;
};

double distanciaEuclidea(ciudad c1, ciudad c2)
{
    return std::sqrt(std::pow(c1.x-c2.x,2)+std::pow(c1.y-c2.y,2));

}


template<typename tCoste>
tCoste Grecoland (vector<ciudad> Fobos,vector<ciudad> Deimos,vector<ciudad>costerasFobos, vector<ciudad>costerasDeimos,ciudad o,ciudad d)
{
    //Aplicar Kruskall a cada isla para reconstruir cada isla al minimo coste
    GrafoP<tCoste> F(Fobos.size()),D(Deimos.size());
    for (int i = 0; i < Fobos.size(); ++i) {
        for (int j = i+1; j < Fobos.size(); ++j) {
            F[i][j]=F[j][i] =distanciaEuclidea(Fobos[i],Fobos[j]);}}
    for (int i = 0; i < Deimos.size(); ++i) {
        for (int j = 0; j < Deimos.size(); ++j) {
            D[i][j]=D[j][i] =distanciaEuclidea(Deimos[i],Deimos[j]);}}

    F= Kruskall(F);
    D= Kruskall(D);

    GrafoP<tCoste> A(Deimos.size()+Fobos.size());
    for (int i = 0; i < Fobos.size(); ++i) {
        for (int j = 0; j < Fobos.size(); ++j) {
            A[i][j]=F[i][j];
        }

    }
    for (int i = 0; i < Deimos.size(); ++i) {
        for (int j = 0; j < Deimos.size(); ++j) {
            A[i+Fobos.size()][j+Fobos.size()]=D[i][j];

        }

    }
    double costePuente;

    //Aplico los puentes
    for (int i = 0; i < costerasFobos.size(); ++i) {
        for (int j = 0; j < costerasDeimos.size(); ++j) {
            costePuente= distanciaEuclidea(costerasFobos[i],costerasDeimos[j]);
            A[i][j+Fobos.size()]=A[j+Fobos.size()][i]=costePuente;


        }

    }
    //Me quedo con los puentes mas chicos
    A= Kruskall(A);

    //Aplico dijkstra
    vector<tCoste> costes;
    vector<typename GrafoP<tCoste>::vertice > P;
    costes= Dijkstra(A,o,P);
    return costes[d];


}






