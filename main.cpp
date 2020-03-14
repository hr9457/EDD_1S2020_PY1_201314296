
//IMPORTACIONES
#include "iostream"
#include "windows.h"
#include "conio.h"
using namespace std;
#include "listaCircular.h"
#include "Cola.h"
#include "arbolBinario.h"
#include "matrizDispersa.h"

//METODO MAIN PARA ARRAQUE DEL SCRABBLE
int main(){
    matrizDispersa matriz;    
    matriz.insertarNodo('a',2,1);
    matriz.insertarNodo('a',3,1);
    matriz.insertarNodo('a',3,1);
    matriz.insertarNodo('a',1,1);

    matriz.insertarNodo('a',2,2);
    matriz.insertarNodo('a',3,3);
    matriz.insertarNodo('a',3,3);
    matriz.insertarNodo('a',1,1);

    matriz.imprimirColumnas();
    cout<<endl;
    matriz.imprimirFilas();
    cout<<endl;
    cout<<"hola mundo"<<endl;
    getch();
    return 0;
}