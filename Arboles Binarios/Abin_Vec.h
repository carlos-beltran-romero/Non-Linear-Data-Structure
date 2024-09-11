//
// Created by carlo on 16/02/2024.
//

#ifndef ARBOLES_BINARIOS_ABIN_VEC_H
#define ARBOLES_BINARIOS_ABIN_VEC_H
#include <cassert>
#include <iostream>


 template <typename T> class Abin {
 public:
    typedef size_t nodo;
    static const nodo NODO_NULO;
    explicit Abin(size_t maxNodos);
    void insertarRaiz(const T& e);
     void insertarHijoIzqdo(nodo n, const T& e);
     void insertarHijoDrcho(nodo n, const T& e);
     void eliminarHijoIzqdo(nodo n);
     void eliminarHijoDrcho(nodo n);
     void eliminarRaiz();
     bool arbolVacio() const;
     const T& elemento(nodo n) const;
     T& elemento(nodo n);
     nodo raiz() const;
     nodo padre(nodo n) const;
     nodo hijoIzqdo(nodo n) const;
     nodo hijoDrcho(nodo n) const;

     Abin(const Abin<T>& a);// Constructor de copia
     Abin<T>& operator =(const Abin<T>& A); //Asignacion por copia
     ~Abin();

     /*--------------------- EJERCICIO 4 P1-------------------------- */
     size_t alturaNodo(nodo n);
     size_t profundidadNodo(nodo n);
    /*----------------------------------------------------------------*/
 private:
    struct celda{
        T elto;
        nodo padre,hizq,hder;
    };
    celda *nodos;
    size_t maxNodos;
    size_t numNodos;
};


/*--------------------- DEF NODO_NULO-------------------------- */
template <typename T>
const  typename Abin<T>::nodo Abin<T>::NODO_NULO(SIZE_MAX);

/*--------------------- METODOS PUBLICOS-------------------------- */

template <typename T>
Abin<T>::Abin(size_t maxNodos): nodos(new celda[maxNodos]),maxNodos(maxNodos), numNodos(0) {}

template <typename T>
void Abin<T>::insertarRaiz(const T &e) {
    assert(numNodos==0);

    nodos[0].elto=e;
    nodos[0].padre=NODO_NULO;
    nodos[0].hder=NODO_NULO;
    nodos[0].hizq=NODO_NULO;
    numNodos=1;

}

template <typename T>
void Abin<T>::insertarHijoIzqdo(nodo n, const T &e) {
    assert(n>=0 && n<numNodos);
    assert(nodos[n].hizq==NODO_NULO);
    assert(numNodos<maxNodos);

    nodos[n].hizq=numNodos;
    nodos[numNodos].elto=e;
    nodos[numNodos].padre=n;
    nodos[numNodos].hizq=NODO_NULO;
    nodos[numNodos].hder=NODO_NULO;
    ++numNodos;
}

template <typename T>
void Abin<T>::insertarHijoDrcho(Abin::nodo n, const T &e) {
    assert(n>=0&& n<numNodos);
    assert(nodos[n].hder==NODO_NULO);
    assert(numNodos<maxNodos);

    nodos[n].hder=numNodos;
    nodos[numNodos].elto=e;
    nodos[numNodos].padre=n;
    nodos[numNodos].hizq=NODO_NULO;
    nodos[numNodos].hder=NODO_NULO;
    ++numNodos;

}

template <typename T>
void Abin<T>::eliminarHijoIzqdo(nodo n) {
    nodo poshizq= nodos[n].hizq;
    assert(n>=0 && n<numNodos);
    assert(nodos[n].hizq!=NODO_NULO);
    assert(nodos[poshizq].hizq==NODO_NULO && nodos[poshizq].hder==NODO_NULO);

    if (poshizq!= numNodos-1){

        nodos[poshizq]= nodos[numNodos-1];
        //Actualizo padre del nodo movido
        if (nodos[nodos[poshizq].padre].hizq==numNodos-1)
            nodos[nodos[poshizq].padre].hizq=nodos[n].hizq;
        else
            nodos[nodos[poshizq].padre].hder=nodos[n].hizq;

        //Actualizo hijos del nodo movido
        if (nodos[poshizq].hder!=NODO_NULO)
            nodos[nodos[poshizq].hder].padre=poshizq;
        if (nodos[poshizq].hizq!=NODO_NULO)
            nodos[nodos[poshizq].hizq].padre=poshizq;

    }
    nodos[n].hizq=NODO_NULO;
    --numNodos;

}

template<typename T>
void Abin<T>::eliminarHijoDrcho(nodo n) {
     nodo posder= nodos[n].hder;
    assert(n>=0 && n<numNodos);
    assert(nodos[n].hder!=NODO_NULO);
    assert(nodos[posder].hizq==NODO_NULO && nodos[posder].hder==NODO_NULO);
    if (posder!= numNodos-1){
        nodos[posder]=nodos[numNodos-1];
        //Actualizo padre del movido

        nodo papamovido= nodos[posder].padre;
        if(nodos[papamovido].hizq==numNodos-1)
            nodos[papamovido].hizq=posder;
        else
            nodos[papamovido].hder=posder;

        //Actualizo hijos del nodo movido
        if (nodos[posder].hizq!=NODO_NULO) {
            nodo hijoizqmovido = nodos[posder].hizq;
            nodos[hijoizqmovido].padre=posder;
        }
        if (nodos[posder].hder!=NODO_NULO){
            nodo hijodermovido= nodos[posder].hder;
            nodos[hijodermovido].padre=posder;

        }
    }
    nodos[n].hder=NODO_NULO;
    --numNodos;

}

template <typename T>
inline void Abin<T>::eliminarRaiz() {
    assert(numNodos==1);
    numNodos=0;
}

template <typename T>
inline bool Abin<T>::arbolVacio() const {
    return numNodos==0;
}

template <typename T>
inline const T& Abin<T>::elemento(Abin::nodo n) const {
    return nodos[n].elto;
}

template <typename T>
inline T& Abin<T>::elemento(Abin::nodo n) {
    return nodos[n].elto;
}

template <typename T>
inline Abin<T>::nodo Abin<T>::raiz() const {
    return (numNodos>0) ? 0 : NODO_NULO;

}

template <typename T>
inline Abin<T>::nodo Abin<T>::padre(Abin::nodo n) const {
    assert(n>=0 && n<numNodos);
    return nodos[n].padre;
}

template <typename T>
inline Abin<T>::nodo Abin<T>::hijoIzqdo(Abin::nodo n) const {
    assert(n>=0 && n<numNodos);
    return nodos[n].hizq;
}

template <typename T>
inline Abin<T>::nodo Abin<T>::hijoDrcho(Abin::nodo n) const {
    assert(n>=0 && n<numNodos);
    return nodos[n].hder;
}

/*--------------------- EJERCICIO 4 P1-------------------------- */
template<typename T>
size_t Abin<T>::alturaNodo(Abin::nodo n) {
    assert(n>=0 && n<numNodos);


    if(n==NODO_NULO){
        return -1;
    }
    else{
        return 1+(max(alturaNodo(nodos[n].hizq,nodos[n].hder)));
    }

}
template <typename T>
size_t Abin<T>::profundidadNodo(Abin::nodo n) {
    assert(n>=0 && n<numNodos);

    if(n==NODO_NULO)
        return -1;
    else
        return 1+ profundidadNodo(nodos[n].padre);

}

/*----------------------------------------------------------------*/



#endif //ARBOLES_BINARIOS_ABIN_VEC_H
