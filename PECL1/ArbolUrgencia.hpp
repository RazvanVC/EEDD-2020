#ifndef ARBOLURGENCIA_HPP
#define ARBOLURGENCIA_HPP
#include "NodoArbol.hpp"

class ArbolUrgencia
{
private:
        Anodo raiz;
        Anodo actual = NULL;
        int contador, altura;
        void podar(Anodo& nodo);
        void auxContador(Anodo nodo);
        void auxAltura(Anodo nodo, int a);
        void mostrar(int& d);

    public:
        ArbolUrgencia();
        ~ArbolUrgencia();
        bool buscar(int CodNumerico);
        void insertar(Paciente p);
        void borrar(string DNI);
        bool esVacio(Anodo nodo) {return raiz == NULL;} 
        bool esHoja(Anodo nodo) {return !nodo->siguiente && !nodo->anterior ;} 
        int numeroNodos();
        int getAlturaArbol();
        Paciente getValorActual() {return actual->paciente;}
        void esRaiz() {actual = raiz;}
        void inOrden(NodoArbol* nodo);
        void preOrden(NodoArbol* nodo);
        void postOrden(NodoArbol* nodo);

};

#endif // ARBOLURGENCIA_HPP
