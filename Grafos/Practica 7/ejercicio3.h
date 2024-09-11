
#ifndef GRAFOS_EJERCICIO3_H
#define GRAFOS_EJERCICIO3_H

#include "../alg_grafoPMC.h"
#include <iostream>

//La estrategia es almacenar el maximo numero de productos posibles en los destinos mas baratos pot unidad de producto
template <typename tCoste, typename capacidad>
tCoste distribucion(typename GrafoP<tCoste>::vertice origen,size_t stock,GrafoP<tCoste>& G,vector<capacidad> CC,const vector<double>& subvenciones,vector<capacidad>& CA)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    vector<vertice> P;
    //Aplico Dijkstra
    vector<tCoste> costesMinimos= Dijkstra(G,origen,P);
    //Aplico subvenciones
    for(int i=0;i<costesMinimos.size();++i){
        if (costesMinimos[i]!=GrafoP<tCoste>::INFINITO)
        costesMinimos[i]*=1-subvenciones[i];
    }
    tCoste min;
    tCoste total=0;
    vertice vmin;
    int i;
    //Saco la ciudad con menor costo de envio
    for( i=0;i<G.numVert()|| stock!=0;i++) {
         min = GrafoP<tCoste>::INFINITO;
        for (int j = 0; j < G.numVert(); ++j) {


            if (costesMinimos[j] < min) {
                min = costesMinimos[j];
                vmin = j;
            }
        }


            //relleno esa ciudad
            if (CC[vmin] < stock) {
                total = total + (costesMinimos[vmin] * CC[vmin]);
                stock -= CC[vmin];
                CA[vmin] = 0;

            } else {
                total = total + (costesMinimos[vmin] * stock);
                CA[vmin] -= stock;
                stock = 0;
            }
            costesMinimos[vmin] = GrafoP<tCoste>::INFINITO;
        }
    return total;




}


#endif //GRAFOS_EJERCICIO3_H
