#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "nodoListaDoble.h"
#include "iostream"
#include "fstream"
#include "windows.h"
using namespace std;

class listaDoble
{
    private:
        nodoListaDoble *primero;
        nodoListaDoble *ultimo;
        int size=0;

    public:
        listaDoble();
        bool estdoLista();
        void insertaFicha(string,int);
        void eliminarFicha(string);
        int getSize();
        void setSize(int);
        void imprimir();
        void generarDOT(string);
        void generarPNG();
        void abrirPNG();
        ~listaDoble();
};

#endif