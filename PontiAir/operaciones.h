#ifndef __OPERACIONES__H__
#define __OPERACIONES__H__

struct Reserva{
    string nombre_cliente;
    int numero_documento;
    char sexo_cliente;
    int cantidad_pasajeros;
    int numero_reserva;
    bool seguro_vuelo;

};

struct Asientos{
    int numero_vuelo;
    string destino;
    int fila;
    int numero_asiento;
    char estado;
    int categoria;
};

void ingresarReserva();
void finalizarReserva();
void consultarRegistros();
void buscarReserva();
void mostrarPortal();
void consultarAsientosOcupados();
void calcularReservasVendidasPorCategoria();
void calcularTotalGanancias();


#include "operaciones.cpp"
#endif