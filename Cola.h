#ifndef COLA_H
#define COLA_H

#include "nodoCola.h"
#include "iostream"
#include "string"
using namespace std;

class Cola
{
    private:
        nodoCola *primero;
        nodoCola *ultimo;

    public:
        Cola();
        nodoCola * getPrimero();
        void setPrimero();
        nodoCola * getUltimo();
        void setUltimo();
        void insertarLetra();
        void eliminarLetra();
        ~Cola();
};

#endif