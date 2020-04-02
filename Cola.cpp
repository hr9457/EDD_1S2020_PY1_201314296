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


//estado del tamanaio de la cola
int Cola::getSize()
{
    return tamanio;
}


void Cola::insertarLetra(int num, string arg)//puntaje y letra
{
    nodoCola *nodoTemporal = new nodoCola(num,arg);
    if (estadoCola() == true)
    {
        primero = nodoTemporal;
        ultimo = nodoTemporal;
        tamanio = tamanio +1;
    }
    else
    {
        ultimo->setSiguiente(nodoTemporal);
        ultimo = nodoTemporal;
        tamanio = tamanio +1;
    }    
}


//para retornar el valor del strin del primero para meterlo en la lista de jugador


//metodo para ir vaciando la cola
void Cola::eliminarLetra(int &puntaje,string &letra)
{    
    if(estadoCola() == true)
    {        
    }
    else
    {
        if(primero == ultimo)
        {
            puntaje = primero->getPuntuacion();
            letra = primero->getLetra();
            primero = NULL;
            ultimo = NULL;
            tamanio = tamanio -1;
        }   
        else
        {
            nodoCola *nodoAuxiiar = primero;
            puntaje = nodoAuxiiar->getPuntuacion();
            letra = nodoAuxiiar->getLetra();            
            primero = primero->getSiguiente();
            delete nodoAuxiiar;
            tamanio = tamanio -1;
        }        
    }
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
            nodoTemporal->getLetra()<<","<<nodoTemporal->getPuntuacion()<<"|<next>}\"];"<<endl;
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


void Cola::abrirPNG()
{
    system("Reportes\\Cola.png");
}

//----------- metodo para imprimir elemetos en la cola
void Cola::imprimir()
{
    nodoCola *auxPrimero = primero;
    while (auxPrimero != NULL)
    {
        cout<<"ficha: "<<auxPrimero->getLetra()<<" Puntaje: "<<auxPrimero->getPuntuacion()<<endl;
        auxPrimero = auxPrimero->getSiguiente();
    }    
}




nodoCola * Cola::getPrimero()
{
    return primero;
}
//----------destructor
Cola::~Cola(){}

