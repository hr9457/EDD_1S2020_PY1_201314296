#include "matrizDispersa.h"

//constructor
matrizDispersa::matrizDispersa()
{
    nodoMatriz *nodoTemporal = new nodoMatriz("",0,-1,-1);
    this->root = nodoTemporal;
    this->inicioColumnas = root;
    this->finalColumnas = NULL;
    this->inicioFilas = root;
    this->finalFilas = NULL;
}



//estado de la matriz
bool matrizDispersa::estadoMatriz()
{
    if(root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }    
}





//para insertar en la lista - en el lado que maneja las columnas
//apuntadores de siguiente y anterior en el root
void matrizDispersa::insertarEnColumna(int posX)
{
    if(root->getSiguiente() == NULL)//si no hay ningun elemento en la matriz
    {
        nodoMatriz *nuevaColumna = new nodoMatriz("",0,posX,0);
        root->setSiguiente(nuevaColumna);
        nuevaColumna->setAnterior(root);
    }
    else
    {
        nodoMatriz *rootTemporal = root;
        //obtiene el nodo anterior para agregar el nuevo en el siguiente
        //para que la agregacion sea en orden
        while (rootTemporal->getSiguiente() != NULL && rootTemporal->getSiguiente()->getPosx()<posX)
        {
            rootTemporal = rootTemporal->getSiguiente();
        }

        //agregando despues de aver encontrado el nodo 
        if(rootTemporal->getSiguiente() == NULL)
        {
            nodoMatriz *nuevaColumna = new nodoMatriz("",0,posX,0);
            rootTemporal->setSiguiente(nuevaColumna);
            nuevaColumna->setAnterior(rootTemporal);
        }
        else if(rootTemporal->getSiguiente() != NULL && rootTemporal->getSiguiente()->getPosx() != posX)
        {
            nodoMatriz *nuevaColumna = new nodoMatriz("",0,posX,0);
            nodoMatriz *nodoDerecha = rootTemporal->getSiguiente();
            rootTemporal->setSiguiente(nuevaColumna);
            nuevaColumna->setAnterior(rootTemporal);
            nuevaColumna->setSiguiente(nodoDerecha);
            nodoDerecha->setAnterior(nuevaColumna);
        }        
    }    
}





//para insertar en la matriz del lado que maneja las filas
//apuntadores de abajo y arriba
void matrizDispersa::insertarEnFila(int posY)
{
    if(root->getAbajo() == NULL)
    {
        nodoMatriz *nuevaFila = new nodoMatriz("",0,0,posY);
        root->setAbajo(nuevaFila);
        nuevaFila->setArriba(root);
    }
    else
    {
        //recorrido hacia abajo en la filas
        //buscar nodo y posicionarme en el nodo anterior para insertar
        nodoMatriz *rootTemporal = root;
        while (rootTemporal->getAbajo()!=NULL && rootTemporal->getAbajo()->getPosy()<posY)
        {
            rootTemporal = rootTemporal->getAbajo();
        }

        //primer caso
        if(rootTemporal->getAbajo() == NULL)
        {
            nodoMatriz *nuevaFila = new nodoMatriz("",0,0,posY);
            rootTemporal->setAbajo(nuevaFila);
            nuevaFila->setArriba(rootTemporal);
        }
        else if(rootTemporal->getAbajo()!=NULL && rootTemporal->getAbajo()->getPosy()!=posY)
        {
            nodoMatriz *nuevaFila = new nodoMatriz("",0,0,posY);
            nodoMatriz *nodoAbajoTemporal = rootTemporal->getAbajo();
            rootTemporal->setAbajo(nuevaFila);
            nuevaFila->setArriba(rootTemporal);
            nuevaFila->setAbajo(nodoAbajoTemporal);
            nodoAbajoTemporal->setArriba(nuevaFila); 
        }
        
    }
    
}



//insertar un nuevo nodo en la matriz
void matrizDispersa::insertarNodo(char caracter,int posX,int posY)
{
    if(estadoMatriz() == true)
    {
    }
    else
    {
        //nodo que se va agregar dentro de la matriz
        nodoMatriz *nodoTemporal = new nodoMatriz("",caracter,posX,posY);
        //creamos su columna
        insertarEnColumna(posX);
        insertarEnFila(posY);
    }    
}





//para la impresion y saber que columnas hay creadas
void matrizDispersa::imprimirColumnas()
{
    if(estadoMatriz() == true)
    {
        cout<<"no hay columnas en la matriz";
    }
    else
    {
        nodoMatriz *rootTemporal = root;
        while (rootTemporal != NULL)
        {
            cout<<rootTemporal->getPosx()<<"<->";
            rootTemporal = rootTemporal->getSiguiente();       
        }         
    }    
}

//para la impresion y saber que filas hay creadas
void matrizDispersa::imprimirFilas()
{
    if(estadoMatriz()==true)
    {
        cout<<"no hay filas en la matriz";
    }
    else
    {
        nodoMatriz *rootTemporal = root;
        while (rootTemporal != NULL)
        {
            cout<<rootTemporal->getPosy()<<"|"<<endl;
            rootTemporal = rootTemporal->getAbajo();
        }
        
    }
    
}


//destructor
matrizDispersa::~matrizDispersa(){}