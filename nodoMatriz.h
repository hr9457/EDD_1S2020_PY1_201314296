#ifndef NODOMATRIZ_h
#define NODOMATRIZ_h

#include "iostream"
#include "string"
using namespace std;

class nodoMatriz
{
    private:
        string tipoCasilla;
        char palabra;
        int posX;
        int posY;
        nodoMatriz *siguiente;
        nodoMatriz *anterior;
        nodoMatriz *arriba;
        nodoMatriz *abajo;

    public:
        nodoMatriz(string,char,int,int);
        string getTipoCasilla();
        void setTipoCasilla(string);
        char getPalabra();
        void setPalabra(char);
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