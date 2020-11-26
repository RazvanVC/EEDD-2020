#include "paciente.hpp"

Paciente::Paciente() // Inializamos las variables a valores estandar que nunca van a adquirir para chequear
{
    this->CodNumerico = -1;
    this->DNI = "NULL";
    this->Nombre = "NULL";
    this->Apell1 = "NULL";
    this->Apell2 = "NULL";
    this->Edad = -1;
    this->Sexo = 'Z';
    this->Prioridad = -1;
    this->Tiempo = -1;
}

// Clase principal de paciente
Paciente::Paciente(int CodNumerico,
    string DNI,
    string Nombre,
    string Apell1,
    string Apell2,
    int Edad,
    char Sexo,
    int Prioridad,
    int Tiempo)
{
    this->CodNumerico = CodNumerico;
    this->DNI = DNI;
    this->Nombre = Nombre;
    this->Apell1 = Apell1;
    this->Apell2 = Apell2;
    this->Edad = Edad;
    this->Sexo = Sexo;
    this->Prioridad = Prioridad;
    this->Tiempo = Tiempo;
}

/* GETS */

int Paciente::getCodNumerico()
{
    return CodNumerico;
}

string Paciente::getDNI()
{
    return DNI;
}

string Paciente::getNombre()
{
    return Nombre;
}

string Paciente::getApell1()
{
    return Apell1;
}

string Paciente::getApell2()
{
    return Apell2;
}

int Paciente::getEdad()
{
    return Edad;
}

char Paciente::getSexo()
{
    return Sexo;
}

int Paciente::getPrioridad()
{
    return Prioridad;
}

int Paciente::getTiempo()
{
    return Tiempo;
}

/* SETS */

void Paciente::setCodNumerico(int num)
{
    CodNumerico = num;
}

void Paciente::setDNI(string pdni)
{
    DNI = pdni;
}

void Paciente::setNombre(string name)
{
    Nombre = name;
}

void Paciente::setApell1(string ape1)
{
    Apell1 = ape1;
}

void Paciente::setApell2(string ape2)
{
    Apell2 = ape2;
}

void Paciente::setEdad(int e)
{
    Edad = e;
}

void Paciente::setSexo(char se)
{
    Sexo = se;
}

void Paciente::setPrioridad(int pri)
{
    Prioridad = pri;
}

void Paciente::setTiempo(int time)
{
    Tiempo = time;
}

Paciente::imprimirPaciente() // Lógica de cómo se tienen que mostrar las cosas por pantalla
{
}

Paciente::~Paciente()
{
}
