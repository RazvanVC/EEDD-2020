#include "ColaPacientes.hpp"
using namespace std;
ColaPacientes::ColaPacientes()
{
    primero = NULL;
    ultimo = NULL;
    }
void ColaPacientes::insertar(Paciente p)
{
    cnodo nodo;
    nodo = new NodoCola(p);
    if (ultimo){
        ultimo->siguiente = nodo;
    }
    ultimo = nodo;
    if (!primero){
        primero = nodo;
    }
    
}
Paciente ColaPacientes::eliminar()
{
    cnodo nodo;
    Paciente p;
    nodo = primero;
    if (!nodo) {
        return p;
    }
    primero = nodo->siguiente;
    p= nodo->paciente;
    delete nodo;
    if (!primero){ultimo=NULL;}
    return p;
}
void ColaPacientes::imprimir()
{
    cnodo aux = primero;
    cnodo imp =aux;
    cout << "-------------------------COLA URGENCIA-----------------------" << endl;
    while (aux){
        imp->paciente.getCodNumerico();
        cout << imp << "|" ;
        aux=aux->siguiente;
        imp = aux;
    }
    
}
ColaPacientes::~ColaPacientes()
{
    while(primero)
        eliminar();
}

