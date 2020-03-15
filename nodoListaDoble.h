#ifndef NODOLISTADOBLE_H
#define NODOLISTADOBLE_H

#include "iostream"
#include "string"
using namespace std;


class nodoListaDoble
{
    private:
        string letra;
        nodoListaDoble *siguiente;
        nodoListaDoble *anterior;
    public:
        nodoListaDoble(string);
        string getLetra();
        void setLetra(string);
        nodoListaDoble * getSiguiente();
        void setSiguiente(nodoListaDoble *);
        nodoListaDoble * getAnterior();
        void setAnterior(nodoListaDoble *);
        ~nodoListaDoble();
};


#endif