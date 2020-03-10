
//IMPORTACIONES
#include "iostream"
#include "windows.h"
#include "conio.h"
using namespace std;
#include "listaCircular.h"
#include "Cola.h"
#include "arbolBinario.h"

//METODO MAIN PARA ARRAQUE DEL SCRABBLE
int main(){
    arbolBinario arbol;
    arbol.insertarJugador("Heidy");
    arbol.insertarJugador("Carlos");
    arbol.insertarJugador("Eduardo");
    arbol.insertarJugador("Rodrigo");
    arbol.insertarJugador("Antonio");
    arbol.generarDot();
    arbol.generarPNG();
    cout<<"hola mundo"<<endl;
    getch();
    return 0;
}