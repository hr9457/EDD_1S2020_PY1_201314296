#include "nodoListaDoble.h"

nodoListaDoble::nodoListaDoble(string caracter,int num,int posx,int posy){
    this->letra = caracter;
    this->puntaje = num;
    this->posx = posx;
    this->posy = posy;
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

int nodoListaDoble::getPuntaje()
{
    return puntaje;
}

void nodoListaDoble::setPuntaje(int num)
{
    this->puntaje = num;
}


int nodoListaDoble::getPosx()
{
    return posx;
}

void nodoListaDoble::setPosx(int num)
{
    this->posx = num;
}

int nodoListaDoble::getPosy()
{
    return posy;
}

void nodoListaDoble::setPosy(int num)
{
    this->posy = num;
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