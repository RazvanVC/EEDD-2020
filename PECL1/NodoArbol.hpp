#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP

#include "paciente.hpp"

class NodoArbol
{
public:
    NodoArbol(Paciente paciente, NodoArbol* sig = NULL, NodoArbol* ant = NULL);
    ~NodoArbol();
    Paciente paciente;
    NodoArbol* siguiente;
    NodoArbol* anterior;
    friend class ArbolUrgencia;
};

typedef NodoArbol* Anodo;
#endif // NODOARBOL_HPP
