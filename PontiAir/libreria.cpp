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
        return 150;
    }

    return 0;
}

void inicializarReservas(Avion *avion)
{
    Reserva reservaAux;
    // Para asiento A-4
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = true;
    reservaAux.numero_reserva = 100;
    reservaAux.numero_documento = 1447895623;
    reservaAux.nombre_cliente = "Juan Perez";
    avion->asientos[0][0].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[0][0].estado = 'O';
    avion->reservas[avion->contador_reservas] = reservaAux;
    avion->contador_reservas++;
    // Para asiento C-4
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Charlie Brown";
    reservaAux.numero_reserva = 101;
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = false;
    reservaAux.numero_documento = 88030547;
    avion->asientos[0][2].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[0][2].estado = 'O';
    avion->reservas[avion->contador_reservas] = reservaAux;
    avion->contador_reservas++;
    // Para asiento D-4
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Maria Lopez";
    reservaAux.numero_reserva = 102;
    reservaAux.sexo_cliente = 'F';
    reservaAux.seguro_vuelo = true;
    reservaAux.numero_documento = 94084786;
    avion->asientos[0][3].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[0][3].estado = 'O';
    avion->reservas[avion->contador_reservas] = reservaAux;
    avion->contador_reservas++;
    // Para asientos A-8 to E-8
    reservaAux.cantidad_pasajeros = 5;
    reservaAux.nombre_cliente = "Luisa Gutierrez";
    reservaAux.numero_reserva = 103;
    reservaAux.sexo_cliente = 'F';
    reservaAux.seguro_vuelo = true;
    reservaAux.numero_documento = 30860651;
    avion->asientos[4][0].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[4][0].estado = 'O';
    avion->asientos[4][1].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[4][1].estado = 'O';
    avion->asientos[4][2].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[4][2].estado = 'O';
    avion->asientos[4][3].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[4][3].estado = 'O';
    avion->asientos[4][4].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[4][4].estado = 'O';
    avion->reservas[avion->contador_reservas] = reservaAux;
    avion->contador_reservas++;
    // Para asientos C-9
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Grace Hopper";
    reservaAux.sexo_cliente = 'F';
    reservaAux.numero_reserva = 104;
    reservaAux.seguro_vuelo = false;
    reservaAux.numero_documento = 1001101201;
    avion->asientos[5][2].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[5][2].estado = 'O';
    avion->reservas[avion->contador_reservas] = reservaAux;
    avion->contador_reservas++;
    // Para asientos D-9
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Bob Dylan";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = true;
    reservaAux.numero_reserva = 105;
    reservaAux.numero_documento = 1002102202;
    avion->asientos[5][3].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[5][3].estado = 'O';
    avion->reservas[avion->contador_reservas] = reservaAux;
    avion->contador_reservas++;
    // Para asientos C-10
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Homer Simpson";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = true;
    reservaAux.numero_reserva = 106;
    reservaAux.numero_documento = 1003103203;
    avion->asientos[6][2].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[6][2].estado = 'O';
    avion->reservas[avion->contador_reservas] = reservaAux;
    avion->contador_reservas++;
    // Para asientos E-10 to F-10
    reservaAux.cantidad_pasajeros = 2;
    reservaAux.nombre_cliente = "Marge Simpson";
    reservaAux.sexo_cliente = 'F';
    reservaAux.seguro_vuelo = true;
    reservaAux.numero_reserva = 107;
    reservaAux.numero_documento = 1004104204;
    avion->asientos[6][4].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[6][4].estado = 'O';
    avion->asientos[6][5].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[6][5].estado = 'O';
    avion->reservas[avion->contador_reservas] = reservaAux;
    avion->contador_reservas++;
    // Para asientos A-11 to B-11
    reservaAux.cantidad_pasajeros = 2;
    reservaAux.nombre_cliente = "Andres Gutierrez";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = false;
    reservaAux.numero_reserva = 108;
    reservaAux.numero_documento = 1005105205;
    avion->asientos[7][0].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[7][0].estado = 'O';
    avion->asientos[7][1].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[7][1].estado = 'O';
    avion->reservas[avion->contador_reservas] = reservaAux;
    avion->contador_reservas++;
    // Para asientos D-12 to E-12
    reservaAux.cantidad_pasajeros = 2;
    reservaAux.nombre_cliente = "Sandra Torres";
    reservaAux.sexo_cliente = 'F';
    reservaAux.seguro_vuelo = false;
    reservaAux.numero_reserva = 109;
    reservaAux.numero_documento = 1006106206;
    avion->asientos[8][3].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[8][3].estado = 'O';
    avion->asientos[8][4].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[8][4].estado = 'O';
    avion->reservas[avion->contador_reservas] = reservaAux;
    avion->contador_reservas++;
    // Para asientos A-13
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Pepito Perez";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = false;
    reservaAux.numero_reserva = 110;
    reservaAux.numero_documento = 1007107207;
    avion->asientos[9][0].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[9][0].estado = 'O';
    avion->reservas[avion->contador_reservas] = reservaAux;
    avion->contador_reservas++;
    // Para asientos E-13 to F-13
    reservaAux.cantidad_pasajeros = 2;
    reservaAux.nombre_cliente = "Jimmy Neutron";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = true;
    reservaAux.numero_reserva = 111;
    reservaAux.numero_documento = 1008108208;
    avion->asientos[9][4].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[9][4].estado = 'O';
    avion->asientos[9][5].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[9][5].estado = 'O';
    avion->reservas[avion->contador_reservas] = reservaAux;
    avion->contador_reservas++;
    // Para asientos A-14
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Bart Simpson";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = false;
    reservaAux.numero_reserva = 112;
    reservaAux.numero_documento = 1009109209;
    avion->asientos[10][0].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[10][0].estado = 'O';
    avion->reservas[avion->contador_reservas] = reservaAux;
    avion->contador_reservas++;
    // Para asientos D-14 to F-14
    reservaAux.cantidad_pasajeros = 3;
    reservaAux.nombre_cliente = "Lisa Simpson";
    reservaAux.sexo_cliente = 'F';
    reservaAux.seguro_vuelo = false;
    reservaAux.numero_reserva = 113;
    reservaAux.numero_documento = 1010110210;
    avion->asientos[10][3].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[10][3].estado = 'O';
    avion->asientos[10][4].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[10][4].estado = 'O';
    avion->asientos[10][5].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[10][5].estado = 'O';
    avion->reservas[avion->contador_reservas] = reservaAux;
    avion->contador_reservas++;
    // Para asientos F-15
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Dylan Crawford";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = false;
    reservaAux.numero_reserva = 114;
    reservaAux.numero_documento = 1011111211;
    avion->asientos[11][5].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[11][5].estado = 'O';
    avion->reservas[avion->contador_reservas] = reservaAux;
    avion->contador_reservas++;
    // Para asientos E-16 to F-16
    reservaAux.cantidad_pasajeros = 2;
    reservaAux.nombre_cliente = "Finn the Human";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = true;
    reservaAux.numero_reserva = 115;
    reservaAux.numero_documento = 1012112212;
    avion->asientos[12][4].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[12][4].estado = 'O';
    avion->asientos[12][5].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[12][5].estado = 'O';
    avion->reservas[avion->contador_reservas] = reservaAux;
    avion->contador_reservas++;
    // Para asientos D-24
    reservaAux.cantidad_pasajeros = 1;
    reservaAux.nombre_cliente = "Jake the Dog";
    reservaAux.sexo_cliente = 'M';
    reservaAux.seguro_vuelo = false;
    reservaAux.numero_reserva = 116;
    reservaAux.numero_documento = 1013113213;
    avion->asientos[20][3].numero_reserva = reservaAux.numero_reserva;
    avion->asientos[20][3].estado = 'O';
    avion->reservas[avion->contador_reservas] = reservaAux;
    avion->contador_reservas++;
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
            avion->asientos[i][j].fila = i + 4;
            avion->asientos[i][j].numero_asiento = j;
            avion->asientos[i][j].estado = 'L';
            avion->asientos[i][j].categoria = definirCategoria(i + 4);
            avion->asientos[i][j].numero_reserva = 000;
        }
    }
    /* mostrarAvion(avion); */
    cout << "AVION CREADO SATISFACTORIAMENTE" << endl;
}

void imprimirAvion(Avion *avion)
{
    cout << setw(3) << "A" << setw(3) << "B" << setw(3) << "C" << setw(5) << "-" << setw(3) << "D" << setw(3) << "E" << setw(3) << "F" << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {

            cout << setw(3) << avion->asientos[i][j].estado;

            if (j == 2)
            {
                cout << setw(5) << avion->asientos[i][j].fila;
            }
        }
        cout << endl;
    }
}

void listarAvion(Avion *avion)
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
                 << setw(10) << avion->asientos[i][j].categoria << endl;
        }
    }
}

bool validarAsientos(Asiento asientoPrevio, Asiento asientoAux, Avion *avion)
{
    if (asientoPrevio.fila == asientoAux.fila)
    {
        if (asientoPrevio.numero_asiento + 1 == asientoAux.numero_asiento || asientoPrevio.numero_asiento - 1 == asientoAux.numero_asiento)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void listarDisponibles(Avion *avion, int cantidad)
{
    bool valido = true;
    
    cout << "Disponibles para " << cantidad << endl;
    for (int i = 0; i < filas; i++)
    {

        for (int j = 0; j < columnas; j++)
        {
            if (avion->asientos[i][j].estado == 'L')
            {
                valido=true;
                for (int k = j; k < cantidad; k++)
                {
                    if (avion->asientos[i][k].estado == 'O')
                    {
                        valido=false;
                        break;
                    }
                }
            }
        }
    }
}
void ingresarReserva(Avion *avion)
{
    Reserva reservaAux;
    Asiento asientoAux;
    int contadorAsignar = 0;
    Asiento asientoPrevio;
    int numero_reserva = avion->reservas[avion->contador_reservas].numero_reserva + 1;
    cout << "INGRESAR RESERVA " << numero_reserva << endl;
    cout << "Ingrese cantidad de pasajeros: " << endl;
    cin >> reservaAux.cantidad_pasajeros;
    if (reservaAux.cantidad_pasajeros <= 6)
    {
        cout << "Ingrese nombre cliente: " << endl;
        cin >> reservaAux.nombre_cliente;
        cout << "Ingrese numero de documento: " << endl;
        cin >> reservaAux.numero_documento;
        cout << "Ingrese sexo(M/F): " << endl;
        cin >> reservaAux.sexo_cliente;
        cout << "Tiene seguro de vuelo? (1/0): " << endl;
        cin >> reservaAux.seguro_vuelo;
        reservaAux.numero_reserva = numero_reserva;
        bool valido = false;
        do
        {
            cout << "Asientos disponibles: " << endl;
            imprimirAvion(avion);
            listarDisponibles(avion, reservaAux.cantidad_pasajeros);
            int aux = 0;
            char auxChar = 0;
            cout << "Seleccione fila de asiento(4-27): ";
            cin >> aux;
            asientoAux.fila = aux - 4;
            cout << "Seleccione columna de asiento(A-F): ";
            cin >> auxChar;
            asientoAux.numero_asiento = charToInt(auxChar);
            cout << "Asiento seleccionado: " << retornarLetra(asientoAux.numero_asiento) << asientoAux.fila << endl;
            avion->reservas[avion->contador_reservas] = reservaAux;
            avion->asientos[asientoAux.fila][asientoAux.numero_asiento].numero_reserva = numero_reserva;
            avion->asientos[asientoAux.fila][asientoAux.numero_asiento].estado = 'O';
            avion->asientos[asientoAux.fila][asientoAux.numero_asiento].numero_vuelo = avion->numero_vuelo;
            avion->asientos[asientoAux.fila][asientoAux.numero_asiento].numero_reserva = numero_reserva;
            if (reservaAux.cantidad_pasajeros > 1)
            {
                asientoPrevio = asientoAux;
            }
            if (contadorAsignar > 1)
            {
                valido = validarAsientos(asientoPrevio, asientoAux, avion);
            }
            contadorAsignar++;
        } while (contadorAsignar <= reservaAux.cantidad_pasajeros && valido == false);
        cout << "Rerserva creada satisfactoriamente" << endl;
    }
    else
    {
        cout << "La cantidad maxima de pasajeros es de 6" << endl;
        cout << "Ingrese una cantidad de pasajeros valida..." << endl;
    }
}

void finalizarReserva()
{
    cout << "Finalizar Reserva" << endl;
}

void consultarRegistros()
{
    cout << "Consultar registros por fila" << endl;
}