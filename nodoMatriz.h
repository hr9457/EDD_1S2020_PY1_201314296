#ifndef NODOMATRIZ_h
#define NODOMATRIZ_h

#include "iostream"
#include "string"
using namespace std;

class nodoMatriz
{
    private:
        int tipoCasilla;//0-simples , 1-doble y 2-triples
        string palabra;
        int puntaje;
        int posX;
        int posY;
        //apuntadores
        nodoMatriz *siguiente;
        nodoMatriz *anterior;
        nodoMatriz *arriba;
        nodoMatriz *abajo;

    public:
        nodoMatriz(int,string,int,int,int);
        int getTipoCasilla();
        void setTipoCasilla(int);
        string getPalabra();
        void setPalabra(string);
        int getPuntaje();
        void setPuntaje(int);
        int getPosx();
        void setPosx(int);
        int getPosy();
        void setPosy(int);
        nodoMatriz * getSiguiente();
        void setSiguiente(nodoMatriz *);
        nodoMatriz * getAnterior();
        void setAnterior(nodoMatriz *);
        nodoMatriz * getArriba();
        void setArriba(nodoMatriz *);
        nodoMatriz * getAbajo();
        void setAbajo(nodoMatriz *);
        ~nodoMatriz();
};

#endif