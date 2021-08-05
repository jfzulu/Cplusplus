#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include<time.h>
#define maxfilas 30
#define maxcol 30
using namespace std;


//ESTRUCTURAS



struct Casilla
{
    int col; //Columna
    int fil; //Fila
    char estado; //Se manejaran diferentes estados en cada casilla: libre(L), ocupada (O), atacada (T),  barco afectado(X)
};
struct Barco
{
    Casilla Inicial; //Posicion del barco
    int tam; //Tamaño de casillas que ocupa el barco
    Casilla Final;

};
struct Player
{
    int tipo; //Puede ser persona(0) o computadora(1)
    string nombre; //IA para la computadora
    Casilla tablero[maxfilas][maxcol]; //Tamaño maximo del tablero indice de la matriz
    int numero_barcos;
    int numero_misiles;
    int n_especiales;
    int atq_especial[3]; //Ataques especiales, 0- Golpe expansivo, afectara a las casillas cercanas, 1- Golpe en fila, 2- Golpe en columna, representan si estan activos o no
    int turno; //Ataques realizados
    Barco barcos[20]; //Arreglo de barcos
    int columnas;//Columnas del tablero
    int filas; //Filas del tablero
};


////////////////////////////////
//                            //
//  DECLARACION DE FUNCIONES  //
//                            //
////////////////////////////////


void Jugar(Player &jugador, Player &IA);//Funcion principal Jugar____usa la funcion jugada
bool MenuConfig (Player &jugador, Player &IA);//Menú para preguntar si quiere automatico o manual; auto__configAuto, Manual____ConfigPersonal
void Config_Personal(Player &jugador, Player &IA);//Configuracionalmanual del usuario
void Config_Auto(Player &jugador, Player &IA);//generacion de aleatoria del juego
void ImprimirTablero (Casilla jugador[][maxcol], int fil, int col);//Imprimir tablero
void ConfigIA_barcos_auto (Player &usu);//Configuracion de Barcos mediante la úbicación aleatoria de los barcos en el tablero
void Jugada (Player &jugador, Player &IA);//Validar si el turno es el del jugador o el de la máquina
void ImprimirTableroJuego (Casilla jugador[][maxcol], int fil, int col);//
bool VerificarGanador(Player &jugador, Player &IA);//
void Reiniciar (Player &jugador, Player &IA);//

//MAIN


int main()
{
    Player jugador; //Jugador
    Player IA; //Computadora
    int opc;
    int reinicio;
    bool config=false;
    do
    {
        system("cls");
        cout << "===JUEGO BATALLA NAVAL==="<<endl;
        cout << "Seleccione una opcion: "<<endl;
        cout << "1. Jugar"<<endl;
        cout << "2. Configuracion"<<endl;
        cout << "3. Salir"<<endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            if(config==true)
            {
                Jugar(jugador, IA);
            }
            else
                cout << "Necesaria configuracion para iniciar"<<endl;
            system("pause");
            break;
        case 2:
            if(config==false)
            {
                config = MenuConfig(jugador, IA);
                config= true;
                cout << "CONFIGURACION ESTABLECIDA CORRECTAMENTE"<<endl;
                system("pause");

            }
            else
                cout << "Ya ha sido configurado el juego"<<endl;
            break;
        }
        system("pause");
    }
    while (opc <3);
    if (opc == 3)
        cout << "GRACIAS POR JUGAR"<<endl;
}

void Jugar(Player &jugador, Player &IA)
{
    system("cls");
    cout << "INICIO DE JUEGO"<<endl;
    cout << "JUEGO YA CONFIGURADO"<<endl;
    system("pause");
    system("cls");
    int reinicio=0;
    int jugadas=0;
    bool winner=false;
    while (reinicio == 0)
    {
        cout << "JUGADA "<< jugadas+1<<endl;
        cout << "TU TABLERO: "<<endl;
        ImprimirTablero(jugador.tablero, jugador.filas, jugador.columnas);
        cout << "TABLERO DEL ADVERSARIO: "<<endl;
        ImprimirTableroJuego(IA.tablero, IA.filas, IA.columnas);
        Jugada (jugador, IA);
        Jugada (IA, jugador);
        cout << "Desea reiniciar el juego? 0-no / 1-si"<<endl;
        cin >> reinicio;
        if (reinicio==0)
        {
            winner= VerificarGanador(jugador, IA);
            if (winner==false)
            {
                cout << "Aun no hay ganador"<<endl;
            }
            if (winner == true)
            {
                reinicio=1;
            }
            system("pause");
        }
        if (reinicio == 1)
        {
            Reiniciar(jugador, IA);
        }
        system("cls");

    }



}

void Jugada(Player &atq, Player &def)
{
    bool modo;//VERIFICACION DE QUIEN ATACA
    if (atq.nombre != "IA")
    {
        modo=true;
    }
    if (atq.nombre == "IA")
    {
        modo=false;
    }


    if (modo==false)//PROCEDIMIENTO DE JUGADA PARA LA COMPUTADORA
    {
        Casilla ataque;
        int fil, col;
        bool repeat=false;
        srand(time(NULL));
        do
        {
            repeat=false;
            fil = 0+ rand()% (atq.filas+1 - 0);
            col = 0+ rand()% (atq.columnas+1 - 0);
            if (atq.tablero[fil][col].estado=='T' || atq.tablero[fil][col].estado=='X')
            {
                repeat=true;
            }
        }
        while (repeat==true);

        if (repeat==false)
        {
            ataque.col=col;
            ataque.fil=fil;
            ataque.estado='T';
            if (def.tablero[fil][col].estado== 'O')
            {
                ataque.estado='X';
            }
            def.tablero[fil][col]=ataque; //REALIZA ATAQUE
            atq.turno++;
            atq.numero_misiles--;

            if (atq.turno==5)
            {
                if (atq.atq_especial[0]==1)
                {


                    for (int i=fil-1; i<=fil+1; i++)
                    {
                        for (int j=col-1; j<=col+1; j++)
                        {
                            if(def.tablero[i][j].estado=='L')
                                def.tablero[i][j].estado='T';
                            if (def.tablero[i][j].estado=='O')
                                def.tablero[i][j].estado='X';
                        }
                    }
                    atq.atq_especial[0]=0;
                }

            }
            if (atq.turno==7)
            {
                if (atq.atq_especial[1]==1)
                {

                    for (int i=0; i<def.columnas; i++)
                    {
                        if(def.tablero[fil][i].estado=='L')
                            def.tablero[fil][i].estado='T';
                        if (def.tablero[fil][i].estado=='O')
                            def.tablero[fil][i].estado='X';
                    }
                    atq.atq_especial[1]=0;
                }

            }
            if (atq.turno==10)
            {
                if (atq.atq_especial[2]==1)
                {

                    for (int i=0; i<def.filas; i++)
                    {
                        if(def.tablero[i][col].estado=='L')
                            def.tablero[i][col].estado='T';
                        if (def.tablero[i][col].estado=='O')
                            def.tablero[i][col].estado='X';

                    }
                    atq.atq_especial[2]=0;
                }

            }

        }






    }

    if (modo==true)//PROCEDIMIENTO DE JUGADA PARA JUGADOR
    {
        int col, fil;
        int opc;
        Casilla ataque;
        cout << "REALICE ATAQUE"<<endl;
        cout << "\nIngrese fila de ataque: "<<endl;
        cin >> fil;
        cout << "\nIngrese columna de ataque: "<<endl;
        cin >> col;
        ataque.col=col;
        ataque.fil=fil;
        ataque.estado='T';
        if (def.tablero[fil][col].estado=='O')
        {
            ataque.estado='X';
        }
        def.tablero[fil][col]=ataque; //SE REALIZA ATAQUE
        cout << "\nDesea usar arma especial? Si(1)- No(0)"<<endl;
        cout << "Ingrese valor"<<endl;
        cin >> opc;
        int arma;
        if (opc != 1)
            cout << "\nNo se eligio arma especial"<<endl;
        if (opc == 1)
        {
            cout<< "\nTiene disponible las siguientes armas: "<<endl;

            for (int i=0; i<atq.n_especiales; i++)
            {
                if (atq.atq_especial[i]== 1)
                {
                    if (i==0)
                    {
                        cout << "\n-Arma "<<i<<": MORTERO"<<endl;

                    }
                    if (i==1)
                    {
                        cout << "\n-Arma "<<i<<": BOMBARDEO EN FILA"<<endl;

                    }
                    if (i==2)
                    {
                        cout << "\n-Arma "<<i<<": BOMBARDEO EN COLUMNA"<<endl;
                    }
                }
            }
            cout << "Ingrese numero de arma a usar: ";
            cin >> arma;
            cout << "SE USARA EL ARMA: ";
            if (atq.atq_especial[arma] != 1)
            {
                cout << "ATAQUE NO DISPONIBLE"<<endl;
            }

            if (arma==0 && atq.atq_especial[arma]== 1)
            {
                cout << "MORTERO"<<endl;
                for (int i=fil-1; i<=fil+1; i++)
                {
                    for (int j=col-1; j<=col+1; j++)
                    {
                        if(def.tablero[i][j].estado=='L')
                            def.tablero[i][j].estado='T';
                        if (def.tablero[i][j].estado=='O')
                            def.tablero[i][j].estado='X';
                    }
                }

            }
            if (arma==1 && atq.atq_especial[arma]== 1)
            {
                cout << "BOMBARDEO EN FILA"<<endl;
                for (int i=0; i<def.columnas; i++)
                {
                    if(def.tablero[fil][i].estado=='L')
                        def.tablero[fil][i].estado='T';
                    if (def.tablero[fil][i].estado=='O')
                        def.tablero[fil][i].estado='X';
                }

            }
            if (arma==2 && atq.atq_especial[arma]== 1)
            {
                cout << "BOMBARDEO EN COLUMNA"<<endl;
                for (int i=0; i<def.filas; i++)
                {
                    if(def.tablero[i][col].estado=='L')
                        def.tablero[i][col].estado='T';
                    if (def.tablero[i][col].estado=='O')
                        def.tablero[i][col].estado='X';

                }
            }






        }


        if (atq.atq_especial[arma]==1)
        {

            cout << "\n\nATAQUE REALIZADO"<<endl;
            atq.atq_especial[arma]=0;
            atq.turno++;
            atq.numero_misiles--;
        }
        system("pause");
        system("cls");
    }

}

void Reiniciar(Player &jugador, Player &IA)
{
    cout << "REINICIO DETECTADO"<<endl;
    Player vacio;
    cout << vacio.nombre<<endl;
    cout << 2<<endl;
    jugador=vacio;
    IA=vacio;
    cout << "CONFIGURACION REINICIADA"<<endl;
}


bool VerificarGanador(Player &jugador, Player &IA)
{
    system("cls");
    int acum1=0, acum2=0;
    //SE VERIFICA POR MISILES
    if (IA.numero_misiles==0)
    {
        cout << "FINALIZA EL JUEGO"<<endl;
        cout << "Motivo: Insuficientes misiles para continuar"<<endl;
        for (int i=0; i<jugador.filas; i++)
        {
            for (int j=0; j<jugador.columnas; j++)
            {
                if (jugador.tablero[i][j].estado=='X')
                {
                    acum2++;
                }
                if (IA.tablero[i][j].estado=='X')
                {
                    acum1++;
                }

            }
        }
        if(acum1>acum2)
        {
            cout << "GANADOR "<<jugador.nombre<<endl;
            cout << "Mas barcos impactados: "<<acum1<<endl;
        }
        if (acum2>acum1)
        {
            cout << "GANADOR IA"<<endl;
            cout << "Mas barcos impactados: "<<acum2<<endl;
        }

        return true;

    }

    //SE VERIFICA POR BARCOS
    bool vivos_ia=false;
    bool vivos_jug=false;
    for (int i=0; i<jugador.filas; i++)
    {
        for (int j=0; j<jugador.columnas; j++)
        {
            if (IA.tablero[i][j].estado=='O')
            {
                vivos_ia=true;
            }
            if (jugador.tablero[i][j].estado=='O')
            {
                vivos_jug=true;
            }

        }
    }
    if (vivos_jug==false)
    {
        cout << "FINALIZA EL JUEGO"<<endl;
        cout << "Motivo: "<<jugador.nombre<< " se ha quedado sin barcos"<<endl;
        cout << "GANADOR LA IA"<<endl;

        return true;
    }
    if (vivos_ia==false)
    {
        cout << "FINALIZA EL JUEGO"<<endl;
        cout << "Motivo: IA se ha quedado sin barcos"<<endl;
        cout << "GANADOR "<<jugador.nombre<<endl;
        return true;
    }



}
//MENU DE CONFIGURACION

bool MenuConfig (Player &jugador, Player &IA)
{
    system("cls");
    bool config;
    int opc;
    cout << "===Menu de configuracion==="<<endl;
    cout << "1. Personalizado: Ajusta el juego a tu manera"<<endl;
    cout << "2. Automatico: Ajustes predeterminados"<<endl;
    cout << "3. Regresar"<<endl;
    cin >> opc;
    switch(opc)
    {
    case 1:
        Config_Personal(jugador, IA);
        break;
    case 2:
        Config_Auto(jugador, IA);
        break;
    }


}

//FUNCION PARA AJUSTE AUTOMATICO
void Config_Auto(Player &jugador, Player &IA)
{
    system("cls");
    int col=0, fil=0;
    srand(time(NULL));
    col= 5+rand()% (30 - 5);
    fil=col;
    jugador.filas=fil;
    jugador.columnas=col;
    IA.columnas=col;
    IA.filas=fil;
    jugador.nombre="Jugador1";
    IA.nombre="IA";
    jugador.turno=0;
    IA.turno=0;
    IA.n_especiales=3;
    jugador.n_especiales=3;
    for (int i=0; i<3; i++)
    {
        IA.atq_especial[i]=1;
        jugador.atq_especial[i]=1;
    }
    int n_misil;
    n_misil= 15 + rand() % (col/2);
    jugador.numero_misiles=n_misil;
    IA.numero_misiles=n_misil;
    int n_barcos;
    n_barcos= 2 + rand() % ((col/3) - 2);
    jugador.numero_barcos=n_barcos;
    IA.numero_barcos=n_barcos;

    for (int i=0; i<jugador.filas; i++)
    {
        for (int j=0; j<jugador.columnas; j++)
        {
            jugador.tablero[i][j].estado='L';
            IA.tablero[i][j].estado='L';
        }
    }

    cout << "CONFIGURACION AUTOMATICA: "<<endl;
    cout << "Tablero de: "<<jugador.filas<< "x"<<jugador.columnas<<endl;
    cout << "Usuario: "<<jugador.nombre<<endl;
    cout << "Numero de misiles: "<< jugador.numero_misiles<<endl;
    cout << "Numero barcos: "<< jugador.numero_barcos<<endl;
    cout << "Armas especiales: "<< jugador.n_especiales<<endl;
    int tam;
    for (int i=0; i<jugador.numero_barcos; i++)
    {
        tam= 2+ rand()%( 6 - 2);
        cout << "   -Barco "<<i+1<<": "<<tam<<endl;
        jugador.barcos[i].tam=tam;
        IA.barcos[i].tam=tam;
    }
    ConfigIA_barcos_auto(jugador);
    ConfigIA_barcos_auto(IA);
    cout << "TU TABLERO ACTUAL"<<endl;
    ImprimirTablero(jugador.tablero, jugador.filas, jugador.columnas);
    /*
    cout << "TABLERO IA"<<endl;
    ImprimirTablero(IA.tablero, jugador.filas, jugador.columnas);
    */



}

//FUNCION PARA AJUSTE PERSONALIZADO
void Config_Personal(Player &jugador, Player &IA)
{
    system("cls");
    int tamfil, tamcol, misiles, barcos;
    string nombre;
    char check;
    cout << "===CONFIGURACION PERSONALIZADA==="<<endl;
    cout << "POR FAVOR DEFINA LOS SIGUIENTES VALORES: "<<endl;
    do
    {
        cout << "INFORMACION BASICA GENERAL: "<<endl;


        do
        {
            cout << "\nNumero de filas: "<<endl;
            cout << "   - Aqui definiras el numero de filas del tablero jugar"<<endl;
            cout << "     Minimo 5, Maximo 30"<<endl;
            cout << "Ingrese valor: ";
            cin >> tamfil;
            if (tamfil<5 || tamfil>30)
            {
                cout << "Valor invalido"<<endl;
                cout << "Asegurate que este en el rango establecido"<<endl;
            }
        }
        while(tamfil<5 || tamfil>30);



        do
        {
            cout << "\nNumero de columnas: "<<endl;
            cout << "   - Aqui definiras el numero de columnas del tablero jugar"<<endl;
            cout << "     Minimo 5, Maximo 30"<<endl;
            cout << "Ingrese valor: ";
            cin >> tamcol;
            if (tamcol<5 || tamcol>30)
            {
                cout << "Valor invalido"<<endl;
                cout << "Asegurate que este en el rango establecido"<<endl;
            }
        }
        while(tamcol<5 || tamcol>30);


        cout << "\nNombre de usuario: "<<endl;
        cout << "   - Sera tu nombre de usuario (Se toma solo una palabra)"<<endl;
        cout << "Ingrese valor: ";
        cin >> nombre;

        cout << "\nNumero de misiles: "<< endl;
        cout << "   - Este es el numero de misiles que estaran disponibles durante el juego"<<endl;
        cout << "     Al usar TODOS los misiles durante el juego, finalizara"<<endl;
        cout << "     Asi que te recomendamos que uses un numero adecuado al tamayo del tablero"<<endl;
        cout << "     Maximo: "<< tamcol*tamfil<<endl;
        cout << "Ingrese valor: ";
        cin >> misiles;

        cout << "\nNumero de barcos: "<<endl;
        cout << "   - Este es el numero de barcos que estaran en el tablero en el juego"<<endl;
        cout << "   - Al hundir TODOS los barcos, el juego finalizara"<<endl;
        cout << "   - ADVERTENCIA: Ten en cuenta el tamayo del tablero, Recomendacion "<< tamfil/3<<endl;
        cout << "Ingrese Valor: ";
        cin >> barcos;








        //ASIGNACION DE DATOS A LAS ESTRUCTURAS
        jugador.nombre=nombre; //NOMBRE
        IA.nombre="IA";
        jugador.columnas=tamcol; //COLUMNAS DEL TABLERO
        IA.columnas=tamcol;
        jugador.filas=tamfil; //FILAS DEL TABLERO
        IA.filas=tamfil;
        jugador.numero_barcos=barcos; //BARCOS
        IA.numero_barcos=barcos;
        jugador.numero_misiles=misiles; //MISILES
        IA.numero_misiles=misiles;
        jugador.turno=0;
        IA.turno=0;


        int ataques[3];
        for (int i=0; i<3; i++)
        {
            ataques[i]=0;
        }

        int arma;
        int n_arma=0;
        do
        {
            cout << "\nAtaques especiales: "<<endl;
            cout << "   - Opcion 0: Esta arma especial hara que el ataque afecte a CASILLAS CERCANAS ADICIONALES"<<endl;
            cout << "   - Opcion 1: Esta arma especial hara que el ataque impacte en TODAS las casillas de esa misma FILA"<<endl;
            cout << "   - Opcion 2: Esta arma especial hara que el ataque impacte en TODAS las casillas de esa misma COLUMNA"<<endl;
            cout << "   - Opcion 3: Continuar"<<endl;
            cout << "Ingrese valor: ";
            cin >> arma;
            if (arma >=0 && arma<3)
            {
                if (ataques[arma]==1)
                {
                    cout << "Arma especial ya agregada\nAgregue una distinta o continue"<<endl;
                }
                if(ataques[arma]==0)
                {
                    ataques[arma]=1;
                    n_arma++;
                    cout << "\n\nATAQUE ESPECIAL AYADIDO"<<endl;
                }

            }
            if (arma==3)
            {
                cout << "\nNo se agrego ningun arma especial"<<endl;
            }
            if (arma>3 || arma<0)
                cout << "\nOpcion invalida\nIngrese una valida"<<endl;


        }
        while (arma!=3);
        system("pause");

        jugador.n_especiales=n_arma;
        for (int i=0; i<3; i++)
        {
            if (ataques[i]==1)
            {
                IA.atq_especial[i]=1;
                jugador.atq_especial[i]=1;
            }
            if (ataques[i]==0)
            {
                IA.atq_especial[i]=0;
                jugador.atq_especial[i]=0;
            }


        }





        //AVISO DE VALIDACION
        system("cls");
        check= 'n';
        cout << "INFORMACION BASICA ESTABLECIDA: "<<endl;
        cout << "\nTamayo del tablero: "<< tamfil<<"x"<<tamcol<<endl;
        cout << "Numero de barcos: "<< barcos<<endl;
        cout << "Numero de misiles: "<<misiles<<endl;
        cout << "Usuario: "<<nombre<<endl;
        cout << "Armas especiales "<< n_arma<<endl;
        cout << "Desea confirmar esta configuracion?"<<endl;
        cout << "Presione 'S' para confirmar, 'N' para reconfigurar"<<endl;
        cin >> check;

    }
    while (check == 'n' || check == 'N');


    //CREACION DE TABLEROS

    Barco boat [barcos];
    Casilla tab[30][30];
    for(int i=0; i<tamfil; i++)
    {
        for (int j=0; j<tamcol; j++)
        {
            tab[i][j].estado='L';
            jugador.tablero[i][j].estado=tab[i][j].estado;
            IA.tablero[i][j].estado=tab[i][j].estado;
        }
    }

//CONFIGURACION DE BARCOS
    char confirm='n';
    do
    {
        system("cls");
        cout << "CONFIGURACION DE BARCOS"<<endl;
        cout << "Barcos totales: "<<barcos<<endl;
        cout << "Ajustar tamayo de cada barco: "<<endl;
        for (int i=0; i<barcos; i++)
        {
            int largo;
            do
            {
                largo=0;
                cout << "\nIngrese tamayo para barco "<<i+1<<endl;
                cout << "Maximo 5, Minimo 2"<<endl;
                cout << "Valor: ";
                cin >> largo;
                boat[i].tam=largo;
                if  (largo<2 || largo>5)
                {
                    cout << "Tamayo no permitido"<<endl;
                    cout << "Ingrese uno valido"<<endl;
                    system("pause");

                }
            }
            while (largo<2 || largo>5);
        }
        system("cls");
        cout << "BARCOS CONFIGURADOS"<<endl;
        for (int i=0; i<barcos; i++)
        {
            cout << "Barco "<<i+1<< ", Tamayo: "<< boat[i].tam<<endl;

        }
        cout << "Desea confirmar esta configuracion?"<<endl;
        cout << "Presione 'S' para confirmar, 'N' para reconfigurar"<<endl;
        cin >> confirm;
    }
    while (confirm == 'n' || confirm == 'N');
    for (int i=0; i<barcos; i++)
    {
        IA.barcos[i]=boat[i];
        jugador.barcos[i]=boat[i];
    }

    system("cls");
    int fila, columna;
    char confirmar_casilla;
    for(int i=0; i<barcos; i++)
    {
        cout << "ASIGNACION DE BARCOS EN TABLERO"<<endl;
        cout << "TABLERO ACTUAL: "<<endl;
        ImprimirTablero (jugador.tablero, tamfil, tamcol);
        cout << "Porfavor seleccione una coordenada para ubicar barco: "<<endl;
        cout << "Barco: "<<i+1<<endl;
        cout << "   - Tamayo: "<<boat[i].tam<<endl;
        do
        {
            cout << "\nIngrese Fila: ";
            cin >> fila;
            cout << "\nIngrese Columna: ";
            cin >> columna;
            if (jugador.tablero[fila][columna].estado!='L')
            {
                cout << "\nCasilla ya ocupada, intente con otra"<<endl;
            }
        }
        while (jugador.tablero[fila][columna].estado!='L');
        jugador.barcos[i].Inicial.fil=fila;
        jugador.barcos[i].Inicial.col=columna;
        jugador.tablero[fila][columna].estado='O';
        system("cls");
        cout << "COORDENADA INICIAL ESTABLECIDA"<<endl;
        cout << "TABLERO ACTUAL"<<endl;
        ImprimirTablero (jugador.tablero, tamfil, tamcol);
        char barco_pos;
        bool verificar=true;
        bool continuar=false;
        cout << "\nIngrese orientacion de barco, USAR MAYUSCULAS: "<<endl;
        cout << "W- Arriba"<<endl;
        cout << "S- Abajo"<<endl;
        cout << "A- Izquierda"<<endl;
        cout << "D- Derecha\n"<<endl;
        cout << "Ingrese valor: ";
        cin >> barco_pos;
        if (barco_pos=='W')
        {
            if((fila-boat[i].tam)<0)
            {
                cout << "\nNo es posible ubicarlo en esa posicion"<<endl;
                cout << "Ingrese una orientacion valida\n"<<endl;
                verificar=false;

            }
        }
        if (barco_pos=='S')
        {
            if((fila+boat[i].tam)> tamfil)
            {
                cout << "\nNo es posible ubicarlo en esa posicion"<<endl;
                cout << "Ingrese una orientacion valida\n"<<endl;
                verificar=false;

            }
        }
        if (barco_pos=='A')
        {
            if((columna-boat[i].tam)< 0)
            {
                cout << "\nNo es posible ubicarlo en esa posicion"<<endl;
                cout << "Ingrese una orientacion valida\n"<<endl;
                verificar=false;

            }
        }
        if (barco_pos=='D')
        {
            if((columna+boat[i].tam)> tamcol)
            {
                cout << "\nNo es posible ubicarlo en esa posicion"<<endl;
                cout << "Ingrese una orientacion valida\n"<<endl;
                verificar=false;

            }
        }
        if (barco_pos!='W' && barco_pos!='A' && barco_pos!='S' && barco_pos!='D' )
        {
            cout << "\nIngrese una opcion valida"<<endl;
            cout << "Tenga en cuenta el uso de mayusculas"<<endl;
            verificar=false;
        }
        if(verificar==true)
        {
            int aux;
            for (int j=1; j<boat[i].tam; j++)
            {
                if (barco_pos=='W')
                {
                    aux=fila;
                    jugador.tablero[aux-1][columna].estado='O';
                    fila--;
                }
                if (barco_pos=='S')
                {
                    aux=fila;
                    jugador.tablero[aux+1][columna].estado='O';
                    fila++;
                }
                if (barco_pos=='A')
                {
                    aux=columna;
                    jugador.tablero[fila][aux-1].estado='O';
                    columna--;

                }
                if (barco_pos=='D')
                {
                    aux=columna;
                    jugador.tablero[fila][aux+1].estado='O';
                    columna++;

                }

            }
            jugador.barcos[i].Final.col=columna;
            jugador.barcos[i].Final.fil=fila;
            system("pause");
            system("cls");
            cout << "TABLERO ACTUAL"<<endl;
            ImprimirTablero(jugador.tablero, tamfil, tamcol);

        }

        cout << "BARCO UBICADO CORRECTAMENTE"<<endl;
        system("pause");
        system("cls");


    }

    ConfigIA_barcos_auto (IA);
    cout << "CPU CONFIGURADA"<<endl;

}

void ConfigIA_barcos_auto (Player &usu)
{
    int nbarcos= usu.numero_barcos;
    Barco barcos[nbarcos];
    int fila;
    int col;
    int pos;
    for(int i=0; i<nbarcos; i++)
    {
        do
        {
            srand(time(NULL));
            fila= 0+rand()%(usu.filas+1 - 0);
            col= 0+rand()%(usu.columnas+1 - 0);
        }
        while (usu.tablero[fila][col].estado != 'L');
        usu.barcos[i].Inicial.col=col;
        usu.barcos[i].Final.fil=fila;
        usu.tablero[fila][col].estado='O';
        Barco boat[usu.numero_barcos];
        /*for (int a=0; a<usu.numero_barcos; a++)
        {
            boat[a]=usu.barcos[a];
        }*/
        bool verificar;
        do
        {
            verificar=true;
            pos= 0 + rand()% (4 -0 );
            pos= 0 + rand()% (4 -0 );


            if (pos== 0)
            {
                if((fila-usu.barcos[i].tam)<0)
                {
                    verificar=false;

                }
            }
            if (pos ==2)
            {
                if((fila+usu.barcos[i].tam)> usu.filas)
                {
                    verificar=false;

                }
            }
            if (pos==1)
            {
                if((col-usu.barcos[i].tam)< 0)
                {
                    verificar=false;

                }
            }
            if (pos==3)
            {
                if((col+usu.barcos[i].tam)> usu.columnas)
                {
                    verificar=false;

                }
            }


        }
        while (verificar==false);


        if(verificar==true)
        {
            int aux;

            for (int j=1; j<usu.barcos[i].tam; j++)
            {
                if (pos ==0)
                {
                    aux=fila;
                    usu.tablero[aux-1][col].estado='O';
                    fila--;
                }
                if (pos ==2)
                {
                    aux=fila;
                    usu.tablero[aux+1][col].estado='O';
                    fila++;
                }
                if (pos==1)
                {
                    aux=col;
                    usu.tablero[fila][aux-1].estado='O';
                    col--;

                }
                if (pos==3)
                {
                    aux=col;
                    usu.tablero[fila][aux+1].estado='O';
                    col++;

                }

            }
            usu.barcos[i].Final.col=col;
            usu.barcos[i].Final.fil=fila;

        }

    }
    //ImprimirTablero(usu.tablero, usu.filas, usu.columnas);
    cout << "BARCOS UBICADOS"<<endl;
    system("pause");
}


void ImprimirTablero (Casilla jugador[][maxcol], int fil, int col)
{
    cout << "    ";
    for (int i=0; i< col; i++)
    {
        cout << setw(2)<<i<<" |";
    }
    cout << "\n";
    for (int j=0; j<col+1; j++)
    {
        cout << "----";
    }
    cout << "\n";

    for (int i=0; i< fil; i++)
    {
        cout << setw(2)<<i<<" |";
        for (int j=0; j<col; j++)
        {
            if(jugador[i][j].estado=='L')
            {
                cout << "   |";
            }
            else
                cout << " "<<jugador[i][j].estado<< " |";
        }
        cout << "\n";
        for (int j=0; j<col+1; j++)
        {
            cout << "----";
        }
        cout << "\n";

    }
}

void ImprimirTableroJuego (Casilla jugador[][maxcol], int fil, int col)
{
    cout << "    ";
    for (int i=0; i< col; i++)
    {
        cout << setw(2)<<i<<" |";
    }
    cout << "\n";
    for (int j=0; j<col+1; j++)
    {
        cout << "----";
    }
    cout << "\n";

    for (int i=0; i< fil; i++)
    {
        cout << setw(2)<<i<<" |";
        for (int j=0; j<col; j++)
        {
            if(jugador[i][j].estado=='L' || jugador[i][j].estado=='O')
            {
                cout << "   |";
            }
            else
                cout << " "<<jugador[i][j].estado<< " |";
        }
        cout << "\n";
        for (int j=0; j<col+1; j++)
        {
            cout << "----";
        }
        cout << "\n";

    }
}
