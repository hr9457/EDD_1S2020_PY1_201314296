#include "nodoListaDoble.h"

nodoListaDoble::nodoListaDoble(string caracter){
    this->letra = caracter;
    this->siguiente = NULL;
    this->anterior = NULL;
}

string nodoListaDoble::getLetra()
{
    return letra;
}

void nodoListaDoble::setLetra(string caracter)
{
    this->letra = caracter;
}

nodoListaDoble * nodoListaDoble::getSiguiente()
{
    return siguiente;
}

void nodoListaDoble::setSiguiente(nodoListaDoble *puntero)
{
    this->siguiente = puntero;
}

nodoListaDoble * nodoListaDoble::getAnterior()
{
    return anterior;
}

void nodoListaDoble::setAnterior(nodoListaDoble *puntero)
{
    this->anterior = puntero;
}

nodoListaDoble::~nodoListaDoble(){}