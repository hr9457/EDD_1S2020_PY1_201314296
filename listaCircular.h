#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

//IMPORTACIONES DE USO
#include "nodoCircular.h"
#include "iostream"
#include "string"
#include "fstream"
#include "windows.h"
#include "conio.h"
using namespace std;

class listaCircular
{
    private:
        nodoCircular *primero;
        nodoCircular *ultimo;
        
    public:
        listaCircular();
        bool estadoLista();
        void insertar(string arg);
        void buscar(string,bool &);
        void imprimir();
        void generarDot();
        void generarPNG();
        void aperturaImagen();
        ~listaCircular();
};


#endif