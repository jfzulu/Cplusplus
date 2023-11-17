#ifndef _LIBRERIA
#define _LIBRERIA

#include <iostream>
#include <string>
#include <fstream>
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
    char seguro_vuelo;

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
    float ganancia_total;
};

int definirCategoria(int i);
int charToInt(char c);
char retornarLetra(int i);
bool validarAsientos(Asiento asientos[], int tam);

void inicializarReservas(Avion &avion);
void inicializarAvion(Avion &avion);
void listarAvion(Avion &avion);
void imprimirAvion(Avion &avion);

void ingresarReserva(Avion &avion);

void finalizarReserva(Avion &avion);
void imprimirReservas(Avion &avion);
bool existeReserva(Avion &avion, int reserva, int &indiceReserva);
void actualizarAvion(Avion &avion, int reserva);

void consultarRegistros(Avion &avion);
void imprimirReserva(Avion &avion, int reserva);

void buscarReserva(Avion &avion);
void buscarReservaNombre(Avion &avion, string nombre);
void buscarReservaDocumento(Avion &avion, int documento);

void mostrarPortal(Avion &avion);  
void reservas_categoria(Avion &avion, int categoria);


void consultarAsientosOcupados(Avion &avion);
void calcularReservasCategoria(Avion &avion);
void escribirArchivo(int categoria, float total);
float total_categoria(Avion &avion, int categoria);
void calcularGananciaAvion(Avion &avion);


#endif