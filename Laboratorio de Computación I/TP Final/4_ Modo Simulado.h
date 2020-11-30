#include "Funciones Generales.h"


int ModoSimulado(){

    /// Declaro vector dados, vector nombre, Op (Opciones del switch) y Ronda inicial en 1.

    int const T=3;
    int Op;
    int Ronda=1;
    int Dados[T];
    char Nombre[15];

    /// Contadores y Acumuladores para las tiradas y puntos.

    int PuntosTirada=0;
    int PuntosTotales=0;
    int Buncos=0;
    int CantFallidas=0;
    int PuntosRonda=0;
    int CantTiradas=0;

    /// Banderas para mostrar o no partes del menu.

    bool X=false;
    bool Y=false;

    /// Desarrollo.

    Rectangulo(5,4,50,4); Say(10,5,"Ingrese su Nombre: "); CargarNombre(Nombre);

    do{
        cls();
        Rectangulo(5,4,60,22);
        Say(25,5,"Partida: SIMULADA.");
        Say(26,7,"Ronda Actual: "); cout<<Ronda;
        Rectangulo(5,10,60,12);

        /// Menu de juego.

        Say(17,12,"1. Realizar Tirada.");
        Say(17,14,"2. Analizar Tirada.");
        Say(17,16,"3. Intrucciones.");
        Say(17,18,"0. Volver al MENU PRINCIPAL.");

        if(Y==true){
            Rectangulo(71,5,38,8);
            Say(75,6,"Buncos: "); cout<<Buncos;
            Say(75,8,"Puntos de la Ronda Actual: "); cout<<PuntosRonda;
            Say(75,10,"Puntos Totales: "); cout<<PuntosTotales;
        }

        Say(11,23,"Seleccionar: "); cin>>Op;
        cls();

        switch(Op){
            case 1: /// Genera numeros aleatorios para los dados.
            if(X==false){CargarVector(Dados, T); X=true; CantTiradas++;}
            else{
                Rectangulo(14,4,50,4); Say(19,5,"Debe analizar su tirada para continuar.");
            }
            break;

            case 2: /// Analiza los puntos obtenidos.
            if(X==true){
                PuntosTirada=AnalizarTirada(Dados, T, Ronda);
                PuntosRonda=PuntosRonda+PuntosTirada;
                PuntosTotales=PuntosTotales+PuntosTirada;
                if(PuntosTirada==21) Buncos++;
                if(PuntosTirada==0) CantFallidas=CantFallidas+1;
                X=false;
                Y=true;
            }
            else{
                Rectangulo(14,4,50,4); Say(19,5,"Debe realizar una tirada para continuar.");
            }
            break;

            case 3: Instrucciones(); /// Reglamento del juego.
            break;

            case 0:
                Rectangulo(14,4,39,4); Say(19,5,"Volviendo al MENU PRINCIPAL.");
                gotoxy(10,9);
                return 0;
            break;

            default:
                Rectangulo(14,4,22,4); Say(19,5,"INCORRECTO.");
            break;
        }

        /// Pasaje de ronda y pantalla con estadisticas del juego entre rondas.

        if(PuntosRonda>=21){
            Ronda++;
            PuntosRonda=0;

            if(Ronda<=6){
                Rectangulo(25,26,50,4);
                gotoxy(30,28);
                system("pause");
                cls();
                AnalisisUnJugador(Nombre, Ronda, Buncos, CantFallidas, CantTiradas, PuntosTotales);
            }
        }
        Rectangulo(25,26,50,4);
        gotoxy(30,28);
        system("pause");
    }
    while(Ronda<=6);

    /// Fin de la partida con las estadisticas finales del juego.

    cls();
    Rectangulo(5,4,57,19);
    Say(13,5,"Cantidad de Rondas totales finalizadas.");
    Say(20,7,"---- Estadisticas ----");
    Say(10,10,"Jugador: "); MostrarNombre(Nombre);
    PuntosTotales=PuntosTotales-CantFallidas*2;

    Rectangulo(5,4,57,9);
    Say(9,14,"Buncos: "); cout<<Buncos;
    Say(9,16,"Tiradas fallidas: "); cout<<CantFallidas;
    Say(35,16,"Tiradas totales: "); cout<<CantTiradas;
    Say(9,18,"Puntaje final: "); cout<<PuntosTotales;
    Say(9,20,"En este modo NO se guardara su puntaje.");

}