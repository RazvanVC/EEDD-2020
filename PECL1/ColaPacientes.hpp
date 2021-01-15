#ifndef COLAPACIENTES_HPP
#define COLAPACIENTES_HPP
#include "NodoCola.hpp"

class ColaPacientes
{
public:
    ColaPacientes();
    ~ColaPacientes();
    void insertar (Paciente p);
    void imprimir();
    Paciente eliminar();
    
private:
    cnodo primero, ultimo;
};

#endif // COLAPACIENTES_HPP
