#include "listaABC.h"

//------- constructor
listaABC::listaABC()
{
    this->primero = NULL;
    this->ultimo = NULL;
}


//-------- ESTADO DE LA LISTA
bool listaABC::estadoLista()
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


//----------- CONTADOR DE LA LISTA
int listaABC::getSize()
{
    return size;
}

void listaABC::setSize(int num)
{
    this->size = num;
}




//------------ METODO PARA INSERTAR EN LA LISTA
void listaABC::insertar(int num,string arg,int num2)
{
    nodoABC *nodoTemporal = new nodoABC(num,arg,num2);//puntaje,letra y cantidad
    if(estadoLista() == true)
    {
        primero = nodoTemporal;
        ultimo = nodoTemporal;
        size++;
    }
    else
    {
        ultimo->setSiguiente(nodoTemporal);
        nodoTemporal->setAnterior(ultimo);
        ultimo = nodoTemporal;
        size++;//aumentamos el contador para saber el tamanio de la lista
    }
}


//------------ METODO PARA ELEIMINAR DE LA LISTA
void listaABC::eliminar(int tamanio,int& puntajeReturn,string& letraReturn)
{
    if(estadoLista() == true)
    {}
    else
    {
        int numeroNodo = 0;
        nodoABC *auxPrimero = primero;
        while (numeroNodo <= tamanio)
        {
            if(numeroNodo==tamanio)
            {
                if(auxPrimero==primero)
                {
                    if(auxPrimero->getCantidad()>1)
                    {
                        //colafichas.insertarLetra(auxPrimero->getPuntuacion(),auxPrimero->getLetra());//inserto en la cola
                        //tengo que hacer la resta en el nodo
                        puntajeReturn = auxPrimero->getPuntuacion();
                        letraReturn = auxPrimero->getLetra();
                        int cantidad = auxPrimero->getCantidad();
                        cantidad = cantidad - 1;
                        auxPrimero->setCantidad(cantidad);
                    }
                    else
                    {
                        //colafichas.insertarLetra(auxPrimero->getPuntuacion(),auxPrimero->getLetra());//inserto en la cola
                        puntajeReturn = auxPrimero->getPuntuacion();
                        letraReturn = auxPrimero->getLetra();
                        if(auxPrimero->getSiguiente()==NULL)
                        {
                            this->primero=NULL;
                            this->ultimo=NULL;
                            delete auxPrimero;
                        }
                        else
                        {
                            primero = auxPrimero->getSiguiente();//muevo el primero
                            delete auxPrimero;
                        }                      
                    }
                }

                else if(auxPrimero==ultimo)
                {
                    if(auxPrimero->getCantidad()>1)
                    {
                        //colafichas.insertarLetra(auxPrimero->getPuntuacion(),auxPrimero->getLetra());//inserto en la cola
                        puntajeReturn = auxPrimero->getPuntuacion();
                        letraReturn = auxPrimero->getLetra();
                        //tengo que hacer la resta en el nodo
                        int cantidad = auxPrimero->getCantidad();
                        cantidad = cantidad - 1;
                        auxPrimero->setCantidad(cantidad);
                    }
                    else
                    {
                        //colafichas.insertarLetra(auxPrimero->getPuntuacion(),auxPrimero->getLetra());//inserto en la cola
                        puntajeReturn = auxPrimero->getPuntuacion();
                        letraReturn = auxPrimero->getLetra();
                        if(auxPrimero->getAnterior()==NULL)
                        {
                            this->ultimo=NULL;
                            this->primero=NULL;                            
                            delete auxPrimero;
                        }
                        else
                        {
                            ultimo = auxPrimero->getAnterior();//muevo el ultimo 
                            delete auxPrimero;
                        }                                                 
                    }
                }

                else
                {
                    if(auxPrimero->getCantidad()>1)
                    {
                        //colafichas.insertarLetra(auxPrimero->getPuntuacion(),auxPrimero->getLetra());//inserto en la cola
                        puntajeReturn = auxPrimero->getPuntuacion();
                        letraReturn = auxPrimero->getLetra();
                        //tengo que hacer la resta en el nodo
                        int cantidad = auxPrimero->getCantidad();
                        cantidad = cantidad - 1;
                        auxPrimero->setCantidad(cantidad);
                    }
                    else
                    {
                        //colafichas.insertarLetra(auxPrimero->getPuntuacion(),auxPrimero->getLetra());//inserto en la cola
                        puntajeReturn = auxPrimero->getPuntuacion();
                        letraReturn = auxPrimero->getLetra();
                        //recoloco los apuntadores
                        nodoABC *aux1 = auxPrimero->getAnterior();
                        nodoABC *aux2 = auxPrimero->getSiguiente();
                        delete auxPrimero;
                        aux1->setSiguiente(aux2);
                        aux2->setAnterior(aux1);                        
                    }
                }
            }
            numeroNodo++;
            auxPrimero = auxPrimero->getSiguiente();   
        }//fin del while        
    }    
}



//---------- metodo para imprimir los elementos de la lista
void listaABC::imprimirLista()
{
    nodoABC *auxPrimero = primero;
    if(estadoLista()==true)
    {
        cout<<"no hay elemento en la lista";
    }
    else
    {
        while (auxPrimero!=NULL)
        {
            cout<<"ficha: "<<auxPrimero->getLetra()<<" Cantidad: "<<auxPrimero->getCantidad()<<endl;
            auxPrimero = auxPrimero->getSiguiente();//paso al siguiente       
        }        
    }    
}


//--------------- imprimir elemento de la cola
void listaABC::imprimirCola()
{
    nodoCola *auxPrimeroCola = colafichas.getPrimero();
    if(auxPrimeroCola==NULL)
    {
        cout<<"no fichas en la cola"<<endl;
    }
    else
    {
        while (auxPrimeroCola!=NULL)
        {
            cout<<"ficha: "<<auxPrimeroCola->getLetra()<<" Puntaje: "<<auxPrimeroCola->getPuntuacion()<<endl;
            auxPrimeroCola = auxPrimeroCola->getSiguiente();
        }        
    }       
}



//------- destructor
listaABC::~listaABC(){}