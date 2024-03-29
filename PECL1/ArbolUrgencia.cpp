#include "ArbolUrgencia.hpp"
#include "iostream"

using namespace std;

ArbolUrgencia::ArbolUrgencia()
{
    raiz = NULL;
    actual = NULL;
    size = 0;
}

void ArbolUrgencia::podar(Anodo& nodo)
{
    if(nodo) {
        podar(nodo->siguiente); // Podar izquierdo
        podar(nodo->anterior);  // Podar derecho
        delete nodo;            // Eliminar nodo
        nodo = NULL;
    }
}
Paciente ArbolUrgencia::buscar(int CodNumerico)
{
    actual = raiz;
    while(!esVacio(actual)) {
        if(CodNumerico == actual->paciente.getCodNumerico())
            return actual->paciente;
        else if(CodNumerico > actual->paciente.getCodNumerico())
            actual = actual->siguiente;
        else if(CodNumerico < actual->paciente.getCodNumerico())
            actual = actual->anterior;
    }
    Paciente p0 = Paciente();
    return p0;
}
void ArbolUrgencia::insertar(Paciente p)
{
    NodoArbol* padre = NULL;
    actual = raiz;
    size = size + 1;
    while(!esVacio(actual) && p.getCodNumerico() != actual->paciente.getCodNumerico()) {
        padre = actual;
        if(p.getCodNumerico() > actual->paciente.getCodNumerico())
            actual = actual->siguiente;
        else
            actual = actual->anterior;
    }
    if(esVacio(padre))
        raiz = new NodoArbol(p);
    else if(p.getCodNumerico() < padre->paciente.getCodNumerico())
        padre->anterior = new NodoArbol(p);
    else if(p.getCodNumerico() > padre->paciente.getCodNumerico())
        padre->siguiente = new NodoArbol(p);
}

void ArbolUrgencia::borrarA(string DNI)
{
    NodoArbol* padre = NULL;
    NodoArbol* nodoaux;
    string DNIaux;
    size = size - 1;
    actual = raiz;
    while(!esVacio(actual)) {
        cout << actual->paciente.getDNI() << endl;
        cout << DNI << endl;
        if(DNI == actual->paciente.getDNI()) { // Si el valor está en el nodo actual
            if(padre) {
                if(padre->siguiente == actual)
                    padre->siguiente = NULL;
                else if(padre->anterior == actual)
                    padre->anterior = NULL;
            }
            delete actual;
            actual = NULL;
            return;

            padre = actual;
            if(actual->siguiente) {
                nodoaux = actual->siguiente;
                while(nodoaux->anterior) {
                    padre = nodoaux;
                    nodoaux = nodoaux->anterior;
                }

                nodoaux = actual->anterior;
                while(nodoaux->siguiente) {
                    padre = nodoaux;
                    nodoaux = nodoaux->siguiente;
                }

                DNIaux = actual->paciente.getDNI(); /* (3-b-ii) */
                actual->paciente.getDNI() = nodoaux->paciente.getDNI();
                nodoaux->paciente.getDNI() = DNIaux;
                actual = nodoaux;
            }
        } else {
            padre = actual;
            if(DNI > actual->paciente.getDNI())
                actual = actual->siguiente;
            else if(DNI < actual->paciente.getDNI())
                actual = actual->anterior;
        }
    }
}

void ArbolUrgencia::postOrden(Anodo nodo)
{
    if(nodo != NULL) {
        postOrden(nodo->anterior);
        postOrden(nodo->siguiente);
        cout << nodo->paciente.getCodNumerico() << " ";
    }
}

void ArbolUrgencia::inOrden(Anodo nodo)
{
    if(nodo != NULL) {
        inOrden(nodo->anterior);
        cout << nodo->paciente.getCodNumerico() << " ";
        inOrden(nodo->siguiente);
    }
}

void ArbolUrgencia::preOrden(Anodo nodo)
{
    if(nodo != NULL) {
        nodo->paciente.getCodNumerico();
		cp.insertar(nodo->paciente);
        cout << nodo->paciente.getCodNumerico() << " ";
        preOrden(nodo->anterior);
        preOrden(nodo->siguiente);
    }
}
void ArbolUrgencia::mostrar()
{
    if(size == 0)
        return;
    if(size == 1)
        cout << "i ";
    else if(size == 2)
        cout << "/ \\"; // Se ha empleado doble slash porque una solo parece ser reservado del sistema
    else {
        cout << "/ ";
        int contador = 0;
        while(contador < size - 2) {
            cout << "i ";
            contador++;
        }
        cout << "\\";
    }
    cout << endl;
    preOrden(raiz);
}
int ArbolUrgencia::getSize(){
    return size;
}
ArbolUrgencia::~ArbolUrgencia()
{
    podar(raiz);
}
