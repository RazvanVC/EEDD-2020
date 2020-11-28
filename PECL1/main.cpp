#include <iostream>
#include <stdio.h>
#include "PilaPacientes.hpp"

using namespace std;

int main()
{
    int opcion;

    cout << "Bienvenido al triaje de emergencias" << endl << endl;
    cout << "0. Alta de paciente en emergencia" << endl;
    cout << "1. Baja de paciente" << endl;
    cout << "2. Modificación-Reasignación de paciente a tipo emergencia" << endl;
    cout << "3. Consultas de pacientes/emergencias" << endl;
    cout << "4. Reiniciar programa" << endl;
    cout << "5. Salir del programa" << endl;
    cout << "Seleccione un opcicion del menu: ";
    cin >> opcion;
    
    Paciente p1;
    p1 = Paciente(1, "99999991A", "Silvia", "Martos", "Esteve", 45, 'H');
    Paciente p2;
    p2 = Paciente(2, "99999992B", "Mario", "Ruiz", "Sanchez", 28, 'V');
    Paciente p3;
    p3 = Paciente(3, "99999993C", "María", "Setien", "Buendia", 60, 'H');
    Paciente p4;
    p4 = Paciente(4, "99999994D", "Luis", "Dominguez", "Gracia", 4, 'V');
    Paciente p5;
    p5 = Paciente(5, "99999995E", "Eva", "Navarro", "Hueste", 23, 'H');
    Paciente p6;
    p6 = Paciente(6, "99999996F", "José", "Márquez", "Higuera", 15, 'V');
    Paciente p7;
    p7 = Paciente(7, "99999997G", "Lucía", "Vindel", "Higuera", 80, 'H');
    Paciente p8;
    p8 = Paciente(8, "99999998H", "Víctor", "Méndez", "Gimeno", 67, 'V');
    Paciente p9;
    p9 = Paciente(9, "99999999J", "Elena", "Espinosa", "Moreno", 2, 'H');
    Paciente p10;
    p10 = Paciente(10, "100000000K", "Manuel", "García", "Pérez", 87, 'V');
    
    PilaPacientes pilaEntrada;
    pilaEntrada = PilaPacientes();
    pilaEntrada.insertar(p1);
    pilaEntrada.insertar(p2);
    pilaEntrada.insertar(p3);
    pilaEntrada.insertar(p4);
    pilaEntrada.insertar(p5);
    pilaEntrada.insertar(p6);
    pilaEntrada.insertar(p7);
    pilaEntrada.insertar(p8);
    pilaEntrada.insertar(p9);
    pilaEntrada.insertar(p10);
    
    while(opcion != 5) {
        switch(opcion) {
        case 0:
            // TODO Code Option 0
            
            break;
        case 1:
            // TODO Code Option 1
            
            break;
        case 2:
            // TODO Code Option 2
            
            break;
        case 3:
            // TODO Code Option 3
            
            break;
        case 4:
            // TODO COde Option 4
            
            break;
        }
        cout << "Seleccione un opcicion del menu: ";
        cin >> opcion;
    }
    return 0;
}
