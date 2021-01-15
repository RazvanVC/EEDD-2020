#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include <iostream>
#include "paciente.hpp"
using namespace std;

class NodoCola
{
public:
    NodoCola(Paciente p, NodoCola* sig = NULL);
    ~NodoCola();
private:
    Paciente paciente;
    NodoCola* siguiente;
    friend class ColaPacientes;
    
};
typedef NodoCola* cnodo;
#endif // NODOCOLA_HPP
