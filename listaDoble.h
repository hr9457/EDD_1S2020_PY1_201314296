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
        int sizeJugada=0;

    public:
        listaDoble();
        bool estdoLista();
        nodoListaDoble * getPrimero();
        void setPrimero(nodoListaDoble *);
        nodoListaDoble * getUltimo();
        void setUltimo(nodoListaDoble *);
        void insertaFicha(string,int,int,int);
        void eliminarFicha(string,int&);
        void eliminarUltimo(string &,int &,int &,int &);
        int getSize();
        int getPosx();
        void setPosx(int);
        int getPosy();
        void setPosy(int);
        void setSize(int);
        void imprimir();        
        void generarDOT(string);
        void generarPNG();
        void abrirPNG();
        ~listaDoble();
};

#endif