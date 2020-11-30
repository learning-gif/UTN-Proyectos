#ifndef ANALIZAR_TIRADA_H_INCLUDED
#define ANALIZAR_TIRADA_H_INCLUDED

#include "Funciones Generales.h"


int AnalizarTirada(int Dados[], int T, int Ronda); /// Ordena las funciones y verifica cual es la de mayor valor, dicho valor lo devuelve como resultado.

int Bunco(int Dados[], int T, int Ronda); /// Verifica si saco 3 dados iguales al numero de ronda.

int Repetidos(int Dados[], int T); /// Verifica si saco 3 dados repetidos pero diferentes al numero de ronda.

int SumaDivisible5(int Dados[], int T); /// Verifica si la suma de sus dados es de resto 0.

int Escalera(int Dados[], int T); /// Ordena sus dados y verifica si estan en orden decreciente.

int CoincidenciaRonda(int Dados[], int T, int Ronda); /// Verifica si alguno de sus dados es igual al numero de ronda.

void CarasDados(int V[], int T);


/// Funciones para mostrar las estadisticas de la partida durante la misma.

void AnalisisUnJugador(char Nombre, int Tam, int Ronda, int Buncos, int CantFallidas, int CantTiradas, int PuntosTotales);

void AnalisisDosJugadores(int Turno, int Ronda, char Nombre_1[], int PuntosTotales_1, int Buncos_1, char Nombre_2[], int PuntosTotales_2, int Buncos_2);



/// Desarrollo de funciones especificas para el juego.



int AnalizarTirada(int Dados[], int T, int Ronda){
    int Puntos[5]={}, Pos;


    Puntos[0]=Bunco(Dados, Ronda, T);
    Puntos[1]=Repetidos(Dados, T);
    Puntos[2]=SumaDivisible5(Dados, T);
    Puntos[3]=Escalera(Dados, T);
    Puntos[4]=ContarNumerosRepetidos(Dados, Ronda, T);

    Pos=MaximoVector(Puntos,5);

    Rectangulo(5,3,50,18);
    Say(9,5,"Ronda: "); cout<<Ronda;
    Say(9,7,"Puntaje de la tirada: "); cout<<Puntos[Pos];

    if(Puntos[Pos]!=0){
        switch(Pos){
        case 0: Say(9,9,"BUNCO!.");
            break;
        case 1: Say(9,9,"3 DADOS REPETIDOS DIFERENTES A LA RONDA!.");
            break;
        case 2: Say(9,9,"LA SUMA DE LOS DADOS ES DIVISIBLES POR 5!.");
            break;
        case 3: Say(9,9,"ESCALERA!.");
            break;
        case 4: Say(9,9,"1 O 2 DADOS IGUAL A LA RONDA!.");
            break;
        }
    }
    else{
    Say(9,9,"TIRADA FALLIDA.");
    }
    Rectangulo(5,3,50,10);
    CarasDados(Dados,T);
    return Puntos[Pos];
}

int Bunco(int Dados[], int Ronda, int T){
    int Bunco;
    Bunco=ContarNumerosRepetidos(Dados, Ronda, T);
    if(Bunco==3) return 21;
    return 0;
}

int Repetidos(int Dados[], int T){
    int Cant;
    bool Repetidos=false;
    for(int I=1; I<=6; I++){
        Cant=ContarNumerosRepetidos(Dados, I, T);
        if(Cant==3) Repetidos=true;
    }
    if(Repetidos==true) return 5;
    return 0;
}

int SumaDivisible5(int Dados[], int T){
    int Suma;
    Suma=SumarVector(Dados, T);
    if(Suma%5==0) return 3;
    return 0;
}

int Escalera(int Dados[], int T){
    bool Ordenados=false;
    OrdenarVector(Dados, T);
    if((Dados[0]==Dados[1]-1) && (Dados[1]==Dados[2]-1)) Ordenados=true;
    if(Ordenados==true) return 2;
    return 0;
}


void AnalisisUnJugador(char Nombre[], int Ronda, int Buncos, int CantFallidas, int CantTiradas, int PuntosTotales){

    Rectangulo(5,4,50,17);
    Say(18,5,"Jugador: "); MostrarNombre(Nombre);
    Say(18,7,"Siguiente Ronda: "); cout<<Ronda;
    Rectangulo(5,4,50,7);
    Say(10,12,"Buncos: "); cout<<Buncos;
    Say(10,14,"Puntos: "); cout<<PuntosTotales;
    Say(10,18,"Tiradas fallidas: "); cout<<CantFallidas;
    Say(10,16,"Tiradas totales: "); cout<<CantTiradas;
}


void AnalisisDosJugadores(int Turno, int Ronda, char Nombre_1[], int PuntosTotales_1, int Buncos_1, char Nombre_2[], int PuntosTotales_2, int Buncos_2){

    Rectangulo(5,2,45,22);
    Say(10,3,"Ronda actual: "); cout<<Ronda;
    Say(10,5,"Siguente turno: ");
    if(Turno==1) MostrarNombre(Nombre_1);
    else MostrarNombre(Nombre_2);

    Rectangulo(5,8,45,8);
    Say(10,9,"Jugador: "); MostrarNombre(Nombre_1);
    Say(10,11,"Puntaje total: "); cout<<PuntosTotales_1;
    Say(10,13,"Buncos: "); cout<<Buncos_1;

    Say(10,17,"Jugador: "); MostrarNombre(Nombre_2);
    Say(10,19,"Puntaje total: "); cout<<PuntosTotales_2;
    Say(10,21,"Buncos: "); cout<<Buncos_2;
}



#endif // ANALIZAR_TIRADA_H_INCLUDED