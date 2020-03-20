//IMPORTACIONES
#include "iostream"
#include "windows.h"
#include "conio.h"
#include "json.hpp"
using namespace std;

#include "ventana.h"
#include "listaCircular.h"
#include "Cola.h"
#include "arbolBinario.h"
#include "matrizDispersa.h"

//METODO MAIN PARA ARRAQUE DEL SCRABBLE
int main(){    
    matrizDispersa matriz; 
    //ventana principal;   
    matriz.insertarNodo('h',10,4);
    matriz.insertarNodo('o',8,5);
    matriz.insertarNodo('s',9,5);
    matriz.insertarNodo('o',10,5);
    matriz.insertarNodo('l',10,6);
    matriz.insertarNodo('a',10,7);
    matriz.insertarNodo('j',11,3);

    matriz.imprimirColumnas();
    cout<<endl;
    matriz.imprimirFilas();
    cout<<endl;
    cout<<"--------------------------"<<endl;
    matriz.imprimirMatriz();
    matriz.crearDOT();
    matriz.crearPNG();
    matriz.abrirPNG();
    getch();
    return 0;
}