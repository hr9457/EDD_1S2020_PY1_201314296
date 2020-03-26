#ifndef NODOLISTADOBLE_H
#define NODOLISTADOBLE_H

#include "iostream"
#include "string"
using namespace std;


class nodoListaDoble
{
    private:
        string letra;
        int puntaje;
        nodoListaDoble *siguiente;
        nodoListaDoble *anterior;

    public:
        nodoListaDoble(string,int);
        string getLetra();
        void setLetra(string);
        int getPuntaje();
        void setPuntaje(int);
        nodoListaDoble * getSiguiente();
        void setSiguiente(nodoListaDoble *);
        nodoListaDoble * getAnterior();
        void setAnterior(nodoListaDoble *);
        ~nodoListaDoble();
};


#endif