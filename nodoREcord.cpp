#include "nodoRecord.h"

//constructor
nodoRecord::nodoRecord(string arg, int num)
{
    this->nombreUsuario = arg;
    this->puntaje = num;
    this->siguiente = NULL;
    this->anterior = NULL;
    this->abajo = NULL;
}


//nombre usuario
string nodoRecord::getNombreUsuario()
{
    return nombreUsuario;
}

void nodoRecord::setNombreUsuario(string arg)
{
    this->nombreUsuario = arg;
}

//puntaje
int nodoRecord::getPuntaje()
{
    return puntaje;
}

void nodoRecord::setPuntaje(int num)
{
    this->puntaje = num;
}

//nodo siguientee
nodoRecord * nodoRecord::getSiguiente()
{
    return siguiente;
}

void nodoRecord::setSiguiente(nodoRecord *puntero)
{
    this->siguiente=puntero;
}


//anterior
nodoRecord * nodoRecord::getAnterior(){return anterior;}

void nodoRecord::setAnterior(nodoRecord *puntero){this->anterior=puntero;}



//abajo
nodoRecord * nodoRecord::getAbajo(){return abajo;}

void nodoRecord::setAbajo(nodoRecord *puntero){this->abajo=puntero;}


//destructor
nodoRecord::~nodoRecord(){}