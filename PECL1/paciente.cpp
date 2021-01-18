#include "paciente.hpp"
#include "iostream"

using namespace std;


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
	this->anno=0;
	this->mes=0;
	this->dia=0;
	this->hora=0;
	this->minuto=0;
	this->segundo=0;
}

// Clase principal de paciente
Paciente::Paciente(

    int CodNumerico,
    string DNI,
    string Nombre,
    string Apell1,
    string Apell2,
    int Edad,
    char Sexo
   ) 

    
{
    this->CodNumerico = CodNumerico;
    this->DNI = DNI;
    this->Nombre = Nombre;
    this->Apell1 = Apell1;
    this->Apell2 = Apell2;
    this->Edad = Edad;
    this->Sexo = Sexo;
    this->Prioridad = 0;
	this->anno=0;
	this->mes=0;
	this->dia=0;
	this->hora=0;
	this->minuto=0;
	this->segundo=0;
}
void Paciente::imprimeLista()
{ cout << "Codigo Numerico: " << CodNumerico << " DNI: " << DNI << " Tiempo: " << getAnno()-2000<<getMes()<<getDia()<<getHora()<<getMinuto()<<getSegundo()<< endl;
    }
void Paciente::imprimePila()
{ cout << "Codigo Numerico: " << CodNumerico << " DNI: " << DNI  << " Nombre: " << Nombre << " Primer apellido: "
 << Apell1 <<" Segundo apellido: " << Apell2 <<" Edad: " << Edad << " Sexo: " << Sexo << endl;
}
void Paciente::imprimeC3(int annoActual, int mesActual, int diaActual, int horaActual, int minutoActual, int segundoActual)
{
	int annoResultado = 0;
	int mesResultado = 0;
	int diaResultado = 0;
	int horaResultado = 0;
	int minutoResultado = 0;
	int segundoResultado = 0;
	
	if (segundoActual > getSegundo()){
		minutoResultado --;
		segundoResultado = 60 + segundoActual - getSegundo();
	} else segundoResultado = segundoResultado + (segundoActual-getSegundo());
	
	if (minutoActual > getMinuto()){
		horaResultado--;
		minutoResultado = 60 + minutoActual - getMinuto();
	} else minutoResultado = minutoResultado + (minutoActual-getMinuto());
	
	if (horaActual > getHora()){
		horaResultado = 24+horaActual-getHora();
		diaResultado--;
	} else horaResultado = horaResultado + (horaActual - getHora());
	
	if (diaActual > getDia()) {
		diaResultado = 30+diaActual-getDia();
		mesResultado--;
	} else diaResultado = diaResultado + diaActual - getDia();
	
	if (mesActual > getMes()) {
		mesResultado = 12 + mesActual - getMes();
		annoResultado--;
	} else mesResultado = mesResultado + mesActual - getMes();
	
	annoResultado = annoActual - getAnno();
	
	if (segundoResultado>60) {
		segundoResultado-=60;
		minutoResultado++;
	}
	if (minutoResultado>60) {
		minutoResultado-=60;
		horaResultado++;
	}
	cout << "Prioridad: "<< getPrioridad() << " Codigo Numerico: " << CodNumerico << " Fecha de alta:" << endl << endl <<
	"Anno: " << getAnno() << " - Mes: " << getMes() << " - Dia: " << getDia() << " - Hora: " << getHora() << " - Minuto: " << getMinuto() << " - Segundo: " << getSegundo() << endl << endl <<
	"Tiempo Excedido: " << endl << annoResultado << " Annos " << mesResultado << " Meses " << diaResultado << " Dias " << horaResultado << " Horas " << minutoResultado << " Minutos " << segundoResultado << " Segundos "<< endl;
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

int Paciente::getAnno()
{
	return anno;
}

int Paciente::getMes()
{
	return mes;
}

int Paciente::getDia()
{
	return dia;
}

int Paciente::getHora()
{
	return hora;
}

int Paciente::getMinuto()
{
	return minuto;
}

int Paciente::getSegundo()
{
	return segundo;
}

float Paciente::getTiempo()
{
    float tiempo;
	//cout << "Tiempo: " << tiempo << endl;
	tiempo = getAnno();
	//cout << "Tiempo: " << tiempo << endl;
	tiempo = tiempo - 2000;
	//cout << "Tiempo: " << tiempo << endl;
	tiempo = tiempo * 100;
	//cout << "Tiempo: " << tiempo << endl;
	tiempo = tiempo + getMes();
	//cout << "Tiempo: " << tiempo << endl;
	tiempo = tiempo * 100;
	//cout << "Tiempo: " << tiempo << endl;
	tiempo = tiempo + getDia();
	//cout << "Tiempo: " << tiempo << endl;
	tiempo*=100;
	//cout << "Tiempo: " << tiempo << endl;
	tiempo+= getHora();
	//cout << "Tiempo: " << tiempo << endl;
	tiempo*=100;
	//cout << "Tiempo: " << tiempo << endl;
	tiempo+= getMinuto();
	//cout << "Tiempo: " << tiempo << endl;
	tiempo*=100;
	//cout << "Tiempo: " << tiempo << endl;
	tiempo+= getSegundo();
	//cout << "Tiempo: " << tiempo << endl;
	return tiempo;
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

void Paciente::setAnno(int annos)
{
	anno = annos;
}

void Paciente::setMes(int mesN)
{
	mes = mesN;
}

void Paciente::setDia(int diaN)
{
	dia = diaN;
}

void Paciente::setHora(int horaN)
{
	hora = horaN;
}

void Paciente::setMinuto(int minutoN)
{
	minuto = minutoN;
}

void Paciente::setSegundo(int segundoN)
{
	segundo = segundoN;
}

Paciente::~Paciente()
{
}
