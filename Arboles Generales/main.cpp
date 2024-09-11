#include <iostream>
#include <fstream>
#include "AgenEnla.h"
#include "agen_E-S.h"
using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura

/* -----------------PRACTICA 3 EJERCICIO 1-------------------*/
template <typename T>
int grado_rec(typename Agen<T>::nodo n, const Agen<T>& A){
    if(n==Agen<T>::NODO_NULO)return 0;
    else{
        int max=0,cont=0;
       typename Agen<T>::nodo hijo=A.hijoIzqdo(n);
       while(hijo!=Agen<T>::NODO_NULO){
           max=std::max(max, grado_rec(hijo,A));
           hijo= A.hermDrcho(hijo);
           cont++;
       }
       return std::max(cont,max);  //RESPUESTA FINAL



    }

}
template<typename T>
int grado(const Agen<T>& A){
    return grado_rec(A.raiz(),A);
}





/* -----------------PRACTICA 3 EJERCICIO 2-------------------*/

int profNodoAgen_Rec(Agen<tElto> abin, Agen<tElto>::nodo n){
    if(n==Agen<tElto>::NODO_NULO){
        return -1;
    }
    else{
        return 1+ profNodoAgen_Rec(abin, abin.padre(n));
    }


}

/* -----------------PRACTICA 3 EJERCICIO 3-------------------*/
template<typename T>
int alturaNodo_rec(typename Agen<T>::nodo n,const Agen<T>& A)
{
    if(n==Agen<T>::NODO_NULO)return -1;
    else
    {
        int max=0;
         typename Agen<T>::nodo hijo= A.hijoIzqdo(n);
         while(hijo != Agen<T>::NODO_NULO)
         {
             max=std::max(max, alturaNodo_rec(hijo,A));
             hijo=A.hermDrcho(hijo);

         }
         return 1 +max; //RESPUESTA FINAL

    }
}
template<typename T>
int desequilibrio_rec(typename Agen<T>::nodo n, const Agen<T>& A)
{
    if(n==Agen<T>::NODO_NULO) return 0;
    else
    {
        int min=SIZE_MAX;
        typename Agen<T>::nodo hijo= A.hijoIzqdo(n);
        while(hijo!=Agen<T>::NODO_NULO)
        {
            min= std::min(min, alturaNodo_rec(hijo,A));
            hijo= A.hermDrcho(hijo);

        }
        return alturaNodo_rec(A.raiz(),A)-1-min;

    }
}



template<typename T>
int desequilibrio(const Agen<T>& A){
    return desequilibrio_rec(A.raiz(),A);
}

/* -----------------PRACTICA 3 EJERCICIO 4-------------------*/

template <typename T>
 typename Agen<T>::nodo buscar(int elemento,typename Agen<T>::nodo n, const Agen<T>& A)
{
     if(n==Agen<T>::NODO_NULO) return Agen<T>::NODO_NULO;
     else if(elemento==A.elemento(n))return n;

     else
     {
         typename Agen<T>::nodo nodo_bus= Agen<T>::NODO_NULO;
         typename Agen<T>::nodo hijo= A.hijoIzqdo(n);

         while (hijo!=Agen<T>::NODO_NULO && nodo_bus== Agen<T>::NODO_NULO)
         {
             nodo_bus= buscar(elemento,hijo,A);
             hijo=A.hermDrcho(hijo);
         }
         return nodo_bus;


     }
}
template <typename T>
void poda_rec(typename Agen<T>::nodo n, Agen<T>& A) {
    if (n != Agen<T>::NODO_NULO) {
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    while (hijo != Agen<T>::NODO_NULO) {
        poda_rec(hijo, A);
        A.eliminarHijoIzqdo(n);
        hijo = A.hijoIzqdo(n); // Actualizar el hijo para el siguiente ciclo

    }
}

}
template<typename T>
void poda(int elemento ,Agen<T>& A){
    typename Agen<T>::nodo n;
    n= buscar(elemento,A.raiz(),A);
    poda_rec(n,A);


}







int main ()
{
    Agen<tElto> A(16), B(16);
    cout << "*** Lectura del árbol A ***\n";
    rellenarAgen(A, fin); // Desde std::cin
    ofstream fs(“agen.dat”); // Abrir fichero de salida.
    imprimirAgen(fs, A, fin); // En fichero.
    fs.close();
    cout << "\n*** Árbol A guardado en fichero agen.dat ***\n";
    cout << "\n*** Lectura de árbol B de agen.dat ***\n";
    ifstream fe(“agen.dat”); // Abrir fichero de entrada.
    rellenarAgen(fe, B); // Desde fichero.
    fe.close();
    cout << "\n*** Mostrar árbol B ***\n";
    imprimirAgen(B); // En std::cout
}
