
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
    matriz.insertarNodo('a',1,1);
    matriz.insertarNodo('a',2,1);
    matriz.imprimirColumnas();
    cout<<endl;
    cout<<"hola mundo"<<endl;
    getch();
    return 0;
}