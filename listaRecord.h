#ifndef LISTARECORD_H
#define LISTARECORD_H

#include "nodoRecord.h"
#include "iostream"
#include "string"
#include "fstream"
#include "windows.h"
using namespace std;

class listaRecord
{
    private:
        nodoRecord *primero;
        nodoRecord *ultimo;
        int tamanioLista=0;

    public:
        listaRecord();
        int getSize();
        void setSize(int);
        bool estadoLista();
        void buscar(string,nodoRecord *&);
        void insertar(string,int);
        void insertarUltimo(string,int);
        void ordenamientoBurbuja();
        void generarDOTGeneral();
        void generarDOTINDIVIDUAL();
        void generarPNGGeneral();
        void abrirPNGGeneral();
        ~listaRecord();
};

#endif