//
// Created by carlo on 08/08/2024.
//

#ifndef GRAFOS_ZUELANDIA_H
#define GRAFOS_ZUELANDIA_H

#include "../alg_grafoPMC.h"
#include <iostream>
#include <vector>

template <typename tCoste>
struct carretera{
     typename GrafoP<tCoste>::vertice o,d;
};
template <typename tCoste>
void elimina_ciudades(GrafoP<tCoste>& G,vector<typename GrafoP<tCoste>::vertice> v)
{
    //Poner a infinito las ciudades por las que no se pueda pasar
    const size_t n= G.numVert();
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<n;j++)
        {
            G[j][v[i]]=GrafoP<tCoste>::INFINITO;

        }
        G[i]=vector<tCoste>(n,GrafoP<tCoste>::INFINITO);
    }

}

template<typename tCoste>
void eliminaCarreteras(GrafoP<tCoste>& G,vector<carretera<tCoste>>& v)
{
    for(int i=0;i<v.size();i++)
    {
        G[v[i].o][v[i].d]= GrafoP<tCoste>::INFINITO;

    }

}

template <typename tCoste>
matriz<tCoste> Zuelandia( GrafoP<tCoste>& G,vector<typename GrafoP<tCoste>::vertice >& cR,vector<carretera<tCoste>> carreterasR,typename GrafoP<tCoste>::vertice Capital)
{
    const size_t n=G.numVert();
    elimina_ciudades(G,cR);
    eliminaCarreteras(G,carreterasR);

    vector<typename GrafoP<tCoste>::vertice> P;

    vector<tCoste> OsC= DijkstraInv(G,Capital,P);
    vector<tCoste> CDs= Dijkstra(G,Capital,P);
    matriz<tCoste> A;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)A[i][j]==0;
            else
            A[i][j]=OsC[i]+CDs[j];


        }
    }
    return  A;








}







#endif //GRAFOS_ZUELANDIA_H
