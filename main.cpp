
//IMPORTACIONES
#include "iostream"
#include "windows.h"
#include "conio.h"
using namespace std;
#include "listaCircular.h"

//METODO MAIN PARA ARRAQUE DEL SCRABBLE
int main(){
    
    listaCircular lista;
    lista.insertar("hector");
    lista.insertar("josue");
    lista.insertar("orozco");
    lista.insertar("salazar");
    lista.generarDot();
    lista.generarPNG();
    
    cout<<"hola mundo"<<endl;
    getch();
    return 0;
}