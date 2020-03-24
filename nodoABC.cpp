#include "nodoABC.h"


//----- constructor
nodoABC::nodoABC(int num,string arg,int num2)
{
    this->puntuacion = num;
    this->letra = arg;
    this->cantidad = num2;
    this->siguiente = NULL;
    this->anterior = NULL;
}

//------ metodos get y set
int nodoABC::getPuntuacion()
{
    return puntuacion;
}

void nodoABC::setPuntuacion(int num)
{
    this->puntuacion = num;
}

string nodoABC::getLetra()
{
    return letra;
}

void nodoABC::setLetra(string arg)
{
    this->letra = arg;
}

int nodoABC::getCantidad()
{
    return cantidad;
}

void nodoABC::setCantidad(int num2)
{
    this->cantidad = num2;
}


nodoABC * nodoABC::getSiguiente()
{
    return siguiente;
}

void nodoABC::setSiguiente(nodoABC *puntero)
{
    this->siguiente = puntero;
}



nodoABC * nodoABC::getAnterior()
{
    return anterior;
}

void nodoABC::setAnterior(nodoABC *puntero)
{
    this->anterior = puntero;
}


//------ destructor
nodoABC::~nodoABC(){}