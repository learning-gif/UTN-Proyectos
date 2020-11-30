#ifndef INSTRUCCIONES_H_INCLUDED
#define INSTRUCCIONES_H_INCLUDED

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>

void Instrucciones(){

    Rectangulo(1,1,108,24);
    setlocale(LC_ALL, ""); /// Permite usar distintos tipos de caracteres que no pertenecen al estandar que se puede imprimir normalmente.

    Say(40,1,"REGLAMENTO DEL JUEGO.");
    Say(3,3,"El juego consiste en seis rondas, las cuales progresan secuencialmente del uno al seis.");
    Say(3,4,"Cada ronda comienza con un lanzamiento de tres dados y un posterior análisis del puntaje de la tirada.");

    Say(3,6,"El jugador obtendrá:");
    Say(3,7,"21 puntos si los tres dados coinciden con el número de la ronda que se está jugando (Bunco).");
    Say(3,8,"5 puntos si los tres dados son iguales pero no coinciden con la ronda en curso.");
    Say(3,9,"3 puntos si la suma de los tres dados es divisible por 5.");
    Say(3,10,"2 puntos si los tres dados forman una escalera.");
    Say(3,11,"1 punto por cada dado que coincida con el número de la ronda.");
    Say(3,12,"Mientras el jugador obtenga algún puntaje en la tirada, podrá seguir realizando lanzamientos.");
    Say(3,13,"Si realiza una tirada que no suma ningún puntaje, a la misma se la considerará tirada fallida.");

    Say(3,15,"Un jugador: ");
    Say(3,16,"Cada ronda termina cuando el jugador llega a un puntaje mayor o igual a 21.");
    Say(3,17,"Al terminar las seis rondas, se le restará al puntaje final dos puntos por cada tirada fallida.");

    Say(3,19,"Multijugador: ");
    Say(3,20,"Cada ronda termina cuando uno de los jugadores obtiene un puntaje mayor o igual a 21 puntos.");
    Say(3,21,"Si en la primera tirada de una ronda el jugador 1 logra este puntaje sin ninguna tirada fallida:");
    Say(3,22,"El segundo jugador podrá realizar lanzamientos hasta finalizar la ronda o sacar una tirada fallida.");

    std::locale::global(std::locale("C")); /// Vuelve a los caracteres standar para poder imprimir los dados correctamente.

}


#endif // INSTRUCCIONES_H_INCLUDED