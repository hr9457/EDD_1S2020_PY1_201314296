#ifndef NODOARBOL_H
#define NODOARBOL_H

#include "iostream"
#include "string"
#include "listaRecord.h"
using namespace std;

class nodoArbol
{
    private:
        string nombreJugador;
        int puntaje;
        nodoArbol *derecha;
        nodoArbol *izquierda;
        listaRecord lista;//lista como atributo de cada nodo-

    public:
        nodoArbol(string arg, int);
        string getNombreJugador();
        void setNombreJugador(string arg);
        int getPuntaje();
        void setPuntaje(int);
        nodoArbol * getDerecha();
        void setDerecha(nodoArbol *puntero);
        nodoArbol * getIzquierda();
        void setIzquierda(nodoArbol *puntero);
        ~nodoArbol();
};


#endif