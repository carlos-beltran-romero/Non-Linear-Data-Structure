//
// Created by carlo on 26/08/2024.
//

#ifndef GRAFOS_EJERCICIO5_H
#define GRAFOS_EJERCICIO5_H

#include "../alg_grafoPMC.h"

template<typename tLong>
tLong RETEUN13(GrafoP<tLong>& G)
{
    GrafoP<tLong> K= Kruskall(G);
    tLong l=0;
    for (int i = 0; i < K.numVert(); ++i) {
        for (int j = i+1; j < K.numVert(); ++j) {
            if (K[i][j]!= GrafoP<tLong>::INFINITO)l+=K[i][j];

        }

    }
    return l;
}

#endif //GRAFOS_EJERCICIO5_H
