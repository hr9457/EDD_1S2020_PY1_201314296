#ifndef COLA_H
#define COLA_H

#include "nodoCola.h"
#include "iostream"
#include "string"
#include "windows.h"
#include "conio.h"
#include "fstream"
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
        bool estadoCola();
        void insertarLetra(int num, char arg);
        string getLetraPrimero();
        void eliminarLetra();
        void generarDot();
        void generarPNG();
        void imprimir();
        ~Cola();
};

#endif