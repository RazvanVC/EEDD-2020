u#include "ListaUrgencia.hpp"

ListaUrgencia::ListaUrgencia()
{  pnodo aux;

    Primero();
    while(pLista) {
        aux = pLista;
        pLista = pLista->siguiente;
        delete aux;
    }
}

void ListaUrgencia::Insertar(int v)
{
    pnodo nuevo;

    Primero();
    // Si la Lista está vacía
    if(ListaVacia() || pLista->valor > v) {
        // Asignamos a Lista un nuevo nodo de valor v y
        // cuyo siguiente elemento es la Lista actual
        nuevo = new nodo(v, pLista);
        if(!pLista)
            pLista = nuevo;
        else
            pLista->anterior = nuevo;
    } else {
        // Buscar el nodo de valor menor a v
        // Avanzamos hasta el último elemento o hasta que el siguiente tenga
        // un valor mayor que v
        while(pLista->siguiente && pLista->siguiente->valor <= v)
            Siguiente();
        // Creamos un nuevo nodo después del nodo actual
        nuevo = new nodo(v, pLista->siguiente, pLista);
        pLista->siguiente = nuevo;
        if(nuevo->siguiente)
            nuevo->siguiente->anterior = nuevo;
    }
}

void ListaUrgencia::Borrar(int v)
{
    pnodo nodo;

    nodo = pLista;
    while(nodo && nodo->valor < v)
        nodo = nodo->siguiente;
    while(nodo && nodo->valor > v)
        nodo = nodo->anterior;

    if(!nodo || nodo->valor != v)
        return;
    // Borrar el nodo

    if(nodo->anterior) // no es el primer elemento
        nodo->anterior->siguiente = nodo->siguiente;
    if(nodo->siguiente) // no el el último nodo
        nodo->siguiente->anterior = nodo->anterior;
    delete nodo;
}

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
void ListaUrgencia::Mostrar()
{
    pnodo nodo;
    {
        primero();
        nodo = pLista;
        while(nodo) {
            cout << nodo->valor << "-> ";
            nodo = nodo->siguiente;
        }
    }
    cout << endl;
}
}

ListaUrgencia::~ListaUrgencia()
{
}

