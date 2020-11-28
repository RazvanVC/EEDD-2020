#include "ListaUrgencia.hpp"
#include <iostream>

ListaUrgencia::ListaUrgencia()
{
    pLista = NULL;
    pnodo aux;

    primero();
    while(pLista) {
        aux = pLista;
        pLista = pLista->siguiente;
        delete aux;
    }
    
}

void ListaUrgencia::insertar(Paciente p)
{
    pnodo nuevo;

    primero();
    // Si la Lista está vacía
    if(ListaVacia() || pLista->paciente.getTiempo() > p.getTiempo()) {
        // Asignamos a Lista un nuevo nodo de valor p y
        // cuyo siguiente elemento es la Lista actual
        new pnodo(p);
        nuevo = new pnodo(p, pLista);
        if(!pLista)
            pLista = nuevo;
        else
            pLista->anterior = nuevo;
    } else {
        // Buscar el nodo de paciente menor a p
        // Avanzamos hasta el último elemento o hasta que el siguiente tenga
        // un paciente mayor que p
        while(pLista->siguiente && pLista->siguiente->paciente <= p)
            siguiente();
        // Creamos un nuevo nodo después del nodo actual
        nuevo = new nodo(p, pLista->siguiente, pLista);
        pLista->siguiente = nuevo;
        if(nuevo->siguiente)
            nuevo->siguiente->anterior = nuevo;
    }
}

void ListaUrgencia::borrar()
{
    pnodo nodo;
    nodo = pLista;
    int valor = cin << "Introduce el número de la lista que quieras borrar" <<
    if (valor > ultimo()){
        cout >> "Valor introducido incorrecto">>
    }
    //else {
    //while(nodo && nodo->valor < v)
    //    nodo = nodo->siguiente;
    //while(nodo && nodo->valor > v)
    //    nodo = nodo->anterior;

    //if(!nodo || nodo->valor != v)
    //    return;
    // Borrar el nodo

    //if(nodo->anterior) // no es el primer elemento
    //    nodo->anterior->siguiente = nodo->siguiente;
    //if(nodo->siguiente) // no el el último nodo
    //    nodo->siguiente->anterior = nodo->anterior;
    //delete nodo;
    }
;}
bool ListaUrgencia::ListaVacia() // Comprueba si la lista está vacía
{
    if(ultimo == NULL && primero == NULL) {
        return true;
    } else {
        return false;
    }
}

void ListaUrgencia::primero()
{
    while(pLista && pLista->anterior)
        pLista = pLista->anterior;
}

void ListaUrgencia::ultimo()
{
    while(pLista && pLista->siguiente)
        pLista = pLista->siguiente;
}
void ListaUrgencia::siguiente()
{
    if(pLista)
        pLista = pLista->siguiente;
}

void ListaUrgencia::anterior()
{
    if(pLista)
        pLista = pLista->anterior;
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
