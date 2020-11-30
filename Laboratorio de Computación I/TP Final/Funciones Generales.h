#ifndef FUNCIONES_GENERALES_H_INCLUDED
#define FUNCIONES_GENERALES_H_INCLUDED

void MostrarVector(int V[], int Tam); /// Muestra el vector del tipo entero.

void CargarNombre(char V[]); /// Carga el vector del tipo char.

void MostrarNombre(char V[]); /// Muestra el vector del tipo char.

void CargarVector(int V[], int Tam); /// Carga el vector del tipo entero.

int ContarNumerosRepetidos(int V[], int Numero , int Tam); /// Cuenta la cantidad de veces que se repite un número en el vector.

int MaximoVector(int V[], int Tam); /// Devuelve  la posición (primera) que ocupa el máximo en el vector.

void CargarAleatorio(int V[], int Tam, int Limite); /// Asigna valores aleatorios al vector.

void OrdenarVector(int V[], int Tam); /// Ordena de menor a mayor un vector.

int SumarVector(int V[], int Tam); /// Suma los valores contenidos en el vector.

void CopiarVectorNombre(char V[], char V2[], int Tam); /// Copia el vector V en V2 para los nombres.


/// Desarrollo de funciones generales.


void OrdenarVector(int V[], int Tam ){
    int PosMin, Aux;
    for(int I=0;I<Tam-1;I++){
        PosMin=I;
        for(int J=I+1;J<Tam;J++){
        if(V[J]<V[PosMin]) PosMin=J;
        }
        Aux=V[I];
        V[I]=V[PosMin];
        V[PosMin]=Aux;
    }
}

int MaximoVector(int V[], int Tam){
    int PosMax=0;
    for(int I=1;I<Tam;I++){
        if(V[I]>V[PosMax]) {
            PosMax=I;
        }
    }
    return PosMax;
}

void CargarAleatorio(int V[], int Tam, int Limite){
  srand(time(NULL));
    for(int I=0; I<Tam; I++){
        V[I]=(rand()%Limite)+1;
    }
}

void MostrarVector(int V[], int Tam){
    for(int I=0;I<Tam;I++){
        cout<<V[I]<<"\n";
    }
    cout<<endl;
}

int ContarNumerosRepetidos(int V[], int Numero, int Tam){
    int Cant=0;
    for(int I=0;I<Tam;I++){
        if(V[I]==Numero) Cant++;
    }
    return Cant;
}

int SumarVector(int V[], int Tam ){
    int Suma=0;
    for(int I=0;I<Tam;I++){
        Suma+=V[I];
    }
    return Suma;
}

void CopiarVectorNombre(char V[], char V2[], int Tam){
    for(int I=0;I<Tam;I++){
        V2[I]=V[I];
    }
}

void CargarVector(int V[], int Tam){
    Rectangulo(5,4,28,6);
    for(int I=0;I<Tam;I++){
        Say(10,I+5,"Ingresar Dado: "); cin>>V[I];
    }
}

void CargarNombre(char V[]){
    cin>>V;
}

void MostrarNombre(char V[]){
    cout<<V<<'\t';
    cout<<endl;
}

#endif // FUNCIONES_GENERALES_H_INCLUDED