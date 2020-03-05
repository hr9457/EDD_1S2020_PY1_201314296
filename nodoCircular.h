#ifndef NODOCIRCULAR_H
#define NODOCIRCULAR_H

//IMPORTACIONES DE USO
#include "iostream"
#include "string"
using namespace std;

class nodoCircular
{
    private:
        string palabra;
        nodoCircular *siguiente;
        nodoCircular *anterior;

    public:
        nodoCircular(string argumento);
        string getPalabra();
        void setPalabra(string argumento);
        nodoCircular * getSiguiente();
        void setSiguiente(nodoCircular *puntero);
        nodoCircular * getAnterior();
        void setAnterior(nodoCircular *puntero);
        ~nodoCircular();
};


#endif