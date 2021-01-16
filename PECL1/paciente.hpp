#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string.h>
#include <string>

using namespace std;

/* Header de la clase de Paciente
 * Incluye todos los atributos que tiene que poseer un paciente al ser dado de alta */
class Paciente
{
public:
    Paciente();
    Paciente(int CodNumerico,
        string DNI,
        string Nombre,
        string Apell1,
        string Apell2,
        int Edad,
        char Sexo
        
        );
    ~Paciente();
    void imprimeLista();
    void imprimePila();
	void imprimeC3(int a, int mes, int d, int h, int m, int s);
    // Declaraciones de gets
    int getCodNumerico();
    string getDNI();
    string getNombre();
    string getApell1();
    string getApell2();
    int getEdad();
    char getSexo();
    int getPrioridad();
    float getTiempo();
	int getAnno();
	int getMes();
	int getDia();
	int getHora();
	int getMinuto();
	int getSegundo();

    // Declaraciones de sets
    void setCodNumerico(int CodNumerico);
    void setDNI(string DNI);
    void setNombre(string Nombre);
    void setApell1(string Apell1);
    void setApell2(string Apell2);
    void setEdad(int Edad);
    void setSexo(char Sexo);
    void setPrioridad(int Prioridad);
	void setAnno(int anno);
	void setMes(int mes);
	void setDia(int dia);
	void setHora(int hora);
	void setMinuto(int minuto);
	void setSegundo(int segundo);

    // Atributos
private:
    int CodNumerico;
    string DNI;
    string Nombre;
    string Apell1;
    string Apell2;
    int Edad;
    char Sexo;
    int Prioridad;
	int anno;
	int mes;
	int dia;
	int hora;
	int minuto;
	int segundo;
};

#endif // PACIENTE_HPP
