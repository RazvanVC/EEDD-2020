#include "NodoArbol.hpp"

NodoArbol::NodoArbol(Paciente p, NodoArbol* sig, NodoArbol* ant)
{
    paciente = p;
    siguiente = sig;
    anterior = ant;
}

NodoArbol::~NodoArbol()
{
}
