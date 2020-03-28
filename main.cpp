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

    //ventana principal;  

    /*
    int size = 5;
    while(size>0)
    {
        srand((unsigned)time(0)); 
        int i;
        i = (rand()%size); 
        cout << i << "\n";        
        size--;
    }
    getch();
    */
    



    
    /*
    listaDoble lista;
    //-----------------MENU PROVICIONAL
    int entradaTeclado;    
    do
    {
        cout<<"1. Ingresar ficha en la lista"<<endl;
        cout<<"2. Imprimir elementos de la lista"<<endl;
        cout<<"3. Eliminar ficha de la lista"<<endl;
        cout<<"4. Salir"<<endl;
        entradaTeclado = getch();
        
        if(entradaTeclado==49)
        {
            string letra;
            int num;
            cout<<"ingrese la letra"<<endl;
            cin>>letra;  
            cout<<"ingres puntaje"<<endl;
            cin>>num;
            lista.insertaFicha(letra,num); 
        }
        else if(entradaTeclado==50)
        {
            lista.generarDOT("hector");
            lista.generarPNG();
            lista.abrirPNG();
        }
        else if(entradaTeclado==51)
        {
            string letraEliminar;
            cout<<"ingrese la letra de la ficha"<<endl;
            cin>>letraEliminar;
            lista.eliminarFicha(letraEliminar);
        }
       
    } while (entradaTeclado!=52);
    */
    



    
    //matrizDispersa matriz;    
    
    //------------------pruba cond datos en la matriz 
    //------------------ingresar datos,simples, dobles y triples
    //-------------------sustitucion con una casilla existente
    matrizDispersa matriz; 
    matriz.insertarNodo(0,"H",0,10,4);
    matriz.insertarNodo(0,"O",0,8,5);
    matriz.insertarNodo(1,"",0,9,5);
    matriz.insertarNodo(2,"O",0,10,5);
    matriz.insertarNodo(0,"L",0,10,6);
    matriz.insertarNodo(0,"A",0,10,7);
    matriz.insertarNodo(2,"J",0,11,3);
    matriz.insertarNodo(1,"S",0,9,5);

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


    /*
    ----------------------------------prueba para el arbol
    arbolBinario arbol;
    arbol.insertarJugador("heidy");
    arbol.insertarJugador("carlos");
    arbol.insertarJugador("antonio");
    arbol.insertarJugador("eduardo");
    arbol.insertarJugador("rodrigo");
    arbol.generarDot();
    arbol.generarPNG(); 

    arbol.generarDotPreorden();
    arbol.generarPNGPreorden();
    
    arbol.generarDotInorden();
    arbol.generarPNGInorden();
    arbol.generarDotPostorden();
    arbol.generarPNGPostorden();

    */
    return 0;
}