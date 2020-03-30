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
        size = size + 1;
    }
    else
    {
        ultimo->setSiguiente(nodoTemporal);
        nodoTemporal->setAnterior(ultimo); 
        ultimo = nodoTemporal;   
        size = size + 1;           
    }    
}






//-------------------------- metodo para eliminar de la lista
void listaDoble::eliminarFicha(string letra,int &puntajeReturnLista)
{
    nodoListaDoble *nodoAuxiliar = primero;
    while(nodoAuxiliar!=NULL)
    {
        if(letra==nodoAuxiliar->getLetra())
        {
            if(primero==nodoAuxiliar)//SI LA FICHA ES IGUAL A PRIMERO
            {  
                if(nodoAuxiliar->getSiguiente()!=NULL)
                {
                    puntajeReturnLista = primero->getPuntaje();
                    primero = nodoAuxiliar->getSiguiente();
                    delete nodoAuxiliar;
                    size = size - 1;
                }
                else
                {
                    puntajeReturnLista = primero->getPuntaje();
                    primero = NULL;
                    ultimo = NULL;
                    size = size - 1;
                }
            }
            else if(ultimo==nodoAuxiliar)//SI LA FICHA ES IGUAL A ULTIIMO
            {     
                if(nodoAuxiliar->getAnterior()!=NULL)
                {
                    nodoListaDoble *nodoAux = ultimo->getAnterior();
                    puntajeReturnLista = ultimo->getPuntaje();
                    ultimo->setAnterior(NULL);
                    nodoAux->setSiguiente(NULL);
                    ultimo = nodoAux;
                }
                else
                {
                    puntajeReturnLista = ultimo->getPuntaje();
                    ultimo= NULL;
                    primero = NULL;
                    size = size - 1;
                }
            }
            else//SI LA FICHA ESTA EN MEDIO
            {
                nodoListaDoble *aux1 = nodoAuxiliar->getAnterior();
                nodoListaDoble *aux2 = nodoAuxiliar->getSiguiente();
                puntajeReturnLista = nodoAuxiliar->getPuntaje();
                aux1->setSiguiente(aux2);
                aux2->setAnterior(aux1);
                delete nodoAuxiliar; 
                size = size - 1;             
            }
            break;
        }//fin del primer if que revisa cuando se halla encontrado la letra
        nodoAuxiliar = nodoAuxiliar->getSiguiente();
    }
}



//---------metodo eliminar de utlimo y vaciar la lista
void listaDoble::eliminarUltimo(string &letra, int &puntaje)
{}



//-------------------- METODO PARA MANEJAR LA CANTIDAD ELEMENTOS DE LA LISTA
int listaDoble::getSize()
{
    return size;
}

void listaDoble::setSize(int num)
{
    this->size = num;
}



void listaDoble::imprimir()
{
    nodoListaDoble *nodoAuxiliar = primero;
    while (nodoAuxiliar!=NULL)
    {
        cout<<"letra: "<<nodoAuxiliar->getLetra()<<" puntaje: "<<nodoAuxiliar->getPuntaje()<<endl;
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
    else
    {
        ofstream archivo("ArchivosDot\\ListaJugador.dot");
        archivo<<"digraph Lista {"<<endl;
        archivo<<"}"<<endl;
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


//------------------- metodo para utilizar de elimiar de ultimo 
void listaDoble::eliminarUltimo()
{
    if(estdoLista()!=true)
    {
        nodoListaDoble *nodoAux = ultimo->getAnterior();
        ultimo->setAnterior(NULL);
        nodoAux->setSiguiente(NULL);
        ultimo = nodoAux;
    }
}




listaDoble::~listaDoble(){}
