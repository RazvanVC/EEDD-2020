#include "ListaUrgencia.hpp"
#include <iostream>

ListaUrgencia::ListaUrgencia()
{
primero = NULL;
ultimo= NULL;
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

void ListaUrgencia::borrar()
{
    pnodo nodo;
    nodo = pLista;
    int valor = cin << "Introduce el número de la lista que quieras borrar" << if(valor > ultimo())
    {
        cout >> "Valor introducido incorrecto" >>
    }
    // else {
    // while(nodo && nodo->valor < v)
    //    nodo = nodo->siguiente;
    // while(nodo && nodo->valor > v)
    //    nodo = nodo->anterior;

    // if(!nodo || nodo->valor != v)
    //    return;
    // Borrar el nodo

    // if(nodo->anterior) // no es el primer elemento
    //    nodo->anterior->siguiente = nodo->siguiente;
    // if(nodo->siguiente) // no el el último nodo
    //    nodo->siguiente->anterior = nodo->anterior;
    // delete nodo;
};
}


void ListaUrgencia::getprimero()
{
   return primero;
}

void ListaUrgencia::getultimo()
{
    return ultimo;
}



void ListaUrgencia::mostrar()
{
    pnodo nodo;
    {
        primero();
        nodo = pLista;
        while(nodo) {
            cout << nodo->paciente << "-> ";
            nodo = nodo->siguiente;
        }
    }
    cout << endl;
}
ListaUrgencia::~ListaUrgencia()
{
}
