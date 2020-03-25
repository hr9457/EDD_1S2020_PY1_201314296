#ifndef LISTAABC_H
#define LISTAABC_H

#include "iostream"
#include "string"
#include "nodoABC.h"
#include "nodoCola.h"
#include "Cola.h"
using namespace std;

class listaABC
{
    private:
        nodoABC *primero;
        nodoABC *ultimo;
        Cola colafichas;
        int size=0;

    public:
        listaABC();
        bool estadoLista();
        int getSize();
        void setSize(int);
        void insertar(int,string,int);
        void eliminar(int,int&,string&);
        void imprimirLista();
        void imprimirCola();
        ~listaABC();
};

#endif