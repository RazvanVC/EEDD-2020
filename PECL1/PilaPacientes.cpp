#include "PilaPacientes.hpp"
#include "iostream"

PilaPacientes::PilaPacientes() // Declaramos la pila
{
    ultimo = NULL;
}

void PilaPacientes::insertar(Paciente v) // Insertar un paciente en la cola
{
    pnodo nuevo;
    nuevo = new NodoPila(v, ultimo);
    ultimo = nuevo;
}

Paciente PilaPacientes::extraer() // Extraer un paciente de la cola
{
    pnodo nodo;
    Paciente v;
    if(!ultimo) {
        return v;
    }
    nodo = ultimo;
    ultimo = nodo->siguiente;
    v = nodo->paciente;
    delete nodo;
    return v;
}

void PilaPacientes::mostrar() // Imprimir por pantalla lo que hay en la cola
{
    pnodo aux = ultimo;
    while(aux) {
        aux->paciente.imprimePila();
        aux = aux->siguiente;
    }
    cout << endl;
}

bool PilaPacientes::estaVacia() // Comprueba si la pila está vacía
{
    if(ultimo == NULL) {
        return true;
    } else {
        return false;
    }
}

Paciente PilaPacientes::buscar(string dni)
{
    PilaPacientes pilaAux;
    pilaAux = PilaPacientes();
    while(ultimo->paciente.getDNI() != dni or ultimo->siguiente == NULL) {
        pilaAux.insertar(extraer());
    }
    if(ultimo->paciente.getDNI() == dni) {
        return extraer();
    } else {
        return Paciente();
    }
}

PilaPacientes::~PilaPacientes()
{
    pnodo aux = ultimo;
    while(aux != NULL) {
        aux = ultimo;
        ultimo = ultimo->siguiente;
        delete aux;
    }
}