#include <iostream> 
#include <string> 
#include "PilaPacientes.hpp"
#include "ListaUrgencia.hpp"
#include "conio.h"
#include <exception>
#include <typeinfo>
#include <stdexcept>

using namespace std;

int main()
{
    
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
    
    int opcion;

    cout << "Bienvenido al triaje de emergencias" << endl << endl;
    cout << endl;
    cout << "0. Alta de paciente en emergencia" << endl;
    cout << "1. Baja de paciente" << endl;
    cout << "2. Modificacion-Reasignacion de paciente a tipo emergencia" << endl;
    cout << "3. Consultas de pacientes/emergencias" << endl;
    cout << "4. Reiniciar programa" << endl;
    cout << "5. Salir del programa" << endl;
    cout << "Seleccione un opcicion del menu: ";
    cin >> opcion;
    cout << endl << endl;
    
    
    PilaPacientes pilaPacientesTemp;
    string DNI;
    
    while(opcion != 5) {
        switch(opcion) {
        case 0:
            int nEmergencia;
            pacienteActual = pilaEntrada.extraer();
            
            cout << "Para dar de alta al paciente " << pacienteActual.getNombre() << " " << pacienteActual.getApell1() << " se necesita que seleccione una prioridad" << endl;
            cout << "1 - Nivel Rojo - Resucitacion" << endl;
            cout << "2 - Nivel Naranja - Emergencia" << endl;
            cout << "3 - Nivel Amarillo - Urgencia" << endl;
            cout << "4 - Nivel Verde - Urgencia Menor" << endl;
            cout << "Inserte la prioridad del paciente: ";
            cin >> nEmergencia;
            
            if (nEmergencia<1 || nEmergencia>4){
                cout << "\nERROR: Numero de emergencia erroneo."<< endl;
                cout << "Regresando a menu principal..." << endl << endl;
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
            
            // Opcion de reseteo cuando se vacia pila
            if (pilaEntrada.estaVacia()){
                int opcionFinal;
                bool opcionCorrecta;
                opcionCorrecta = true;
                do {
                    cout << endl;
                    cout << "La pila de pacientes se ha vaciado, seleccione una de las siguientes opciones: " << endl;
                    cout << "1 -  Resetear del programa" << endl;
                    cout << "2 -  Salir del programa" << endl;
                    cin >> opcionFinal;
                    if (!(opcionFinal<1) || !(opcionFinal>2)) opcionCorrecta = true;
                } while (!opcionCorrecta);
                if (opcionFinal == 1){
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
                    
                    listaRoja = ListaUrgencia();
                    listaNaranja = ListaUrgencia();
                    listaAmarilla = ListaUrgencia();
                    listaVerde = ListaUrgencia();
                }else return 0;
            }
            break;
        case 1:
            cout << "Indique el DNI del paciente que desea dar de baja: ";
            cin >> DNI;
            
            if (DNI.empty()){
                cout << "El DNI no puede estar vacio" << endl;
            } else if (DNI.size()<9){
                cout << "La longitud del DNI es incorrecta" << endl;
            }
            
            //Comprobar si está en pila
            
            pilaPacientesTemp = PilaPacientes();
            int iteracion;
            iteracion = 1;
            do {
                cout << "Iteracion: " << iteracion << endl;
                cout << "Pila principal de pacientes" << endl << endl;
                pilaEntrada.mostrar();
                cout << endl << "Pila pacientes temporal" << endl << endl;
                pilaPacientesTemp.mostrar();
                pacienteActual = pilaEntrada.extraer();
                
                cout << "Pila principal de pacientes" << endl << endl;
                pilaEntrada.mostrar();
                cout << endl << "Pila pacientes temporal" << endl << endl;
                pilaPacientesTemp.mostrar();
                
                if (pacienteActual.getDNI() != DNI) {
                pilaPacientesTemp.insertar(pacienteActual);
                cout << "Pila principal de pacientes" << endl << endl;
                pilaEntrada.mostrar();
                cout << endl << "Pila pacientes temporal" << endl << endl;
                pilaPacientesTemp.mostrar();
                
                cout << endl;
                cout << "El paciente aun no se ha encontrado"<<endl;
                } else break;
                getch();
                iteracion++;
            } while (!pilaEntrada.estaVacia());
            
            cout << endl;
            cout << "Revertimos el proceso de las pilas" << endl;
            
            do {
                cout << "Iteracion: " << iteracion << endl;
                cout << "Pila principal de pacientes" << endl << endl;
                pilaPacientesTemp.mostrar();
                cout << endl << "Pila pacientes temporal" << endl << endl;
                pilaEntrada.mostrar();
                pacienteActual = pilaPacientesTemp.extraer();
                
                cout << "Pila principal de pacientes" << endl << endl;
                pilaEntrada.mostrar();
                cout << endl << "Pila pacientes temporal" << endl << endl;
                pilaPacientesTemp.mostrar();
                
                pilaEntrada.insertar(pacienteActual);
                cout << "Pila principal de pacientes" << endl << endl;
                pilaEntrada.mostrar();
                cout << endl << "Pila pacientes temporal" << endl << endl;
                pilaPacientesTemp.mostrar();
                
                cout << endl;
                getch();
                iteracion++;
            } while (!pilaPacientesTemp.estaVacia());
            
            try{
                if (listaRoja.size!=0){
                    listaRoja.borrar(DNI);
                } else cout << "La lista roja esta vacia" << endl;
            } catch(...){
                cout << "No se encuentra en la lista roja" << endl;
                break;
            }
            getch();
            
            try{
                if (listaNaranja.size!=0){
                    listaNaranja.borrar(DNI);
                } else cout << "La lista naranja esta vacia" << endl;
            } catch(...){
                cout << "No se encuentra en la lista naranja" << endl;
            }
            getch();
            
            try{
                if (listaAmarilla.size!=0){
                    listaAmarilla.borrar(DNI);
                } else cout << "La lista amarilla esta vacia" << endl;
            } catch(...){
                cout << "No se encuentra en la lista amarilla" << endl;
            }
            getch();
            
            try{
                if (listaVerde.size!=0){
                    listaVerde.borrar(DNI);
                } else cout << "La lista verde esta vacia" << endl;
            } catch(...){
                cout << "No se encuentra en la lista verde" << endl;
            }
            getch();
            
            cout << "No se ha encontrado el DNI especificado" << endl;
            
            break;
        case 2:
            // TODO Code Option 2
            int codPaciente, emergenciaA, emergenciaN;
            
            //Asignacion Codigo Paciente
            cout << "Inserte el codigo de paciente a modificar: ";
            cin >> codPaciente;
            if (codPaciente<1 || codPaciente>10){
                cout << "ERROR: Codigo de paciente incorrecto" << endl;
                cout << "Regresando a menu principal..." << endl;
                break;
            }
            
            //Asignacion de Emergencia Antigua
            cout << "Indique la emergencia anterior a la que estaba asignado" << endl;
            cout << "1 - Nivel Rojo - Resucitacion" << endl;
            cout << "2 - Nivel Naranja - Emergencia" << endl;
            cout << "3 - Nivel Amarillo - Urgencia" << endl;
            cout << "4 - Nivel Verde - Urgencia Menor" << endl;;
            cout << "Emergencia anterior: ";
            cin >> emergenciaA;
            
            if (emergenciaA<1 || emergenciaA>4){
                cout << "\nERROR: Numero de emergencia antigua erroneo."<< endl;
                cout << "Regresando a menu principal..." << endl;
                break;
            }
            

                switch (emergenciaA){
                    case 1:
                        pacienteActual = listaRoja.buscarCodNumerico(codPaciente);
                        listaRoja.borrar(pacienteActual.getDNI());
                        break;
                    case 2:
                        pacienteActual = listaNaranja.buscarCodNumerico(codPaciente);
                        listaNaranja.borrar(pacienteActual.getDNI());
                        break;
                    case 3:
                        pacienteActual = listaAmarilla.buscarCodNumerico(codPaciente);
                        listaAmarilla.borrar(pacienteActual.getDNI());
                        break;
                    case 4:
                        pacienteActual = listaVerde.buscarCodNumerico(codPaciente);
                        listaVerde.borrar(pacienteActual.getDNI());
                        break;
                }

            
            //Asignacion de Nueva Emergencia
            cout << "Indique la emergencia actual a la que se desea asignar" << endl;
            cout << "1 - Nivel Rojo - Resucitacion" << endl;
            cout << "2 - Nivel Naranja - Emergencia" << endl;
            cout << "3 - Nivel Amarillo - Urgencia" << endl;
            cout << "4 - Nivel Verde - Urgencia Menor" << endl;
            cout << "Emergencia nueva: ";
            cin >> emergenciaN;
            if (emergenciaN<1 || emergenciaN>4){
                cout << "\nERROR: Numero de emergencia antigua erroneo."<< endl;
                cout << "Regresando a menu principal..." << endl;
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
        cout << endl;
        cout << "0. Alta de paciente en emergencia" << endl;
        cout << "1. Baja de paciente" << endl;
        cout << "2. Modificacion-Reasignacion de paciente a tipo emergencia" << endl;
        cout << "3. Consultas de pacientes/emergencias" << endl;
        cout << "4. Reiniciar programa" << endl;
        cout << "5. Salir del programa" << endl;
        cout << "Seleccione un opcicion del menu: ";
        cin >> opcion;
        cout << endl << endl;
        }
    return 0;
}
