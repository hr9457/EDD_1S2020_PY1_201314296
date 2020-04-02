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
        int tamanio;

    public:
        Cola();
        nodoCola * getPrimero();
        void setPrimero();
        nodoCola * getUltimo();
        void setUltimo();
        bool estadoCola();
        int getSize();
        void insertarLetra(int num, string arg);
        string getLetraPrimero();
        void eliminarLetra(int&,string&);
        void generarDot();
        void generarPNG();
        void abrirPNG();
        void imprimir();
        ~Cola();
};

#endif