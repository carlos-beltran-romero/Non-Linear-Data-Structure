#include "../alg_grafoPMC.h"
#include <iostream>
/*El planteamiento de este problema consiste en que primeramente modificamos floyd para
que la diagonal principal contenga infinitos, es decir no ponerla a 0
Luego si despues de aplicar floyd hay algun elemento de la d.p que no este a infinito
esto quiere decir que se puede llegar hasta ese elemento a traves de otro nodo y por
lo tanto habria ciclo.*/

template <typename tCoste>

matriz<tCoste> FloydMod(const GrafoP<tCoste>& G, matriz<typename GrafoP<tCoste>::vertice>& P)
{
       typedef typename GrafoP<tCoste>::vertice vertice;
       const size_t n= G.numVert();
       matriz<tCoste> A(n);
       for(int i=0;i<n;i++)
       {
        A[i]=G[i];
        P[i]=vector<vertice>(n,i);
       }
        // Calcular costes mínimos y caminos correspondientes
   // entre cualquier par de vértices i, j
   for (vertice k = 0; k < n; k++)
      for (vertice i = 0; i < n; i++)
         for (vertice j = 0; j < n; j++) {
            tCoste ikj = suma(A[i][k], A[k][j]);
            if (ikj < A[i][j]) {
               A[i][j] = ikj;
               P[i][j] = k;
            }
         }
   return A;

}

template <typename tCoste>
bool Subvención(const GrafoP<tCoste>& G)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t n= G.numVert();
    bool valido=true;

    matriz<vertice> P;
    matriz<tCoste> costes_minimos= FloydMod(G,P);

    for(int i=0;i<n;i++)
    {
        if(costes_minimos[i][i]!= GrafoP<tCoste>::INFINITO)valido=false;
    }

    return valido;




}