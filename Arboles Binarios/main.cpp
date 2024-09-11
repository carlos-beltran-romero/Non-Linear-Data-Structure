#include <iostream>
#include "Abin_Enla.h"
#include "abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin='#';


/*--------------------- EJERCICIO 1 P1-------------------------- */
size_t numNodosAbin_Rec(const Abin<tElto>& abin,  typename Abin<tElto>::nodo n);

size_t numNodosAbin(const Abin<tElto>& A)
{
    return numNodosAbin_Rec(A, A.raiz());
}

size_t numNodosAbin_Rec(const Abin<tElto>& A,  typename Abin<tElto>::nodo n) {
    if(n==Abin<tElto>::NODO_NULO){
        return 0;
    }
    else{
         return 1+numNodosAbin_Rec(A,A.hijoIzqdo(n))+ numNodosAbin_Rec(A,A.hijoDrcho(n));

    }
}

/*--------------------- EJERCICIO 2 P1-------------------------- */

size_t alturaAbin_Rec(Abin<tElto> abin,  typename Abin<tElto>::nodo n);

size_t alturaAbin(Abin<tElto> abin){
    return alturaAbin_Rec(abin, abin.raiz());
}

size_t alturaAbin_Rec(Abin<tElto> abin,  typename Abin<tElto>::nodo n){
    if(n==Abin<tElto>::NODO_NULO){
        return -1;
    }
    else{
        return 1+ max(alturaAbin_Rec(abin, abin.hijoIzqdo(n)), alturaAbin_Rec(abin,abin.hijoDrcho(n)));

    }

}

/*--------------------- EJERCICIO 3 P1-------------------------- */

size_t profNodoAbin_Rec(const Abin<tElto>& abin,  typename Abin<tElto>::nodo n){
    if(n==Abin<tElto>::NODO_NULO){
        return -1;
    }
    else{
        return 1+ profNodoAbin_Rec(abin,abin.padre(n) );
    }


}

/*--------------------- EJERCICIO 6 P1-------------------------- */
int desequilibrio_rec(const Abin<tElto>& A, typename Abin<tElto>::nodo n) ;

int desequilibrio(const Abin<tElto>& A)
{
   /* if(A.arbolVacio())
        return 0; ESTA LINEA NO HACE FALTA PORQUE SI ES UN ARBOL VACIO A.RAIZ() DEVUELVE NODO_NULO*/
    //else
        return desequilibrio_rec(A, A.raiz());
}


int desequilibrio_rec(const Abin<tElto>& A, typename Abin<tElto>::nodo n) {
    if (n == Abin<tElto>::NODO_NULO)
        return 0;
    else
        return std::max(abs(A.alturaNodo(A.hijoDrcho(n)) - A.alturaNodo(A.hijoIzqdo(n))),
                        std::max(desequilibrio_rec(A, A.hijoDrcho(n)), desequilibrio_rec(A, A.hijoIzqdo(n))));

}
/*--------------------- EJERCICIO 7 P1 CREO QUE BIEN-------------------------- */
template<typename T>
size_t alturaNodo_rec( typename Abin<T>::nodo n, const Abin<T>&A)
{
    if(n==Abin<T>::NODO_NULO)return -1;
    else return 1+ max(alturaNodo_rec(A.hijoIzqdo(n),A), alturaNodo_rec(A.hijoDrcho(n)));
}
template <typename T>
bool pseudocompleto_rec(typename Abin<T>::nodo n, const Abin<T>& A){
    if(alturaNodo_rec(n)==1)
    {
        if((A.hijoIzqdo(n)==Abin<T>::NODO_NULO && A.hijoDrcho(n)==Abin<T>::NODO_NULO)||
        (A.hijoIzqdo(n)!=Abin<T>::NODO_NULO && A.hijoDrcho(n)!=Abin<T>::NODO_NULO))
        {
            return true;
        }
        else return false;
    }
    else if(alturaNodo_rec(A.hijoIzqdo(n)> alturaNodo_rec(A.hijoDrcho(n))))
    {
        return pseudocompleto_rec(A.hijoIzqdo(n),A);

    }
    else if(alturaNodo_rec(A.hijoIzqdo(n)< alturaNodo_rec(A.hijoDrcho(n))))
    {
        return pseudocompleto_rec(A.hijoDrcho(n),A);
    }
    else{
        return pseudocompleto_rec(A.hijoIzqdo(n),A) && pseudocompleto_rec(A.hijoDrcho(n),A);


    }
}
template <typename T>
bool pseudocompleto(const Abin<T>& A){
    if(A.arbolVacio()) return false;
    if(A.hijoIzqdo(A.raiz()==Abin<T>::NODO_NULO && A.hijoDrcho(A.raiz()==Abin<T>::NODO_NULO)))return false;
    else return pseudocompleto_rec(A.raiz(),A);
}



/*--------------------- EJERCICIO 1 P2-------------------------- */
template <typename T>
bool similares_rec( typename Abin<T>::nodo nA, const Abin<T>& A,  typename Abin<tElto>::nodo nB, const Abin<T>& B){
    if(nA==Abin<T>::NODO_NULO && nB==Abin<T>::NODO_NULO)return true;
    else {

        if (nA == Abin<T>::NODO_NULO || nB == Abin<T>::NODO_NULO) return false;

        else
            return similares_rec(A.hijoIzqdo(nA), A, B.hijoIzqdo(nB), B) &&
                   similares_rec(A.hijoDrcho(nA), A, B.hijoDrcho(nB), B);
    }


}

template <typename T>
bool similares(const Abin<T>& A, const Abin<T>& B){
    return similares_rec(A.raiz(),A,B.raiz(),B);
}

/*--------------------- EJERCICIO 2 P2-------------------------- */
template<typename T>
Abin<T> reflejado_rec(typename Abin<T>::nodo n,const Abin<T>& A, Abin<T>& B ){

        if(A.hijoIzqdo(n)!=Abin<T>::NODO_NULO){
            B.insertarHijoDrcho(A.hijoIzqdo(n));// MAL
            reflejado_rec(A.hijoIzqdo(n),A,B);
        }
        if (A.hijoDrcho(n)!=Abin<T>::NODO_NULO){
            B.insertarHijoIzqdo(A.hijoDrcho(n));//MAL
            reflejado_rec(A.hijoDrcho(n),A,B);
        }

}

template<typename T>
Abin<T> reflejado( const Abin<T>&A){
    Abin<T> B;
    B.insertarRaiz(A.elemento(A.raiz()));
    if (A.arbolVacio()) return A.arbolVacio();
    else return reflejado_rec(A.raiz(),A,B);
}

/*--------------------- EJERCICIO 3 P2-------------------------- */
union expresion{
    double operando;
    char operador;
};
double aritmetico_rec(Abin<expresion>::nodo n, const Abin<expresion>& A) {
    if (A.hijoIzqdo(n) == Abin<expresion>::NODO_NULO) {
        return A.elemento(n).operando;
    } else {
        switch (A.elemento(n).operador) {
            case '+':
                return aritmetico_rec(A.hijoIzqdo(n), A) + aritmetico_rec(A.hijoDrcho(n), A);
                break;
            case '-':
                return aritmetico_rec(A.hijoIzqdo(n), A) - aritmetico_rec(A.hijoDrcho(n), A);
                break;
            case '*':
                return aritmetico_rec(A.hijoIzqdo(n), A) * aritmetico_rec(A.hijoDrcho(n), A);
                break;
            case '/':
                return aritmetico_rec(A.hijoIzqdo(n), A) / aritmetico_rec(A.hijoDrcho(n), A);
                break;
        }
    }
}
double aritmetico(const Abin<expresion>& A){
    if(A.arbolVacio())return 0;
    else return aritmetico_rec(A.raiz(),A);
}

/*--------------------- EJERCICIO EXAMEN-------------------------- */
/*Contar el numero de nodos de un arbol binario que tienen exactamente 3 nietos*/
template<typename T>
size_t contar(size_t cont,  typename Abin<T>::nodo n, const Abin<T>& A){
    size_t aux=0;
    if(A.hijoIzqdo(n)!=Abin<T>::NODO_NULO && A.hijoDrcho(n)!=Abin<T>::NODO_NULO){
        if(A.hijoIzqdo(A.hijoIzqdo(n))!=Abin<T>::NODO_NULO)aux++;
        if(A.Drcho(A.hijoIzqdo(n))!=Abin<T>::NODO_NULO)aux++;
        if (A.hijoIzqdo(A.hijoDrcho(n))!=Abin<T>::NODO_NULO)aux++;
        if (A.hijoDrcho(A.hijoDrcho(n))!=Abin<T>::NODO_NULO)aux++;
        if(aux==3){
            cont++;
        }


    }
    return cont;

}
template <typename T>
size_t nietos_rec(size_t cont,typename Abin<T>::nodo n, const Abin<T>& A){
    if(A.alturaNodo(n)<2){
        return cont;
    } else{
        cont=contar(cont,n,A);
        nietos_rec(cont,A.hijoIzqdo(n),A);
        nietos_rec(cont,A.hijoDrcho(n),A);
    }

}
template <typename T>
size_t nietos(const Abin<T>& A){
   return nietos_rec(0,A.raiz(),A);

}

/* Otra Version numero nietos==3 sin usar contador*/
template <typename T>
size_t contar2(typename Abin<T>::nodo n, const Abin<T>& A){
    size_t aux=0;
    if(A.hijoIzqdo(n)!=Abin<T>::NODO_NULO && A.hijoDrcho(n)!=Abin<T>::NODO_NULO){
        if(A.hijoIzqdo(A.hijoIzqdo(n))!=Abin<T>::NODO_NULO)aux++;
        if(A.Drcho(A.hijoIzqdo(n))!=Abin<T>::NODO_NULO)aux++;
        if (A.hijoIzqdo(A.hijoDrcho(n))!=Abin<T>::NODO_NULO)aux++;
        if (A.hijoDrcho(A.hijoDrcho(n))!=Abin<T>::NODO_NULO)aux++;

    }
    return aux;
}
template <typename T>
size_t nietos_rec2(typename Abin<T>::nodo n, const Abin<T>& A) {
    if (A.alturaNodo(n) < 2) return 0;

    else {

        if (contar(n, A) == 3) return 1 + nietos_rec2(A.hijoIzqdo(n),A)+ nietos_rec2(A.hijoDrcho(n),A);
        else return nietos_rec2(A.hijoIzqdo(n),A)+ nietos_rec2(A.hijoDrcho(n),A);


    }
}
template <typename T>
size_t nietos2(const Abin<T>& A){
    return nietos_rec2(A.raiz(),A);
}


/*Contar el numero de nodos de un arbol que tenga el doble de nietos que de bisnietos*/
template <typename T>
size_t num_hijos(typename  Abin<T>::nodo n,const Abin<T>& A )
{

    size_t aux=0;
    if(A.hijoIzqdo(n)!=Abin<T>::NODO_NULO)aux++;
    if (A.hijoDrcho(n)!=Abin<T>::NODO_NULO)aux++;
    return aux;
}
template <typename T>
size_t num_nietos(typename Abin<T>::nodo n, const Abin<T>& A){

    return num_hijos(A.hijoIzqdo(n),A)+ num_hijos(A.hijoDrcho(n),A);
}
template <typename T>
size_t num_bisnietos(typename Abin<T>::nodo n, const Abin<T>&A){
    return num_nietos(A.hijoIzqdo(n),A)+ num_nietos(A.hijoDrcho(n));
}
template <typename T>
size_t bisnietos_rec(typename Abin<T>::nodo n, const Abin<T>& A){
    if(A.alturaNodo(n)<3){
        return 0;
    }
    else{
        if(2* num_bisnietos(n,A)== num_nietos(n,A))return 1+ bisnietos_rec(A.hijoIzqdo(n),A)+ bisnietos_rec(A.hijoDrcho(n),A);
        else return bisnietos_rec(A.hijoIzqdo(n),A)+ bisnietos_rec(A.hijoDrcho(n),A);
    }
}
template <typename T>
size_t bisnietos(const Abin<T>& A){
    return bisnietos_rec(A.raiz(),A);
}

/*Dado un árbol binario de un tipo genérico T calcular el número de nodos que siendo hermanos entre
sí tienen misma raíz y sus subárboles son reflejados (respecto a sus elementos).*/
/* NO ES SEGURO SI ESTA BIEN*/

template<typename T>
bool comprueba()
template <typename T>
size_t num_nodosReflejados(typename Abin<T>::nodo n, const Abin<T>& A){
    if(A.hijoIzqdo(n)!=Abin<T>::NODO_NULO && A.hijoDrcho(n)!= Abin<T>::NODO_NULO){
        if(comprueba(A.hijoIzqdo(n),A.hijoDrcho(n),A)) return 2+ num_nodosReflejados(A.hijoIzqdo(n),A)+
                                                                num_nodosReflejados(A.hijoDrcho(n),A);
        else{return num_nodosReflejados(A.hijoIzqdo(n),A)+
                    num_nodosReflejados(A.hijoDrcho(n),A);

        }
    }




}
















int main() {
    Abin<tElto> A,B;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // Desde std::cin
    ofstream fs("abin.dat"); // Abrir fichero de salida.
    imprimirAbin(fs, A, fin); // En fichero.
    fs.close();
    cout << "\n*** Árbol A guardado en fichero abin.dat ***\n";
    cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
    ifstream fe("abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, B); // Desde fichero.
    fe.close();
    cout << "\n*** Mostrar árbol binario B ***\n";
    imprimirAbin(B); // En std::cout


    return 0;
}
