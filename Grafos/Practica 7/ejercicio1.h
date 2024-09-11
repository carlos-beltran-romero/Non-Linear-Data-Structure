#include "../alg_grafoPMC.h"
#include <iostream>

template<typename tCoste>
struct viaje{
    typename GrafoP<tCoste>::vertice origen,destino;
    tCoste Coste;

};
template <typename tCoste>
 matriz <tCoste> FloydMod(const GrafoP<tCoste>& G,matriz<typename GrafoP<tCoste>::vertice>& P)
 {
     typedef typename GrafoP<tCoste>::vertice vertice;
     const size_t n = G.numVert();
     matriz<tCoste> A(n);   // matriz de costes mínimos

     // Iniciar A y P con caminos directos entre cada par de vértices.
     P = matriz<vertice>(n);
     for (vertice i = 0; i < n; i++) {
         A[i] = G[i];                    // copia costes del grafo
         A[i][i] = 0;                    // diagonal a 0
         P[i] = vector<vertice>(n, i);   // caminos directos
     }
     // Calcular costes maximos y caminos correspondientes
     // entre cualquier par de vértices i, j
     for (vertice k = 0; k < n; k++)
         for (vertice i = 0; i < n; i++)
             for (vertice j = 0; j < n; j++) {
                 tCoste ikj = suma(A[i][k], A[k][j]);
                 if (ikj > A[i][j]) {
                     A[i][j] = ikj;
                     P[i][j] = k;
                 }
             }
     return A;

}


template <typename tCoste>
viaje<tCoste> viajeMasCaro(const GrafoP<tCoste>& G )
{
    tCoste coste=0;
    typename GrafoP<tCoste>::vertice o,d;
     matriz<typename GrafoP<tCoste>::vertice > P;
     matriz<tCoste> costesMaximos= FloydMod(G,P);
     for( typename GrafoP<tCoste>::vertice i=0;i<G.numVert();i++){
         for( typename GrafoP<tCoste>::vertice j=0;j<G.numVert();j++){
             if (costesMaximos[i][j]>coste && costesMaximos[i][j]!= GrafoP<tCoste>::INFINITO){
                 coste=costesMaximos[i][j];
                 o=i;
                 d=j;
             }
         }
     }

     viaje<tCoste> A;
     A.origen=o;
     A.destino=d;
     A.Coste=coste;
     return A;


}


















