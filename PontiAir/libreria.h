#ifndef _LIBRERIA
#define _LIBRERIA

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#define filas 27
#define columnas 6


struct Reserva{
    string nombre_cliente;
    int numero_documento;
    char sexo_cliente;
    int cantidad_pasajeros;
    int numero_reserva;
    bool seguro_vuelo;

};

struct Asiento{
    int numero_vuelo;
    string destino;
    int fila;
    int numero_asiento;
    char estado;
    int categoria;
    int numero_reserva;
};

struct Avion{
    int numero_vuelo;
    string destino;
    Asiento asientos[filas][columnas];
    Reserva reservas[50];
    int contador_reservas;
};

int definirCategoria(int i);
int charToInt(char c);
char retornarLetra(int i);
void listarDisponibles(Avion *avion, int cantidad);
bool validarAsientos (Asiento asientoPrevio, Asiento asientoAux, Avion *avion);
void inicializarReservas(Avion *avion);
void inicializarAvion(Avion *avion);
void listarAvion(Avion *avion);
void imprimirAvion(Avion *avion);
void ingresarReserva(Avion *avion);
void finalizarReserva();
void consultarRegistros();

#endif