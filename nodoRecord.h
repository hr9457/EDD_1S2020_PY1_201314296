#ifndef NODORECORD_H
#define NODORECORD_H

#include "iostream"
#include "string"
using namespace std;

class nodoRecord
{
    private:
        string nombreUsuario;
        int puntaje;
        nodoRecord *siguiente;
        nodoRecord *anterior;
        nodoRecord *abajo;

    public:
        nodoRecord(string,int);
        string getNombreUsuario();
        void setNombreUsuario(string);
        int getPuntaje();
        void setPuntaje(int);
        nodoRecord * getSiguiente();
        void setSiguiente(nodoRecord *);
        nodoRecord * getAnterior();
        void setAnterior(nodoRecord *);
        nodoRecord * getAbajo();
        void setAbajo(nodoRecord *);
        ~nodoRecord();
};

#endif