#include "nodoMatriz.h"

//constructor
nodoMatriz::nodoMatriz(int tipo, string arg,int puntaje ,int num, int num2){
    this->tipoCasilla = tipo;
    this->palabra = arg;
    this->puntaje = puntaje;
    this->posX = num;
    this->posY = num2;
    this->siguiente = NULL;
    this->anterior = NULL;
    this->arriba = NULL;
    this->abajo = NULL;
}

//metodo get y set 
//para palabra
int nodoMatriz::getTipoCasilla()
{
    return tipoCasilla;
}

void nodoMatriz::setTipoCasilla(int tipo)
{
    this->tipoCasilla = tipo;
}

string nodoMatriz::getPalabra()
{
    return palabra;
}

void nodoMatriz::setPalabra(string arg)
{
    this->palabra = arg;
}

int nodoMatriz::getPuntaje()
{
    return puntaje;
}

void nodoMatriz::setPuntaje(int num)
{
    this->puntaje = num;
}

int nodoMatriz::getPosx()
{
    return posX;
}

void nodoMatriz::setPosx(int numX)
{
    this->posX = numX;
}

int nodoMatriz::getPosy()
{
    return posY;
}

void nodoMatriz::setPosy(int numY)
{
    this->posY = numY;
}

nodoMatriz * nodoMatriz::getSiguiente()
{
    return siguiente;
}

void nodoMatriz::setSiguiente(nodoMatriz *punteroSiguiente)
{
    this->siguiente = punteroSiguiente;
}

nodoMatriz * nodoMatriz::getAnterior()
{
    return anterior;
}

void nodoMatriz::setAnterior(nodoMatriz *punteroAnterior)
{
    this->anterior = punteroAnterior;
}

nodoMatriz * nodoMatriz::getArriba()
{
    return arriba;
}

void nodoMatriz::setArriba(nodoMatriz *punteroArriba)
{
    this->arriba = punteroArriba;
}

nodoMatriz * nodoMatriz::getAbajo(){
    return abajo;
}

void nodoMatriz::setAbajo(nodoMatriz *punteroAbajo)
{
    this->abajo = punteroAbajo;
}

//destructor
nodoMatriz::~nodoMatriz(){}