#include "listaRecord.h"

//contructor
listaRecord::listaRecord()
{
    this->primero=NULL;
    this->ultimo=NULL;
}


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
void listaRecord::buscar(string nombre, nodoRecord *&nodoBusqueda)
{
    nodoRecord *auxPrimero = primero;
    while (auxPrimero!=NULL)
    {
        if(nombre==auxPrimero->getNombreUsuario())
        {
            nodoBusqueda=auxPrimero;
            break;
        }
        else
        {
            nodoBusqueda=NULL;
        }
        
        auxPrimero = auxPrimero->getSiguiente();        
    }  
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
        nodoRecord *nodoBusqueda;
        buscar(nombre,nodoBusqueda);
        if(nodoBusqueda==NULL)
        {
            ultimo->setSiguiente(nodoTemporal);
            nodoTemporal->setAnterior(ultimo);
            ultimo = nodoTemporal;
            tamanioLista = tamanioLista+1;
        }
        else
        {
            nodoBusqueda->setPuntaje(puntaje);
        }
    }    
}

//insertar de ultimo
void listaRecord::insertarUltimo(string nombre,int puntaje)
{
    nodoRecord *nodoTemporal = new nodoRecord(nombre,puntaje);
    if(estadoLista()==true)
    {
        primero=nodoTemporal;
        ultimo=nodoTemporal;
        tamanioLista=tamanioLista+1;
    }
    else
    {
        ultimo->setSiguiente(nodoTemporal);
        nodoTemporal->setAnterior(ultimo);
        ultimo=nodoTemporal;
        tamanioLista=tamanioLista+1;
    }    
}


//ordenamiento burbuja
void listaRecord::ordenamientoBurbuja()
{
    int tamanioLista = getSize();
    nodoRecord *auxprimero=primero;
    if(tamanioLista>1)
    {
        for(int i=0;i<tamanioLista-1;i++)
        {
            for(int j=0;j<tamanioLista-1;j++)
            {
                if(auxprimero->getPuntaje()>auxprimero->getSiguiente()->getPuntaje())
                {
                    string letraAuxiliar = auxprimero->getNombreUsuario();
                    int numAuxiliar = auxprimero->getPuntaje();                    

                    auxprimero->setNombreUsuario(auxprimero->getSiguiente()->getNombreUsuario());
                    auxprimero->setPuntaje(auxprimero->getSiguiente()->getPuntaje());
                    
                    auxprimero->getSiguiente()->setNombreUsuario(letraAuxiliar);
                    auxprimero->getSiguiente()->setPuntaje(numAuxiliar);
                }
                auxprimero = auxprimero->getSiguiente();
            }
            auxprimero = primero;
        }
    }
}


//metodo para generar los reportes en graphviz
void listaRecord::generarDOTGeneral()
{
    int numeroNodo = 0;//colocacion deun indice
    ofstream archivo("ArchivosDot\\scoreboardGeneral.dot");
    archivo<<"digraph Scoreboard {"<<endl;
    archivo<<"rankdir=LR;"<<endl;
    //para la colocacion de los nodos
    if (estadoLista() == true)
    {
        //fin del archivo
        archivo<<"}"<<endl;
        archivo.close();
    }
    else
    {
        nodoRecord *nodoTemporal = ultimo;
        while (nodoTemporal!=NULL)
        {
            archivo<<"Nodo"<<numeroNodo<<"[shape=record,label=\""<<
            nodoTemporal->getNombreUsuario()<<", "<<nodoTemporal->getPuntaje()<<"-Pts\"];"<<endl;
            nodoTemporal = nodoTemporal->getAnterior();
            numeroNodo = numeroNodo + 1;
        }
            //anidacion de los nodos
        for (int i = 0; i < numeroNodo-1; i++)
        {
            archivo<<"Nodo"<<i<<"->Nodo"<<i+1<<";"<<endl;
        }    
        //fin del archivo
        archivo<<"label=\"Scoreboard General\";"<<endl;
        archivo<<"}"<<endl;
        archivo.close();        
    }

    system("dot.exe -Tpng ArchivosDot\\scoreboardGeneral.dot -o Reportes\\scoreboardGeneral.png");
    system("Reportes\\scoreboardGeneral.png");
}


void listaRecord::generarDOTINDIVIDUAL()
{
    int numeroNodo = 0;//colocacion deun indice
    ofstream archivo("ArchivosDot\\scoreboardINDIVIDUAL.dot");
    archivo<<"digraph Scoreboard {"<<endl;
    archivo<<"rankdir=LR;"<<endl;
    //para la colocacion de los nodos
    if (estadoLista() == true)
    {
        //fin del archivo
        archivo<<"}"<<endl;
        archivo.close();
    }
    else
    {
        nodoRecord *nodoTemporal = ultimo;
        while (nodoTemporal!=NULL)
        {
            archivo<<"Nodo"<<numeroNodo<<"[shape=record,label=\""<<
            nodoTemporal->getNombreUsuario()<<", "<<nodoTemporal->getPuntaje()<<"-Pts\"];"<<endl;
            nodoTemporal = nodoTemporal->getAnterior();
            numeroNodo = numeroNodo + 1;
        }
            //anidacion de los nodos
        for (int i = 0; i < numeroNodo-1; i++)
        {
            archivo<<"Nodo"<<i<<"->Nodo"<<i+1<<";"<<endl;
        }    
        //fin del archivo
        archivo<<"label=\"Scoreboard General\";"<<endl;
        archivo<<"}"<<endl;
        archivo.close();        
    }

    system("dot.exe -Tpng ArchivosDot\\scoreboardINDIVIDUAL.dot -o Reportes\\scoreboardINDIVIDUAL.png");
    system("Reportes\\scoreboardINDIVIDUAL.png");
}

//destructor
listaRecord::~listaRecord(){}