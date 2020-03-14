#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

#include "nodoMatriz.h"
#include "iostream"
#include "string"
using namespace std;

class matrizDispersa
{
    private:
        nodoMatriz *root;
        nodoMatriz *inicioColumnas;
        nodoMatriz *finalColumnas;
        nodoMatriz *inicioFilas;
        nodoMatriz *finalFilas;
        
    public:
        matrizDispersa();
        bool estadoMatriz();
        void insertarEnColumna(int);
        void insertarEnFila(int);
        void insertarCasillaPuntuacion(string,char,int,int);
        void insertarNodo(char,int,int);
        void imprimirColumnas();
        void imprimirFilas();
        ~matrizDispersa();
};

#endif