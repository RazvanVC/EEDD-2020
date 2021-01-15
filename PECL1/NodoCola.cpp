#include "NodoCola.hpp"

NodoCola::NodoCola(Paciente p, NodoCola* sig)
{
    paciente= p;
    siguiente = sig;
    
}

NodoCola::~NodoCola()
{
}

