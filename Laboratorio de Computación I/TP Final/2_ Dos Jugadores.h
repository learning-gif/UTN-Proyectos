#include "Funciones Generales.h"
#include "Instrucciones.h"


int DosJugadores(char VecNombre_1[], int Tam, int PuntosMax2[], int Tam2, int CBuncos[], int Test[]){

    /// Declaro vector dados, vectores nombres, Op (Opciones del switch), ronda y turno inicial en 1.

    int Op;
    int const T=3;
    int Dados[T];
    int Ronda=1;
    int Turno=1;
    int Ant;
    char Nombre_1[Tam];
    char Nombre_2[Tam];

    /// Contadores y Acumuladores para las tiradas y puntos.

    int PuntosTirada_1=0;
    int PuntosTirada_2=0;
    int PuntosRonda_1=0;
    int PuntosRonda_2=0;
    int PuntosTotales_1=0;
    int PuntosTotales_2=0;
    int Buncos_1=0;
    int Buncos_2=0;

    /// Banderas para mostrar o no partes del menu.

    bool X=false;
    bool Y=false;
    bool Z=false;

    /// Bandera para saber si ya jugo o no el segundo jugador.

    bool Flag=false;

    Rectangulo(5,4,50,4);
    Rectangulo(5,4,50,8);
    Say(10,5,"Nombre del Jugador 1: "); CargarNombre(Nombre_1);
    Say(10,9,"Nombre del Jugador 2: "); CargarNombre(Nombre_2);

    do{
        /// Jugador inicial.

        cls();
        Rectangulo(5,4,50,21);
        Say(17,5,"Partida: MULTIJUGADOR.");
        Rectangulo(5,8,50,4);
        Say(10,9,"Ronda: "); cout<<Ronda;
        Say(25,9,"Turno: ");

        if(Turno==1) MostrarNombre(Nombre_1);
        else MostrarNombre(Nombre_2);

        /// Menu de juego.

        Ant=Turno;
        Say(10,14,"1. Realizar Tirada.");
        Say(10,16,"2. Analizar Tirada.");
        Say(10,18,"3. Instrucciones.");
        Say(10,22,"0. Volver al MENU PRINCIPAL.");

        Rectangulo(5,25,50,4);
        Say(17,26,"Seleccionar: "); cin>>Op;
        cls();

        switch(Op){
            case 1:
            if(X==false){
                Rectangulo(14,4,30,4); Say(19,5,"Lanzando dados! ");
                msleep(3000);
                DadoRandom();
                CargarAleatorio(Dados, T,5);
                X=true;
            }
            else{Rectangulo(14,4,50,4); Say(19,5,"Debe analizar su tirada para continuar.");}
            break;

            case 2:
            if(X==true){
                if(Y==true) Z==true;

                X=false;
                Y=true;

                /// Dependiendo el turno realiza el analisis de la tirada y acumula los puntajes por ronda y por totales.

                if(Turno==1){
                    PuntosTirada_1 = AnalizarTirada(Dados, T, Ronda);
                    PuntosTotales_1 = PuntosTotales_1 + PuntosTirada_1;
                    PuntosRonda_1 = PuntosRonda_1 + PuntosTirada_1;
                    if(PuntosTirada_1==21) Buncos_1++;
                }
                else{
                    PuntosTirada_2 = AnalizarTirada(Dados, T, Ronda);
                    PuntosTotales_2 = PuntosTotales_2 + PuntosTirada_2;
                    PuntosRonda_2 = PuntosRonda_2 + PuntosTirada_2;
                    if(PuntosTirada_2==21) Buncos_2++;
                    Flag=true;
                }

                /// Cambio de turno segun corresponda.

                if(Turno==1 && (PuntosRonda_1>=21 || PuntosTirada_1==0)) Turno=2;
                else if(Turno==2 && (PuntosRonda_2>=21 || PuntosTirada_2==0)) Turno=1;

                /// Cambio de ronda segun corresponda.

                if(PuntosRonda_1>21 || PuntosRonda_2>=21){ /// Caso del jugador 1 completando la ronda SIN BUNCO y del jugador 2 completando la ronda CON O SIN BUNCO.
                    Ronda++;
                    PuntosRonda_1=0;
                    PuntosRonda_2=0;
                }
                if(PuntosTirada_1==21 && PuntosTirada_2==0 && Flag==true){ /// Caso de BUNCO del jugador 1 en la primera tirada.
                    Ronda++;
                    Flag=false;
                    PuntosRonda_1=0;
                    PuntosRonda_2=0;
                }

                /// Muestra pantalla con estadisticas del juego entre turnos.

                if(Ant!=Turno){
                    Rectangulo(25,26,50,4);
                    gotoxy(30,28);
                    system("pause");
                    cls();
                    AnalisisDosJugadores(Turno, Ronda, Nombre_1, PuntosTotales_1, Buncos_1, Nombre_2, PuntosTotales_2, Buncos_2);
                }
            }
            else{Rectangulo(14,4,50,4); Say(19,5,"Debe realizar una tirada para continuar.");}
            break;

            case 3: Instrucciones(); /// Reglamento del juego.
            break;

            case 0: Rectangulo(14,4,39,4); Say(19,5,"Volviendo al MENU PRINCIPAL.");
                gotoxy(10,9);
                return 0;
            break;

            default: Rectangulo(14,4,22,4); Say(19,5,"INCORRECTO.");;
            break;
        }
        Rectangulo(25,26,50,4);
        gotoxy(30,28);
        system("pause");
    }
    while(Ronda<=6);
    cls();

    /// Fin de la partida y carga de los vectores y variables con los parametros necesarios para la seccion de Puntajes.

    Rectangulo(5,2,61,22);
    Rectangulo(5,2,61,4);
    Rectangulo(5,12,61,6);

    Say(15,3,"Cantidad de Rondas totales finalizadas.");

    /// Ganador jugador 1 por puntos totales.

    if(PuntosTotales_1>PuntosTotales_2){
        Say(25,7,"GANADOR: "); MostrarNombre(Nombre_1);

        if(PuntosMax2[Tam2]==0){

            CopiarVectorNombre(Nombre_1, VecNombre_1, Tam);
            CBuncos[Tam2]=Buncos_1;
            Test[0]=0;
            PuntosMax2[Tam2]=PuntosTotales_1;
        }
        else if(PuntosTotales_1>PuntosMax2[Tam2]){

            CopiarVectorNombre(Nombre_1, VecNombre_1, Tam);
            CBuncos[Tam2]=Buncos_1;
            Test[0]=0;
            PuntosMax2[Tam2]=PuntosTotales_1;
        }
    }

    /// Ganador jugador 1 mismos puntos pero mayor cant de Buncos.

    else if(PuntosTotales_1==PuntosTotales_2 && Buncos_1>Buncos_2){
        Say(25,7,"GANADOR: "); MostrarNombre(Nombre_1);

        if(PuntosMax2[Tam2]==0){

            CopiarVectorNombre(Nombre_1, VecNombre_1, Tam);
            CBuncos[Tam2]=Buncos_1;
            Test[0]=0;
            PuntosMax2[Tam2]=PuntosTotales_1;
        }
        else if(PuntosTotales_1>PuntosMax2[Tam2]){

            CopiarVectorNombre(Nombre_1, VecNombre_1, Tam);
            CBuncos[Tam2]=Buncos_1;
            Test[0]=0;
            PuntosMax2[Tam2]=PuntosTotales_1;
        }
    }

    /// Ganador jugador 2 por puntos totales.

    else if(PuntosTotales_1<PuntosTotales_2){
        Say(25,7,"GANADOR: "); MostrarNombre(Nombre_2);

        if(PuntosMax2[Tam2]==0){

            CopiarVectorNombre(Nombre_2, VecNombre_1, Tam);
            CBuncos[Tam2]=Buncos_2;
            Test[0]=0;
            PuntosMax2[Tam2]=PuntosTotales_2;
        }
        else if(PuntosTotales_2>PuntosMax2[Tam2]){

            CopiarVectorNombre(Nombre_2, VecNombre_1, Tam);
            CBuncos[Tam2]=Buncos_2;
            Test[0]=0;
            PuntosMax2[Tam2]=PuntosTotales_2;
        }
    }

    /// Ganador jugador 2 mismos puntos pero mayor cant de Buncos.

    else if(PuntosTotales_1==PuntosTotales_2 && Buncos_1<Buncos_2){
        Say(25,7,"GANADOR: "); MostrarNombre(Nombre_2);

        if(PuntosMax2[Tam2]==0){

            CopiarVectorNombre(Nombre_2, VecNombre_1, Tam);
            CBuncos[Tam2]=Buncos_2;
            Test[0]=0;
            PuntosMax2[Tam2]=PuntosTotales_2;
        }
        else if(PuntosTotales_2>PuntosMax2[Tam2]){

            CopiarVectorNombre(Nombre_2, VecNombre_1, Tam);
            CBuncos[Tam2]=Buncos_2;
            Test[0]=0;
            PuntosMax2[Tam2]=PuntosTotales_2;
        }
    }

    /// Empate.

    else{
        Say(28,7,"EMPATE! ");

        if(PuntosMax2[Tam2]==0){

            CopiarVectorNombre(Nombre_1, VecNombre_1, Tam);;

            CBuncos[Tam2]=Buncos_1;
            Test[0]=1;
            PuntosMax2[Tam2]=PuntosTotales_1;
        }
        else if(PuntosTotales_1>PuntosMax2[Tam2]){

            CopiarVectorNombre(Nombre_1, VecNombre_1, Tam);

            CBuncos[Tam2]=Buncos_1;
            Test[0]=1;
            PuntosMax2[Tam2]=PuntosTotales_1;
        }

    }


    /// Estadisticas de la partida.

    Say(22,9,"--- Estadisticas ---");

    Say(10,13,"Jugador: "); MostrarNombre(Nombre_1);
    Say(10,14,"Buncos: "); cout<<Buncos_1;
    Say(10,15,"Puntaje total: "); cout<<PuntosTotales_1;

    Say(10,19,"Jugador: "); MostrarNombre(Nombre_2);
    Say(10,20,"Buncos: "); cout<<Buncos_2;
    Say(10,21,"Puntaje total: "); cout<<PuntosTotales_2;

    if(PuntosMax2[Tam2]==PuntosTotales_1 || PuntosMax2[Tam2]==PuntosTotales_2){
        if(PuntosTotales_1>=PuntosTotales_2) return PuntosTotales_1;
        else return PuntosTotales_2;
    }
    else return 0;
}
