#include "Cola.h"

Cola::Cola(){
    primero = NULL;
    ultimo = NULL;
}

bool Cola::estadoCola()
{
    if (primero == NULL && ultimo == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }  
}


void Cola::insertarLetra(int num, string arg)
{
    nodoCola *nodoTemporal = new nodoCola(num,arg);
    if (estadoCola() == true)
    {
        primero = nodoTemporal;
        ultimo = nodoTemporal;
    }
    else
    {
        primero->setSiguiente(nodoTemporal);
        ultimo = nodoTemporal;
    }    
}


void Cola::eliminarLetra()
{

}


void Cola::generarDot()
{
    int numeroNodo = 0;//colocacion deun indice
    ofstream archivo("ArchivosDot\\Cola.dot");
    archivo<<"digraph Cola {"<<endl;
    archivo<<"}"<<endl;
    archivo.close();
}

void Cola::generarPNG()
{

}


Cola::~Cola(){}

