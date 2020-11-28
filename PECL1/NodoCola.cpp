#include "NodoCola.hpp"

NodoCola::NodoCola(Paciente paciente, NodoCola* sig)
{
    this->p=paciente;
    this->sig=sig;
}

NodoCola::~NodoCola()
{
}

