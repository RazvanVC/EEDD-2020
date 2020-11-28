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
        delete(aux);

    } else if(ultimo->paciente.getDNI() == dni) {
        aux = ultimo;
        ultimo->anterior->siguiente = NULL;
        ultimo = ultimo->anterior;
        delete(aux);
    } else {
        aux = primero;
        while(aux->siguiente->paciente.getDNI() != dni) {
            aux = aux->siguiente;
        }
        aux->siguiente->anterior = aux->anterior;
        aux->anterior->siguiente = aux->siguiente;
        aux->siguiente = NULL;
        aux->anterior = NULL;
        delete(aux);
    }
    size = size - 1;
}

/*void ListaUrgencia::mostrar()
{
    lnodo nodo;
    {
        primero();
        nodo = pLista;
        while(nodo) {
            cout << nodo->paciente << "-> ";
            nodo = nodo->siguiente;
        }
    }
    cout << endl;
}*/

Paciente ListaUrgencia::buscarCodNumerico(int CodNumerico)
{
    lnodo aux;
    aux = primero;
    while(aux->siguiente != NULL) {
        if(aux->paciente.getCodNumerico() == CodNumerico) {
            return aux->paciente;
        } else {
            aux = aux->siguiente;
        }
    }
}

ListaUrgencia::~ListaUrgencia()
{
}
