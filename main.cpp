//IMPORTACIONES
#include "iostream"
#include "cstdlib"
#include "ctime"
#include "string"
#include "windows.h"
#include "conio.h"
#include "json.hpp"
using namespace std;

#include "ventana.h"
#include "listaCircular.h"
#include "listaABC.h"
#include "Cola.h"
#include "arbolBinario.h"
#include "matrizDispersa.h"
#include "listaRecord.h"

//METODO MAIN PARA ARRAQUE DEL SCRABBLE
int main(){
    //ventana ventanainicio;

    arbolBinario arbol;
    
    int entradaTeclado;
    do
    {
        cout<<"1. Insertar jugador"<<endl;
        cout<<"2. Mostrar arbol"<<endl;
        cout<<"3. insertar puntaje"<<endl;
        cout<<"4. Mostar puntaje de jugador"<<endl;
        cout<<"Salir-Esc"<<endl;

        entradaTeclado = getch();        
        if(entradaTeclado==49)
        {
            string nombre;
            int puntaje;
            cout<<"ingrese el nombre del jugador: ";
            cin>>nombre;
            arbol.insertarJugador(nombre);
        }
        else if(entradaTeclado==50)
        {
            arbol.generarDot();
            arbol.generarPNG();
            arbol.abrirPNG();
        }
        else if(entradaTeclado==51)
        {
            string nombre;
            int puntaje;
            cout<<"ingrese el nombre del jugador: ";
            cin>>nombre;
            cout<<"ingrese el punaje del juagador";
            arbol.insertaPuntaje(nombre,puntaje);
        }
        else if(entradaTeclado==52)
        {
            string nombre;
            cout<<"ingrese el nombre del juagador: ";
            cin>>nombre;
            arbol.puntajeOrdenado(nombre);
        }
       
    } while (entradaTeclado!=27);
    

    return 0;
}