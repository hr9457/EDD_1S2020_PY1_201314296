#ifndef NODOARBOL_H
#define NODOARBOL_H

#include "iostream"
#include "string"
using namespace std;

class nodoArbol
{
    private:
        string nombreJugador;
        nodoArbol *derecha;
        nodoArbol *izquierda;

    public:
        nodoArbol(string arg);
        string getNombreJugador();
        void setNombreJugador(string arg);
        nodoArbol * getDerecha();
        void setDerecha(nodoArbol *puntero);
        nodoArbol * getIzquierda();
        void setIzquierda(nodoArbol *puntero);
        ~nodoArbol();
};


#endif