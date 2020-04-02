#ifndef LISTARECORD_H
#define LISTARECORD_H

#include "nodoRecord.h"
#include "iostream"
#include "string"
using namespace std;

class listaRecord
{
    private:
        nodoRecord *primero;
        nodoRecord *ultimo;
        int tamanioLista;

    public:
        listaRecord();
        int getSize();
        void setSize(int);
        bool estadoLista();
        nodoRecord * buscar(string);
        void insertar(string,int);
        void ordenamientoBurbuja();
        ~listaRecord();
};

#endif