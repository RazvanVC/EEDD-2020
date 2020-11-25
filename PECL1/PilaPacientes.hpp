#ifndef PILAPACIENTES_HPP
#define PILAPACIENTES_HPP

#include "NodoPila.hpp"
class PilaPacientes
{
public:
    PilaPacientes();
    ~PilaPacientes();
    void insertar(Paciente v);
    Paciente extraer();
    void mostrar();
    bool estaVacia();

private:
    pnodo ultimo;
};

#endif // PILAPACIENTES_HPP