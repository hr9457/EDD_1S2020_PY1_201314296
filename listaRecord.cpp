#include "listaRecord.h"

//contructor
listaRecord::listaRecord(){}


//estado de la lista
bool listaRecord::estadoLista()
{
    if(primero==NULL && ultimo==NULL){return true;}
    else{return false;}
}

//tamanio lista
int listaRecord::getSize()
{return tamanioLista;}

void listaRecord::setSize(int num)
{this->tamanioLista=num;}



//buscar
nodoRecord * listaRecord::buscar(string nombre)
{
    nodoRecord *auxPrimero = primero;
    while (auxPrimero!=NULL)
    {
        if(nombre==auxPrimero->getNombreUsuario())
        {
            return auxPrimero;
            break;
        }
        else
        {
            return NULL;
            auxPrimero->getSiguiente(); 
        }          
    }
    return NULL;    
}




//insertar
void listaRecord::insertar(string nombre,int puntaje)
{
    nodoRecord *nodoTemporal = new nodoRecord(nombre,puntaje);
    if(estadoLista()==true)
    {
        primero=nodoTemporal;
        ultimo=nodoTemporal;
        tamanioLista = tamanioLista+1;
    }
    else
    {
        ultimo->setSiguiente(nodoTemporal);
        nodoTemporal->setAnterior(ultimo);
        ultimo = nodoTemporal;
        tamanioLista = tamanioLista+1;
    }    
}



//forma de ordenar la lista por el ordenamiento burbuja
void listaRecord::ordenamientoBurbuja()
{
    int tamanioActuaLista = getSize();
    nodoRecord *auxPrimero=primero;
    for(int i=0;i<tamanioActuaLista-1;i++)
    {
        
    }
}




//destructor
listaRecord::~listaRecord(){}