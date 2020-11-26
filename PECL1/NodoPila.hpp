#ifndef NODOPILA_HPP
#define NODOPILA_HPP

#include "paciente.hpp"

#include <iostream>
using namespace std;

class NodoPila
{
public:
    NodoPila(Paciente p, NodoPila* sig = NULL);
    ~NodoPila();
    Paciente paciente;
    NodoPila* siguiente;
    friend class Cola;
    friend class Pila;
};
typedef NodoPila* pnodo;

#endif // NODOPILA_HPP