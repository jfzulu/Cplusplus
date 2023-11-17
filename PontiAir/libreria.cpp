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

    return 'A';
}

int charToInt(char c)
{
    if (c == 'A')
    {
        return 0;
    }
    if (c == 'B')
    {
        return 1;
    }
    if (c == 'C')
    {
        return 2;
    }
    if (c == 'D')
    {
        return 3;
    }
    if (c == 'E')
    {
        return 4;
    }
    if (c == 'F')
    {
        return 5;
    }
    return -1;
}
int definirCategoria(int i)
{
    i = i + 4;
    if (i >= 4 && i <= 10) // Categoria Business
    {
        return 500;
    }
    if (i == 11) // Categoria Emergencia
    {
        return 250;
    }

    if (i >= 12 && i <= 20)
    {
        return 200;
    }

    if (i >= 21 && i <= 30)
    {
        return 100;
    }
    return 0;
}

void inicializarReservas(Avion &avion)
{
    Reserva reservaAux;
    // Para asiento A-4
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = 'S';
    reservaAux.numero_reserva = 100;
    reservaAux.numero_documento = 1447895623;
    reservaAux.nombre_cliente = "Olivia";
    avion.asientos[0][0].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[0][0].estado = 'O';
    avion.reservas[avion.contador_reservas] = reservaAux;
    avion.contador_reservas++;
    // Para asiento C-4
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Liam";
    reservaAux.numero_reserva = 101;
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = 'N';
    reservaAux.numero_documento = 88030547;
    avion.asientos[0][2].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[0][2].estado = 'O';
    avion.reservas[avion.contador_reservas] = reservaAux;
    avion.contador_reservas++;
    // Para asiento D-4
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Emma";
    reservaAux.numero_reserva = 102;
    reservaAux.sexo_cliente = 'F';
    reservaAux.seguro_vuelo = 'S';
    reservaAux.numero_documento = 94084786;
    avion.asientos[0][3].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[0][3].estado = 'O';
    avion.reservas[avion.contador_reservas] = reservaAux;
    avion.contador_reservas++;
    // Para asientos A-8 to E-8
    reservaAux.cantidad_pasajeros = 5;
    reservaAux.nombre_cliente = "Noah";
    reservaAux.numero_reserva = 103;
    reservaAux.sexo_cliente = 'F';
    reservaAux.seguro_vuelo = 'S';
    reservaAux.numero_documento = 30860651;
    avion.asientos[4][0].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[4][0].estado = 'O';
    avion.asientos[4][1].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[4][1].estado = 'O';
    avion.asientos[4][2].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[4][2].estado = 'O';
    avion.asientos[4][3].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[4][3].estado = 'O';
    avion.asientos[4][4].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[4][4].estado = 'O';
    avion.reservas[avion.contador_reservas] = reservaAux;
    avion.contador_reservas++;
    // Para asientos C-9
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Ava";
    reservaAux.sexo_cliente = 'F';
    reservaAux.numero_reserva = 104;
    reservaAux.seguro_vuelo = 'N';
    reservaAux.numero_documento = 1001101201;
    avion.asientos[5][2].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[5][2].estado = 'O';
    avion.reservas[avion.contador_reservas] = reservaAux;
    avion.contador_reservas++;
    // Para asientos D-9
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Isabella";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = 'S';
    reservaAux.numero_reserva = 105;
    reservaAux.numero_documento = 1002102202;
    avion.asientos[5][3].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[5][3].estado = 'O';
    avion.reservas[avion.contador_reservas] = reservaAux;
    avion.contador_reservas++;
    // Para asientos C-10
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Sophia";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = 'S';
    reservaAux.numero_reserva = 106;
    reservaAux.numero_documento = 1003103203;
    avion.asientos[6][2].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[6][2].estado = 'O';
    avion.reservas[avion.contador_reservas] = reservaAux;
    avion.contador_reservas++;
    // Para asientos E-10 to F-10
    reservaAux.cantidad_pasajeros = 2;
    reservaAux.nombre_cliente = "Jackson";
    reservaAux.sexo_cliente = 'F';
    reservaAux.seguro_vuelo = 'S';
    reservaAux.numero_reserva = 107;
    reservaAux.numero_documento = 1004104204;
    avion.asientos[6][4].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[6][4].estado = 'O';
    avion.asientos[6][5].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[6][5].estado = 'O';
    avion.reservas[avion.contador_reservas] = reservaAux;
    avion.contador_reservas++;
    // Para asientos A-11 to B-11
    reservaAux.cantidad_pasajeros = 2;
    reservaAux.nombre_cliente = "Aiden";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = 'N';
    reservaAux.numero_reserva = 108;
    reservaAux.numero_documento = 1005105205;
    avion.asientos[7][0].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[7][0].estado = 'O';
    avion.asientos[7][1].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[7][1].estado = 'O';
    avion.reservas[avion.contador_reservas] = reservaAux;
    avion.contador_reservas++;
    // Para asientos D-12 to E-12
    reservaAux.cantidad_pasajeros = 2;
    reservaAux.nombre_cliente = "Lucas";
    reservaAux.sexo_cliente = 'F';
    reservaAux.seguro_vuelo = 'N';
    reservaAux.numero_reserva = 109;
    reservaAux.numero_documento = 1006106206;
    avion.asientos[8][3].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[8][3].estado = 'O';
    avion.asientos[8][4].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[8][4].estado = 'O';
    avion.reservas[avion.contador_reservas] = reservaAux;
    avion.contador_reservas++;
    // Para asientos A-13
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Mia";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = 'N';
    reservaAux.numero_reserva = 110;
    reservaAux.numero_documento = 1007107207;
    avion.asientos[9][0].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[9][0].estado = 'O';
    avion.reservas[avion.contador_reservas] = reservaAux;
    avion.contador_reservas++;
    // Para asientos E-13 to F-13
    reservaAux.cantidad_pasajeros = 2;
    reservaAux.nombre_cliente = "Amelia";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = 'S';
    reservaAux.numero_reserva = 111;
    reservaAux.numero_documento = 1008108208;
    avion.asientos[9][4].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[9][4].estado = 'O';
    avion.asientos[9][5].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[9][5].estado = 'O';
    avion.reservas[avion.contador_reservas] = reservaAux;
    avion.contador_reservas++;
    // Para asientos A-14
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Harper";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = 'N';
    reservaAux.numero_reserva = 112;
    reservaAux.numero_documento = 1009109209;
    avion.asientos[10][0].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[10][0].estado = 'O';
    avion.reservas[avion.contador_reservas] = reservaAux;
    avion.contador_reservas++;
    // Para asientos D-14 to F-14
    reservaAux.cantidad_pasajeros = 3;
    reservaAux.nombre_cliente = "Elijah";
    reservaAux.sexo_cliente = 'F';
    reservaAux.seguro_vuelo = 'N';
    reservaAux.numero_reserva = 113;
    reservaAux.numero_documento = 1010110210;
    avion.asientos[10][3].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[10][3].estado = 'O';
    avion.asientos[10][4].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[10][4].estado = 'O';
    avion.asientos[10][5].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[10][5].estado = 'O';
    avion.reservas[avion.contador_reservas] = reservaAux;
    avion.contador_reservas++;
    // Para asientos F-15
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Abigail";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = 'N';
    reservaAux.numero_reserva = 114;
    reservaAux.numero_documento = 1011111211;
    avion.asientos[11][5].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[11][5].estado = 'O';
    avion.reservas[avion.contador_reservas] = reservaAux;
    avion.contador_reservas++;
    // Para asientos E-16 to F-16
    reservaAux.cantidad_pasajeros = 2;
    reservaAux.nombre_cliente = "Benjamin";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = 'S';
    reservaAux.numero_reserva = 115;
    reservaAux.numero_documento = 1012112212;
    avion.asientos[12][4].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[12][4].estado = 'O';
    avion.asientos[12][5].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[12][5].estado = 'O';
    avion.reservas[avion.contador_reservas] = reservaAux;
    avion.contador_reservas++;
    // Para asientos D-24
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Camilo";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = 'N';
    reservaAux.numero_reserva = 116;
    reservaAux.numero_documento = 1013113213;
    avion.asientos[25][3].numero_reserva = reservaAux.numero_reserva;
    avion.asientos[25][3].estado = 'O';
    avion.reservas[avion.contador_reservas] = reservaAux;
    avion.contador_reservas++;
}
void inicializarAvion(Avion &avion)
{
    cout << "Inicializar avion" << endl;
    cout << "Ingrese numero de vuelo: " << endl;
    cin >> avion.numero_vuelo;
    cout << "Ingrese destino: " << endl;
    cin >> avion.destino;
    avion.contador_reservas = 0;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            avion.asientos[i][j].numero_vuelo = avion.numero_vuelo;
            avion.asientos[i][j].destino = avion.destino;
            avion.asientos[i][j].fila = i + 4;
            avion.asientos[i][j].numero_asiento = j;
            avion.asientos[i][j].estado = 'L';
            avion.asientos[i][j].categoria = definirCategoria(i);
            avion.asientos[i][j].numero_reserva = 000;
        }
    }
    /* mostrarAvion(avion); */
    cout << "AVION CREADO SATISFACTORIAMENTE" << endl;
}

void imprimirAvion(Avion &avion)
{
    cout << setw(3) << "A" << setw(3) << "B" << setw(3) << "C" << setw(5) << "-" << setw(3) << "D" << setw(3) << "E" << setw(3) << "F" << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {

            cout << setw(3) << avion.asientos[i][j].estado;

            if (j == 2)
            {
                cout << setw(5) << avion.asientos[i][j].fila;
            }
        }
        cout << endl;
    }
    cout << "\n";
}

void listarAvion(Avion &avion)
{
    cout << "Mostrar avion" << endl;
    cout << "Numero de vuelo: " << avion.numero_vuelo << endl;
    cout << "Destino: " << avion.destino << endl;
    cout << "Asientos" << endl;
    std::cout << std::setw(5) << "Vuelo" << std::setw(10) << "Fila" << std::setw(10) << "Columna" << std::setw(10) << "Estado" << std::setw(10) << "Categoria" << std::endl;
    cout << "-----------------------------------------------------" << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << setw(5) << avion.asientos[i][j].numero_vuelo
                 << setw(10) << avion.asientos[i][j].fila
                 << setw(10) << retornarLetra(avion.asientos[i][j].numero_asiento)
                 << setw(10) << avion.asientos[i][j].estado
                 << setw(10) << avion.asientos[i][j].categoria << endl;
        }
    }
}

bool validarAsientos(Asiento asientos[], int tam)
{
    bool valido = true;
    int fila = asientos[0].fila;
    int columna = asientos[0].numero_asiento;
    for (int i = 1; i < tam; i++)
    {
        if (asientos[i].fila != fila)
        {
            valido = false;
            return valido;
        }

        if (asientos[i].numero_asiento - asientos[i - 1].numero_asiento != 1)
        {
            valido = false;
            return valido;
        }
    }

    return valido;
}

void ingresarReserva(Avion &avion)
{
    Reserva reserva;
    cout << "======INGRESAR RESERVA======" << endl;
    imprimirAvion(avion);
    cout << "Ingrese cantidad de pasajeros: ";
    cin >> reserva.cantidad_pasajeros;
    if (reserva.cantidad_pasajeros <= 6)
    {
        int indiceAsientos = 0;
        cout << "Ingrese asientos deseados" << endl;
        Asiento puestos[reserva.cantidad_pasajeros];
        Asiento aux;
        char columna;
        int fila;
        bool valido = true;
        for (int i = 0; i < reserva.cantidad_pasajeros; i++)
        {
            do
            {
                valido = true;
                cout << "Asiento " << i + 1 << endl;
                cout << "Fila(4-30): ";
                cin >> fila;
                aux.fila = fila - 4;
                cout << "Columna(A-F): ";
                cin >> columna;
                aux.numero_asiento = charToInt(columna);
                // cout << "Asiento seleccionado: " << aux.fila << "-" << aux.numero_asiento << endl;
                if (avion.asientos[aux.fila][aux.numero_asiento].estado == 'L')
                {
                    // aux = avion.asientos[aux.fila][aux.numero_asiento];
                    puestos[indiceAsientos] = aux;
                    indiceAsientos++;
                }
                else
                {
                    cout << "Asiento ocupado" << endl;
                    cout << "Seleccione otro asiento" << endl;
                    valido = false;
                }
            } while (!valido);
        }
        bool asientosValidos = validarAsientos(puestos, reserva.cantidad_pasajeros);

        if (asientosValidos)
        {

            cout << "Asientos validos" << endl;
            cout << indiceAsientos << endl;
            cout << "Ingrese nombre del cliente: ";
            cin >> reserva.nombre_cliente;
            cout << "Ingrese documento del cliente: ";
            cin >> reserva.numero_documento;
            cout << "Ingrese sexo del cliente(M/F/N): ";
            cin >> reserva.sexo_cliente;
            cout << "Cuenta con seguro de viaje? (S/N): ";
            cin >> reserva.seguro_vuelo;
            int nReserva = avion.reservas[avion.contador_reservas - 1].numero_reserva;
            reserva.numero_reserva = nReserva + 1;
            avion.reservas[avion.contador_reservas] = reserva;
            avion.contador_reservas++;
            for (int i = 0; i < indiceAsientos; i++)
            {
                avion.asientos[puestos[i].fila][puestos[i].numero_asiento].numero_reserva = reserva.numero_reserva;
                avion.asientos[puestos[i].fila][puestos[i].numero_asiento].estado = 'O';
            }

            cout << "###===RESERVA EXITOSA===###" << endl;
        }
        else
        {
            cout << "Asientos invalidos" << endl;
            cout << "Intente una nueva reserva " << endl;
        }
    }
    else
    {
        cout << "Cantidad de pasajeros invalido" << endl;
        cout << "El maximo de pasajeros por reserva son 6" << endl;
    }
}

bool existeReserva(Avion &avion, int reserva, int &indiceReserva)
{
    for (int i = 0; i < avion.contador_reservas; i++)
    {
        if (avion.reservas[i].numero_reserva == reserva)
        {
            cout << "Reserva existente" << endl;
            indiceReserva = i;
            return true;
        }
    }
    return false;
}

void finalizarReserva(Avion &avion)
{
    cout << "###===FINALIZAR RESERVA===###" << endl;
    imprimirReservas(avion);
    int reserva;
    cout << "Ingrese numero de reserva a finalizar: ";
    cin >> reserva;
    int indiceReserva = 0;
    bool existe = existeReserva(avion, reserva, indiceReserva);
    if (existe)
    {
        /* cout << "Posicion reserva: "<< indiceReserva << endl; */
        for (int i = indiceReserva; i < avion.contador_reservas - 1; ++i)
        {
            avion.reservas[i] = avion.reservas[i + 1];
        }

        avion.contador_reservas--;

        cout << "RESERVA ELIMINADA SATISFACTORIAMENTE" << endl;

        actualizarAvion(avion, reserva);
        // imprimirReservas(avion);
    }
    else
    {
        cout << "Reserva no existente" << endl;
        cout << "Seleccione una reserva existente" << endl;
    }
}

void actualizarAvion(Avion &avion, int reserva)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (avion.asientos[i][j].numero_reserva == reserva)
            {
                avion.asientos[i][j].numero_reserva = 0;
                avion.asientos[i][j].estado = 'L';
            }
        }
    }
}

void imprimirReservas(Avion &avion)
{
    cout << "###===RESERVAS===###" << endl;
    cout << setw(20) << "N_Reserva"
         << setw(20) << "Nombre"
         << setw(20) << "Documento"
         << setw(20) << "Sexo"
         << setw(20) << "N_Pasajeros"
         << setw(20) << "Seguro" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < avion.contador_reservas; i++)
    {
        cout << setw(20) << avion.reservas[i].numero_reserva
             << setw(20) << avion.reservas[i].nombre_cliente
             << setw(20) << avion.reservas[i].numero_documento
             << setw(20) << avion.reservas[i].sexo_cliente
             << setw(20) << avion.reservas[i].cantidad_pasajeros
             << setw(20) << avion.reservas[i].seguro_vuelo << endl;
    }
}
void consultarRegistros(Avion &avion)
{
    imprimirAvion(avion);
    cout << "###===CONSULTAR REGISTROS===###" << endl;
    int fila;
    int nReserva;
    cout << "Ingrese fila para consultar registros: ";
    cin >> fila;
    fila = fila - 4;
    cout << "###===REGISTROS "
         << "FILA " << fila + 4 << "===###" << endl;
    for (int i = 0; i < columnas; i++)
    {
        if (avion.asientos[fila][i].estado == 'O')
        {
            nReserva = avion.asientos[fila][i].numero_reserva;
            imprimirReserva(avion, nReserva);
        }
    }
}

void imprimirReserva(Avion &avion, int reserva)
{
    for (int i = 0; i < avion.contador_reservas; i++)
    {
        if (avion.reservas[i].numero_reserva == reserva)
        {
            cout << "###===RESERVA===###" << endl;
            cout << setw(20) << "N_Reserva"
                 << setw(20) << "Nombre"
                 << setw(20) << "Documento"
                 << setw(20) << "Sexo"
                 << setw(20) << "N_Pasajeros"
                 << setw(20) << "Seguro" << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << setw(20) << avion.reservas[i].numero_reserva
                 << setw(20) << avion.reservas[i].nombre_cliente
                 << setw(20) << avion.reservas[i].numero_documento
                 << setw(20) << avion.reservas[i].sexo_cliente
                 << setw(20) << avion.reservas[i].cantidad_pasajeros
                 << setw(20) << avion.reservas[i].seguro_vuelo << endl;
        }
    }
    cout << "\n\n\n";
}

void buscarReserva(Avion &avion)
{
    int opc;
    string nombre;
    int documento;
    imprimirReservas(avion);
    cout << "###===BUSCAR RESERVA===###" << endl;
    cout << "Como desea buscar la reserva?" << endl;
    cout << "1. Nombre" << endl;
    cout << "2. Documento" << endl;
    cin >> opc;
    switch (opc)
    {
    case 1:
        cout << "Ingrese nombre: ";
        cin >> nombre;
        buscarReservaNombre(avion, nombre);
        break;
    case 2:
        cout << "Ingrese documento: ";
        cin >> documento;
        buscarReservaDocumento(avion, documento);
        break;
    }
}

void buscarReservaNombre(Avion &avion, string nombre)
{
    int nReserva;
    for (int i = 0; i < avion.contador_reservas; i++)
    {
        if (avion.reservas[i].nombre_cliente == nombre)
        {
            nReserva = avion.reservas[i].numero_reserva;
            imprimirReserva(avion, nReserva);
        }
    }
}

void buscarReservaDocumento(Avion &avion, int documento)
{
    int nReserva;
    for (int i = 0; i < avion.contador_reservas; i++)
    {
        if (avion.reservas[i].numero_documento == documento)
        {
            nReserva = avion.reservas[i].numero_reserva;
            imprimirReserva(avion, nReserva);
        }
    }
}

void mostrarPortal(Avion &avion)
{
    int category[4] = {500, 250, 200, 100};
    cout << "###===PORTAL===###" << endl;
    for (int i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 0:
            cout << "+++++CATEGORIA BUSINESS+++++" << endl;
            reservas_categoria(avion, category[i]);
            break;
        case 1:
            cout << "++++++CATEGORIA EMERGENCIA+++++" << endl;
            reservas_categoria(avion, category[i]);
            break;
        case 2:
            cout << "+++++CATEGORIA ESTANDAR+++++" << endl;
            reservas_categoria(avion, category[i]);
            break;
        case 3:
            cout << "+++++CATEGORIA ECONOMICA++++++" << endl;
            reservas_categoria(avion, category[i]);
            break;
        }
    }
}

void reservas_categoria(Avion &avion, int categoria)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (avion.asientos[i][j].categoria == categoria && avion.asientos[i][j].estado == 'O')
            {
                imprimirReserva(avion, avion.asientos[i][j].numero_reserva);
            }
        }
    }
}
void consultarAsientosOcupados(Avion &avion)
{
    cout << "###===ASIENTOS OCUPADOS===###" << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (avion.asientos[i][j].estado == 'O')
            {
                cout << avion.asientos[i][j].fila << " - " << retornarLetra(avion.asientos[i][j].numero_asiento) << endl;
            }
        }
    }
}
void calcularReservasCategoria(Avion &avion)
{
    int nReserva;
    float totalCategoria = 0;
    int category[4] = {500, 250, 200, 100};
    cout << "###===RESERVAS POR CATEGORIA===###" << endl;

    for (int i = 0; i < 4; i++)
    {
        totalCategoria = 0;
        switch (i)
        {
        case 0:
            cout << "+++++CATEGORIA BUSINESS+++++" << endl;
            totalCategoria = total_categoria(avion, category[i]);
            cout << "Total: " << totalCategoria << endl;
            escribirArchivo(category[i], totalCategoria);
            break;
        case 1:
            cout << "++++++CATEGORIA EMERGENCIA+++++" << endl;
            totalCategoria = total_categoria(avion, category[i]);
            cout << "Total: " << totalCategoria << endl;
            escribirArchivo(category[i], totalCategoria);
            break;
        case 2:
            cout << "+++++CATEGORIA ESTANDAR+++++" << endl;
            totalCategoria = total_categoria(avion, category[i]);
            cout << "Total: " << totalCategoria << endl;
            escribirArchivo(category[i], totalCategoria);
            break;
        case 3:
            cout << "+++++CATEGORIA ECONOMICA++++++" << endl;
            totalCategoria = total_categoria(avion, category[i]);
            cout << "Total: " << totalCategoria << endl;
            escribirArchivo(category[i], totalCategoria);
            break;
        }
    }
}

void escribirArchivo(int categoria, float total)
{
    // Abre el archivo en modo de escritura (se crea si no existe)
    std::ofstream archivo("informacion.txt", std::ios::app);
    string category;
    if (categoria == 500)
    {
        category = "BUSINESS";
    }
    else if (categoria == 250)
    {
        category = "EMERGENCIA";
    }
    else if (categoria == 200)
    {
        category = "ESTANDAR";
    }
    else
    {
        category = "ECONOMICA";
    }

    if (archivo.is_open()) {
        // Escribe la información en el archivo
        archivo << "Categoría: " << category << ", Total: " << total << std::endl;

        // Cierra el archivo
        archivo.close();

        std::cout << "Informacion escrita en el archivo correctamente." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo." << std::endl;
    }
}

float total_categoria(Avion &avion, int categoria)
{
    float totalCategoria = 0;
    for (int k = 0; k < filas; k++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (avion.asientos[k][j].categoria == categoria && avion.asientos[k][j].estado == 'O')
            {
                for (int l = 0; l < avion.contador_reservas; l++)
                {
                    if (avion.reservas[l].numero_reserva == avion.asientos[k][j].numero_reserva)
                    {
                        if (avion.reservas[l].seguro_vuelo == 'S')
                        {
                            totalCategoria = totalCategoria + categoria + 100;
                        }
                        else
                        {
                            totalCategoria = totalCategoria + categoria;
                        }
                    }
                }
            }
        }
    }
    return totalCategoria;
}
void calcularGananciaAvion(Avion &avion)
{
    float ganancia = 0;
    int category[4] = {500, 250, 200, 100};
    cout << "###===GANANCIAS TOTALES===###" << endl;

    for (int i = 0; i < 4; i++)
    {
        for ( int j = 0; j<filas; j++)
        {
            for (int k = 0; k < columnas; k++)
            {
                if (avion.asientos[j][k].categoria == category[i] && avion.asientos[j][k].estado == 'O')
                {
                    for (int l=0; l< avion.contador_reservas; l++)
                    {
                        if (avion.reservas[l].numero_reserva == avion.asientos[j][k].numero_reserva)
                        {
                            if (avion.reservas[l].seguro_vuelo == 'S')
                            {
                                ganancia = ganancia + category[i] + 100;
                            }
                            else
                            {
                                ganancia = ganancia + category[i];
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "Total: " << ganancia << endl;
}