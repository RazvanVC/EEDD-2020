#ifndef PACIENTE_HPP
#define PACIENTE_HPP
#include <string.h>
#include <string>

using namespace std;

class Paciente
{
public:
    Paciente();
    Paciente(int CodNumerico, string DNI, string Nombre, string Apell1, string Apell2, int Edad, char Sexo);
    ~Paciente();

    int getCodNumerico():
    string getDNI();
    string getNombre();
    string getApell1();
    string getApell2();
    int getEdad();
    char getSexo();
    
    void setCodNumerico(int CodNumerico);
    void setDNI(string DNI);
    void setNombre(string Nombre);
    void setApell1(string Apell1);
    void setApell2(string Apell2);
    void setEdad(int Edad);
    void setSexo(char Sexo);
    
    void imprimirPaciente();

private:
    int CodNumerico;
    string DNI;
    string Nombre;
    string Apell1;
    string Apell2;
    int Edad;
    char Sexo;
};

#endif // PACIENTE_HPP
