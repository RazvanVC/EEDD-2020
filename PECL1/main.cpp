
#include "ArbolUrgencia.hpp"
#include "PilaPacientes.hpp"
#include "conio.h"
#include "paciente.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <time.h>
#include <typeinfo>

using namespace std;

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

/**
 * @brief Retorna la opción del menu principal seleccionada
 * @return opcion (Integer)
 */
const int imprimirMenu()
{

    int opcion = 0;

    cout << endl << endl << "Fecha y hora actual: " << currentDateTime() << endl;
    cout << endl;
    cout << "0. Alta de paciente en emergencia" << endl;
    cout << "1. Baja de paciente" << endl;
    cout << "2. Modificacion-Reasignacion de paciente a tipo emergencia" << endl;
    cout << "3. Consultas de pacientes/emergencias" << endl;
    cout << "4. Reiniciar programa" << endl;
    cout << "5. Salir del programa" << endl << endl;
    cout << "Seleccione un opcion del menu: ";
    cin >> opcion;
    cout << endl << endl;

    return opcion;
}

const void imprimirNivelesUrgencia()
{
    cout << "1 - Nivel Rojo - Resucitacion" << endl;
    cout << "2 - Nivel Naranja - Emergencia" << endl;
    cout << "3 - Nivel Amarillo - Urgencia" << endl;
    cout << "4 - Nivel Verde - Urgencia Menor" << endl;
}

// Seteamos el tiempo del paciente
const Paciente setTimePaciente(Paciente p) 
{
		time_t     now = time(0);
		struct tm  tstruct;
		tstruct = *localtime(&now);
		
		p.setAnno(tstruct.tm_year+1900);
		p.setMes(tstruct.tm_mon);
		p.setDia(tstruct.tm_mday);
		p.setHora(tstruct.tm_hour);
		p.setMinuto(tstruct.tm_min);
		p.setSegundo(tstruct.tm_sec);

		return p;
}

//Mostramos la lista de emergencia roja ordenada por tiempo de espera
const void mostrarListas(ArbolUrgencia* arbol)
{
        time_t now = time(0);
		struct tm tstruct;
        tstruct = *localtime(&now);
		Paciente pt;
		int i = 0;
		while (i < arbol->size){
			//pt = arbol -> getValue(i);
			pt.imprimeC3(tstruct.tm_year+1900, tstruct.tm_mon, tstruct.tm_mday, tstruct.tm_hour, tstruct.tm_min,tstruct.tm_sec);
		}
        arbol->mostrar(); //tstruct.tm_year+1900, tstruct.tm_mon, tstruct.tm_mday, tstruct.tm_hour, tstruct.tm_min,tstruct.tm_sec);
}

int main()
{
	//Declaracion de variables
	
	// Creamos punteros hacia los arboles
	ArbolUrgencia* ArbolRojo;
	ArbolUrgencia* ArbolNaranja;
	ArbolUrgencia* ArbolAmarillo;
	ArbolUrgencia* ArbolVerde;
	
	int opcion = 0; //Variable de seleccion de opcion
	
	PilaPacientes pilaEntrada, pilaPacientesTemp; //Pilas de pacientes, tanto la primera donde se introducen los pacientes y la temporal para la consulta 1.1
	string DNI; //Iniciamos el DNI por el que se van a realizar las diversas busquedas.

    Paciente p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, pacienteActual; // Generamos 10 pacientes y el paciente que vamos a usar de apoyo
    p1 = Paciente(1, "99999991A", "Silvia", "Martos", "Esteve", 45, 'H');
    p2 = Paciente(2, "99999992B", "Mario", "Ruiz", "Sanchez", 28, 'V');
    p3 = Paciente(3, "99999993C", "Maria", "Setien", "Buendia", 60, 'H');
    p4 = Paciente(4, "99999994D", "Luis", "Dominguez", "Gracia", 4, 'V');
    p5 = Paciente(5, "99999995E", "Eva", "Navarro", "Hueste", 23, 'H');
    p6 = Paciente(6, "99999996F", "Jose", "Marquez", "Higuera", 15, 'V');
    p7 = Paciente(7, "99999997G", "Lucia", "Vindel", "Higuera", 80, 'H');
    p8 = Paciente(8, "99999998H", "Victor", "Mendez", "Gimeno", 67, 'V');
    p9 = Paciente(9, "99999999J", "Elena", "Espinosa", "Moreno", 2, 'H');
    p10 = Paciente(10, "100000000K", "Manuel", "Garcia", "Perez", 87, 'V');

    // Insertamos los pacientes en la pila PilaPacientes en orden inverso (LIFO)
    
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

	// Cremoas las listas de emergencia
    ArbolRojo = new ArbolUrgencia();
    ArbolAmarillo = new ArbolUrgencia();
    ArbolNaranja = new ArbolUrgencia();
    ArbolVerde = new ArbolUrgencia();

	opcion = imprimirMenu();
    
    while(opcion != 5) {
        switch(opcion) {
			case 0:
				int nEmergencia; // Declaramos la variable nEmergencia
				
				pacienteActual = pilaEntrada.extraer(); // Se saca el primer paciente de la pila
 
				cout << "Para dar de alta al paciente " << pacienteActual.getNombre() << " " << pacienteActual.getApell1() << " se necesita que seleccione una prioridad" << endl;
				imprimirNivelesUrgencia();
				cout << "Inserte la prioridad del paciente: "; cin >> nEmergencia; // Guardamos el número de la opción introducida por el usuario para asignar el paciente a la lista de emergencia

				if(nEmergencia < 1 || nEmergencia > 4) { // Controlamos que el usuario no pueda meter una opción que no se muestre por pantalla
					cout << "\nERROR: Numero de emergencia erroneo." << endl;
					cout << "Regresando a menu principal..." << endl << endl;
					// Insertamos de nuevo el paciente a la pila
					pilaEntrada.insertar(pacienteActual);
					break;
				}
				pacienteActual.setPrioridad(nEmergencia); // Seteamos la prioridad del paciente y el tiempo

				int opcionSeleccionTiempo;
				cout << "Seleccione una manera de establecer el tiempo" << endl << endl;
				cout << "1 - Usar la hora del sistema" << endl;
				cout << "2 - Establecer el tiempo manualmente" << endl << endl;

				cout << "Opcion: "; cin >> opcionSeleccionTiempo;
				if (opcionSeleccionTiempo < 1 || opcionSeleccionTiempo > 2) {
					cout << endl << "La opcion seleccionada no esta registrada" << endl;
					cout << "Volviendo al menu principal..." << endl << endl;
					pilaEntrada.insertar(pacienteActual);
					break;
				}
				if (opcionSeleccionTiempo == 1) {
					pacienteActual = setTimePaciente(pacienteActual);
				} else {
					int anno, mes, dia, hora, minuto, seg;
					bool valoresCorrectos;
					valoresCorrectos = true;

					cout << "Inserte el anno de ingreso: "; cin >> anno;
					cout << "Inserte el mes de ingreso: "; cin >> mes;
					cout << "Inserte el dia de ingreso: "; cin >> dia;
					cout << "Inserte la hora de ingreso: "; cin >> hora;
					cout << "Inserte el minuto de ingreso: "; cin >> minuto;
					cout << "Inserte el segundo de ingreso: "; cin >> seg;

					//Comprobación de valores, sino menu principal;
					if (anno > 2021 || anno < 0) valoresCorrectos = false;
					if (mes > 12 || mes < 1) valoresCorrectos = false;
					if (dia > 31 || dia < 1) valoresCorrectos = false;
					if (mes == 2 && dia > 28) valoresCorrectos = false;
					if (hora > 60 || hora < 0) valoresCorrectos = false;
					if (minuto > 60 || minuto < 0) valoresCorrectos = false;
					if (seg > 60 || seg < 0) valoresCorrectos = false;

					if (!valoresCorrectos) { //Si se ha introducido algun valor incorrecto se vuelve al menu principal y se descartan los cambios
						cout << endl << "Alguno de los parametros introducidos son erroneos" << endl;
						cout << "Volviendo al menu principal..." << endl << endl;
						pilaEntrada.insertar(pacienteActual);
						break;
					}

					pacienteActual.setAnno(anno);
					pacienteActual.setMes(mes);
					pacienteActual.setDia(dia);
					pacienteActual.setHora(hora);
					pacienteActual.setMinuto(minuto);
					pacienteActual.setSegundo(seg);

				}

				// Hacemos un get de la prioridad del paciente y se le asigna a una lista de emergencia según el caso
				switch(pacienteActual.getPrioridad()) {
					case 1:
						ArbolRojo->insertar(pacienteActual);
						break;
					case 2:
						ArbolNaranja->insertar(pacienteActual);
						break;
					case 3:
						ArbolAmarillo->insertar(pacienteActual);
						break;
					case 4:
						ArbolVerde->insertar(pacienteActual);
						break;
				}

				if(pilaEntrada.estaVacia()) {
					int opcionFinal;
					bool opcionCorrecta;
					opcionCorrecta = true;
					do {
						cout << endl;
						cout << "La pila de pacientes se ha vaciado, seleccione una de las siguientes opciones: " << endl;
						cout << "1 - Resetear del programa" << endl;
						cout << "2 - Salir del programa" << endl;
						cin >> opcionFinal;
						if(!(opcionFinal < 1) || !(opcionFinal > 2))
							opcionCorrecta = true;
					} while(!opcionCorrecta);

					if(opcionFinal == 1) {
						// Volvemos a llenar PilaPacientes
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

						// Sobreescribimos las listas de emergencias (las vaciamos)
						ArbolRojo = new ArbolUrgencia();
						ArbolNaranja = new ArbolUrgencia();
						ArbolAmarillo = new ArbolUrgencia();
						ArbolVerde = new ArbolUrgencia();
					} else return 0;
				}
				break;

			case 1:
				cout << "Indique el DNI del paciente que desea dar de baja: "; cin >> DNI;

				if(DNI.empty()) { // Error si no se introduce nada
					cout << "El DNI no puede estar vacio" << endl;
					cout << "Volviendo al menu principal..." << endl << endl;
					break;
				}
				if(DNI.length() < 9) { // Error si no introducimos la longitud correcta
					cout << "La longitud del DNI es incorrecta" << endl;
					cout << "Volviendo al menu principal..." << endl << endl;
					break;
				}

				// Comprobar si está en pila

				pilaPacientesTemp = PilaPacientes();
				int iteracion;
				bool encontrado;
				encontrado = false;
				iteracion = 1;
				do {
					// Se va vaciando la pilaEntrada y se vuelca en pilaPacientesTem para ir buscando el paciente del DNI
					// introducido Se muestran una por una las iteraciones realizadas imprimiendo por pantalla las pilas de
					// los pacientes(principal y temporal)
					cout << "Iteracion: " << iteracion << endl;
					cout << "Pila principal de pacientes" << endl << endl;
					pilaEntrada.mostrar();
					cout << endl << "Pila pacientes temporal" << endl << endl;
					pilaPacientesTemp.mostrar();
					pacienteActual = pilaEntrada.extraer();

					if(pacienteActual.getDNI() != DNI) { // Si el dni del paciente no coincide con el DNI introducido,se introduce en una pila temporal
						pilaPacientesTemp.insertar(pacienteActual);
						cout << "Pila principal de pacientes" << endl << endl;
						pilaEntrada.mostrar();
						cout << endl << "Pila pacientes temporal" << endl << endl;
						pilaPacientesTemp.mostrar();
						cout << endl << "El paciente aun no se ha encontrado" << endl;
					} else { // Si se encuentra, se revierte la pila temporal en la principal y se borra la pila temporal
						encontrado = true;
						cout << endl
							<< "Se ha encontrado el paciente" << endl
							<< "Iniciando el borrado..." << endl
							<< "Borrado completo. Revertiendo listas...";
						break;
					}
					getch();
					iteracion++;
				} while(!pilaEntrada.estaVacia()); // Esto se repetirá hasta que la pilaEntrada esté vacía

				cout << endl;
				cout << "Revertimos el proceso de las pilas" << endl;

				do {
					// Este es el proceso contrario (rellenar)
					cout << "Iteracion: " << iteracion << endl;
					cout << "Pila principal de pacientes" << endl << endl;
					pilaPacientesTemp.mostrar();
					cout << endl << "Pila pacientes temporal" << endl << endl;
					pilaEntrada.mostrar();
					pacienteActual = pilaPacientesTemp.extraer();

					pilaEntrada.insertar(pacienteActual);
					cout << "Pila principal de pacientes" << endl << endl;
					pilaEntrada.mostrar();
					cout << endl << "Pila pacientes temporal" << endl << endl;
					pilaPacientesTemp.mostrar();

					cout << endl;
					getch();
					iteracion++;
				} while(!pilaPacientesTemp.estaVacia()); // Esto se repite hasta que la pilaPacientesTemp esté vacía

				if(encontrado) break; // En el momento en que lo encuentra, para de buscar

				try { // Busca en la lista de emergencia Roja
					if(ArbolRojo->size != 0) {  // Si la lista contiene algo, comienza a buscar en ella
						ArbolRojo->borrar(DNI); // Si lo encuentra, lo borra
						cout << "Se ha borrado de la lista roja" << endl << endl;
						break;
					} else cout << "La lista roja esta vacia" << endl; // Si la lista está vacía, lo indica por pantalla
				} catch(...) {
					cout << "No se encuentra en la lista roja" << endl; // Si no está en esta lista, salta una excepción y seindica por pantalla
				}
				getch();

				try { // Busca en la lista de emergencia Naranaja
					if(ArbolNaranja->size != 0) {  // Si la lista contiene algo, comienza a buscar en ella
						ArbolNaranja->borrar(DNI); // Si lo encuentra, lo borra
						cout << "Se ha borrado de la lista naranja" << endl << endl;
						break;
					} else cout << "La lista naranja esta vacia" << endl; // Si la lista está vacía, lo indica por pantalla
				} catch(...) {
					cout << "No se encuentra en la lista naranja" << endl; // Si no está en esta lista, salta una excepción y se indica por pantalla
				}
				getch();

				try { // Busca en la lista de emergencia Amarilla
					if(ArbolAmarillo->size != 0) {  // Si la lista contiene algo, comienza a buscar en ella
						ArbolAmarillo->borrar(DNI); // Si lo encuentra, lo borra
						cout << "Se ha borrado de la lista amarilla" << endl << endl;
						break;
					} else cout << "La lista amarilla esta vacia" << endl; // Si la lista está vacía, lo indica por pantalla
				} catch(...) {
					cout << "No se encuentra en la lista amarilla" << endl; // Si no está en esta lista, salta una excepción y se indica por pantalla
				}
				getch();

				try { // Busca en la lista de emergencia Verde
					if(ArbolVerde->size != 0) {  // Si la lista contiene algo, comienza a buscar en ella
						ArbolVerde->borrar(DNI); // Si lo encuentra, lo borra
						cout << "Se ha borrado de la lista verde" << endl << endl;
						break;
					} else
						cout << "La lista verde esta vacia" << endl; // Si la lista está vacía, lo indica por pantalla
				} catch(...) {
					cout << "No se encuentra en la lista verde" << endl; // Si no está en esta lista, salta una excepción y se indica por pantalla
				}
				getch();
				cout << "No se ha encontrado el DNI especificado" << endl; // SI no está el DNI, se indica por pantalla
				break;
			case 2:
				// Se declaran las siguientes variables
				int codPaciente, emergenciaA, emergenciaN;

				// Asignacion Codigo Paciente
				cout << "Inserte el codigo de paciente a modificar: "; cin >> codPaciente; // El usuario introduce el código del paciente
				if(codPaciente < 1 || codPaciente > 10) {                   // Se comprueba que la entreada sea entre 1 y 10
					cout << "ERROR: Codigo de paciente incorrecto" << endl; // Si hay un error, se indica por pantalla
					cout << "Regresando a menu principal..." << endl;       // Regresamos al menú principal
					break;
				}

				// Asignacion de Emergencia Antigua
				cout << "Indique la emergencia anterior a la que estaba asignado" << endl;
				imprimirNivelesUrgencia();
				cout << "Emergencia anterior: "; cin >> emergenciaA; // El usuario introduce la lista donde se encuentra el paciente actualmente

				if(emergenciaA < 1 || emergenciaA > 4) { // Se comprueba que la entrada sea entre 1 y 4
					cout << endl << "ERROR: Numero de emergencia antigua erroneo." << endl; // Si hay un error, se indica por pantalla
					cout << "Regresando a menu principal..." << endl; // Regresamos al menú principal break;
				}

				try {
					switch(emergenciaA) { // Dependiendo de la lista en la que se encuentre entrará en un caso, seleccionará al paciente y lo borrará de la lista
						case 1:
							pacienteActual = ArbolRojo->buscar(codPaciente);
							ArbolRojo->borrar(pacienteActual.getDNI());
							break;
						case 2:
							pacienteActual = ArbolNaranja->buscar(codPaciente);
							ArbolNaranja->borrar(pacienteActual.getDNI());
							break;
						case 3:
							pacienteActual = ArbolAmarillo->buscar(codPaciente);
							ArbolAmarillo->borrar(pacienteActual.getDNI());
							break;
						case 4:
							pacienteActual = ArbolVerde->buscar(codPaciente);
							ArbolVerde->borrar(pacienteActual.getDNI());
							break;
					} 
				}catch (...) {
					cout << "El paciente no se ha podido encontrar en la lista especificada" << endl;
					cout << "Volviendo al menu principal..." << endl;
					break;
				}

				cout << "Paciente: " << pacienteActual.getApell1() << endl; // Se imprime por pantalla el paciente seleccionado

				// Asignacion de Nueva Emergencia
				cout << "Indique la emergencia actual a la que se desea asignar" << endl;
				imprimirNivelesUrgencia();
				cout << "Emergencia nueva: "; cin >> emergenciaN; // El usuario introduce la lista donde se va a trasladar al paciente
				if(emergenciaN < 1 || emergenciaN > 4) { // Se comprueba que la entrada sea entre 1 y 4
					cout << endl << "ERROR: Numero de emergencia antigua erroneo." << endl; // Si hay un error, se indica por pantalla
					cout << "Regresando a menu principal..." << endl; // Regresamos al menú principal break;
					break;
				}

				// Asignacion Tiempo
				pacienteActual.setPrioridad(emergenciaN);

				// Una vez asignado el tiempo, se asigna al paciente a la nueva lista de emergencia
				switch(pacienteActual.getPrioridad()) {
					case 1:
						ArbolRojo->insertar(pacienteActual);
						break;
					case 2:
						ArbolNaranja->insertar(pacienteActual);
						break;
					case 3:
						ArbolAmarillo->insertar(pacienteActual);
						break;
					case 4:
						ArbolVerde->insertar(pacienteActual);
						break;
				}

				break;
			case 3:
				// Se declara la variable para la opción
				int opcionP3;
				cout << "Seleccione la opcion que quiere consultar" << endl << endl;
				cout << "1 - Consultas de pacientes" << endl;
				cout << "2 - Consultas de emergencia" << endl;
				cout << "3 - Consultas de tiempos de emergencia superados" << endl << endl;
				cout << "Opcion: "; cin >> opcionP3; /* El usuario introduce la opción que quiere consultar*/ cout << endl;

				if(opcionP3 < 1 || opcionP3 > 3) { // Se comprueba que la entrada sea entre 1 y 3
					cout << "La opcion seleccionada es erronea" << endl; // Si hay un error, se indica por pantalla
					cout << "Regresando al menu principal..." << endl;   // Regresamos al menú principal
				}

				switch(opcionP3) {
					case 1:
						// Se declara otra variable para la opción
						int opcionP31;
						cout << "Seleccione la opcion que quiere consultar" << endl << endl;
						cout << "1 - Consultas paciente determinado en pila de paciente" << endl;
						cout << "2 - Consultas la pila de pacientes" << endl << endl;
						cout << "Opcion: "; cin >> opcionP31; /* El usuario introduce la opción que quiere consultar */ cout << endl;
						if(opcionP31 == 1) {
							// Declaramos la variable para poder buscar por DNI
							string DNI31;
							cout << "Inserte el DNI a buscar: "; cin >> DNI31; // El usuario introduce el DNI que quiere consultar
							bool encontrado = false; // Se declara e iniciliza la variabe encontrado
							do { // Vamos comparando el DNI introducido hasta encontrar el paciente correspondiente
								pacienteActual = pilaEntrada.extraer(); // Extraemos el primero de la pila
								if(pacienteActual.getDNI() == DNI31) {  // Comparamos si tienen el mismo DNI
									cout << endl << endl << "El paciente buscado es: " << endl; // En caso positivo, se imprimer el paciente por pantalla 
									pacienteActual.imprimePila();
									encontrado = true;
									break;
								} else pilaPacientesTemp.insertar(pacienteActual); // Se inserta el paciente actual en la pila temporal
							} while(!pilaEntrada.estaVacia()); // Esto se repetirá hasta que la pilaEntrada esté vacía
						if(!encontrado)
							cout << "El paciente no se ha encontrado" << endl; // Si no se encuentra el paciente, se indica por pantalla
						do { // Extraemos el paciente de la pila temporal para reconstruir nuestra pilaEntrada
							pacienteActual = pilaPacientesTemp.extraer();
							pilaEntrada.insertar(pacienteActual); // Insertamos el paciente actual en la pilaEntrada para volver a los valores anteriores a la búsqueda
						} while(!pilaPacientesTemp.estaVacia()); // Esto se repetirá hasta que la pilaPacientesTemp esté vacía
						} else if(opcionP31 == 2) {
							cout << "Imprimiendo pila de pacientes" << endl << endl;
							pilaEntrada.mostrar(); /* Se imprime por pantalla toda la pila */ cout << endl;
						} else {
							cout << "La opcion seleccionada es erronea" << endl; // Si hay un error, se indica por pantalla
							cout << "Regresando al menu principal... " << endl;  // Regresamos al menu principal
						}
						break;
					case 2:
						// Se declara otra variable para la opcion
						int opcionP32;
						cout << "Seleccione la opcion que quiere consultar" << endl << endl;
						cout << "1 - Consultar emergencia a la que esta asignada un paciente" << endl;
						cout << "2 - Consultar la lista de emergencia seleccionada" << endl;
						cout << "3 - Mostrar todos los arboles y la cola de los mismos" << endl << endl;
						cout << "Opcion: "; cin >> opcionP32; /* El usuario introduce la opciÃ³n que quiere consultar*/ cout << endl;

						if(opcionP32 == 1) {
							// Declaramos la variable para poder buscar por el cÃ³digo de identificaciÃ³n
							int numeroPaciente;
							cout << "Inserte el codigo del paciente a buscar: "; cin >> numeroPaciente; // El usuario introduce el codigo que quiere consultar
							try {
								pacienteActual = ArbolRojo->buscar(numeroPaciente); // Buscamos el codigo del paciente en la lista Roja
								if(pacienteActual.getCodNumerico() == numeroPaciente) { // Si coincide con el codigo introducido 
									cout << "DNI del paciente: " << pacienteActual.getDNI() << " se encuentra en la lista de emergencias roja" << endl; // Se indica por pantalla que se ha encontrado
									break;
								}
							} catch(...) { }

							try {
								pacienteActual = ArbolNaranja->buscar(numeroPaciente); // Buscamos el codigo del paciente en la lista Naranja if
								if(pacienteActual.getCodNumerico() == numeroPaciente) {// Si coincide con el codigo introducido
									cout << "DNI del paciente: " << pacienteActual.getDNI() << " se encuentra en la lista de emergencias naranja" << endl; // Se indica por pantalla que se haencontrado
									break;
								}
							} catch(...) { }

							try {
								pacienteActual = ArbolAmarillo->buscar(numeroPaciente); // Buscamos el codigo del paciente en la lista Naranja if
								if(pacienteActual.getCodNumerico() == numeroPaciente) { // Si coincide con el cÃ³digo introducido
									cout << "DNI del paciente: " << pacienteActual.getDNI() << " se encuentra en la lista de emergencias naranja" << endl; // Se indica por pantalla que se haencontrado
								break;
								}
							} catch(...) { }

							try {
								pacienteActual = ArbolVerde->buscar(numeroPaciente); // Buscamos el codigo del paciente en la lista Verde
								if(pacienteActual.getCodNumerico() == numeroPaciente) { // Si coincide con el codigo introducido
									cout << "DNI del paciente: " << pacienteActual.getDNI() << " se encuentra en la lista de emergencias verde " << endl; // Se indica por pantalla que se ha encontrado
									break;
								}
							} catch(...) { }

							cout << "El paciente con el codigo numerico: " << numeroPaciente << " no se ha encontrado en ninguna lista de emergencias " << endl;

						} else if(opcionP32 == 2) {
							// Declaramos la variable para poder buscar por lista de emergencia
							int ArbolConsultado;
							cout << "Indique la lista de emergencias que desea ver. " << endl;
							imprimirNivelesUrgencia();
							cout << "Opcion: "; cin >> ArbolConsultado; cout << endl;  // El usuario introduce la lista de emergencia que desea consultar
							switch(ArbolConsultado) { // Segun el caso, mostrara una de las 4 listas disponibles
								case 1:
									cout << "Mostrando lista de emergencias roja..." << endl << endl;
									ArbolRojo->mostrar(); // Muestra la Arbol de emergencia Rojo
									break;
								case 2:
									cout << "Mostrando lista de emergencias naranja... " << endl << endl;
									ArbolNaranja->mostrar(); // Muestra el arbol de emergencia Naranja
									break;
								case 3:
									cout << "Mostrando lista de emergencias amarilla..." << endl << endl;
									ArbolAmarillo->mostrar(); // Muestra el arbol de emergencia Amarillo
									break;
								case 4:
									cout << "Mostrando lista de emergencias verde..." << endl << endl;
									ArbolVerde->mostrar(); // Muestra la lista de emergencia Verde
									break;
							}
						} else if (opcionP32 == 3){ //Mostrar todos los arboles
							cout << endl << "ArbolR" << endl;
							ArbolRojo->mostrar();
							cout << endl << "ArbolN" << endl;
							ArbolNaranja->mostrar();
							cout << endl << "ArbolA" << endl;
							ArbolAmarillo->mostrar();
							cout << endl << "ArbolV" << endl;
							ArbolVerde->mostrar();
						} else {
							cout << "La opcion seleccionada es erronea" << endl; // Si hay un error,se indica por pantalla
							cout << "Regresando al menu principal..." << endl;   // Regresamos al menu principal
						}
						break;
					case 3:
						mostrarListas(ArbolRojo); //Muestra la lista de emergencia Roja
						break;
				}
				break;
			case 4:
				//Se resetea la PilaPacientes aÃ±adiendo de nuevo todos los pacientes
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

				//Sobreescribimos las listas de emergencias (las vaciamos)
				ArbolRojo = new ArbolUrgencia();
				ArbolNaranja = new ArbolUrgencia();
				ArbolAmarillo = new ArbolUrgencia();
				ArbolVerde = new ArbolUrgencia();

				break;
		}
	opcion = imprimirMenu();
	}
	return 0;
}
/*
// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}
// Seteamos el tiempo del paciente
const Paciente setTimePaciente(Paciente p) {
        time_t     now = time(0);
    struct tm  tstruct;
        tstruct = *localtime(&now);

        p.setAnno(tstruct.tm_year+1900);
        p.setMes(tstruct.tm_mon);
        p.setDia(tstruct.tm_mday);
        p.setHora(tstruct.tm_hour);
        p.setMinuto(tstruct.tm_min);
        p.setSegundo(tstruct.tm_sec);

        return p;
}
//Mostramos la lista de emergencia roja ordenada por tiempo de espera
const void mostrarListas(ListaUrgencia* listaRoja){
        time_t     now = time(0);
    struct tm  tstruct;
        tstruct = *localtime(&now);
        listaRoja->mostrarC3(tstruct.tm_year+1900, tstruct.tm_mon, tstruct.tm_mday, tstruct.tm_hour, tstruct.tm_min,
tstruct.tm_sec);
}

using namespace std;

int main()
{
    //Generamos 10 pacientes
    Paciente p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
    p1 = Paciente(1, "99999991A", "Silvia", "Martos", "Esteve", 45, 'H',21,01,12,14,03,32);
    p2 = Paciente(2, "99999992B", "Mario", "Ruiz", "Sanchez", 28, 'V');
    p3 = Paciente(3, "99999993C", "Maria", "Setien", "Buendia", 60, 'H');
    p4 = Paciente(4, "99999994D", "Luis", "Dominguez", "Gracia", 4, 'V');
    p5 = Paciente(5, "99999995E", "Eva", "Navarro", "Hueste", 23, 'H');
    p6 = Paciente(6, "99999996F", "Jose", "Marquez", "Higuera", 15, 'V');
    p7 = Paciente(7, "99999997G", "Lucia", "Vindel", "Higuera", 80, 'H');
    p8 = Paciente(8, "99999998H", "Victor", "Mendez", "Gimeno", 67, 'V');
    p9 = Paciente(9, "99999999J", "Elena", "Espinosa", "Moreno", 2, 'H');
    p10 = Paciente(10, "100000000K", "Manuel", "Garcia", "Perez", 87, 'V');

    //Insertamos los pacientes en la pila PilaPacientes en orden inverso (LIFO)
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

    //Declaramos la variable paciente
    Paciente pacienteActual;

    //Creamos punteros /Hecho
    ArbolUrgencia* listaRoja;
    ListaUrgencia* listaNaranja;
    ListaUrgencia* listaAmarilla;
    ListaUrgencia* listaVerde;

    //Cremoas las arboles de emergencia /Hecho
    listaRoja = new ListaUrgencia();
    listaAmarilla = new ListaUrgencia();
    listaNaranja = new ListaUrgencia();
    listaVerde = new ListaUrgencia();

    //Declaramos la variable opción que va a ser la que introduzca el usuario por pantalla
    int opcion;


        cout << "Fecha y hora actual: " << currentDateTime() << endl;
        cout << endl;
    cout << "Bienvenido al triaje de emergencias" << endl << endl;
    cout << endl;
    cout << "0. Alta de paciente en emergencia" << endl;
    cout << "1. Baja de paciente" << endl;
    cout << "2. Modificacion-Reasignacion de paciente a tipo emergencia" << endl;
    cout << "3. Consultas de pacientes/emergencias" << endl;
    cout << "4. Reiniciar programa" << endl;
    cout << "5. Salir del programa" << endl;
    cout << "Seleccione un opcion del menu: ";
    cin >> opcion;
    cout << endl << endl;

    //Declaramos las variables pilaPacientesTemp y DNI para utilizarlas más adelante
    PilaPacientes pilaPacientesTemp;
    string DNI;

    //Bucle para controlar lo que va a hacer el programa según la opción introducida por el usuario
    while(opcion != 5) {
        switch(opcion) {
        case 0:
            //Declaramos la variable nEmergencia
            int nEmergencia;
            //Se saca el primer paciente de la pila
            pacienteActual = pilaEntrada.extraer();

            cout << "Para dar de alta al paciente " << pacienteActual.getNombre() << " " << pacienteActual.getApell1()
<< " se necesita que seleccione una prioridad" << endl; cout << "1 - Nivel Rojo - Resucitacion" << endl; cout << "2 -
Nivel Naranja - Emergencia" << endl; cout << "3 - Nivel Amarillo - Urgencia" << endl; cout << "4 - Nivel Verde -
Urgencia Menor" << endl; cout << "Inserte la prioridad del paciente: "; cin >> nEmergencia; //Guardamos el número de la
opción introducida por el usuario para asignar el paciente a la lista de emergencia

            //Controlamos que el usuario no pueda meter una opción que no se muestre por pantalla
            if (nEmergencia<1 || nEmergencia>4){
                cout << "\nERROR: Numero de emergencia erroneo."<< endl;
                cout << "Regresando a menu principal..." << endl << endl;
                //Insertamos de nuevo el paciente a la pila
                pilaEntrada.insertar(pacienteActual);
                break;
            }
            //Seteamos la prioridad del paciente y el tiempo
            pacienteActual.setPrioridad(nEmergencia);
            pacienteActual = setTimePaciente(pacienteActual);
            //cout << "Current local time : " << tm_local->tm_hour << ":" << tm_local->tm_min << ":" <<
tm_local->tm_sec;

            //Hacemos un get de la prioridad del paciente y se le asigna a una lista de emergencia según el caso
            switch (pacienteActual.getPrioridad()){
                case 1:
                    listaRoja -> insertar(pacienteActual);
                    break;
                case 2:
                    listaNaranja -> insertar(pacienteActual);
                    break;
                case 3:
                    listaAmarilla -> insertar(pacienteActual);
                    break;
                case 4:
                    listaVerde -> insertar(pacienteActual);
                    break;
            } //Hecho

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
                    //Volvemos a llenar PilaPacientes
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

                    //Sobreescribimos las listas de emergencias (las vaciamos)
                    listaRoja = new ListaUrgencia();
                    listaNaranja = new ListaUrgencia();
                    listaAmarilla = new ListaUrgencia();
                    listaVerde = new ListaUrgencia();
                }else return 0;
            }
            break;
        case 1:
            cout << "Indique el DNI del paciente que desea dar de baja: ";
            cin >> DNI; //El usuario introduce el DNI

            if (DNI.empty()){ //Error si no se introduce nada
                cout << "El DNI no puede estar vacio" << endl;
            }
            if (DNI.length()<9){ //Error si no introducimos la longitud correcta
                cout << "La longitud del DNI es incorrecta" << endl;
            }

            //Comprobar si está en pila

            pilaPacientesTemp = PilaPacientes();
            int iteracion;
            bool encontrado; encontrado = false;
            iteracion = 1;
            do {
                //Se va vaciando la pilaEntrada y se vuelca en pilaPacientesTem para ir buscando el paciente del DNI
introducido
                //Se muestran una por una las iteraciones realizadas imprimiendo por pantalla las pilas de los pacientes
(principal y temporal) cout << "Iteracion: " << iteracion << endl; cout << "Pila principal de pacientes" << endl <<
endl; pilaEntrada.mostrar(); cout << endl << "Pila pacientes temporal" << endl << endl; pilaPacientesTemp.mostrar();
                pacienteActual = pilaEntrada.extraer();

                    if (pacienteActual.getDNI() != DNI) { //Si el dni del paciente no coincide con el DNI introducido,
se introduce en una pila temporal pilaPacientesTemp.insertar(pacienteActual); cout << "Pila principal de pacientes" <<
endl << endl; pilaEntrada.mostrar(); cout << endl << "Pila pacientes temporal" << endl << endl;
                        pilaPacientesTemp.mostrar();

                        cout << endl;
                        cout << "El paciente aun no se ha encontrado"<<endl;
                    } else { //Si se encuentra, se revierte la pila temporal en la principal y se borra la pila temporal
                        encontrado = true;
                        cout << endl << "Se ha encontrado el paciente" << endl << "Iniciando el borrado..." << endl <<
"Borrado completo. Reviertiendo listas..."; break;
                    }
                getch();
                iteracion++;
            } while (!pilaEntrada.estaVacia()); //Esto se repetirá hasta que la pilaEntrada esté vacía

            cout << endl;
            cout << "Revertimos el proceso de las pilas" << endl;

            do {
                //Este es el proceso contrario (rellenar)
                cout << "Iteracion: " << iteracion << endl;
                cout << "Pila principal de pacientes" << endl << endl;
                pilaPacientesTemp.mostrar();
                cout << endl << "Pila pacientes temporal" << endl << endl;
                pilaEntrada.mostrar();
                pacienteActual = pilaPacientesTemp.extraer();

                pilaEntrada.insertar(pacienteActual);
                cout << "Pila principal de pacientes" << endl << endl;
                pilaEntrada.mostrar();
                cout << endl << "Pila pacientes temporal" << endl << endl;
                pilaPacientesTemp.mostrar();

                cout << endl;
                getch();
                iteracion++;
            } while (!pilaPacientesTemp.estaVacia()); //Esto se repite hasta que la pilaPacientesTemp esté vacía

            if (encontrado) break; //En el momento en que lo encuentra, para de buscar

            try{
                //Busca en la lista de emergencia Roja
                if (listaRoja -> size!=0){ //Si la lista contiene algo, comienza a buscar en ella
                    listaRoja -> borrar(DNI); //Si lo encuentra, lo borra
                                        cout << "Se ha borrado de la lista roja" << endl << endl;
                    break;
                } else cout << "La lista roja esta vacia" << endl; //Si la lista está vacía, lo indica por pantalla
            } catch(...){
                cout << "No se encuentra en la lista roja" << endl; //Si no está en esta lista, salta una excepción y se
indica por pantalla break;
            }
            getch();

            try{
                //Busca en la lista de emergencia Naranaja
                if (listaNaranja->size!=0){ //Si la lista contiene algo, comienza a buscar en ella
                    listaNaranja->borrar(DNI); //Si lo encuentra, lo borra
                                        cout << "Se ha borrado de la lista naranja" << endl << endl;
                                        break;
                } else cout << "La lista naranja esta vacia" << endl; //Si la lista está vacía, lo indica por pantalla
            } catch(...){
                cout << "No se encuentra en la lista naranja" << endl; //Si no está en esta lista, salta una excepción y
se indica por pantalla
            }
            getch();

            try{
                //Busca en la lista de emergencia Amarilla
                if (listaAmarilla->size!=0){ //Si la lista contiene algo, comienza a buscar en ella
                    listaAmarilla->borrar(DNI); //Si lo encuentra, lo borra
                                        cout << "Se ha borrado de la lista amarilla" << endl << endl;
                                        break;
                } else cout << "La lista amarilla esta vacia" << endl; //Si la lista está vacía, lo indica por pantalla
            } catch(...){
                cout << "No se encuentra en la lista amarilla" << endl; //Si no está en esta lista, salta una excepción
y se indica por pantalla
            }
            getch();

            try{
                //Busca en la lista de emergencia Verde
                if (listaVerde->size!=0){ //Si la lista contiene algo, comienza a buscar en ella
                    listaVerde->borrar(DNI); //Si lo encuentra, lo borra
                                        cout << "Se ha borrado de la lista verde" << endl << endl;
                                        break;
                } else cout << "La lista verde esta vacia" << endl; //Si la lista está vacía, lo indica por pantalla
            } catch(...){
                cout << "No se encuentra en la lista verde" << endl; //Si no está en esta lista, salta una excepción y
se indica por pantalla
            }
            getch();

            cout << "No se ha encontrado el DNI especificado" << endl; //SI no está el DNI, se indica por pantalla

            break;
        case 2:
            //Se declaran las siguientes variables
            int codPaciente, emergenciaA, emergenciaN;

            //Asignacion Codigo Paciente
            cout << "Inserte el codigo de paciente a modificar: ";
            cin >> codPaciente; //El usuario introduce el código del paciente
            if (codPaciente<1 || codPaciente>10){ //Se comprueba que la entreada sea entre 1 y 10
                cout << "ERROR: Codigo de paciente incorrecto" << endl; //Si hay un error, se indica por pantalla
                cout << "Regresando a menu principal..." << endl; //Regresamos al menú principal
                break;
            }

            //Asignacion de Emergencia Antigua
            cout << "Indique la emergencia anterior a la que estaba asignado" << endl;
            cout << "1 - Nivel Rojo - Resucitacion" << endl;
            cout << "2 - Nivel Naranja - Emergencia" << endl;
            cout << "3 - Nivel Amarillo - Urgencia" << endl;
            cout << "4 - Nivel Verde - Urgencia Menor" << endl;;
            cout << "Emergencia anterior: ";
            cin >> emergenciaA; //El usuario introduce la lista donde se encuentra el paciente actualmente

            if (emergenciaA<1 || emergenciaA>4){ //Se comprueba que la entrada sea entre 1 y 4
                cout << "\nERROR: Numero de emergencia antigua erroneo."<< endl; //Si hay un error, se indica por
pantalla cout << "Regresando a menu principal..." << endl; //Regresamos al menú principal break;
            }

                        switch (emergenciaA){
                //Dependiendo de la lista en la que se encuentre entrará en un caso, seleccionará al paciente y lo
borrará de la lista case 1: pacienteActual = listaRoja->buscarCodNumerico(codPaciente);
                                        listaRoja->borrar(pacienteActual.getDNI());
                                        break;
                                case 2:
                                        pacienteActual = listaNaranja->buscarCodNumerico(codPaciente);
                                        listaNaranja->borrar(pacienteActual.getDNI());
                                        break;
                                case 3:
                                        pacienteActual = listaAmarilla->buscarCodNumerico(codPaciente);
                                        listaAmarilla->borrar(pacienteActual.getDNI());
                                        break;
                                case 4:
                                        pacienteActual = listaVerde->buscarCodNumerico(codPaciente);
                                        listaVerde->borrar(pacienteActual.getDNI());
                                        break;
                        }

            cout << "Paciente: " << pacienteActual.getApell1() << endl; //Se imprime por pantalla el paciente
seleccionado

            //Asignacion de Nueva Emergencia
            cout << "Indique la emergencia actual a la que se desea asignar" << endl;
            cout << "1 - Nivel Rojo - Resucitacion" << endl;
            cout << "2 - Nivel Naranja - Emergencia" << endl;
            cout << "3 - Nivel Amarillo - Urgencia" << endl;
            cout << "4 - Nivel Verde - Urgencia Menor" << endl;
            cout << "Emergencia nueva: ";
            cin >> emergenciaN; //El usuario introduce la lista donde se va a trasladar al paciente
            if (emergenciaN<1 || emergenciaN>4){ //Se comprueba que la entrada sea entre 1 y 4
                cout << "\nERROR: Numero de emergencia antigua erroneo."<< endl; //Si hay un error, se indica por
pantalla cout << "Regresando a menu principal..." << endl; //Regresamos al menú principal break;
            }

            //Asignacion Tiempo
            pacienteActual.setPrioridad(emergenciaN);

            //Una vez asignado el tiempo, se asigna al paciente a la nueva lista de emergencia
            switch (pacienteActual.getPrioridad()){
                case 1:
                    listaRoja->insertar(pacienteActual);
                    break;
                case 2:
                    listaNaranja->insertar(pacienteActual);
                    break;
                case 3:
                    listaAmarilla->insertar(pacienteActual);
                    break;
                case 4:
                    listaVerde->insertar(pacienteActual);
                    break;
            }

            break;
        case 3:
            //Se declara la variable para la opción
                        int opcionP3;
                        cout << "Seleccione la opcion que quiere consultar" << endl << endl;
                        cout << "1 - Consultas de pacientes" << endl;
                        cout << "2 - Consultas de emergencia" << endl;
                        cout << "3 - Consultas de tiempos de emergencia superados" << endl << endl;

                        cout << "Opcion: ";
                        cin >> opcionP3; //El usuario introduce la opción que quiere consultar
                        cout << endl;

                        if (opcionP3<1 || opcionP3>3){ //Se comprueba que la entrada sea entre 1 y 3
                                cout << "La opcion seleccionada es erronea" << endl; //Si hay un error, se indica por
pantalla cout << "Regresando al menu principal..." << endl; //Regresamos al menú principal
                        }

                        switch (opcionP3){
                                case 1:
                    //Se declara otra variable para la opción
                                        int opcionP31;
                                        cout << "Seleccione la opcion que quiere consultar" << endl << endl;
                                        cout << "1 - Consultas paciente determinado en pila de paciente" << endl;
                                        cout << "2 - Consultas la pila de pacientes" << endl << endl;
                                        cout << "Opcion: ";
                                        cin >> opcionP31; //El usuario introduce la opción que quiere consultar
                                        cout << endl;
                                        if (opcionP31==1){
                        //Declaramos la variable para poder buscar por DNI
                                                string DNI31;
                                                cout << "Inserte el DNI a buscar: ";
                                                cin >> DNI31; //El usuario introduce el DNI que quiere consultar
                                                bool encontrado = false; //Se declara e iniciliza la variabe encontrado
                                                do {
                            //Vamos comparando el DNI introducido hasta encontrar el paciente correspondiente
                                                        pacienteActual = pilaEntrada.extraer(); //Extraemos el primero
de la pila if (pacienteActual.getDNI() == DNI31) { //Comparamos si tienen el mismo DNI cout << endl << endl << "El
paciente buscado es: " << endl; //En caso positivo, se imprimer el paciente por pantalla pacienteActual.imprimePila();
                                                                encontrado = true;
                                                                break;
                                                        } else {
                                                                pilaPacientesTemp.insertar(pacienteActual); //Se inserta
el paciente actual en la pila temporal
                                                        }
                                                } while (!pilaEntrada.estaVacia()); //Esto se repetirá hasta que la
pilaEntrada esté vacía

                                                if (!encontrado) cout << "El paciente no se ha encontrado" << endl; //Si
no se encuentra el paciente, se indica por pantalla

                                                do {
                            //Extraemos el paciente de la pila temporal para reconstruir nuestra pilaEntrada
                                                        pacienteActual = pilaPacientesTemp.extraer();
                                                        pilaEntrada.insertar(pacienteActual); //Insertamos el paciente
actual en la pilaEntrada para volver a los valores anteriores a la búsqueda } while (!pilaPacientesTemp.estaVacia());
//Esto se repetirá hasta que la pilaPacientesTemp esté vacía } else if (opcionP31==2) { cout << "Imprimiendo pila de
pacientes" << endl << endl; pilaEntrada.mostrar(); //Se imprime por pantalla toda la pila cout << endl; } else { cout <<
"La opcion seleccionada es erronea" << endl; //Si hay un error, se indica por pantalla cout << "Regresando al menu
principal..." << endl; //Regresamos al menÃº principal
                                        }
                                        break;
                                case 2:
                    //Se declara otra variable para la opciÃ³n
                                        int opcionP32;
                                        cout << "Seleccione la opcion que quiere consultar" << endl << endl;
                                        cout << "1 - Consultar emergencia a la que esta asignada un paciente" << endl;
                                        cout << "2 - Consultar la lista de emergencia seleccionada" << endl << endl;
                                        cout << "Opcion: ";
                                        cin >> opcionP32; //El usuario introduce la opciÃ³n que quiere consultar
                                        cout << endl;
                                        if (opcionP32==1){
                        //Declaramos la variable para poder buscar por el cÃ³digo de identificaciÃ³n
                                                int numeroPaciente;
                                                cout << "Inserte el codigo del paciente a buscar: ";
                                                cin >> numeroPaciente; //El usuario introduce el cÃ³digo que quiere
consultar try { pacienteActual = listaRoja->buscarCodNumerico(numeroPaciente); //Buscamos el cÃ³digo del paciente en la
lista Roja if (pacienteActual.getCodNumerico()==numeroPaciente){ //Si coincide con el cÃ³digo introducido cout << "DNI
del paciente: " << pacienteActual.getDNI() << " se encuentra en la lista de emergencias roja"<< endl; //Se indica por
pantalla que se ha encontrado break;
                                                        }
                                                } catch (...) {}

                                                try {
                                                        pacienteActual =
listaNaranja->buscarCodNumerico(numeroPaciente); //Buscamos el cÃ³digo del paciente en la lista Naranja if
(pacienteActual.getCodNumerico()==numeroPaciente){ //Si coincide con el cÃ³digo introducido cout << "DNI del paciente: "
<< pacienteActual.getDNI() << " se encuentra en la lista de emergencias naranja"<< endl; //Se indica por pantalla que se
ha encontrado break;
                                                        }
                                                } catch (...) {}

                                                try {
                                                        pacienteActual =
listaAmarilla->buscarCodNumerico(numeroPaciente); //Buscamos el cÃ³digo del paciente en la lista Amarilla if
(pacienteActual.getCodNumerico()==numeroPaciente){ //Si coincide con el cÃ³digo introducido cout << "DNI del paciente: "
<< pacienteActual.getDNI() << " se encuentra en la lista de emergencias amarilla"<< endl; //Se indica por pantalla que
se ha encontrado break;
                                                        }
                                                } catch (...) {}

                                                try {
                                                        pacienteActual = listaVerde->buscarCodNumerico(numeroPaciente);
//Buscamos el cÃ³digo del paciente en la lista Verde if (pacienteActual.getCodNumerico()==numeroPaciente){ //Si coincide
con el cÃ³digo introducido cout << "DNI del paciente: " << pacienteActual.getDNI() << " se encuentra en la lista de
emergencias verde" << endl; //Se indica por pantalla que se ha encontrado break;
                                                        }
                                                cout << "No se ha encontrado el paciente en ninguna lista"; //Si no se
encuentra el paciente, se indica por pantalla break; } catch (...) {}

                                                cout << "El paciente con el codigo numerico: " << numeroPaciente << " no
se ha encontrado en ninguna lista de emergencias" << endl; } else if (opcionP32==2) {
                        //Declaramos la variable para poder buscar por lista de emergencia
                                                int ArbolConsultado;
                                                cout << "Indique la lista de emergencias que desea ver. " << endl;
                                                cout << "1 - Nivel Rojo - Resucitacion" << endl;
                                                cout << "2 - Nivel Naranja - Emergencia" << endl;
                                                cout << "3 - Nivel Amarillo - Urgencia" << endl;
                                                cout << "4 - Nivel Verde - Urgencia Menor" << endl;
                                                cout << "Opcion: ";
                                                cin >> ArbolConsultado; //El usuario introduce la lista de emergencia
que desea consultar cout << endl; switch (ArbolConsultado){
                            //SegÃºn el caso, mostrarÃ¡ una de las 4 listas disponibles
                                                        case 1:
                                                                cout << "Mostrando lista de emergencias roja..." << endl
<< endl; listaRoja->mostrar(); //Muestra la lista de emergencia Roja break; case 2: cout << "Mostrando lista de
emergencias naranja..." << endl << endl; listaNaranja->mostrar(); //Muestra la lista de emergencia Naranja break; case
3: cout << "Mostrando lista de emergencias amarilla..." << endl << endl; listaAmarilla->mostrar(); //Muestra la lista de
emergencia Amarilla break; case 4: cout << "Mostrando lista de emergencias verde..." << endl << endl;
                                                                listaVerde->mostrar(); //Muestra la lista de emergencia
Verde break;
                                                }
                                        } else {
                                                cout << "La opcion seleccionada es erronea" << endl; //Si hay un error,
se indica por pantalla cout << "Regresando al menu principal..." << endl; //Regresamos al menÃº principal
                                        }
                                        break;
                                case 3:
                                        mostrarListas(listaRoja); //Muestra la lista de emergencia Roja
                                        break;
                        }

            break;
        case 4:
            //Se resetea la PilaPacientes aÃ±adiendo de nuevo todos los pacientes
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

            //Sobreescribimos las listas de emergencias (las vaciamos)
            listaRoja = new ListaUrgencia();
            listaNaranja = new ListaUrgencia();
            listaAmarilla = new ListaUrgencia();
            listaVerde = new ListaUrgencia();

            break;

                case 6:
                        cout << endl << "Lista Roja" << endl;
            listaRoja->mostrar();
            getch();
            cout << endl << "Lista Naranja" << endl;
            listaNaranja->mostrar();
            getch();
            cout << endl << "Lista Amarilla" << endl;
            listaAmarilla->mostrar();
            getch();
            cout << endl << "Lista Verde" << endl;
            listaVerde->mostrar();
            getch();
            break;
        }

        curr_time = time(NULL);
        tm *tm_local = localtime(&curr_time);*/

/*
        cout<< endl << endl << "Fecha y hora actual: " << currentDateTime() << endl;
cout << endl;
cout << "0. Alta de paciente en emergencia" << endl;
cout << "1. Baja de paciente" << endl;
cout << "2. Modificacion-Reasignacion de paciente a tipo emergencia" << endl;
cout << "3. Consultas de pacientes/emergencias" << endl;
cout << "4. Reiniciar programa" << endl;
cout << "5. Salir del programa" << endl;
cout << "Seleccione un opcion del menu: ";
cin >> opcion;
cout << endl << endl;
}

        cout << "Cerrando programa..." << endl << endl;
        cout << "Pulse ENTER para continuar..." <<endl;
        getch();
return 0;
}

*/