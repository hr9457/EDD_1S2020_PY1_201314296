#include "listaDoble.h"

listaDoble::listaDoble()
{
    this->primero = NULL;
    this->ultimo = NULL;
}


//----------------- metodo para saber el estdo de la lista
bool listaDoble::estdoLista()
{
    if(primero==NULL && ultimo==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }    
}



//--------------------- metodo para insertar una ficha en la lista
void listaDoble::insertaFicha(string caracter,int num)
{
    nodoListaDoble *nodoTemporal = new nodoListaDoble(caracter,num);
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



//-------------------------- metodo para eliminar de la lista
void listaDoble::eliminarFicha(string letra)
{
    nodoListaDoble *nodoAuxiliar = primero;
    while(nodoAuxiliar!=NULL)
    {
        if(letra==nodoAuxiliar->getLetra())
        {
            if(nodoAuxiliar==primero)
            {                
            }
            else if(nodoAuxiliar==ultimo)
            {                
            }
            else
            {                
            }
            break;
        }
        nodoAuxiliar = nodoAuxiliar->getSiguiente();
    }
}




//-------------------- METODOS PARA GENERA LOS REPORTES 
void listaDoble::generarDOT(string nombreJugador)
{    
    if(estdoLista()!=true)
    {
        int numeroNodo = 0;//colocacion deun indice
        ofstream archivo("ArchivosDot\\ListaJugador.dot");
        archivo<<"digraph Lista {"<<endl;
        archivo<<"rankdir=LR;"<<endl;
        archivo<<"node [shape=record];"<<endl;
        nodoListaDoble *nodoTemporal = primero;
        while (nodoTemporal!=NULL)
        {
            archivo<<"Nodo"<<numeroNodo<<"[label=\""<<
            nodoTemporal->getLetra()<<"  X"<<nodoTemporal->getPuntaje()<<"pts\"]"<<endl;
            nodoTemporal = nodoTemporal->getSiguiente();
            numeroNodo = numeroNodo + 1;   
        }

        //anidacion de los nodos
        for(int i=0;i<numeroNodo-1;i++)
        {
            archivo<<"Nodo"<<i<<"->Nodo"<<i+1<<"[dir=both];"<<endl;
        }
        archivo<<"label=\""<<nombreJugador<<"\";"<<endl;      
        archivo<<"}"<<endl;
        archivo.close();
    }
}


void listaDoble::generarPNG()
{
    system("dot.exe -Tpng ArchivosDot\\ListaJugador.dot -o Reportes\\ListaJugador.png");
}



void listaDoble::abrirPNG()
{
    system("Reportes\\ListaJugador.png");
}



listaDoble::~listaDoble(){}
