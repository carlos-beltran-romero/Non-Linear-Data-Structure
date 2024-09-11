//
// Created by carlo on 21/08/2024.
//

#ifndef GRAFOS_EJERCICIO6_H
#define GRAFOS_EJERCICIO6_H

#include "../alg_grafoPMC.h"
#include <iostream>

#endif //GRAFOS_EJERCICIO6_H
/*Aplico Floyd a ambos grafos
 * Compruebo para i j cual es mas chico entre A[i][j] A[i][k]+T[k][j] T[i][j] T[i][k]+A[k][j]
 *
 * */


template<typename tCoste>
matriz<tCoste>TarifaMinima(GrafoP<tCoste>& A, GrafoP<tCoste>& T, vector<typename GrafoP<tCoste>::vertice> ciudades)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    matriz<tCoste> a,t, def;
    vector<vertice> Pa,Pt;
    a= Floyd(A,Pa);
    t= Floyd(T,Pt);
    tCoste aux1,aux2;
    for (vertice i=0;i<T.numVert();++i){
        for (vertice j = 0; j < T.numVert(); ++j) {
            for (int k = 0; k < ciudades.size(); ++k) {


                aux1 = std::min(A[i][j], T[i][j]); //Sin transbordo
                aux2 = std::min(A[i][k]+T[k][k],T[i][k]+A[k][j]); //Con transbordo
                def[i][j]= std::min(aux1,aux2);
            }




        }

    }

    return def;






}
