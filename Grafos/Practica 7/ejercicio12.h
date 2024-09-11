//
// Created by carlo on 22/08/2024.
//

#ifndef GRAFOS_EJERCICIO12_H
#define GRAFOS_EJERCICIO12_H

#include "../alg_grafoPMC.h"
#include <iostream>

/* La estrategia es primeramente aplicar floyd, y luego seleccionar las ciudades costeras con costes minimos a las ciudades de su isla tanto de
 * ida como de vuelta.
 * ¿Porque no dikstra y dikstra inverso? Claro porque tendria que aplicarlo con cada ciudad costera= ineficiente. Mejor una vez floyd y ya*/
template <typename tCoste>
vector<typename GrafoP<tCoste>::vertice> ejercicio12(GrafoP<tCoste>& F, GrafoP<tCoste>& D, vector<typename GrafoP<tCoste>::vertice> CF,vector<typename GrafoP<tCoste>::vertice> CD)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    matriz<tCoste> f,d;
    matriz<vertice> Pf, Pd;
    f= Floyd(F,Pf);
    d= Floyd(d,Pd);
    tCoste costeMin= GrafoP<tCoste>::INFINITO;
    vertice costeraFobos,costeraDeimos;
    tCoste aux=0;
    // Selecciono la ciudad costera de Fobos con costes minimos para llegar a otras ciudades de su misma isla
    for (int i = 0; i <CF.size() ; ++i) {
        aux=0;
        for (int j = 0; j <F.numVert() ; ++j) {
            if(f[i][j]!= GrafoP<tCoste>::INFINITO)aux+=f[i][j];
            if(f[j][i]!= GrafoP<tCoste>::INFINITO)aux+=f[j][i];
        }
        if (aux<costeMin){
            costeMin=aux;
            costeraFobos=i;

        }

    }
    aux=0;costeMin= GrafoP<tCoste>::INFINITO;

    // Selecciono la ciudad costera de Deimos con costes minimos para llegar a otras ciudades de su misma isla
    for (int i = 0; i <CD.size() ; ++i) {
        aux=0;
        for (int j = 0; j <D.numVert() ; ++j) {
            if(f[i][j]!= GrafoP<tCoste>::INFINITO)aux+=f[i][j];
            if(f[j][i]!= GrafoP<tCoste>::INFINITO)aux+=f[j][i];
        }
        if (aux<costeMin){
            costeMin=aux;
            costeraDeimos=i;

        }

    }
    vector<vertice> salida={costeraFobos,costeraDeimos};
    return salida;


}




#endif //GRAFOS_EJERCICIO12_H
