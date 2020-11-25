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
        char Sexo,
        int Prioridad,
        int Tiempo);
    ~Paciente();

    // Declaraciones de gets
    int getCodNumerico();
    string getDNI();
    string getNombre();
    string getApell1();
    string getApell2();
    int getEdad();
    char getSexo();
    int getPrioridad();
    int getTiempo();

    // Declaraciones de sets
    void setCodNumerico(int CodNumerico);
    void setDNI(string DNI);
    void setNombre(string Nombre);
    void setApell1(string Apell1);
    void setApell2(string Apell2);
    void setEdad(int Edad);
    void setSexo(char Sexo);
    void setPrioridad(int Prioridad);
    void setTiempo(int Tiempo);

    // Declaración de método para imprimir por pantalla el paciente
    void imprimirPaciente();

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
    int Tiempo;
};

#endif // PACIENTE_HPP
