#include <iostream>
#include <stdio.h>

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
