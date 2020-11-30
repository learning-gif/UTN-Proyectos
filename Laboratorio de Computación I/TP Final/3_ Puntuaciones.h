
void Puntuaciones(char VecNombre[], int CantBuncos[], int Puntos, int PuntosMax[], char VecNombre_1[], int CBuncos[], int PuntosGanador, int PuntosMax2[], int T2, int Test[]){
    cls();
    Rectangulo(5,2,60,21);
    Rectangulo(5,2,60,10);
    Say(18,3,"UN JUGADOR:");

    if(PuntosMax[T2]!=0){
        if(Puntos==0){
            Say(18,7,"Nombre: "); MostrarNombre(VecNombre);
            Say(18,9,"Buncos: "); cout<<CantBuncos[T2];
            Say(18,11,"Mayor Puntaje: "); cout<<PuntosMax[T2];
        }
        else{
            Say(18,7,"Nombre: "); MostrarNombre(VecNombre);
            Say(18,9,"Buncos: "); cout<<CantBuncos[T2];
            Say(18,11,"Mayor Puntaje: "); cout<<Puntos;
        }
    }
    else{
        Say(10,7,"Debe completar una partida en el modo UN JUGADOR.");
    }

    Say(17,13,"MULTIJUGADOR:");
    if(PuntosMax2[T2]!=0){

        if(PuntosGanador!=0){

            if(Test[0]==0){
                Say(18,15,"Nombre: "); MostrarNombre(VecNombre_1);
                Say(18,17,"Buncos: "); cout<<CBuncos[T2];
                Say(18,19,"Mayor Puntaje: "); cout<<PuntosGanador;
            }
            else{
                Say(17,15,"EMPATE!.");
                Say(10,17,"Empato en la ultima partida.");
                Say(10,19,"Buncos: "); cout<<CBuncos[T2];
                Say(30,19,"Mayor Puntaje: "); cout<<PuntosGanador;
            }
        }
        else if(Test[0]==0){
            Say(18,15,"Nombre: "); MostrarNombre(VecNombre_1);
            Say(18,17,"Buncos: "); cout<<CBuncos[T2];
            Say(18,19,"Mayor Puntaje: "); cout<<PuntosMax2[T2];
        }
        else{
            Say(17,15,"EMPATE!.");
            Say(10,17,"Empato en la ultima partida.");
            Say(10,19,"Buncos: "); cout<<CBuncos[T2];
            Say(30,19,"Mayor Puntaje: "); cout<<PuntosMax2[T2];
        }
    }
    else{
        Say(9,18,"Debe completar una partida en el modo MULTIJUGADOR.");
    }
}
