//
// Created by carlo on 26/08/2024.
//

#ifndef GRAFOS_EJERCICIO6_H
#define GRAFOS_EJERCICIO6_H
#include "../alg_grafoPMC.h"
template <typename tCoste>
struct canal{
    typename GrafoP<tCoste>::vertice v1,v2;
    tCoste longitud;
    double caudal;
    canal(typename GrafoP<tCoste>::vertice v11,typename GrafoP<tCoste>::vertic v22,tCoste l, double c):v1(v11),v2(v22),longitud(l),caudal(c){}


};

/*Máximo caudal posible y canales mas chicos posible. La estrategia que se me ocurre es seleccionar aquellos canales
 * mas pequeños que sean capaces de soportar mayor caudal.*/
template <typename tCoste>
vector<canal<tCoste>> EMASAJER2(GrafoP<tCoste>& G, matriz<double> caudal,double subvencion,double coste)
{
    vector<canal<tCoste>> J;

    //Lo primero multiplico costes por distancia entre ciudades para obtener cuanto nos costaria un canal para cada ciudad
    size_t N= G.numVert();
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            if (G[i][j]!=GrafoP<tCoste>::INFINITO)
            {
                G[i][j]*=coste;
                G[i][j]=std::abs(caudal[i][j]*(subvencion/100)-G[i][j]);
            }


        }

    }
    GrafoP<tCoste> K= Kruskall(G); //K obtendra un grafo
    for (int i = 0; i < K.numVert(); ++i) {
        for (int j = i+1; j < K.numVert(); ++j) {
            if (G[i][j]!=GrafoP<tCoste>::INFINITO)
                J.push_back(canal(i,j,G[i][j],caudal[i][j]));


        }

    }







}

#endif //GRAFOS_EJERCICIO6_H
