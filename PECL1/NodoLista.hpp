#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

#include "paciente.hpp"

class NodoLista
{
public:
    NodoLista(Paciente paciente, NodoLista* sig = NULL, NodoLista* ant = NULL);
    ~NodoLista();
    Paciente paciente;
    NodoLista* siguiente;
    NodoLista* anterior;
    friend class ListaUrgencia;
};

typedef NodoLista* lnodo;
#endif // NODOLISTA_HPP
