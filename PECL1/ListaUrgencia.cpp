#include "ListaUrgencia.hpp"
#include <iostream>

ListaUrgencia::ListaUrgencia()
{
    primero = NULL;
    ultimo = NULL;
    size = 0;
}

void ListaUrgencia::insertar(Paciente nuevo)
{
    lnodo aux;
    lnodo n;

    n = new NodoLista(nuevo);

    if(primero == NULL) {
        primero = n;
        ultimo = n;
    } else {
        // nuevo tiene hora más pequeño
        if(nuevo.getTiempo() > primero->paciente.getTiempo()) {
            n->siguiente = primero;
            primero->anterior = n;
            primero = n;
        } else if(nuevo.getTiempo() <= ultimo->paciente.getTiempo()) {
            ultimo->siguiente = n;
            n->anterior = ultimo;
            ultimo = n;
        } else {
            aux = primero;
            while(aux->siguiente->paciente.getPrioridad() > nuevo.getTiempo()) {
                aux = aux->siguiente;
            }
            n->siguiente = aux->siguiente;
            n->anterior = aux;
            aux->siguiente->anterior = n;
            aux->siguiente = n;
        }
    }
    size = size + 1;
}

void ListaUrgencia::borrar(string dni)
{
    lnodo aux;

    if(primero->paciente.getDNI() == dni) {
        aux = primero;
        primero->siguiente->anterior = NULL;
        primero->siguiente = primero;
        aux->siguiente = NULL;
        delete(aux);
        size = size - 1;
    } else if(ultimo->paciente.getDNI() == dni) {
        aux = ultimo;
        ultimo = ultimo->anterior;
        ultimo->siguiente = NULL;
        aux->anterior = NULL;
        delete(aux);
        size = size - 1;
    } else {
        aux = primero;
        while(aux->siguiente != NULL or aux->paciente.getDNI() == dni) {
            aux = aux->siguiente;
        }
        if(aux->paciente.getDNI() == dni) {
            aux->siguiente = aux->anterior;
            aux->anterior = aux->siguiente;
            aux->siguiente = NULL;
            aux->anterior = NULL;
            delete(aux);
            size = size - 1;
        }
    }
}

void ListaUrgencia::mostrar()
{
    lnodo aux;
    aux = primero;
    while(aux->siguiente != NULL) {
        aux->paciente.imprimeLista();
        aux = aux->siguiente;
    }
    cout << endl;
}

Paciente ListaUrgencia::buscarCodNumerico(int CodNumerico)
{
    lnodo aux;
    aux = primero;
    while(aux->siguiente != NULL or aux->paciente.getCodNumerico() == CodNumerico)
        if(aux->paciente.getCodNumerico() == CodNumerico) {
            return aux->paciente;
        } else {
            aux = aux->siguiente;
        }
    Paciente p0 = Paciente();
    return p0; // Hay que comprobar que el código sea mayor que -1, si no el paciente no existe.
}

ListaUrgencia::~ListaUrgencia()
{
}
