#include "listaDoble.h"

listaDoble::listaDoble()
{
    this->primero = NULL;
    this->ultimo = NULL;
}

bool listaDoble::estdoLista()
{
    if(primero=ultimo=NULL)
    {
        return true;
    }
    else
    {
        return false;
    }    
}

void listaDoble::insertaFicha(string caracter)
{
    nodoListaDoble *nodoTemporal = new nodoListaDoble(caracter);
    if(estdoLista() == true)
    {
        primero = nodoTemporal;
        ultimo = nodoTemporal;
    }
    else
    {
        ultimo->setSiguiente(nodoTemporal);
        nodoTemporal->setAnterior(ultimo); 
        ultimo = nodoTemporal;              
    }
    
}



listaDoble::~listaDoble()
{
    delete primero;
    delete ultimo;
}
