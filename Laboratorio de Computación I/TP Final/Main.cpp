#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "rlutil.h"

using namespace rlutil;

#include "Funciones Esteticas.h"
#include "1_ Un Jugador.h"
#include "2_ Dos Jugadores.h"
#include "3_ Puntuaciones.h"
#include "4_ Modo Simulado.h"


/// PENSAR COMO HACER PARA QUE SOLO MUESTRE LA MAYOR PUNTUACION OBTENIDA EN PUNTUACIONES.H Y QUE NO SE PISE CON OTRAS PARTIDAS JUGADAS.


int main(){

    setBackgroundColor(YELLOW);
    setColor(BLACK);

    int Op;

    /// Variables y vectores para cargar en UnJugador() y DosJugadores() que despues se mostraran dentro de la funcion Puntuaciones().

    int Puntos=0;
    int PuntosGanador=0;

    const int T=15;
    const int T2=1;

    /// Un Jugador.

    char VecNombre[T]={};
    int CantBuncos[T2]={};
    int PuntosMax[T2]={};

    /// Dos Jugadores.

    char VecNombre_1[T]={};
    int CBuncos[T2]={};
    int PuntosMax2[T2]={};
    int Test[1];

    /// Menu principal del programa.

    while(true){

        cls();
        Rectangulo(5,4,60,22);

        Say(18,5,"-----  MENU PRINCIPAL  -----");
        Say(21,7,"Juego de dados BUNCO!");
        Rectangulo(5,10,60,12);
        Say(10,11,"1. JUEGO NUEVO: Un jugador.");
        Say(10,13,"2. JUEGO NUEVO: Dos jugadores.");
        Say(10,15,"3. MOSTRAR PUNTUACION MAS ALTA.");
        Say(10,17,"4. MODO SIMULADO (Carga de dados manual).");
        Say(10,19,"0. SALIR.");
        Say(10,23,"Seleccionar: "); cin>>Op;

        cls();

        switch(Op){
        case 1: Puntos=UnJugador(VecNombre, T, CantBuncos, PuntosMax, T2); /// Le envio los parametros y le pido el retorno que necesito para Mostrar puntuacion mas alta.
            break;
        case 2: PuntosGanador=DosJugadores(VecNombre_1, T, PuntosMax2, T2, CBuncos, Test); /// Le envio los parametros y le pido el retorno que necesito para Mostrar puntuacion mas alta.
            break;
        case 3: Puntuaciones(VecNombre, CantBuncos, Puntos, PuntosMax, VecNombre_1, CBuncos, PuntosGanador, PuntosMax2, T2, Test); /// Solo mostrará la puntuación Max de ambos modos.
            break;
        case 4: ModoSimulado(); /// Misma funcion que UnJugador pero con carga manual del vector dados.
            break;
        case 0: Rectangulo(5,4,31,4); Say(11,5,"CERRANDO PROGRAMA.");
            gotoxy(10,9);
            return 0;
            break;
        default:
            Rectangulo(14,4,30,4);
            Say(19,5,"INCORRECTO.");
            break;
        }
        Rectangulo(25,26,50,4);
        gotoxy(30,28);
        system("pause");
        cls();
    }
}
