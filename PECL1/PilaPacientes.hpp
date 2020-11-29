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
	Paciente buscar(string dni);

private:
    pnodo ultimo;
};

#endif // PILAPACIENTES_HPP