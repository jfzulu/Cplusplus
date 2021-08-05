#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
#define maxsem 15
#define maxestudiantes 100
//ESTRUCTURAS
struct Ubicacion
{
    string direccion;
    string ciudad;
};
struct Fecha
{
    int dia;
    int mes;
    int year;
};
struct Semestre
{
    char prueba;
    float promedio;
    int creditos;
};
struct Carpeta
{
    int n_semestres;
    Semestre semestres[maxsem];

};
struct Asignatura
{
    string nombre;
    float nota;
};
struct Estudiante
{
    int cedula;
    string nombre;
    int telefono;
    Ubicacion ubicacion;
    Asignatura perdidas[10]; //Asignaturas perdidas, maximo 10
    int n_perdidas; //Numero de asignaturas perdidas
    Fecha cumple; //Cumpleaños del estudiante
    char sexo;
    Carpeta carpeta;

};

void Ingreso_Datos(fstream &estudiante, int n_estudiantes);

int main ()
{
    int opc;
    int n_estudiantes=0;
    fstream estudiante;
    bool datos=false;
    do
    {
        cout << "===BIENVENIDO AL MANEJO DE ESTUDIANTES==="<<endl;
        cout << "\n\n                               +++OPCIONES+++\n\n"<<endl;
        cout << "0. INTRODUCIR DATOS DISPONIBLES"<<endl;
        cout << "   - Leer y almacenar datos de estudiantes en un archivo"<<endl;
        cout << "     En forma masiva, mas de uno a la vez\n"<<endl;
        cout << "     Si ya hay datos, sobreescribira el archivo"<<endl;
        cout << "1. LISTA DE TODOS LOS ESTUDIANTES DE SEXO MASCULINO"<<endl;
        cout << "2. LISTA DE TODOS LOS ESTUDIANTES DE SEXO FEMENINO"<<endl;
        cout << "3. NOMBRE DEL ESTUDIANTE QUE HA ESTADO MAS VECES EN PRUEBA ACADEMICA"<<endl;
        cout << "4. LISTA DE LAS ASIGNATURAS PERDIDAS POR ESTUDIANTES FEMENINOS QUE ALGUNA VEZ HAN ESTADO EN PRUEBA"<<endl;
        cout << "5. ACTUALIZAR UN ESTUDIANTE DADO POR CEDULA"<<endl;
        cout << "6. AGREGAR UN ESTUDIANTE"<<endl;
        cout << "7. REPORTE DE ESTUDIANTES A SER EXCLUIDOS"<<endl;
        cout << "8. REPORTE DE ESTUDIANTES POSIBLES CANDIDATOS A GRADO"<<endl;
        cout << "9. SALIR DEL PROGRAMA"<<endl;
        cout << "\n+++INGRESE UNA OPCION: ";
        cin >> opc;
        switch (opc)
        {
        case 0:
            estudiante.open("estudiante.dat",ios::binary|ios::out); // Abre de salida
            if (!estudiante)
            {
                cout <<"\nNo se pudo abrir de salida archivo."<<endl;
            }
            else
            {
                Ingreso_Datos(estudiante, n_estudiantes);
            }

            break;
        case 1:
            break;
        }


    }while (opc !=9);

}



//FUNCION INGRESAR DATOS POR PRIMERA VEZ
void Ingreso_Datos(fstream &estudiante, int n_estudiantes)
{
    Estudiante elemento;
    char respuesta;
    cout <<"\nIngrese los datos de su agenda:"<<endl;
    do
    {
        cout <<"\nNombre:"<<endl;
        cin >> elemento.nombre;
        cout <<"\nCalle:"<<endl;
        cin >> elemento.cedula;
        cout<<"\nTelefono:"<<endl;
        cin >> elemento.telefono;
        // Graba el registro en el archivo
        estudiante.write((char *)&elemento,sizeof(Estudiante));
        cout<<"\nDesea ingresar otro dato?(s/n):";
        cin >> respuesta;
    }
    while (respuesta == 's');
    estudiante.close();	// Archivo cerrado por cada función

}
