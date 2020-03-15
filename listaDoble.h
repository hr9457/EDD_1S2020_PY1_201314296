#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "nodoListaDoble.h"
#include "iostream"
using namespace std;

class listaDoble
{
    private:
        nodoListaDoble *primero;
        nodoListaDoble *ultimo;

    public:
        listaDoble();
        bool estdoLista();
        void insertaFicha(string);
        void eliminarFicha();
        void imprimirLista();
        ~listaDoble();
};

#endif