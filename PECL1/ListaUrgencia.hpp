#ifndef LISTAURGENCIA_HPP
#define LISTAURGENCIA_HPP

#include "NodoLista.hpp"
class ListaUrgencia
{
public:
    ListaUrgencia();
    ~ListaUrgencia();

    void insertar(Paciente p);
    void borrar(string dni); // Cambiar a borrar último
    void mostrar();
    lnodo getultimo();
    lnodo getprimero();
    int longitud;
    int size;
    Paciente buscarCodNumerico(int CodNumerico);

private:
    lnodo primero;
    lnodo ultimo;
};
#endif // LISTAURGENCIA_HPP
