#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <operaciones.h>
using namespace std;
int main()
{
    int opc;
    bool valido=false;
    
    do{
        cout << "BIENVENIDO A PONTIAIR"<<endl;
        cout << "1. Ingresar reserva"<<endl;
        cout << "2. Finalizar reserva"<<endl;
        cout << "3. Consultar registros por fila"<<endl;
        cout << "4. Buscar reserva"<<endl;
        cout << "5. Mostrar todo el portal"<<endl;
        cout << "6. Consultar asientos ocupados"<<endl;
        cout << "7. Calcular el total de reservas vendidas por categoria"<<endl;
        cout << "8. Calcular el total de ganancias por reservas vendidas de todo el avion"<<endl;
        cout << "9. Salir"<<endl;
        cout <<"Seleccione una opcion: ";
        cin >> opc;
        if (opc >= 1 &&  opc<=9){
            valido = true;
        }
        if (valido == false){
            cout << "Ingrese una opcion valida..."<<endl;
            valido = true;
            system("pause");
        }
        system("cls");
    }while(opc != 9 && valido==true);

    cout << "Que tenga feliz dia... Gracias por usar PontiAir"<<endl;
}