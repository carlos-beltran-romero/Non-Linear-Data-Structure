//
// Created by carlo on 23/08/2024.
//

#ifndef GRAFOS_EJERCICIO1_H
#define GRAFOS_EJERCICIO1_H
#include "../alg_grafoPMC.h"
#include <iostream>
#include <valarray>
#include <set>

/* El planteamiento es: La distribucion de islas la hacemos mediante TAD Particion
 * Para el coste minimo, debemos construir la matriz de costes minimos y aplicar Floyd.
 * */

/*struct ciudad{
    double x,y;
};

std::pair<Particion,matriz<double>> Tombuctu(const Grafo Ad, vector<ciudad> ciudades)
{
    size_t N= Ad.numVert();
    //Creo un GrafoP para tener la matriz de costes minimos
    GrafoP<double> G(N);
    //Creamos Particion
    Particion p(N);
    //Con esto tenemos las ciudades divididas en sus islas(particiones) y la magtriz de costes minimos
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(Ad[i][j]){
                if (p.encontrar(i)!=p.encontrar(j)){
                    p.unir(p.encontrar(i),p.encontrar(j));
                }

                G[i][j]=std::sqrt(std::pow(ciudades[i].x - ciudades[j].x, 2) +
                                  std::pow(ciudades[i].y - ciudades[j].y, 2));}}}

    matriz<typename GrafoP<double>::vertice> P;
    matriz<double> fin= Floyd(G,P);
    return std::make_pair(p,fin);






}*/

typedef std::pair<double, double> ciudad;
struct Isla{
    vector<ciudad> ciudades;
    matriz<double> costesIsla;
};

//Funcion que nos calcula la distancia euclidea de dos ciudades
double distanciaEuclidea(ciudad c1,ciudad c2)
{
    return std::sqrt(std::pow(c1.first-c2.first,2)+std::pow(c1.second-c2.second,2));
}

//Dado un vector de ciudades calculamos la matriz de costes minimos
matriz<double> costesMinimosIsla(vector<ciudad> ciudades)
{
    size_t N= ciudades.size();
    GrafoP<double> G(ciudades.size());
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            G[i][j]= distanciaEuclidea(ciudades[i],ciudades[j]);

        }

    }
    matriz<typename GrafoP<double>::vertice> P;
    matriz<double> costesMin;
    costesMin= Floyd(G,P);
    return costesMin;




}
//Devuelve las ciudades pertenecientes a una isla.
vector<ciudad> Conjunto(Particion& P,vector<ciudad> ciudades, size_t representante)
{
    size_t N= ciudades.size();
    vector<ciudad> isla;

    for (int j = 0; j < N; ++j) {
        if (representante==P.encontrar(j)){
            isla.push_back(ciudades[j]);
        }


    }
    return isla;




}


vector<Isla> Tombuctu(vector<ciudad> ciudades, const Grafo& G)
{
    size_t N= ciudades.size();
    Particion P(N);
    /* Usar TAD particion para conseguir los distintos subconjuntos*/

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (G[i][j] && P.encontrar(i)!=P.encontrar(j))
                P.unir(P.encontrar(i),P.encontrar(j));}}

    //Tenemos los subconjuntos creados, nos disponemos a insertar en cada isla sus ciudades
    size_t representanteActual;

    Isla m;
    vector<Isla> Archipielago;


    std::set<size_t> representantesProcesados; // Guardará los representantes ya procesados

    for (int j = 0; j < N; ++j) {
        representanteActual = P.encontrar(j);

        // Verificamos si el representante ya ha sido procesado
        if (representantesProcesados.find(representanteActual) == representantesProcesados.end()) {
            // Si no ha sido procesado, lo añadimos al set
            representantesProcesados.insert(representanteActual);

            // Procesamos la isla correspondiente
            m.ciudades = Conjunto(P, ciudades, representanteActual);
            m.costesIsla = costesMinimosIsla(m.ciudades);
            Archipielago.push_back(m);
        }
    }

    return Archipielago;



}






#endif //GRAFOS_EJERCICIO1_H


