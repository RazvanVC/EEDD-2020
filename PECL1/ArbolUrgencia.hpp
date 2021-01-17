#ifndef ARBOLURGENCIA_HPP
#define ARBOLURGENCIA_HPP
#include "NodoArbol.hpp"

class ArbolUrgencia
{
private:
        Anodo raiz;
        Anodo actual = NULL;
        void podar(Anodo& nodo);
        void auxContador(Anodo nodo);
        void auxAltura(Anodo nodo, int a);
        
    public:
        ArbolUrgencia();
        ~ArbolUrgencia();
        void mostrar();
        Paciente buscar(int CodNumerico);
        void insertar(Paciente p);
        void insertarAux(Anodo nodo, Paciente p);
        void borrarA(string DNI);
        bool esVacio(Anodo nodo) {return nodo == NULL;} 
        bool esHoja(Anodo nodo) {return !nodo->siguiente && !nodo->anterior ;} 
        int size;
        int getAlturaArbol();
        Paciente getValorActual() {return actual->paciente;}
        void esRaiz() {actual = raiz;}
        void inOrden(NodoArbol* nodo);
        void preOrden(NodoArbol* nodo);
        void postOrden(NodoArbol* nodo);

};

#endif // ARBOLURGENCIA_HPP
