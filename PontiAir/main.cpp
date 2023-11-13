#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "libreria.h"
using namespace std;
int main()
{
    Avion avion;
    inicializarAvion(&avion);
    inicializarReservas(&avion);
    //listarAvion(&avion);
    //imprimirAvion(&avion);
    int opc;
    bool valido = false;

    do
    {
        valido = false;
        //cout << "\033[2J\033[H";
        cout << "\n\nBIENVENIDO A PONTIAIR" << endl;
        cout << "1. Ingresar reserva" << endl;
        cout << "2. Finalizar reserva" << endl;
        cout << "3. Consultar registros por fila" << endl;
        cout << "4. Buscar reserva" << endl;
        cout << "5. Mostrar todo el portal" << endl;
        cout << "6. Consultar asientos ocupados" << endl;
        cout << "7. Calcular el total de reservas vendidas por categoria" << endl;
        cout << "8. Calcular el total de ganancias por reservas vendidas de todo el avion" << endl;
        cout << "9. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            ingresarReserva(&avion);
            break;
        case 2:
            finalizarReserva();
            break;
        case 3:
            consultarRegistros();
            break;
        }
        if (opc >= 1 && opc <= 9)
        {
            valido = true;
        }
        if (valido == false)
        {
            cout << "OPCION INVALIDA"<<endl;
            cout << "Por favor ingrese una opcion valida"<<endl;
            valido=true;
        }
        cout << "Presione Enter para continuar...";
        cin.ignore();
        cin.get();
        cout << "\033[2J\033[H";

    } while (opc != 9 && valido == true);

    cout << "Que tenga feliz dia... Gracias por usar PontiAir" << endl;
    return 0;
}