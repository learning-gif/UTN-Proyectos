/*

23) Se ingresan los datos de los 10 art�culos que vende una empresa. Cada registro
contiene:
- N�mero de art�culo (1 a 10)
- Precio Unitario
- Clase de art�culo (1, 2 o 3)
Se pide determinar e informar:
a) El n�mero del art�culo m�s caro para cada una de las 3 clases. Se listan 3 resultados, uno
para cada una de las 3 clases.
b) La clase de art�culo con el mayor precio promedio.

*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int numArt, preUnit, claseArt;

for(int i=1; i<10; i++)
{
    cout << "Ingrese N�mero de art�culo:" << endl;
    cin numArt;

    cout << "Ingrese Precio Unitario:" << endl;
    cin preUnit;

    cout << "Ingrese Clase de art�culo:" << endl;
    cin claseArt;

}

  system("pause");
  return 0;
}