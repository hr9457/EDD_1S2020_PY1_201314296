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


void Cola::insertarLetra(int num, char arg)
{
    nodoCola *nodoTemporal = new nodoCola(num,arg);
    if (estadoCola() == true)
    {
        primero = nodoTemporal;
        ultimo = nodoTemporal;
    }
    else
    {
        ultimo->setSiguiente(nodoTemporal);
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
    //para la colocacion de los nodos
    if (estadoCola() == true)
    {}
    else
    {
        nodoCola *nodoTemporal = primero;
        while (nodoTemporal != NULL)
        {
            archivo<<"Nodo"<<numeroNodo<<"[shape=record,label=\"{"<<
            nodoTemporal->getLetra()<<"|<next>}\"];"<<endl;
            nodoTemporal = nodoTemporal->getSiguiente();
            numeroNodo = numeroNodo + 1;
        }
        
    }

    //anidacion de los nodos
    for (int i = 0; i < numeroNodo-1; i++)
    {
        archivo<<"Nodo"<<i<<"->Nodo"<<i+1<<";"<<endl;
    }    
    //fin del archivo
    archivo<<"}"<<endl;
    archivo.close();
}

void Cola::generarPNG()
{
    system("dot.exe -Tpng ArchivosDot\\Cola.dot -o Reportes\\Cola.png");
}

void Cola::imprimir(){
    nodoCola *nodoAuxiliar = primero;
    cout<<"<---"<<nodoAuxiliar->getLetra()<<"--->"<<endl;
    nodoAuxiliar = nodoAuxiliar->getSiguiente();
    cout<<"<---"<<nodoAuxiliar->getLetra()<<"--->"<<endl;
    nodoAuxiliar = nodoAuxiliar->getSiguiente();
    /*
    if(estadoCola()==true){        
    }
    else
    {
        nodoCola *nodoAuxiliar = primero;
        while (nodoAuxiliar != NULL)
        {
            cout<<"<---"<<nodoAuxiliar->getLetra()<<"--->"<<endl;
            nodoAuxiliar = nodoAuxiliar->getSiguiente();
        }
        
    }
    */
    
}


Cola::~Cola(){}

