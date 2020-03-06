
//IMPORTACIONES
#include "iostream"
#include "windows.h"
#include "conio.h"
using namespace std;
#include "listaCircular.h"
#include "Cola.h"

//METODO MAIN PARA ARRAQUE DEL SCRABBLE
int main(){ 
    Cola cola;
    cola.insertarLetra(2,'D');
    cola.insertarLetra(3,'B');
    cola.insertarLetra(3,'P');
    cola.insertarLetra(1,'A');
    cola.insertarLetra(4,'H');
    cola.insertarLetra(4,'V');
    cola.imprimir();
    cola.generarDot();
    cola.generarPNG();
    cout<<"hola mundo"<<endl;
    getch();
    return 0;
}