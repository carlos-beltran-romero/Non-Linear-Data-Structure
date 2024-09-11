#include "../alg_grafoPMC.h"
#include <iostream>



template <typename tCoste>
tCoste longitudD(const GrafoP<tCoste>& G)
{
    
    typedef typename GrafoP<tCoste>::vertice vertice;
    matriz<vertice> P;
    matriz<tCoste> costes_minimos=Floyd(G,P);
    tCoste diametro=GrafoP<tCoste>::INFINITO;
    tCoste a,b;
    for(int i=0;i<G.numVert();i++){
        a=0;
        b=0;

        for(int j=0;j<G.numVert();j++){
            if(costes_minimos[i][j]>a)
            {
                b=a;
                a=costes_minimos[i][j];

            }
            else if( costes_minimos[i][j]>b)
            {
                b=costes_minimos[i][j]
            }



        }
        if(a+b<diametro)
            diametro=a+b;
    }
    return diametro;





}