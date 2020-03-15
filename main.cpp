
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
    matriz.insertarNodo('h',10,4);
    matriz.insertarNodo('o',8,5);
    matriz.insertarNodo('s',9,5);
    matriz.insertarNodo('o',10,5);
    matriz.insertarNodo('l',10,6);
    matriz.insertarNodo('a',10,7);

    matriz.imprimirColumnas();
    cout<<endl;
    matriz.imprimirFilas();
    cout<<endl;
    cout<<"--------------------------"<<endl;
    matriz.imprimirMatriz();
    getch();
    return 0;
}