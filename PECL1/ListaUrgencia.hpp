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
    void getprimero();
    void getultimo();
    int longitud;
    Paciente buscarCodNumerico(int CodNumerico);

private:
    lnodo primero;
    lnodo ultimo;
    int size;
};
#endif // LISTAURGENCIA_HPP
