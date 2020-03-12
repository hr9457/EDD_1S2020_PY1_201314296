#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "nodoArbol.h"
#include "iostream"
#include "string"
#include "fstream"
#include "windows.h"
using namespace std;

class arbolBinario
{
    private:
        nodoArbol *root;//raiz del arbol
    public:        
        ofstream archivo;
        arbolBinario();
        bool estadoArbol();
        nodoArbol * getRoot();
        void setRoot();
        void buscarInsert(nodoArbol *puntero,string);
        void insertarJugador(string);
        void recorrerArbol(nodoArbol *inicio);
        void recorrerArbol2(nodoArbol *inicio);
        void buscarNodo();
        void generarDot();
        void generarPNG();
        ~arbolBinario();
};

#endif