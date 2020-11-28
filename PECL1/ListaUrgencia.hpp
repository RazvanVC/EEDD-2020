#ifndef LISTAURGENCIA_HPP
#define LISTAURGENCIA_HPP

#include "NodoLista.hpp"
class ListaUrgencia
{
public:
    ListaUrgencia();
    ~ListaUrgencia();
    bool ListaVacia()
    {
        return pLista == NULL;
    }
    void insertar(Paciente p);
    void borrar(); // Cambiar a borrar último
    void mostrar();
    void siguiente();
    void anterior();
    void primero();
    void ultimo();
    Paciente valorActual()
    {
        return pLista->paciente;
    }
    int longitud;

private:
    lnodo pLista;
};
#endif // LISTAURGENCIA_HPP
