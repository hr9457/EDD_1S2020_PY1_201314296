#ifndef VENTANA_H
#define VENTANA_H

#include "iostream"
#include "string"
#include "windows.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "json.hpp"
#include "fstream"

//--------importaciones de mis estructruas
#include "listaCircular.h"
#include "Cola.h"
#include "arbolBinario.h"
#include "matrizDispersa.h"

using json = nlohmann::json;//para el archiv json
using namespace std;

class ventana
{
    private:
        int centroMenu = 45 ;
        int lineaMenu = 5 ;
        int inKeyborad;
        string rutaArchivo;
        int dimensionMaxima;

    public:
        ventana();
        void gotoxy(int,int);
        void menu();
        void opMenu(int);
        ~ventana();
};

#endif