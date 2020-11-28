#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include "paciente.hpp"

class NodoCola
{
public:
    NodoCola(Paciente p, NodoCola *sig);
    ~NodoCola();
private:
    Paciente p;
    NodoCola* sig;
    friend class cola;
};

#endif // NODOCOLA_HPP
