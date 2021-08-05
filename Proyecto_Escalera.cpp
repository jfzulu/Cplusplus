#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#include <string>
using namespace std;
const int TJ = 4;

const int TT = 8;

const int TL = 21;
struct player
{
    string nombre;
    char genero;
    int edad;
    int posicion;
    string color;
};
struct box
{
    int posicion;
    string tipo;
    int p_final;
};
struct tab
{
    int numero;
    int posicion;
    string tipo;
    int p_final;
    string ficha;
};
struct jugada
{
    string color;
    int valor;

};
//FUNCION A
void P_player(player jugadores[TJ])
{
    player temporal;
    for (int i = 0; i < TJ; i++)
    {
        for (int j = 0; j< TJ-1; j++)
        {
            if (jugadores[j].edad > jugadores[j+1].edad)  // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
            {
                temporal = jugadores[j];
                jugadores[j] = jugadores[j+1];
                jugadores[j+1] = temporal;
            }
        }
    }

    for(int i=0; i<TJ; i++)
    {
        cout << "\nJugador "<<i+1<<endl;
        cout << "Nombre: "<<setw(15)<<jugadores[i].nombre<<endl;
        if(jugadores[i].genero=='M')
        {
            cout <<"Genero: "<<setw(15)<< "Masculino"<<endl;
        }
        if(jugadores[i].genero=='F')
        {
            cout <<"Genero: "<<setw(15)<< "Femenino"<<endl;
        }
        cout << "Edad: "<<setw(15)<< jugadores[i].edad<<endl;
        cout << "Color: "<<setw(15)<<jugadores[i].color<<endl;
        cout << "Posicion: "<<setw(11)<<jugadores[i].posicion<<endl;
    }
    system("pause");
}

//FUNCION B
void C_posicion(player jugadores[TJ])
{
    string name;
    int pos=0;
    cout << "Ingrese el nombre del jugador que desea consultar la posicion: ";
    cin >> name;
    for(int i=0; i< TJ; i++)
    {
        if(jugadores[i].nombre==name)
        {
            pos=i;
        }
    }
    cout << "La posicion de "<<jugadores[pos].nombre<< " es: "<<jugadores[pos].posicion<<endl;

    system("pause");

}
//FUNCION C
void P_tablero(tab tablero[TT][TT])
{
    for(int i=0; i<130; i++)
    {
        cout << "*";
    }
    cout << endl;
    int grupo=0;
    for(int i=0; i<TT; i++)
    {
        cout <<"|"<<
             setw(2)<<tablero[grupo][i].numero;
        if(tablero[grupo][i].tipo=="Escalera")
        {
            cout<<right<<setw(2)<<" E ";
        }
        if(tablero[grupo][i].tipo=="Rodadero")
        {
            cout<<left<<setw(2)<<" R ";
        }
        if(tablero[grupo][i].tipo!="Rodadero" && tablero[grupo][i].tipo!="Escalera")
        {
            cout <<right<< setw(2)<<"   ";
        }
        cout <<left<<setw(3)<< tablero[grupo][i].p_final<<" ";
        cout <<right<< setw(6)<<tablero[grupo][i].ficha;
    }
    cout <<"\n"<< setw( 130 ) << setfill( '-' ) << '\n' << setfill( ' ' );
    grupo++;
    for(int i=TT-1; i>=0; i--)
    {
        cout <<"|"<<
             setw(2)<<tablero[grupo][i].numero;
        if(tablero[grupo][i].tipo=="Escalera")
        {
            cout<<right<<setw(2)<<" E ";
        }
        if(tablero[grupo][i].tipo=="Rodadero")
        {
            cout<<left<<setw(2)<<" R ";
        }
        if(tablero[grupo][i].tipo!="Rodadero" && tablero[grupo][i].tipo!="Escalera")
        {
            cout <<right<< setw(2)<<"   ";
        }
        cout <<left<<setw(3)<< tablero[grupo][i].p_final<<" ";
        cout <<right<< setw(6)<<tablero[grupo][i].ficha;
    }
    cout <<"\n"<< setw( 130 ) << setfill( '-' ) << '\n' << setfill( ' ' );
    grupo++;
    for(int i=0; i<TT; i++)
    {
        cout <<"|"<<
             setw(2)<<tablero[grupo][i].numero;
        if(tablero[grupo][i].tipo=="Escalera")
        {
            cout<<right<<setw(2)<<" E ";
        }
        if(tablero[grupo][i].tipo=="Rodadero")
        {
            cout<<left<<setw(2)<<" R ";
        }
        if(tablero[grupo][i].tipo!="Rodadero" && tablero[grupo][i].tipo!="Escalera")
        {
            cout <<right<< setw(2)<<"   ";
        }
        cout <<left<<setw(3)<< tablero[grupo][i].p_final<<" ";
        cout <<right<< setw(6)<<tablero[grupo][i].ficha;
    }
    cout <<"\n"<< setw( 130 ) << setfill( '-' ) << '\n' << setfill( ' ' );
    grupo++;
    for(int i=TT-1; i>=0; i--)
    {
        cout <<"|"<<
             setw(2)<<tablero[grupo][i].numero;
        if(tablero[grupo][i].tipo=="Escalera")
        {
            cout<<right<<setw(2)<<" E ";
        }
        if(tablero[grupo][i].tipo=="Rodadero")
        {
            cout<<left<<setw(2)<<" R ";
        }
        if(tablero[grupo][i].tipo!="Rodadero" && tablero[grupo][i].tipo!="Escalera")
        {
            cout <<right<< setw(2)<<"   ";
        }
        cout <<left<<setw(3)<< tablero[grupo][i].p_final<<" ";
        cout <<right<< setw(6)<<tablero[grupo][i].ficha;
    }
    cout <<"\n"<< setw( 130 ) << setfill( '-' ) << '\n' << setfill( ' ' );
    grupo++;
    for(int i=0; i<TT; i++)
    {
        cout <<"|"<<
             setw(2)<<tablero[grupo][i].numero;
        if(tablero[grupo][i].tipo=="Escalera")
        {
            cout<<right<<setw(2)<<" E ";
        }
        if(tablero[grupo][i].tipo=="Rodadero")
        {
            cout<<left<<setw(2)<<" R ";
        }
        if(tablero[grupo][i].tipo!="Rodadero" && tablero[grupo][i].tipo!="Escalera")
        {
            cout <<right<< setw(2)<<"   ";
        }
        cout <<left<<setw(3)<< tablero[grupo][i].p_final<<" ";
        cout <<right<< setw(6)<<tablero[grupo][i].ficha;
    }
    cout <<"\n"<< setw( 130 ) << setfill( '-' ) << '\n' << setfill( ' ' );
    grupo++;
    for(int i=TT-1; i>=0; i--)
    {
        cout <<"|"<<
             setw(2)<<tablero[grupo][i].numero;
        if(tablero[grupo][i].tipo=="Escalera")
        {
            cout<<right<<setw(2)<<" E ";
        }
        if(tablero[grupo][i].tipo=="Rodadero")
        {
            cout<<left<<setw(2)<<" R ";
        }
        if(tablero[grupo][i].tipo!="Rodadero" && tablero[grupo][i].tipo!="Escalera")
        {
            cout <<right<< setw(2)<<"   ";
        }
        cout <<left<<setw(3)<< tablero[grupo][i].p_final<<" ";
        cout <<right<< setw(6)<<tablero[grupo][i].ficha;
    }
    cout <<"\n"<< setw( 130 ) << setfill( '-' ) << '\n' << setfill( ' ' );
    grupo++;
    for(int i=0; i<TT; i++)
    {
        cout <<"|"<<
             setw(2)<<tablero[grupo][i].numero;
        if(tablero[grupo][i].tipo=="Escalera")
        {
            cout<<right<<setw(2)<<" E ";
        }
        if(tablero[grupo][i].tipo=="Rodadero")
        {
            cout<<left<<setw(2)<<" R ";
        }
        if(tablero[grupo][i].tipo!="Rodadero" && tablero[grupo][i].tipo!="Escalera")
        {
            cout <<right<< setw(2)<<"   ";
        }
        cout <<left<<setw(3)<< tablero[grupo][i].p_final<<" ";
        cout <<right<< setw(6)<<tablero[grupo][i].ficha;
    }
    cout <<"\n"<< setw( 130 ) << setfill( '-' ) << '\n' << setfill( ' ' );
    grupo++;
    for(int i=TT-1; i>=0; i--)
    {
        cout <<"|"<<
             setw(2)<<tablero[grupo][i].numero;
        if(tablero[grupo][i].tipo=="Escalera")
        {
            cout<<right<<setw(2)<<" E ";
        }
        if(tablero[grupo][i].tipo=="Rodadero")
        {
            cout<<left<<setw(2)<<" R ";
        }
        if(tablero[grupo][i].tipo!="Rodadero" && tablero[grupo][i].tipo!="Escalera")
        {
            cout <<right<< setw(2)<<"   ";
        }
        cout <<left<<setw(3)<< tablero[grupo][i].p_final<<" ";
        cout <<right<< setw(6)<<tablero[grupo][i].ficha;
    }
    grupo++;
    cout << endl;
    for(int i=0; i<130; i++)
    {
        cout << "*";
    }
    cout << endl;
    system("pause");
}
//FUNCION D
void Simular_jugada(tab tablero[TT][TT], player jugadores[TJ], jugada jugadas[TL])
{
    int n;
    cout << "Ingrese el numero de jugadas que desea simular: ";
    cin >> n;
    int cont=0;
    for (int i=0 ; i<n; i++)
    {
        for(int j=0; j<TJ; j++)
        {
            if(jugadas[i].color==jugadores[j].color)
            {
                jugadores[j].posicion=jugadores[j].posicion+jugadas[i].valor;
                for(int a=0; a<TT; a++)
                {
                    for(int b=0; b<TT; b++)
                    {
                        if(tablero[a][b].numero==jugadores[j].posicion)
                        {
                            if(tablero[a][b].tipo=="Escalera" || tablero[a][b].tipo=="Rodadero")
                            {
                                jugadores[j].posicion=tablero[a][b].p_final;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i=0; i<TJ; i++)
    {
        for(int j=0; j<TT; j++)
        {
            for(int k=0; k<TT; k++)
            {
                if(jugadores[i].posicion==tablero[j][k].numero)
                {
                    string aux= jugadores[i].color.substr(0,1);
                    tablero[j][k].ficha.append(aux);
                }

            }
        }
    }
    P_tablero(tablero);


    system("pause");
}
//FUNCION E
void Clasificacion( player jugadores[TJ])
{
    player temporal;
    for (int i = 0; i < TJ; i++)
    {
        for (int j = 0; j< TJ-1; j++)
        {
            if (jugadores[j].posicion < jugadores[j+1].posicion)  // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
            {
                temporal = jugadores[j];
                jugadores[j] = jugadores[j+1];
                jugadores[j+1] = temporal;
            }
        }
    }
    for(int i=0; i<TJ; i++)
    {
        cout << "\nJugador "<<i+1<<endl;
        cout << "Nombre: "<<setw(15)<<jugadores[i].nombre<<endl;
        if(jugadores[i].genero=='M')
        {
            cout <<"Genero: "<<setw(15)<< "Masculino"<<endl;
        }
        if(jugadores[i].genero=='F')
        {
            cout <<"Genero: "<<setw(15)<< "Femenino"<<endl;
        }
        cout << "Edad: "<<setw(15)<< jugadores[i].edad<<endl;
        cout << "Color: "<<setw(15)<<jugadores[i].color<<endl;
        cout << "Posicion: "<<setw(11)<<jugadores[i].posicion<<endl;
    }
    system("pause");



}
int main()
{
    const int TP = 17;
    cout << ">>>>>BIENVENIDO AL JUEGO ESCALERA<<<<<"<<endl;

    //INICIALIZACION DE VALORES TABLERO, JUGADORES, JUGADAS
    player jugadores[TJ] = { {"Hugo",'M',8,0,"Blanco"},{"Daisy",'F',7,0,"Rojo"},{"Paco",'M',8,0,"Verde"},{"Minie",'F',6,0,"Azul"}};

    box TableroPosiciones[TP]= { {4,"Escalera",20}, {5,"Escalera",10}, {7,"Escalera",23}, {22,"Escalera",39}, {18,"Escalera",35},
        {5,"Escalera",10}, {27,"Escalera",37}, {41,"Escalera",58}, {42,"Escalera",53}, {49,"Escalera",62}, {34,"Rodadero",2}, {38,"Rodadero",3},
        {43,"Rodadero",23}, {46,"Rodadero",33}, {57,"Rodadero",44},  {43,"Rodadero",23}, {59,"Rodadero",46}
    };
    tab tablero[TT][TT];
    //INICIALIZACION TABLERO
    int cont=1;
    int cont2=0;
    for (int i=0 ; i<TT; i++ )
    {
        for (int j=0; j<TT; j++)
        {
            tablero[i][j].numero=cont;
            tablero[i][j].posicion=0;
            tablero[i][j].p_final=0;
            tablero[i][j].ficha[0]=' ';
            cont++;
        }
    }
    int aux=0;
    for (int i=0 ; i<TP; i++ )
    {
        for(int j=0; j<TT; j++)
        {
            for(int k=0; k<TT; k++)
            {
                if(tablero[j][k].numero==TableroPosiciones[i].posicion)
                {
                    tablero[j][k].posicion=TableroPosiciones[i].posicion;
                    tablero[j][k].p_final= TableroPosiciones[i].p_final;
                    tablero[j][k].tipo= TableroPosiciones[i].tipo;
                }
            }
        }
    }



    jugada jugadas[TL] = { {"Blanco",3},{"Azul",5},{"Verde",3},{"Rojo",3},{"Blanco",3},{"Azul",4},{"Verde",1},
        {"Rojo",4},{"Blanco",3},{"Azul",1},{"Verde",5},{"Rojo",3},{"Blanco",4},{"Azul",4},{"Verde",1},{"Rojo",2},{"Blanco",4},
        {"Azul",4},{"Verde",6},{"Rojo",6}
    };
    int opc;
    do
    {
        cout << "Escoga una opcion"<<endl;
        cout << "1. Presentar jugadores, ordenados por edad"<<endl;
        cout << "2. Consultar posicion de un jugador, dado su nombre"<<endl;
        cout << "3. Presentar tablero"<<endl;
        cout << "4. Simular n jugadas, dado por el usuario"<<endl;
        cout << "5. Tabla de clasificacion, ordenados por posicion"<<endl;
        cout << "6. Salir"<<endl;
        cin >> opc;
        switch(opc)
        {
        case 1:
            system("cls");
            P_player(jugadores);
            system("cls");
            break;
        case 2:
            system("cls");
            C_posicion(jugadores);
            system("cls");
            break;
        case 3:
            system("cls");
            P_tablero(tablero);
            system("cls");
            break;
        case 4:
            system("cls");
            Simular_jugada(tablero, jugadores, jugadas);
            system("cls");
            break;
        case 5:
            system("cls");
            Clasificacion(jugadores);
            system("cls");
            break;

        }
        if(opc>6 || opc<1)
        {
            cout << "Ingrese una opcion valida"<<endl;
            system("pause");
            system("cls");
        }
    }
    while(opc<6 && opc>0 || opc!=6);
    if(opc==6)
    {
        cout << ">>GRACIAS POR JUGAR<<"<<endl;
        system("pause");
    }

}
