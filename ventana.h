#ifndef VENTANA_H
#define VENTANA_H

//----------impotaciones de librerias de uso interno
#include "iostream"
#include "string"
#include "windows.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "json.hpp"
#include "fstream"
#include "cstdlib"
#include "ctime"

//--------importaciones de mis estructruas
#include "listaCircular.h"
#include "listaABC.h"
#include "Cola.h"
#include "arbolBinario.h"
#include "nodoArbol.h"
#include "matrizDispersa.h"
#include "listaDoble.h"

using json = nlohmann::json;//para el archiv json
using namespace std;

class ventana
{
    private:
        //listaCircular bibliotecaDePalabras;//listado oficial que hay en archivo json
        //matrizDispersa matrizScrabble;
        arbolBinario arbol;//arbol de usuarios
        listaABC listaFichas;
        Cola colaFichas;//colas de las fichas random
        

        int centroMenu = 45 ;
        int lineaMenu = 5 ;
        int inKeyborad;
        string rutaArchivo;
        int dimensionMaxima;
        json JSON;
        string nuevoJugador;
        string jugador1;
        string jugador2;
        bool resultadoBusquedaJugador1=false;
        bool resultadoBusquedaJugador2=false;

    public:
        ventana();
        void gotoxy(int,int);
        void lecturaDeJson(json);
        void generarFichas();
        void opJugadores(int);
        void ventanaJugadores();
        void opReportes(int);
        void ventanaReportes();
        void ventanaJugar();
        void selecionJugador(int);
        void ventanaSelecionJugador();
        void menu();
        void opMenu(int);
        ~ventana();
};

#endif