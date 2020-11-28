#include "NodoLista.hpp"
NodoLista::NodoLista(Paciente p, NodoLista* sig, NodoLista* ant)
{
    Paciente = p;
    siguiente = sig;
    anterior = ant;
}

NodoLista::~NodoLista()
{
}
