#include "NodoLista.hpp"

NodoLista::NodoLista(Paciente p, NodoLista* sig, NodoLista* ant)
{
    paciente = p;
    siguiente = sig;
    anterior = ant;
}

NodoLista::~NodoLista()
{
}
