//
// Created by carlo on 22/08/2024.
//

#ifndef GRAFOS_EJERCICIO11_H
#define GRAFOS_EJERCICIO11_H

#include "../alg_grafoPMC.h"
#include <iostream>
template <typename tCoste>
struct puente{
    typename GrafoP<tCoste>::vertice A,B;
};
/* Lo primero será hacer una matriz combinada con todas las ciudades
 * Luego las ciudades que cuenten con un puente ponemos 0
 * Luego floyd y devolver floyd*/


template <typename tCoste>
matriz<tCoste> ejercicio11(GrafoP<tCoste>& C1, GrafoP<tCoste>& C2, GrafoP<tCoste>& C3, vector<puente<tCoste>>& puentes)
{
    GrafoP<tCoste> A(C1.numVert()+C2.numVert()+C3.numVert());
    typedef typename GrafoP<tCoste>::vertice vertice;

    //Relleno con la primera isla C1
    for(vertice i =0;i<C1.numVert();++i){
        for (vertice j = 0; j <C1.numVert() ; ++j) {
            A[i][j]=C1[i][j];}}
    //Relleno con la segunda isla C2
    for (vertice i = C1.numVert(),k=0; i <C2.numVert() ; ++i,++k) {
        for (vertice j = C1.numVert(),l=0; j <C2.numVert() ; ++j,++l) {
            A[i][j]=C2[k][l];}}
    //Relleno con la tercera isla C3
    for (vertice i = C2.numVert(),k=0; i <C3.numVert() ; ++i,++k) {
        for (vertice j = C2.numVert(),l=0; j <C3.numVert() ; ++j,++l) {
            A[i][j]=C3[k][l];}}

    //Marco los puentes
    for (int i = 0; i <puentes.size() ; ++i) {
        A[puentes[i].A][puentes[i].B]=0;

    }

    matriz<vertice> P;
    matriz<tCoste> DEF= Floyd(A,P);
    return DEF;












}

#endif //GRAFOS_EJERCICIO11_H
