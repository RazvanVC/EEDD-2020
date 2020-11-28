#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"
#include "paciente.hpp"

class Cola
{
public:
    Cola();
    ~Cola();
    void encolar(Paciente p);
    void desencolar();
    //int primero()
    bool esVacia();
    void verCola();

private:
    NodoCola *frente, *ultimo;
};

#endif // COLA_HPP
