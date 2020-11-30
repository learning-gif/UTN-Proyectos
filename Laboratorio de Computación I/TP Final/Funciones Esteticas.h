#ifndef FUNCIONES_ESTETICAS_H_INCLUDED
#define FUNCIONES_ESTETICAS_H_INCLUDED


void CarasDados(int V[], int T);   /// Segun el vector, imprime el dado correspondiente.

void Rectangulo(int X, int Y, int Ancho, int Alto);   /// Imprime un una figura dandole los parametros.

void Say(int X, int Y, const char *txt);    /// Cout pero con coordenadas.

void Gotoxy(int X, int Y);   /// Darle posiciones con coordenadas a otro codigo visual.

void CarasDadosRandom(int X);  /// Efecto de rotacion del dado.


/// Desarrollo de funciones.



void CarasDados(int V[], int T){

    /// Dado 1 (Cuadrado).

    for(int I=10; I<18; I++){
        locate(I, 15); printf("%c", 205);
        locate(I, 19); printf("%c", 205);
    }

    for (int I=18; I>15; I--){
        locate(10, I); printf("%c", 186);
        locate(18, I); printf("%c", 186);
    }

    locate(10, 15); printf("%c", 201);
    locate(10, 19); printf("%c", 200);
    locate(18, 15); printf("%c", 187);
    locate(18, 19); printf("%c", 188);

    /// Dado 2 (Cuadrado).

    for(int I=25; I<33; I++){
        locate(I, 15); printf("%c", 205);
        locate(I, 19); printf("%c", 205);
    }

    for (int I=18; I>15; I--){
        locate(25, I); printf("%c", 186);
        locate(33, I); printf("%c", 186);
    }

    locate(25, 15); printf("%c", 201);
    locate(25, 19); printf("%c", 200);
    locate(33, 15); printf("%c", 187);
    locate(33, 19); printf("%c", 188);

    /// Dado 3 (Cuadrado).

    for(int I=40; I<48; I++){
        locate(I, 15); printf("%c", 205);
        locate(I, 19); printf("%c", 205);
    }

    for (int I=18; I>15; I--){
        locate(40, I); printf("%c", 186);
        locate(48, I); printf("%c", 186);
    }

    locate(40, 15); printf("%c", 201);
    locate(40, 19); printf("%c", 200);
    locate(48, 15); printf("%c", 187);
    locate(48, 19); printf("%c", 188);


    /// Caras de los dados.

    /// Dado 1.

    switch(V[0]){
    case 1:
        locate(14, 17); printf("%c", 254);
        break;

    case 2:
        locate(12, 18); printf("%c", 254);
        locate(16, 16); printf("%c", 254);
        break;

    case 3:
        locate(12, 18); printf("%c", 254);
        locate(14, 17); printf("%c", 254);
        locate(16, 16); printf("%c", 254);
        break;

    case 4:
        locate(12, 16); printf("%c", 254);
        locate(16, 16); printf("%c", 254);
        locate(12, 18); printf("%c", 254);
        locate(16, 18); printf("%c", 254);
        break;

    case 5:
        locate(12, 16); printf("%c", 254);
        locate(16, 16); printf("%c", 254);
        locate(14, 17); printf("%c", 254);
        locate(12, 18); printf("%c", 254);
        locate(16, 18); printf("%c", 254);
        break;

    case 6:
        locate(12, 16); printf("%c", 254);
        locate(16, 16); printf("%c", 254);
        locate(12, 17); printf("%c", 254);
        locate(16, 17); printf("%c", 254);
        locate(12, 18); printf("%c", 254);
        locate(16, 18); printf("%c", 254);
        break;
    }

    /// Dado 2.

    switch(V[1]){
    case 1:
        locate(29, 17); printf("%c", 254);
        break;

    case 2:
        locate(27, 18); printf("%c", 254);
        locate(31, 16); printf("%c", 254);
        break;

    case 3:
        locate(27, 18); printf("%c", 254);
        locate(29, 17); printf("%c", 254);
        locate(31, 16); printf("%c", 254);
        break;

    case 4:
        locate(27, 16); printf("%c", 254);
        locate(31, 16); printf("%c", 254);
        locate(27, 18); printf("%c", 254);
        locate(31, 18); printf("%c", 254);
        break;

    case 5:
        locate(27, 16); printf("%c", 254);
        locate(31, 16); printf("%c", 254);
        locate(29, 17); printf("%c", 254);
        locate(27, 18); printf("%c", 254);
        locate(31, 18); printf("%c", 254);
        break;

    case 6:
        locate(27, 16); printf("%c", 254);
        locate(31, 16); printf("%c", 254);
        locate(27, 17); printf("%c", 254);
        locate(31, 17); printf("%c", 254);
        locate(27, 18); printf("%c", 254);
        locate(31, 18); printf("%c", 254);
        break;
    }

    /// Dado 3.

    switch(V[2]){
    case 1:
        locate(44, 17); printf("%c", 254);
        break;

    case 2:
        locate(42, 18); printf("%c", 254);
        locate(46, 16); printf("%c", 254);
        break;

    case 3:
        locate(42, 18); printf("%c", 254);
        locate(44, 17); printf("%c", 254);
        locate(46, 16); printf("%c", 254);
        break;

    case 4:
        locate(42, 16); printf("%c", 254);
        locate(46, 16); printf("%c", 254);
        locate(42, 18); printf("%c", 254);
        locate(46, 18); printf("%c", 254);
        break;

    case 5:
        locate(42, 16); printf("%c", 254);
        locate(46, 16); printf("%c", 254);
        locate(44, 17); printf("%c", 254);
        locate(42, 18); printf("%c", 254);
        locate(46, 18); printf("%c", 254);
        break;

    case 6:
        locate(42, 16); printf("%c", 254);
        locate(46, 16); printf("%c", 254);
        locate(42, 17); printf("%c", 254);
        locate(46, 17); printf("%c", 254);
        locate(42, 18); printf("%c", 254);
        locate(46, 18); printf("%c", 254);
        break;
    }
}

void DadoRandom(){

    hidecursor();
    for(int I=1; I<=6; I++){
        CarasDadosRandom(I);
        msleep(25);
        cls();
    }

    for(int I=6; I>=1; I--){
        CarasDadosRandom(I);
        msleep(25);
        cls();
    }
}


void CarasDadosRandom(int X){

    for(int I=10; I<18; I++){
        locate(I, 15); printf("%c", 205);
        locate(I, 19); printf("%c", 205);
    }

    for (int I=18; I>15; I--){
        locate(10, I); printf("%c", 186);
        locate(18, I); printf("%c", 186);
    }

    locate(10, 15); printf("%c", 201);
    locate(10, 19); printf("%c", 200);
    locate(18, 15); printf("%c", 187);
    locate(18, 19); printf("%c", 188);

    for(int I=25; I<33; I++){
        locate(I, 15); printf("%c", 205);
        locate(I, 19); printf("%c", 205);
    }

    for (int I=18; I>15; I--){
        locate(25, I); printf("%c", 186);
        locate(33, I); printf("%c", 186);
    }

    locate(25, 15); printf("%c", 201);
    locate(25, 19); printf("%c", 200);
    locate(33, 15); printf("%c", 187);
    locate(33, 19); printf("%c", 188);


    for(int I=40; I<48; I++){
        locate(I, 15); printf("%c", 205);
        locate(I, 19); printf("%c", 205);
    }

    for (int I=18; I>15; I--){
        locate(40, I); printf("%c", 186);
        locate(48, I); printf("%c", 186);
    }

    locate(40, 15); printf("%c", 201);
    locate(40, 19); printf("%c", 200);
    locate(48, 15); printf("%c", 187);
    locate(48, 19); printf("%c", 188);


    switch(X){
    case 1:
        locate(14, 17); printf("%c", 254);
        break;

    case 2:
        locate(12, 18); printf("%c", 254);
        locate(16, 16); printf("%c", 254);
        break;

    case 3:
        locate(12, 18); printf("%c", 254);
        locate(14, 17); printf("%c", 254);
        locate(16, 16); printf("%c", 254);
        break;

    case 4:
        locate(12, 16); printf("%c", 254);
        locate(16, 16); printf("%c", 254);
        locate(12, 18); printf("%c", 254);
        locate(16, 18); printf("%c", 254);
        break;

    case 5:
        locate(12, 16); printf("%c", 254);
        locate(16, 16); printf("%c", 254);
        locate(14, 17); printf("%c", 254);
        locate(12, 18); printf("%c", 254);
        locate(16, 18); printf("%c", 254);
        break;

    case 6:
        locate(12, 16); printf("%c", 254);
        locate(16, 16); printf("%c", 254);
        locate(12, 17); printf("%c", 254);
        locate(16, 17); printf("%c", 254);
        locate(12, 18); printf("%c", 254);
        locate(16, 18); printf("%c", 254);
        break;
    }

    switch(X){
    case 1:
        locate(29, 17); printf("%c", 254);
        break;

    case 2:
        locate(27, 18); printf("%c", 254);
        locate(31, 16); printf("%c", 254);
        break;

    case 3:
        locate(27, 18); printf("%c", 254);
        locate(29, 17); printf("%c", 254);
        locate(31, 16); printf("%c", 254);
        break;

    case 4:
        locate(27, 16); printf("%c", 254);
        locate(31, 16); printf("%c", 254);
        locate(27, 18); printf("%c", 254);
        locate(31, 18); printf("%c", 254);
        break;

    case 5:
        locate(27, 16); printf("%c", 254);
        locate(31, 16); printf("%c", 254);
        locate(29, 17); printf("%c", 254);
        locate(27, 18); printf("%c", 254);
        locate(31, 18); printf("%c", 254);
        break;

    case 6:
        locate(27, 16); printf("%c", 254);
        locate(31, 16); printf("%c", 254);
        locate(27, 17); printf("%c", 254);
        locate(31, 17); printf("%c", 254);
        locate(27, 18); printf("%c", 254);
        locate(31, 18); printf("%c", 254);
        break;
    }

    switch(X){
    case 1:
        locate(44, 17); printf("%c", 254);
        break;

    case 2:
        locate(42, 18); printf("%c", 254);
        locate(46, 16); printf("%c", 254);
        break;

    case 3:
        locate(42, 18); printf("%c", 254);
        locate(44, 17); printf("%c", 254);
        locate(46, 16); printf("%c", 254);
        break;

    case 4:
        locate(42, 16); printf("%c", 254);
        locate(46, 16); printf("%c", 254);
        locate(42, 18); printf("%c", 254);
        locate(46, 18); printf("%c", 254);
        break;

    case 5:
        locate(42, 16); printf("%c", 254);
        locate(46, 16); printf("%c", 254);
        locate(44, 17); printf("%c", 254);
        locate(42, 18); printf("%c", 254);
        locate(46, 18); printf("%c", 254);
        break;

    case 6:
        locate(42, 16); printf("%c", 254);
        locate(46, 16); printf("%c", 254);
        locate(42, 17); printf("%c", 254);
        locate(46, 17); printf("%c", 254);
        locate(42, 18); printf("%c", 254);
        locate(46, 18); printf("%c", 254);
        break;
    }
}



void Rectangulo(int X, int Y, int Ancho, int Alto){      /// Recuadros.
    for(int I=X; I<=X+Ancho; I++){
        gotoxy(I, Y);
        cout<<"*";
    }
    for(int I=X; I<=X+Ancho; I++){
        gotoxy(I, Y+Alto);
        cout<<"*";
    }
    for(int I=Y; I<=Y+Alto; I++){
        gotoxy(X, I);
        cout<<"*";
        gotoxy(X+Ancho, I);
        cout<<"*";
    }
}


void Say(int X,int Y,const char *txt){         /// Posicionar el texto.
	Gotoxy(X,Y);printf("%s",txt);
}


void Gotoxy(int X, int Y){            /// Para que funcione el Say.
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = X;
  dwPos.Y= Y;
  SetConsoleCursorPosition(hcon,dwPos);
}


#endif // FUNCIONES_ESTETICAS_H_INCLUDED
