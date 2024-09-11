#include <iostream>
#include <vector>
#include "Abb.h"
template<typename T>
using Conjunto = Abb<T>;

/*------------------------PRACTICA 4 EJERCICIO 2-----------------------------------*/
template <typename T>
void equilibrio (const Abb<T>& A, const Abb<T>& B){
    std::vector<T> v;
    fill(v,A);
    sort(v.begin(),v.end());
    unsigned tam= v.size();
    equilibrio_rec(v,B,tam,0);

}
template <typename T>
void fill(std::vector<T> v, const Abb<T>& A){
    if(!A.vacio()) {
        v.push_back(A.elemento());
        fill(v, A.izqdo());
        fill(v, A.drcho());
    }

}

template <typename T>
void equilibrio_rec(std::vector<T> v, Abb<T>& B, unsigned fin, unsigned ini){
    if(fin!=ini){
        unsigned pos=((fin-ini)/2)+ini;
        B.insertar(v[pos]);
        equilibrio_rec(v,B,pos,ini);
        equilibrio_rec(v,B,fin,pos+1);

    }
}

/*------------------------PRACTICA 4 EJERCICIO 3-----------------------------------*/

template <typename T>
void rellenar_conjunto_recA(const Conjunto<T>& A, Conjunto<T>& C)
{
    if(!A.vacio()) {
        C.insertar(A.elemento());
        rellenar_conjunto_rec(A.izqdo(), C);
        rellenar_conjunto_rec(A.drcho(), C);
    }



}
template <typename T>
void rellenar_conjunto_recB(const Conjunto<T>& B, Conjunto<T>& C)
{
    if(!B.vacio()) {
        C.insertar(B.elemento());
        rellenar_conjunto_rec(B.izqdo(), C);
        rellenar_conjunto_rec(B.drcho(), C);
    }



}

template <typename T>
Conjunto<T> union_conjunto(Conjunto<T> A,Conjunto<T> B)
{
    Conjunto<T> C,final;
    rellenar_conjunto_recA(A,B,C);
    rellenar_conjunto_recB(B,C);
    equilibrio(C,final);
    return final;




}

/*------------------------PRACTICA 4 EJERCICIO 4-----------------------------------*/
template<typename T>
void recorrido(const T& elto, const Conjunto<T>& B,Conjunto<T>& C)
{
    if(!B.buscar(elto).vacio())
    {
        C.insertar(B.buscar(elto).elemento());

    }

}



template <typename T>
void interseccion(const Conjunto<T>& A, const Conjunto<T>& B, Conjunto<T>& C)
{
    if(!A.vacio())
    {
        recorrido(A.elemento(),B,C);
        interseccion(A.izqdo(),B,C);
        interseccion(A.drcho(),B,C);
    }




}



template <typename T>
Conjunto<T> interseccion_conjunto(Conjunto<T> A,Conjunto<T> B)
{
    Conjunto<T> C,final;
    interseccion(A,B,C);

    equilibrio(C,final);
    return final;




}


/*------------------------PRACTICA 4 EJERCICIO 5-----------------------------------*/
template <typename T>
void resta(const T& elto, const Conjunto<T>& B, Conjunto<T>& C)
{
    if(B.buscar(elto).vacio())
        C.insertar(elto);
}



template<typename T>
void elemento( const Conjunto<T>&A, const Conjunto<T>& B,Conjunto <T>& C)
{
    if(!A.vacio())
    {
        resta(A.elemento(),B,C);
        interseccion(A.izqdo(),B,C);
        interseccion(A.drcho(),B,C);
    }


}




template <typename T>
Conjunto<T> resta_conjunto(Conjunto<T> A,Conjunto<T> B)
{
    Conjunto<T> interseccion,unionn,C,final;
    interseccion= interseccion_conjunto(A,B);
    unionn= union_conjunto(A,B);
    elemento(unionn,interseccion,C);
    equilibrio(C,final);
    return final;


}












int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
