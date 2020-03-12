#include "nodoMatriz.h"

//constructor
nodoMatriz::nodoMatriz(char arg,int num, int num2){
    this->palabra = arg;
    this->posX = num;
    this->posY = num2;
    this->siguiente = NULL;
    this->anterior = NULL;
    this->arriba = NULL;
    this->abajo = NULL;
}

//metodo get y set 
//para palabra
string nodoMatriz::getTipoCasilla()
{
    return tipoCasilla;
}

void nodoMatriz::setTipoCasilla(string tipo)
{
    this->tipoCasilla = tipo;
}

char nodoMatriz::getPalabra()
{
    return palabra;
}

void nodoMatriz::setPalabra(char arg)
{
    this->palabra = arg;
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