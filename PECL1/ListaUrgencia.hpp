#ifndef LISTAURGENCIA_HPP
#define LISTAURGENCIA_HPP

#include "NodoLista.hpp"
class ListaUrgencia
{
public:
    ListaUrgencia();
    ~ListaUrgencia();
    bool ListaVacia() { return pLista == NULL; }
    void insertar(Paciente p);
    void borrar(int v); //Cambiar a borrar último  
    void mostrar();
    void siguiente();
    void anterior();
    void Primero();
    void ultimo();
    pnodo actual() { return pLista;}
    int valorActual() { return pLista ->paciente;}

private:
    pnodo pLista;
};