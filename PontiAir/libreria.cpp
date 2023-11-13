#include "libreria.h"

char retornarLetra(int i)
{
    if (i == 0)
    {
        return 'A';
    }
    if (i == 1)
    {
        return 'B';
    }
    if (i == 2)
    {
        return 'C';
    }
    if (i == 3)
    {
        return 'D';
    }
    if (i == 4)
    {
        return 'E';
    }
    if (i == 5)
    {
        return 'F';
    }
}

int definirCategoria(int i)
{
    if ( i>=4 && i<=10)//Categoria Business
    {
        return 500;
    }
    if ( i == 11)//Categoria Emergencia
    {
        return 250;
    }

    if ( i>=12 && i<=20)
    {
        return 200;
    }

    if ( i>=21 && i<=30)
    {
        return 150;
    }

    return 0;
}
void inicializarAvion(Avion *avion)
{
    cout << "Inicializar avion" << endl;
    cout << "Ingrese numero de vuelo: " << endl;
    cin >> avion->numero_vuelo;
    cout << "Ingrese destino: " << endl;
    cin >> avion->destino;
    avion->contador_reservas = 0;
    
   
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            avion->asientos[i][j].numero_vuelo = avion->numero_vuelo;
            avion->asientos[i][j].destino = avion->destino;
            avion->asientos[i][j].fila = i+4;
            avion->asientos[i][j].numero_asiento = j;
            avion->asientos[i][j].estado = 'L';
            avion->asientos[i][j].categoria = definirCategoria(i+4);
            avion->asientos[i][j].numero_reserva = 000;
            
        }
    }
    mostrarAvion(avion);
    cout << "AVION CREADO SATISFACTORIAMENTE"<<endl;
}




void mostrarAvion(Avion *avion)
{
    cout << "Mostrar avion" << endl;
    cout << "Numero de vuelo: " << avion->numero_vuelo << endl;
    cout << "Destino: " << avion->destino << endl;
    cout << "Asientos" << endl;
    std::cout << std::setw(5) << "Vuelo" << std::setw(10) << "Fila" << std::setw(10) << "Columna" << std::setw(10) << "Estado" << std::setw(10) << "Categoria" << std::endl;
    cout << "-----------------------------------------------------" << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << setw(5) << avion->asientos[i][j].numero_vuelo
                << setw(10) << avion->asientos[i][j].fila
                << setw(10) << retornarLetra(avion->asientos[i][j].numero_asiento)
                << setw(10) << avion->asientos[i][j].estado
                << setw(10) << avion->asientos[i][j].categoria<<endl;
        }
    }
}
void ingresarReserva()
{
    cout << "Ingresar Reserva" << endl;
}

void finalizarReserva()
{
    cout << "Finalizar Reserva" << endl;
}

void consultarRegistros()
{
    cout << "Consultar registros por fila" << endl;
}