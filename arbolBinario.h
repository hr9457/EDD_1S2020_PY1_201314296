#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "nodoArbol.h"
#include "iostream"
#include "conio.h"
#include "string"
#include "fstream"
#include "windows.h"
using namespace std;

class arbolBinario
{
    private:
        nodoArbol *root;//raiz del arbol
        nodoArbol *auxRoot=root;
        int nodoPostorden=0;
        int nodoPreorden=0;
        int nodoInorden=0;

    public:        
        ofstream archivo;
        arbolBinario();
        bool estadoArbol();
        nodoArbol * getRoot();
        void setRoot();
        void buscarInsert(nodoArbol *puntero,string);
        void insertarJugador(string);
        
        void buscarNodo(nodoArbol *,string,nodoArbol *);
        void insertaPuntaje(string,int);
        void puntajeOrdenado(string);
        

        void recorrerArbol(nodoArbol *inicio);
        void recorrerArbol2(nodoArbol *inicio);
                

        void generarDot();
        void generarPNG();
        void abrirPNG();
        void buscar(nodoArbol *, string,bool&);
        bool buscarEnArbol(string);

        //-----Metodos para los diferentes tipos de recorridos
        void Preorden(nodoArbol *);
        void generarDotPreorden();
        void generarPNGPreorden();
        void abrirPNGPreorden();

        //-----------------------
        void Inorden(nodoArbol *);
        void generarDotInorden();
        void generarPNGInorden();
        void abrirPNGInorden();

        //------------------------
        void Postorden(nodoArbol *);
        void generarDotPostorden();
        void generarPNGPostorden();
        void abrirPNGPostorden();
        //-------------------------

        void impresionInorden(nodoArbol *);
        ~arbolBinario();
};

#endif