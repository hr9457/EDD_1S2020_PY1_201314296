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

//METODO MAIN PARA ARRAQUE DEL SCRABBLE
int main(){
    ventana ventanainicio;
    /*
    matrizDispersa matriz;    
    
    //------------------pruba cond datos en la matriz 
    //------------------ingresar datos,simples, dobles y triples
    //-------------------sustitucion con una casilla existente
    matriz.insertarNodo(1,"",0,2,5);
    matriz.insertarNodo(1,"",5,10,15);
    matriz.insertarNodo(2,"",0,0,1);
    int entradaTeclado;    
    do
    {
        cout<<"1. Insertar ficha"<<endl;
        cout<<"2. Eliminar ficha"<<endl;
        cout<<"3. Mostrar matriz"<<endl;
        cout<<"4. Buscar Nodo"<<endl;
        cout<<"Salir-Esc"<<endl;
        entradaTeclado = getch();
        
        if(entradaTeclado==49)
        {
            string letra;
            int posx,posy;
            cout<<"ingrese la letra que quiere insertar: ";
            cin>>letra;
            cout<<"ingres la posicion en x: ";
            cin>>posx;
            cout<<"ingrese la posicion en y: ";
            cin>>posy;
            matriz.insertarNodo(0,letra,1,posx,posy);
        }
        else if(entradaTeclado==50)
        {
            int posx,posy;
            cout<<"ingres la posicion en x: ";
            cin>>posx;
            cout<<"ingrese la posicion en y: ";
            cin>>posy;
            matriz.eliminarNodo(posx,posy);
        }
        else if(entradaTeclado==51)
        {
            matriz.crearDOT();
            matriz.crearPNG();
            matriz.abrirPNG();
        }
       
    } while (entradaTeclado!=27);
    */
    return 0;
}