#include "ArbolUrgencia.hpp"
#include "iostream"

ArbolUrgencia::ArbolUrgencia(){
    raiz = NULL;
    actual = NULL;
    

    }

void ArbolUrgencia::podar(Anodo& nodo)
{
    if(nodo) {
        podar(nodo->siguiente); // Podar izquierdo
        podar(nodo->anterior);  // Podar derecho
        delete nodo;            // Eliminar nodo
        nodo = NULL;
    }
}
bool ArbolUrgencia::buscar(int CodNumerico)
{
    actual = raiz;
    while(!esVacio(actual)) {
        if(CodNumerico == actual->paciente.getCodNumerico())
            return true;
        else if(CodNumerico > actual->paciente.getCodNumerico())
            actual = actual->siguiente;
        else if(CodNumerico < actual->paciente.getCodNumerico())
            actual = actual->anterior;
    }
    return false;
}
void ArbolUrgencia::insertar(Paciente p)
{
    NodoArbol* padre = NULL;
    actual = raiz;
    contador = contador +1;
    
    while(!esVacio(actual) && p.getCodNumerico() != actual->paciente.getCodNumerico()) {
        padre = actual;
        if(p.getCodNumerico() > actual->paciente.getCodNumerico())
            actual = actual->siguiente;
        else if(p.getCodNumerico() < actual->paciente.getCodNumerico())
            actual = actual->anterior;
    }
    if(!esVacio(actual))
        return;
    if(esVacio(padre))
        raiz = new NodoArbol(p);
    else if(p.getCodNumerico() < padre->paciente.getCodNumerico())
        padre->anterior = new NodoArbol(p);
    else if(p.getCodNumerico() > padre->paciente.getCodNumerico())
        padre->siguiente = new NodoArbol(p);
}

void ArbolUrgencia::borrar(string DNI)
{
    NodoArbol* padre = NULL;
    NodoArbol* nodoaux;
    string DNIaux;
    contador = contador -1;
    actual = raiz;
    while(!esVacio(actual)) {
        if(DNI == actual->paciente.getDNI()) { // Si el valor está en el nodo actual
            if(esHoja(actual)) {
                if(padre) // Si tiene padre (no es el nodo raiz)
                    if(padre->siguiente == actual)
                        padre->siguiente = NULL;
                if(padre->anterior == actual)
                    padre->anterior = NULL;
                delete actual; // Borrar el nodo
                actual = NULL;
                return;
            } else {
                padre = actual;
                if(actual->siguiente) {
                    nodoaux = actual->siguiente;
                    while(nodoaux->anterior) {
                        padre = nodoaux;
                        nodoaux = nodoaux->anterior;
                    }
                } else {
                    nodoaux = actual->anterior;
                    while(nodoaux->siguiente) {
                        padre = nodoaux;
                        nodoaux = nodoaux->siguiente;
                    }
                }
                DNIaux = actual->paciente.getDNI();
                actual->paciente.getDNI() = nodoaux->paciente.getDNI();
                nodoaux->paciente.getDNI() = DNIaux;
                actual = nodoaux;
            }
        } else {
            padre = actual;
            if(DNI > actual->paciente.getDNI())
                actual = actual->siguiente;
            else if(DNI < actual->paciente.getDNI())
                actual = actual->anterior;
        }
    }
}

void ArbolUrgencia::postOrden(Anodo nodo)
{
    if(nodo != NULL) {
        postOrden(nodo->anterior);
        postOrden(nodo->siguiente);
        cout << nodo->paciente.getCodNumerico() << " ";
    }
}

void ArbolUrgencia::inOrden(Anodo nodo)
{
    if(nodo != NULL) {
        inOrden(nodo->anterior);
        cout << nodo->paciente.getCodNumerico() << " ";
        inOrden(nodo->siguiente);
    }
}

void ArbolUrgencia::preOrden(Anodo nodo)
{
    if(nodo != NULL) {
        cout << nodo->paciente.getCodNumerico() << " ";
        postOrden(nodo->anterior);
        postOrden(nodo->siguiente);
    }
}

ArbolUrgencia::~ArbolUrgencia()
{
    podar(raiz);
}
