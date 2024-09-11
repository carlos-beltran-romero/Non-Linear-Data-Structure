//
// Created by carlo on 22/08/2024.
//

#ifndef GRAFOS_EJERCICIO10_H
#define GRAFOS_EJERCICIO10_H

#include "../alg_grafoPMC.h"
#include <iostream>
// DIFERENTES POSIBILIDADES
//tren       trenbus     trenavion
//bustren      bus      busavion
//aviontren   avionbus    avion

template<typename tCoste>
tCoste ejercicio10( GrafoP<tCoste>& A, GrafoP<tCoste>& T, GrafoP<tCoste>& B,typename GrafoP<tCoste>::vertice o,typename GrafoP<tCoste>::vertice d,const tCoste taxiBT,const tCoste taxiAeropuerto,vector<typename GrafoP<tCoste>::vertice > &camino);
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t N= A.numVert();
    GrafoP<tCoste> C(3*N);

    // RELLENAR COMBINADA: TREN BUS AVION
    for ( vertice i= 0; i < N; ++i) {
        for (vertice j = 0; j <N ; ++j) {
            C[i][j]=T[i][j];
        }
    }
    for (vertice i = N,k=0; i < 2 * N; ++i,++k) {
        for (vertice j = N,l=0; j < 2*N; ++j,++l) {
            C[i][j]=B[k][l];

        }

    }
    for (vertice i = 2*N,k=0; i <3*N ; ++i,++k) {
        for (vertice j = 2*N,l=0; j < 3*N; ++j,++l) {
            C[i][j]=A[k][l];

        }

    }

    //APLICAR TARIFAS TAXI

    //1. Taxi tren-autobus y viceversa
    for (vertice i = 0; i <N ; ++i) {
        for (vertice j = N; j <N*2 ; ++j) {
            if (i!=j-N) C[i][j]= GrafoP<tCoste>::INFINITO;
            else C[i][j]=taxiBT;}}
    for (vertice i = N; i <N*2 ; ++i) {
        for (vertice j = 0; j < N; ++j) {
            if (j=i-N)C[i][j]=taxiBT;
            else C[i][j]= GrafoP<tCoste>::INFINITO;}}
    //2.Taxi aeropuerto to (tren,bus) o viceversa
    //tren avion
    for (vertice i = 0; i <N ; ++i) {
        for (vertice j = N*2; j < N*3; ++j) {
            if (i!=j-(2*N)) C[i][j]= GrafoP<tCoste>::INFINITO;
            else C[i][j]=taxiAeropuerto;}}
    //avion tren
    for (vertice i = 2*N; i <3*N ; ++i) {
        for (vertice j = 0; j < N; ++j) {
            if (j!=i-(2*N)) C[i][j]= GrafoP<tCoste>::INFINITO;
            else C[i][j]=taxiAeropuerto;}}

    //bus avion

    for (vertice i = N; i <2*N ; ++i) {
        for (vertice j = N*2; j < N*3; ++j) {
            if (i!=j-(N)) C[i][j]= GrafoP<tCoste>::INFINITO;
            else C[i][j]=taxiAeropuerto;}}
    //avion bus

    for (vertice i = 2*N; i <3*N ; ++i) {
        for (vertice j = N; j < 2*N; ++j) {
            if (j!=i-(N)) C[i][j]= GrafoP<tCoste>::INFINITO;
            else C[i][j]=taxiAeropuerto;}}
    vector<tCoste> trenInicio, avionInicio, busInicio;
    vector<vertice> Pt,Pa,Pb;
    trenInicio= Dijkstra(C,o,Pt);
    busInicio= Dijkstra(C,o+N,Pb);
    aviInicio= Dijkstra(C,o+2*N,Pa);
    //calculo min tren(terminar en tren, terminar en bus y terminar en avion) (idem con el resto)
    //Tren
    tCoste minTren= std::min(trenInicio[d],std::min(trenInicio[d+N],trenInicio[d+2*N]));     //Ya tengo el minimo si voy en tren
    tCoste minBus=std::min(busInicio[d],std::min(busInicio[d+N],busInicio[d+2*N])); //Minimo si voy en bus
    tCoste minAvion=std::min(avionInicio[d],std::min(avionInicio[d+N],avionInicio[d+2*N])); //Minimo si voy en avion
    tCoste minimo= std::min(res,std::min(res2,res3));

    /* ahora se asgina a camino l oque devuelve la funcion camino de algPMC, imprimir nada me da pereza cambiarlo*/
if(minimo == minTren)
{
if(minimo == trenInicio[d])
{
std::cout << "Ruta en tren, empezando y terminando en tren: " << std::endl;
for(int i = 0; i < N; ++i)
std::cout  << Pt[i] << " " << std::endl;
}
else if(minimo == trenInicio[d+N])
{
std::cout << "Ruta en tren, empezando en tren y terminando en bus: " << std::endl;
for(int i = N; i < N)*2; ++i)
std::cout  << Pt[i] << " " << std::endl;
}
else
{
std::cout << "Ruta en tren, empezando en tren y terminando en avion: " << std::endl;
for(int i = N*2; i < N*3; ++i)
std::cout  << Pt[i] << " " << std::endl;
}
}
else if(minimo == minBus)
{
if(minimo == busInicio[d])
{
std::cout << "Ruta en bus, empezando en bus y terminando en tren: " << std::endl;
for(int i = 0; i < N; ++i)
std::cout  << Pb[i] << " " << std::endl;
}
else if(minimo == busInicio[d+N])
{
std::cout << "Ruta en bus, empezando y terminando en bus: " << std::endl;
for(int i = N; i < N*2; ++i)
std::cout  << Pb[i] << " " << std::endl;
}
else
{
std::cout << "Ruta en bus, empezando en bus y terminando en avion: " << std::endl;
for(int i = N*2; i < N*3; ++i)
std::cout  << Pb[i] << " " << std::endl;
}
}
else
{
if(minimo == aviInicio[d])
{
std::cout << "Ruta en avion, empezando en avion y terminando en tren: " << std::endl;
for(int i = 0; i < N; ++i)
std::cout  << Pa[i] << " " << std::endl;
}
else if(minimo == aviInicio[d+N])
{
std::cout << "Ruta en avion, empezando avion y terminando en bus: " << std::endl;
for(int i = N; i < N*2; ++i)
std::cout  << Pa[i] << " " << std::endl;
}
else
{
std::cout << "Ruta en avion, empezando y terminando en avion: " << std::endl;
for(int i = N*2; i < N*3; ++i)
std::cout  << Pa[i] << " " << std::endl;
}
}

    return def;




























}

#endif //GRAFOS_EJERCICIO10_H
