#include <fstream>
#include <string>
#include <iostream>
using namespace std;
struct User
{
    string nombre;
    string contrasena;
    string rol; // 1:Administrador, 2:Contador, 3:Basico
};
struct Service
{
    string nombre;
    string tipo;
    string id;
    float calificacion;
    int totalIngresos;
    float duracion;
};
struct Reporte
{
    string servicio;
    int totalIngresos;
};

int LeerUsuarios(User usuario, User usuarios[]);

void ImprimirUsuarios(User usuarios[], int numUsuarios);

int LeerServicios(Service servicios[]);

void ImprimirServicios(Service servicios[], int numServicios);

bool ValidarIngreso(User usuarios[], int numUsuarios, User &user);

int MostrarMenu(User user, User usuarios[], int &numUsuarios, Service servicios[], int &numServicios);

Service crearServicio();

bool ValidarNuevoServicio(Service servicios[], int numServicios, Service &servicio);

void ActualizarServicio(Service servicios[], int numServicios, Service &servicio);

void EliminarServicioID(Service servicios[], int &numServicios, string id);

void EliminarServicioNombre(Service servicios[], int &numServicios, string nombre);
void RegistrarPago(Service servicios[], int numServicios);

int BuscarPosicionById(Service servicios[], int numServicios, string id);

void ServicioMasUsado(Service servicios[], int numServicios);

void MostrarTiposServicios(Service servicios[], int numServicios);

void CerrarApp(Service servicios[], int &numServicios, User user);

void CrearUsuario(User usuarios[], int &numUsuarios);


int main()
{
    User user;
    User usuarios[100];
    Service servicios[100];
    int numUsuarios = 0;
    // Leer usuarios
    numUsuarios = LeerUsuarios(user, usuarios);
    ImprimirUsuarios(usuarios, numUsuarios);
    cout << numUsuarios << endl;
    //  Leer Servicios
    int numServicios = 0;
    // numServicios = LeerServicios(servicios);
    bool valido = false;
    while (!valido)
    {
        valido = ValidarIngreso(usuarios, numUsuarios, user);
    }
    if (valido)
    {
        int opc = 0;
        do
        {
            cout << "\n\n\nBienvenido " << user.nombre << "\n";
            opc = MostrarMenu(user, usuarios, numUsuarios, servicios, numServicios);
        } while (opc != -1);
        if (opc == -1)
        {
            cout << "Cerrando aplicacion...\n";
            cout << "Feliz dia :)\n";
        }
    }
}

int MostrarMenu(User user, User usuarios[], int &numUsuarios, Service servicios[], int &numServicios)
{
    int opc1, opc2 = 0;
    string opcS1 = " ", opcS2 = " ";

    cout << "Su rol es: " << user.rol << "\n";
    if (user.rol == "Administrador")
    {
        do
        {
            cout << "MENU ADMINISTRADOR\n";
            cout << "1. Cargar servicios de archivo\n";
            cout << "2. Agregar nuevo servicio\n";
            cout << "3. Eliminar servicio\n";
            cout << "4. Registrar pago de servicio\n";
            cout << "5. Calcular el servicio mas usado\n";
            cout << "6. Mostrar los tipos de servicios\n";
            cout << "7. Cerrar aplicacion(actualizar historial y servicios)\n";
            cout << "8. Crear nuevo usuario\n";
            cout << "Ingrese una opcion: ";
            cin >> opcS1;
            opc1 = atoi(opcS1.c_str());
            cout << opc1 << endl;
            switch (opc1)
            {
            case 1:
                numServicios = LeerServicios(servicios);
                // ImprimirServicios(servicios, numServicios);
                cout << "SERVICIOS CARGADOS CORRECTAMENTE...\n";
                break;
            case 2:
                if (numServicios == 0)
                {
                    cout << "ERROR: NO SE PUEDE AGREGAR UN NUEVO SERVICIO SI NO HAY SERVICIOS\n";
                    cout << "CARGUE LOS SERVICIOS DE ARCHIVO\n\n\n";
                    break;
                }
                else
                {
                    bool valido = false;
                    Service nuevoServicio;
                    do
                    {
                        nuevoServicio = crearServicio();
                        valido = ValidarNuevoServicio(servicios, numServicios, nuevoServicio);
                    } while (valido == false);
                    if (valido)
                    {
                        numServicios++;
                        ActualizarServicio(servicios, numServicios, nuevoServicio);
                        cout << "\nSERVICIO AGREGADO CORRECTAMENTE...\n";
                    }
                    else
                    {

                        cout << "ERROR AL AGREGAR SERVICIO...\n";
                    }
                }

                break;

            case 3:
                if (numServicios == 0)
                {
                    cout << "ERROR: NO SE PUEDE ELIMINAR UN SERVICIO SI NO HAY SERVICIOS\n";
                    cout << "CARGUE LOS SERVICIOS DE ARCHIVO\n\n\n";
                    break;
                }
                else
                {
                    cout << "ELIMINAR SERVICIO\n";
                    cout << "1. Buscar por ID\n";
                    cout << "2. Buscar por nombre\n";
                    cout << "Ingrese una opcion: ";
                    cin >> opcS2;
                    opc2 = atoi(opcS2.c_str());
                    string id;
                    string nombre;
                    switch (opc2)
                    {
                    case 1:
                        ImprimirServicios(servicios, numServicios);
                        cout << "INGRESE EL ID DEL SERVICIO A ELIMINAR: ";
                        cin >> id;
                        EliminarServicioID(servicios, numServicios, id);
                        break;
                    case 2:
                        ImprimirServicios(servicios, numServicios);
                        cout << "INGRESE EL NOMBRE DEL SERVICIO A ELIMINAR: ";
                        cin.ignore();
                        getline(cin, nombre);
                        EliminarServicioNombre(servicios, numServicios, nombre);
                        break;
                    default:
                        cout << "ERROR AL INTENTAR ELIMINAR SERVICIO...\n";
                        break;
                    }
                }
                break;

            case 4:
                if (numServicios == 0)
                {
                    cout << "ERROR: NO SE PUEDE REGISTRAR UN PAGO SI NO HAY SERVICIOS\n";
                    cout << "CARGUE LOS SERVICIOS DE ARCHIVO\n\n\n";
                    break;
                }
                else
                {
                    RegistrarPago(servicios, numServicios);
                }
                break;

            case 5:
                if (numServicios == 0)
                {
                    cout << "ERROR: NO SE PUEDE REGISTRAR UN PAGO SI NO HAY SERVICIOS\n";
                    cout << "CARGUE LOS SERVICIOS DE ARCHIVO\n\n\n";
                    break;
                }
                else
                {
                    ServicioMasUsado(servicios, numServicios);
                }
                break;

            case 6:
                if (numServicios == 0)
                {
                    cout << "ERROR: NO SE PUEDE REGISTRAR UN PAGO SI NO HAY SERVICIOS\n";
                    cout << "CARGUE LOS SERVICIOS DE ARCHIVO\n\n\n";
                    break;
                }
                else
                {
                    MostrarTiposServicios(servicios, numServicios);
                }

                break;
            case 7:
                cout << "CERRANDO...\n";
                CerrarApp(servicios, numServicios, user);
                return -1;
                break;
            case 8:
                CrearUsuario(usuarios, numUsuarios);
                break;

            default:
                cout << "ERROR...\n";
                break;
            }
            if (opc1 < 1 || opc1 > 8)
            {
                cout << "OPCION INVALIDA\n";
                cout << "INGRESE OPCION VALIDA\n";
                /* code */
            }

        } while (opc1 != 7 || opc1 < 1 || opc1 > 8);

    }
    else if (user.rol == "Contador")
    {
        do
        {
            cout << "MENU CONTADOR\n";
            cout << "1. Cargar servicios de archivo\n";
            cout << "2. Calcular el servicio mas usado\n";
            cout << "3. Mostrar los tipos de servicios\n";
            cout << "4. Cerrar aplicacion(actualizar historial y servicios)\n";
            cout << "Ingrese una opcion: ";
            cin >> opcS1;
            opc1 = atoi(opcS1.c_str());
            switch (opc1)
            {
            case 1:
                numServicios = LeerServicios(servicios);
                // ImprimirServicios(servicios, numServicios);
                cout << "SERVICIOS CARGADOS CORRECTAMENTE...\n";
                break;
            case 2:
                if (numServicios == 0)
                {
                    cout << "ERROR: NO SE PUEDE REGISTRAR UN PAGO SI NO HAY SERVICIOS\n";
                    cout << "CARGUE LOS SERVICIOS DE ARCHIVO\n\n\n";
                    break;
                }
                else
                {
                    ServicioMasUsado(servicios, numServicios);
                }
                break;
            case 3:
                if (numServicios == 0)
                {
                    cout << "ERROR: NO SE PUEDE REGISTRAR UN PAGO SI NO HAY SERVICIOS\n";
                    cout << "CARGUE LOS SERVICIOS DE ARCHIVO\n\n\n";
                    break;
                }
                else
                {
                    MostrarTiposServicios(servicios, numServicios);
                }
                break;
            case 4:
                cout << "CERRANDO...\n";
                CerrarApp(servicios, numServicios, user);
                return -1;
                break;

            default:
                cout << "OPCION INVALIDA\n";
                break;
            }
            if (opc1 < 1 || opc1 > 4)
            {
                cout << "OPCION INVALIDA\n";
                cout << "INGRESE OPCION VALIDA\n";
                opc1 = 1;
                /* code */
            }
        } while (opc1 != 4 || opc1 < 1 || opc1 > 4);
    }

    else if (user.rol == "Basico")
    {
        do
        {
            cout << "MENU CONTADOR\n";
            cout << "1. Cargar servicios de archivo\n";
            cout << "2. Registrar pago de servicio\n";
            cout << "3. Cerrar aplicacion(actualizar historial y servicios)\n";
            cout << "Ingrese una opcion: ";
            cin >> opcS1;
            opc1 = atoi(opcS1.c_str());
            switch (opc1)
            {
            case 1 /* constant-expression */:
                numServicios = LeerServicios(servicios);
                // ImprimirServicios(servicios, numServicios);
                cout << "SERVICIOS CARGADOS CORRECTAMENTE...\n";
                break;
            case 2:
                if (numServicios == 0)
                {
                    cout << "ERROR: NO SE PUEDE REGISTRAR UN PAGO SI NO HAY SERVICIOS\n";
                    cout << "CARGUE LOS SERVICIOS DE ARCHIVO\n\n\n";
                    break;
                }
                else
                {
                    RegistrarPago(servicios, numServicios);
                }
                break;
            case 3:
                cout << "CERRANDO...\n";
                CerrarApp(servicios, numServicios, user);
                return -1;
                break;

            default:
                cout << "OPCION INVALIDA\n";
                break;
            }
            if (opc1 < 1 || opc1 > 3)
            {
                cout << "OPCION INVALIDA\n";
                cout << "INGRESE OPCION VALIDA\n";
                opc1 = 1;
                /* code */
            }
        } while (opc1 != 3 || opc1 < 1 || opc1 > 4);
    }

    return opc1;
}
void CrearUsuario(User usuarios[], int &numUsuarios)
{
    cout << "CREACION DE NUEO USUARIO\n";
    User nuevoUser;
    cout << "INGRESE EL NOMBRE: ";
    cin >> nuevoUser.nombre;
    cout << "INGRESE EL ROL: ";
    cin >> nuevoUser.rol;
    cout << "INGRESE LA CONTRASENIA: ";
    cin >> nuevoUser.contrasena;
    usuarios[numUsuarios] = nuevoUser;
    numUsuarios++;

    // AGREGAR USUARIO AL ARCHIVO
    ofstream archivo;
    archivo.open("Empleados.txt", ios::app);
    archivo << endl << "#" << endl;
    archivo << nuevoUser.nombre << endl;
    archivo << nuevoUser.contrasena << endl;
    archivo << nuevoUser.rol;
    cout << "USUARIO CREADO CON EXITO\n";
    archivo.close();
}

void CerrarApp(Service servicios[], int &numServicios, User user)
{
    // ACTUALIZAR ARCHIVOS:
    ofstream archivo;
    archivo.open("Servicios.txt");
    for (int i = 0; i < numServicios; ++i)
    {
        archivo << servicios[i].nombre << endl;
        archivo << servicios[i].tipo << endl;
        archivo << servicios[i].id << endl;
        archivo << servicios[i].calificacion << endl;
        archivo << servicios[i].totalIngresos << endl;
        archivo << servicios[i].duracion << endl;
        archivo << "#" << endl;
    }
    archivo << "FIN" << endl;
    archivo.close();

    // ACTUALIZAR HISTORIAL
    ofstream historial;
    historial.open("Historial.txt", ios::app);
    historial << user.nombre << "--" << user.rol << endl;
    historial.close();
}
void MostrarTiposServicios(Service servicios[], int numServicios)
{
    int n = 3;
    Reporte tiposServicios[n];
    tiposServicios[0].servicio = "Caminata";
    tiposServicios[1].servicio = "Spa";
    tiposServicios[2].servicio = "Salon de juegos";
    tiposServicios[0].totalIngresos = 0;
    tiposServicios[1].totalIngresos = 0;
    tiposServicios[2].totalIngresos = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < numServicios; ++j)
        {
            if (servicios[j].tipo == tiposServicios[i].servicio)
            {
                tiposServicios[i].totalIngresos += servicios[j].totalIngresos;
            }
        }
    }

    // ORDENARLOS DE MAYOR A MENOR:
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (tiposServicios[j].totalIngresos < tiposServicios[j + 1].totalIngresos)
            {
                // Intercambiar arr[j] y arr[j + 1]
                Reporte temp = tiposServicios[j];
                tiposServicios[j] = tiposServicios[j + 1];
                tiposServicios[j + 1] = temp;
            }
        }
    }

    // IMPRIMIR TIPOS SERVICIOS YA ORDENADOS
    for (int i = 0; i < n; ++i)
    {
        cout << tiposServicios[i].servicio << ": " << tiposServicios[i].totalIngresos << "\n";
    }

    // ACTUALIZAR ARCHIVO REPORTES.TXT
    ofstream archivo("Reporte.txt");
    for (int i = 0; i < n; ++i)
    {
        archivo << tiposServicios[i].servicio << " $" << tiposServicios[i].totalIngresos << endl;
    }

    archivo.close();
}

void ServicioMasUsado(Service servicios[], int numServicios)
{
    int topServicio = 0;
    int ingresos;
    float duracion;
    float calificacion;
    cout << "SERVICIO MAS USADO\n";
    cout << "1. Por Ingresos\n";
    cout << "2. Por Calificacion\n";
    cout << "3. Por Duracion\n";
    cout << "Ingrese una opcion: ";
    int opc;
    cin >> opc;
    switch (opc)
    {
    case 1:
        ingresos = 0;
        for (int i = 0; i < numServicios; ++i)
        {
            if (servicios[i].totalIngresos > ingresos)
            {
                ingresos = servicios[i].totalIngresos;
                topServicio = i;
            }
        }
        break;
    case 2:
        calificacion = 0;
        for (int i = 0; i < numServicios; ++i)
        {
            if (servicios[i].calificacion > calificacion)
            {
                calificacion = servicios[i].calificacion;
                topServicio = i;
            }
        }
        break;
    case 3:
        duracion = 0;
        for (int i = 0; i < numServicios; ++i)
        {
            if (servicios[i].duracion > duracion)
            {
                duracion = servicios[i].duracion;
                topServicio = i;
            }
        }
        break;
    default:
        cout << "OPCION INVALIDA\n";
        break;
    }

    cout << "EL SERVICIO MAS USADO ES: SERVICIO " << topServicio << "\n";
    cout << "   - Nombre: " << servicios[topServicio].nombre << "\n";
    cout << "   - Tipo: " << servicios[topServicio].tipo << "\n";
    cout << "   - ID: " << servicios[topServicio].id << "\n";
    cout << "   - Calificacion: " << servicios[topServicio].calificacion << "\n";
    cout << "   - Total Ingresos: " << servicios[topServicio].totalIngresos << "\n";
    cout << "   - Duracion: " << servicios[topServicio].duracion << "\n";
}

int BuscarPosicionById(Service servicios[], int numServicios, string id)
{
    for (int i = 0; i < numServicios; ++i)
    {
        if (servicios[i].id == id)
        {
            return i;
        }
    }
    return -1;
}
void RegistrarPago(Service servicios[], int numServicios)
{
    ImprimirServicios(servicios, numServicios);
    string id;
    cout << "INGRESE EL ID DEL SERVICIO DEL PAGO: ";
    cin >> id;
    int position = BuscarPosicionById(servicios, numServicios, id);
    if (position == -1)
    {
        cout << "ERROR AL REGISTRAR PAGO...\n";
    }
    else
    {
        cout << "REGISTRAR PAGO\n";
        string tipo = servicios[position].tipo;
        int personasServicio;
        float calificacion;
        float calificacionPromedio;
        float duracionServicio;
        cout << "INGRESE NUMERO DE PERSONAS DEL SERVICIO: ";
        cin >> personasServicio;
        int edadesClientes[personasServicio];
        cout << "INGRESE CALIFICACION DEL SERVICIO: ";
        cin >> calificacion;
        for (int i = 0; i < personasServicio; ++i)
        {
            cout << "-CLIENTE " << i + 1 << "\n";
            cout << "   EDAD: ";
            cin >> edadesClientes[i];
            cout << "\n";
        }
        // cout << "CALIFICACION PROMEDIO: " << calificacionPromedio << "\n";
        float totalIngreso = 0;
        if (tipo == "Caminata")
        {
            duracionServicio = 160 / 60;
            for (int i = 0; i < personasServicio; ++i)
            {
                totalIngreso += 100000;
            }
        }
        if (tipo == "Spa")
        {
            duracionServicio = 100 / 60;
            for (int i = 0; i < personasServicio; ++i)
            {
                if (edadesClientes[i] < 18)
                {
                    totalIngreso += 50000;
                }
                else
                {
                    totalIngreso += 80000;
                }
            }
        }
        if (tipo == "Salon de juegos")
        {
            duracionServicio = 120 / 60;
            int diff = personasServicio - 5;
            if (diff > 0)
            {
                totalIngreso += 70000;
                totalIngreso += diff * 18000;
            }
            else
            {
                totalIngreso += 18000 * personasServicio;
            }
        }

        // Actualizar archivo Servicios.txt
        servicios[position].calificacion = (servicios[position].calificacion + calificacion) / 2;
        servicios[position].totalIngresos += totalIngreso;
        servicios[position].duracion += duracionServicio;

        ofstream archivo("Servicios.txt");
        for (int i = 0; i < numServicios; ++i)
        {
            archivo << servicios[i].nombre << endl;
            archivo << servicios[i].tipo << endl;
            archivo << servicios[i].id << endl;
            archivo << servicios[i].calificacion << endl;
            archivo << servicios[i].totalIngresos << endl;
            archivo << servicios[i].duracion << endl;
            archivo << "#" << endl;
        }
        archivo.close();

        cout << "PAGO REGISTRADO...\n";
    }
}
void EliminarServicioID(Service servicios[], int &numServicios, string id)
{
    // Validar que exista, y guardar su posicion
    bool existe = false;
    int position = -1;
    for (int i = 0; i < numServicios; ++i)
    {
        if (servicios[i].id == id)
        {
            existe = true;
            position = i;
            break;
        }
    }

    // Borrar el servicio del arreglo y actualizar archivo
    if (existe)
    {
        for (int i = position; i < numServicios - 1; ++i)
        {
            servicios[i] = servicios[i + 1];
        }
        numServicios--;
        ofstream archivo("Servicios.txt");
        for (int i = 0; i < numServicios; ++i)
        {
            archivo << servicios[i].nombre << endl;
            archivo << servicios[i].tipo << endl;
            archivo << servicios[i].id << endl;
            archivo << servicios[i].calificacion << endl;
            archivo << servicios[i].totalIngresos << endl;
            archivo << servicios[i].duracion << endl;
            archivo << "#" << endl;
        }
    }
    else
    {
        cout << "ERROR: SERVICIO NO ENCONTRADO/NO EXISTENTE\n";
    }
}
void EliminarServicioNombre(Service servicios[], int &numServicios, string nombre)
{
    // Validar que exista, y guardar su posicion
    bool existe = false;
    int position = -1;
    for (int i = 0; i < numServicios; ++i)
    {
        if (servicios[i].nombre == nombre)
        {
            existe = true;
            position = i;
            break;
        }
    }

    // Borrar el servicio del arreglo y actualizar archivo
    if (existe)
    {
        for (int i = position; i < numServicios - 1; ++i)
        {
            servicios[i] = servicios[i + 1];
        }
        numServicios--;
        ofstream archivo("Servicios.txt");
        for (int i = 0; i < numServicios; ++i)
        {
            archivo << servicios[i].nombre << endl;
            archivo << servicios[i].tipo << endl;
            archivo << servicios[i].id << endl;
            archivo << servicios[i].calificacion << endl;
            archivo << servicios[i].totalIngresos << endl;
            archivo << servicios[i].duracion << endl;
            archivo << "#" << endl;
        }
    }
    else
    {
        cout << "ERROR: SERVICIO NO ENCONTRADO/NO EXISTENTE\n";
    }
}

bool ValidarNuevoServicio(Service servicios[], int numServicios, Service &servicio)
{
    bool valido = true;
    for (int i = 0; i < numServicios; ++i)
    {
        if (servicio.id == servicios[i].id)
        {
            valido = false;
        }
        if (servicio.nombre == servicios[i].nombre)
        {
            valido = false;
        }
    }
    return valido;
}
void ActualizarServicio(Service servicios[], int numServicios, Service &servicio)
{
    servicios[numServicios - 1] = servicio;
    ofstream archivo("Servicios.txt");
    for (int i = 0; i < numServicios; ++i)
    {
        archivo << servicios[i].nombre << endl;
        archivo << servicios[i].tipo << endl;
        archivo << servicios[i].id << endl;
        archivo << servicios[i].calificacion << endl;
        archivo << servicios[i].totalIngresos << endl;
        archivo << servicios[i].duracion << endl;
        archivo << "#" << endl;
    }
    archivo << "FIN" << endl;
    archivo.close();
}
bool ValidarIngreso(User usuarios[], int numUsuarios, User &user)
{
    bool valido = false;
    cout << "VALIDACION DE INGRESO\n";
    cout << "Usuario: ";
    cin >> user.nombre;
    cout << "Password: ";
    cin >> user.contrasena;
    for (int i = 0; i < numUsuarios; ++i)
    {
        if (user.nombre == usuarios[i].nombre && user.contrasena == usuarios[i].contrasena)
        {
            user.rol = usuarios[i].rol;
            valido = true;
        }
    }
    if (valido)
    {
        cout << "Ingreso exitoso\n";
    }
    else
    {
        cout << "Ingreso fallido\n";
        cout << "Intente de nuevo...\n";
    }
    return valido;
}

int LeerServicios(Service servicios[])
{

    ifstream archivo("Servicios.txt");
    string linea;
    int contador = 0;
    int numServicios = 0;

    while (getline(archivo, linea))
    {
        if (linea == "#")
        {
            numServicios++;
            contador = 0; // Resetear el contador para el último servicio
        }
        else
        {
            switch (contador)
            {
            case 0:
                servicios[numServicios].nombre = linea;
                break;
            case 1:
                servicios[numServicios].tipo = linea;
                break;
            case 2:
                servicios[numServicios].id = linea;
                break;
            case 3:
                servicios[numServicios].calificacion = stof(linea);
                break;
            case 4:
                servicios[numServicios].totalIngresos = stod(linea);
                break;
            case 5:
                servicios[numServicios].duracion = stoi(linea);
                break;
            }
            contador++;
        }
    }

    return numServicios;
}

void ImprimirServicios(Service servicios[], int numServicios)
{
    for (int i = 0; i < numServicios; ++i)
    {
        cout << "Servicio " << i + 1 << ":\n";
        cout << "  Nombre: " << servicios[i].nombre << "\n";
        cout << "  Tipo: " << servicios[i].tipo << "\n";
        cout << "  ID: " << servicios[i].id << "\n";
        cout << "  Calificacion: " << servicios[i].calificacion << "\n";
        cout << "  Total Ingresos: " << servicios[i].totalIngresos << "\n";
        cout << "  Duracion: " << servicios[i].duracion << "\n";
    }
}
void ImprimirUsuarios(User usuarios[], int numUsuarios)
{
    for (int i = 0; i < numUsuarios; ++i)
    {
        cout << "Usuario " << i + 1 << ":\n";
        cout << "  Nombre: " << usuarios[i].nombre << "\n";
        cout << "  Pass: " << usuarios[i].contrasena << "\n";
        cout << "  Rol: " << usuarios[i].rol << "\n";
    }
}
int LeerUsuarios(User usuario, User usuarios[])
{

    fstream archivo("Empleados.txt", std::ios::in);
    string linea;
    int contador = 0;
    int numUsuarios = 1;

    while (getline(archivo, linea))
    {
        if (linea == "")
        {
            cin.ignore();
        }
        if (linea == "#")
        {
            numUsuarios++;
            contador = 0; // Resetear el contador para el próximo usuario
        }
        else
        {
            switch (contador)
            {
            case 0:
                usuarios[numUsuarios - 1].nombre = linea;
                break;
            case 1:
                usuarios[numUsuarios - 1].contrasena = linea;
                break;
            case 2:
                usuarios[numUsuarios - 1].rol = linea;
                break;
            }
            contador++;
        }
    }
    archivo.close();
    // numUsuarios++;
    return numUsuarios;
}

Service crearServicio()
{
    Service servicio;
    cin.ignore();
    cout << "\n\nNombre: ";
    std::getline(std::cin, servicio.nombre);
    cout << "Tipo: ";
    std::getline(std::cin, servicio.tipo);
    cout << "ID: ";
    std::getline(std::cin, servicio.id);
    cout << "Calificacion: ";
    cin >> servicio.calificacion;
    cout << "Total Ingresos: ";
    cin >> servicio.totalIngresos;
    cout << "Duracion: ";
    cin >> servicio.duracion;

    return servicio;
}