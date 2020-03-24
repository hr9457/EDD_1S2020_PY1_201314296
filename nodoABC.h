#ifndef NODOABC_H
#define NODOABC_H

#include "iostream"
#include "string"
using namespace std;

class nodoABC
{
    private:
        int puntuacion;
        string letra;
        int cantidad;
        nodoABC *siguiente;
        nodoABC *anterior;

    public:
        nodoABC(int,string,int);

        int getPuntuacion();
        void setPuntuacion(int);

        string getLetra();
        void setLetra(string);

        int getCantidad();
        void setCantidad(int);

        nodoABC * getSiguiente();
        void setSiguiente(nodoABC *);

        nodoABC * getAnterior();
        void setAnterior(nodoABC *);

        ~nodoABC();
};

#endif