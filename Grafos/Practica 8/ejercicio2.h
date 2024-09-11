//
// Created by carlo on 24/08/2024.
//

#ifndef GRAFOS_EJERCICIO2_H
#define GRAFOS_EJERCICIO2_H
#include "../alg_grafoPMC.h"
#include "ejercicio1.h"
#include <iostream>

/*DATO= CREO QUE EN VEZ DE HACER 4 BUCLES ANIDADOS, ES MAS EFICIENTE CON UN APO


/*Nos dicen que la línea aerea escogida entre cada par de isla sera la mas corta entre todas las posibles
 * Se me ocurre primero con TAD Particion ver que ciudades pertenecen a que isla. Luego sacar las dos ciudades
 * de islas distintas que mas cercas se encuentreny ahi implantar la linea aerea. Hacer eso con cada par de islas.
 * */

typedef std::pair<double,double> ciudad;
struct lineaAerea{
    size_t origen,destino;
    lineaAerea(size_t o, size_t d):origen(o),destino(d){}
};



vector<lineaAerea> Tombuctu2(const Grafo G, vector<ciudad> ciudades)
{
    vector<Isla> archipielago= Tombuctu(ciudades,G);
    size_t N= archipielago.size();
    double distanciaMin= GrafoP<double>::INFINITO;
    size_t o,d;
    vector<lineaAerea> LA;


    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            distanciaMin=GrafoP<double>::INFINITO;
            for (int k = 0; k < archipielago[i].ciudades.size(); ++k) {
                for (int l = 0; l < archipielago[k].ciudades.size(); ++l) {
                    if (distanciaEuclidea(archipielago[i].ciudades[k],archipielago[j].ciudades[l])< distanciaMin){
                        o=k;
                        d=l;
                        distanciaMin=distanciaEuclidea(archipielago[i].ciudades[k],archipielago[j].ciudades[l]);

                    }

                }

            }
            LA.push_back(lineaAerea(o,d));


        }

    }
    return LA;








}

#endif //GRAFOS_EJERCICIO2_H
