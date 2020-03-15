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
        nodoMatriz * insertarEnColumna(int);//insertar en columnas
        nodoMatriz * insertarEnFila(int);//insertar en filas
        void insertarCasillaPuntuacion(string,char,int,int);//insertar columna casilla puntos
        void anidarInformacionColumna(nodoMatriz *,nodoMatriz *);
        void anidarInforamcionFila(nodoMatriz *,nodoMatriz *);
        void insertarNodo(char,int,int);//insertar un nodo como tal
        void imprimirColumnas();
        void imprimirFilas();
        void impresionPorFilas(nodoMatriz *);
        void impresionPorColumnas(nodoMatriz *);
        void imprimirMatriz();
        void crearDOT();
        ~matrizDispersa();
};

#endif