#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

#include "paciente.hpp"

class NodoLista
{
public:
    NodoLista(Paciente p, NodoLista* sig = NULL, NodoLista* ant = NULL);
    ~NodoLista();

    Paciente p;
    NodoLista* siguiente;
    NodoLista* anterior;

    friend class ListaUrgencia;
};

typedef NodoLista* pnodo;
#endif // NODOLISTA_HPP
