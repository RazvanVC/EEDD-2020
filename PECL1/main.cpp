#include <iostream>
#include <stdio.h>
#include "PilaPacientes.hpp"
#include "ListaUrgencia.hpp"

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
    
    Paciente p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
    p1 = Paciente(1, "99999991A", "Silvia", "Martos", "Esteve", 45, 'H');
    p2 = Paciente(2, "99999992B", "Mario", "Ruiz", "Sanchez", 28, 'V');
    p3 = Paciente(3, "99999993C", "María", "Setien", "Buendia", 60, 'H');
    p4 = Paciente(4, "99999994D", "Luis", "Dominguez", "Gracia", 4, 'V');
    p5 = Paciente(5, "99999995E", "Eva", "Navarro", "Hueste", 23, 'H');
    p6 = Paciente(6, "99999996F", "José", "Márquez", "Higuera", 15, 'V');
    p7 = Paciente(7, "99999997G", "Lucía", "Vindel", "Higuera", 80, 'H');
    p8 = Paciente(8, "99999998H", "Víctor", "Méndez", "Gimeno", 67, 'V');
    p9 = Paciente(9, "99999999J", "Elena", "Espinosa", "Moreno", 2, 'H');
    p10 = Paciente(10, "100000000K", "Manuel", "García", "Pérez", 87, 'V');
    
    PilaPacientes pilaEntrada;
    pilaEntrada = PilaPacientes();
    pilaEntrada.insertar(p10);
    pilaEntrada.insertar(p9);
    pilaEntrada.insertar(p8);
    pilaEntrada.insertar(p7);
    pilaEntrada.insertar(p6);
    pilaEntrada.insertar(p5);
    pilaEntrada.insertar(p4);
    pilaEntrada.insertar(p3);
    pilaEntrada.insertar(p2);
    pilaEntrada.insertar(p1);
    
    Paciente pacienteActual;
    ListaUrgencia listaRoja, listaNaranja, listaAmarilla, listaVerde;
    listaRoja = ListaUrgencia();
    listaNaranja = ListaUrgencia();
    listaAmarilla = ListaUrgencia();
    listaVerde = ListaUrgencia();
    
    
    while(opcion != 5) {
        switch(opcion) {
        case 0:
            int nEmergencia;
            pacienteActual = pilaEntrada.extraer();
            
            cout << "\nPara dar de alta al paciente " << pacienteActual.getNombre() << " " << pacienteActual.getApell1() << " se necesita que seleccione una prioridad" << endl;
            cout << "1 - Nivel Rojo - Resucitación" << endl;
            cout << "2 - Nivel Naranja - Emergencia" << endl;
            cout << "3 - Nivel Amarillo - Urgencia" << endl;
            cout << "4 - Nivel Verde - Urgencia Menor" << endl;
            cout << "Inserte la prioridad del paciente: "; 
            cin >> nEmergencia;
            
            if (nEmergencia<0 || nEmergencia>4){
                cout << "\nNumero de emergencia erroneo. Vuelva a intentarlo.";
                pilaEntrada.insertar(pacienteActual);
                break;
            }
            pacienteActual.setPrioridad(nEmergencia);
            
            //Pensar en como determinar Tiempo
            
            switch (pacienteActual.getPrioridad()){
                case 1:
                    listaRoja.insertar(pacienteActual);
                    break;
                case 2:
                    listaNaranja.insertar(pacienteActual);
                    break;
                case 3:
                    listaAmarilla.insertar(pacienteActual);
                    break;
                case 4:
                    listaVerde.insertar(pacienteActual);
                    break;
            }
            break;
        case 1:
            // TODO Code Option 1
            
            
            
            break;
        case 2:
            // TODO Code Option 2
            int codPaciente, emergenciaA, emergenciaN;
            
            //Asignacion Codigo Paciente
            cout << "Inserte el codigo de paciente a modificar: ";
            cin >> codPaciente;
            if (codPaciente<0 || codPaciente>10){
                cout << "ERROR: Codigo de paciente incorrecto" << endl;
                cout << "Regresando a menu principal..." << endl;
                break;
            }
            
            //Asignacion de Emergencia Antigua
            cout << "Indique la emergencia anterior a la que estaba asignado" << endl;
            cout << "1 - Nivel Rojo - Resucitación" << endl;
            cout << "2 - Nivel Naranja - Emergencia" << endl;
            cout << "3 - Nivel Amarillo - Urgencia" << endl;
            cout << "4 - Nivel Verde - Urgencia Menor" << endl;
            cout << "Emergencia anterior: ";
            cin >> emergenciaA;
            if (emergenciaA<0 || emergenciaA>4){
                cout << "\nERROR: Numero de emergencia antigua erroneo."<< endl;
                cout << "Regresando a menu principal..." << endl;
                break;
            }
            
            //Asignacion de Nueva Emergencia
            cout << "Indique la emergencia anterior a la que estaba asignado" << endl;
            cout << "1 - Nivel Rojo - Resucitación" << endl;
            cout << "2 - Nivel Naranja - Emergencia" << endl;
            cout << "3 - Nivel Amarillo - Urgencia" << endl;
            cout << "4 - Nivel Verde - Urgencia Menor" << endl;
            cout << "Emergencia nueva: ";
            cin >> emergenciaN;
            if (emergenciaN<0 || emergenciaN>4){
                cout << "\nERROR: Numero de emergencia nueva erroneo.";
                cout << "Regresando a menu principal..." << endl;
                break;
            }
            
            switch (emergenciaA){
                case 1:
                    //pacienteActual = listaRoja.buscarCodNumerico(codPaciente);
                    listaRoja.borrar(pacienteActual.getDNI());
                    break;
                case 2:
                    //pacienteActual = listaNaranja.buscarCodNumerico(codPaciente);
                    listaNaranja.borrar(pacienteActual.getDNI());
                    break;
                case 3:
                    //pacienteActual = listaAmarilla.buscarCodNumerico(codPaciente);
                    listaAmarilla.borrar(pacienteActual.getDNI());
                    break;
                case 4:
                    //pacienteActual = listaVerde.buscarCodNumerico(codPaciente);
                    listaVerde.borrar(pacienteActual.getDNI());
                    break;
            }
            
            //asignacion Tiempo
            
            pacienteActual.setPrioridad(emergenciaN);
            
            switch (pacienteActual.getPrioridad()){
                case 1:
                    listaRoja.insertar(pacienteActual);
                    break;
                case 2:
                    listaNaranja.insertar(pacienteActual);
                    break;
                case 3:
                    listaAmarilla.insertar(pacienteActual);
                    break;
                case 4:
                    listaVerde.insertar(pacienteActual);
                    break;
            }
            
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
