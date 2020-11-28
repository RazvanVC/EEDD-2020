#include "Cola.hpp"
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include "paciente.hpp"

using namespace std;

Cola::Cola()
{
    frente = NULL;
    ultimo = NULL;
}

Cola::~Cola()
{
}

void Cola::encolar(Paciente p){
    NodoCola *nuevo =  new NodoCola(p, NULL);
    if(frente){
        ultimo-> sig = nuevo;
    } else {
        frente = nuevo;
    }
    ultimo = nuevo;
    }



