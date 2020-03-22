#include "arbolBinario.h"



//contructor del arbol
arbolBinario::arbolBinario(){
    this->root = NULL;
}

//estado del arbol
bool arbolBinario::estadoArbol(){
    if (root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}



//para buscar donde insertar en el arbol
void arbolBinario::buscarInsert(nodoArbol *nodo, string arg){
    if(arg == nodo->getNombreJugador() )
    {        
    }
    else if(arg < nodo->getNombreJugador())
    {
        if(nodo->getIzquierda() == NULL)
        {
            nodoArbol *nodoTemporal = new nodoArbol(arg,0);
            nodo->setIzquierda(nodoTemporal);
        }
        else
        {
            nodo = nodo->getIzquierda();
            buscarInsert(nodo,arg);
        }        
    }
    else if(arg > nodo->getNombreJugador())
    {
        if(nodo->getDerecha() == NULL)
        {
            nodoArbol *nodoTemporal = new nodoArbol(arg,0);
            nodo->setDerecha(nodoTemporal);
        }
        else
        {
            nodo = nodo->getDerecha();
            buscarInsert(nodo,arg);
        } 
    }
}

//metodo para inserta en el arbol
void arbolBinario::insertarJugador(string arg){    
    if (estadoArbol() == true)
    {
        nodoArbol *nodoTemporal = new nodoArbol(arg,0);
        root = nodoTemporal;
    }
    else
    {
        buscarInsert(root,arg);
    }
}


//para imprimir en el doot los nodos
void arbolBinario::recorrerArbol(nodoArbol *inicio){
    if (inicio != NULL){
        //archivo<<"nodo"<<inicio->dato<<"[ label = \"<C0>|"<<inicio->dato<<"|<C1>\"]; "<<endl;
        archivo<<"nodo"<<inicio->getNombreJugador()<<"[ label = \"<C0>|"<<inicio->getNombreJugador()<<"|<C1>\"]; "<<endl;
        if(inicio->getIzquierda() != NULL){
            nodoArbol *siguiente = inicio->getIzquierda();
            archivo<<"nodo"<<inicio->getNombreJugador()<<":C0->nodo"<<siguiente->getNombreJugador()<<endl;
            recorrerArbol(inicio->getIzquierda());
        }
        if(inicio->getDerecha() != NULL){
            nodoArbol *siguiente = inicio->getDerecha();
            archivo<<"nodo"<<inicio->getNombreJugador()<<":C1->nodo"<<siguiente->getNombreJugador()<<endl;
            recorrerArbol(inicio->getDerecha());
        }
    }
}

//para imprimir en el doot los nodos
void arbolBinario::recorrerArbol2(nodoArbol *inicio){
    if (inicio != NULL){
        //archivo<<"nodo"<<inicio->dato<<"[ label = \"<C0>|"<<inicio->dato<<"|<C1>\"]; "<<endl;
        archivo<<"nodo"<<inicio->getNombreJugador()<<"[ label = \""<<inicio->getNombreJugador()<<"\"]; "<<endl;
        if(inicio->getIzquierda() != NULL){
            nodoArbol *siguiente = inicio->getIzquierda();
            archivo<<"nodo"<<inicio->getNombreJugador()<<"->nodo"<<siguiente->getNombreJugador()<<endl;
            recorrerArbol2(inicio->getIzquierda());
        }
        if(inicio->getDerecha() != NULL){
            nodoArbol *siguiente = inicio->getDerecha();
            archivo<<"nodo"<<inicio->getNombreJugador()<<"->nodo"<<siguiente->getNombreJugador()<<endl;
            recorrerArbol2(inicio->getDerecha());
        }
    }
}


//metodo para generar el dot del arbol binario
void arbolBinario::generarDot(){
    archivo.open("ArchivosDot\\Arbol.dot",ios::out);
    if(archivo.fail()){
        cout<<"no se puedo abrir el archivo"<<endl;
    }else{
        archivo<<"digraph arbol"<<endl;
        archivo<<"{"<<endl;
        archivo<<"rankdir=TB;"<<endl;
        //archivo<<"graph [splines=ortho, nodesep=0.5];"<<endl;
        //archivo<<"node [shape = record, style=filled, fillcolor=seashell2,width=0.7,height=0.2];"<<endl;
        recorrerArbol2(root);
        archivo<<"label = \" Arbol Binario \" "<<endl;
        archivo<<"}"<<endl;
        archivo.close();
    }
}



//--------metodo para genera la imgen del archivo dot del arbol binario
void arbolBinario::generarPNG(){
    system("dot.exe -Tpng ArchivosDot\\Arbol.dot -o Reportes\\Arbol.png");
}


//-----------metodo para abrir la imagen del arbol binario
void arbolBinario::abrirPNG()
{
    system("Reportes\\Arbol.png");
}



//------------------------------METODO DE RECORRIDO EN EL ARBOL-----------------------------------------

//--------------------------METODO PARA PREORDEN
void arbolBinario::Preorden(nodoArbol *nodo)
{
    if(nodo !=NULL)
    {
        archivo<<"nodo"<<nodoPreorden<<"[label=\""<<nodo->getNombreJugador()<<"\"];"<<endl;
        nodoPreorden++;
        Preorden(nodo->getIzquierda());
        Preorden(nodo->getDerecha());
    }    
}

void arbolBinario::generarPNGPreorden()
{
    system("dot.exe -Tpng ArchivosDot\\ArbolPreorden.dot -o Reportes\\ArbolPreorden.png");
}

void arbolBinario::abrirPNGPreorden()
{
    system("Reportes\\ArbolPreorden.png");
}


void arbolBinario::generarDotPreorden()
{
    nodoArbol *auxRoot = root;//variable para recorrer el arbol si mover la raiz
    nodoPreorden = 0;
    if(estadoArbol() != true)
    {
        archivo.open("ArchivosDot\\ArbolPreorden.dot",ios::out);
        if(archivo.fail()){
            cout<<"no se puedo abrir el archivo"<<endl;
        }else{
            archivo<<"digraph arbolPreorden {"<<endl;
            archivo<<"node [shape=record];"<<endl;
            archivo<<"rankdir=LR;"<<endl;
            //creo los nodos con un sub indice de 0,1,2,3 etc
            Preorden(auxRoot);
            //anido los nodos ya creados segun el orden indicado 
            for (int numeroNodo = 0; numeroNodo < nodoPreorden; numeroNodo++)
            {
                archivo<<"nodo"<<numeroNodo;
                if(numeroNodo+1<nodoPreorden)
                {
                    archivo<<"->";
                }   
            }
            archivo<<";";
            archivo<<endl;
            archivo<<"label = \" Arbol Binario - Preorden \" "<<endl;
            archivo<<"}"<<endl;
            archivo.close();
        }        
    }    
}



//----------------------------METODO PAR INORDEN
void arbolBinario::Inorden(nodoArbol *nodo)
{
    if(nodo !=NULL)
    {        
        Inorden(nodo->getIzquierda());
        archivo<<"nodo"<<nodoInorden<<"[label=\""<<nodo->getNombreJugador()<<"\"];"<<endl;
        nodoInorden++;
        Inorden(nodo->getDerecha());
    }    
}

void arbolBinario::generarPNGInorden()
{
    system("dot.exe -Tpng ArchivosDot\\ArbolInorden.dot -o Reportes\\ArbolInorden.png");
}

void arbolBinario::abrirPNGInorden()
{
    system("Reportes\\ArbolInorden.png");
}


void arbolBinario::generarDotInorden()
{
    nodoArbol *auxRoot = root;//variable para recorrer el arbol si mover la raiz
    nodoInorden = 0;
    if(estadoArbol() != true)
    {
        archivo.open("ArchivosDot\\ArbolInorden.dot",ios::out);
        if(archivo.fail()){
            cout<<"no se puedo abrir el archivo"<<endl;
        }else{
            archivo<<"digraph arbolInorden {"<<endl;
            archivo<<"node [shape=record];"<<endl;
            archivo<<"rankdir=LR;"<<endl;
            //creo los nodos con un sub indice de 0,1,2,3 etc
            Inorden(auxRoot);
            //anido los nodos ya creados segun el orden indicado             
            for (int numeroNodo = 0; numeroNodo < nodoInorden; numeroNodo++)
            {
                archivo<<"nodo"<<numeroNodo;
                if(numeroNodo+1<nodoInorden)
                {
                    archivo<<"->";
                }   
            }            
            archivo<<";";
            archivo<<endl;
            archivo<<"label = \" Arbol Binario - Inorden \" "<<endl;
            archivo<<"}"<<endl;
            archivo.close();
        }        
    }    
}




//--------------------------METODO PARA POSTORDEN
void arbolBinario::Postorden(nodoArbol *nodo)
{
    if(nodo !=NULL)
    {        
        Postorden(nodo->getIzquierda());        
        Postorden(nodo->getDerecha());
        archivo<<"nodo"<<nodoPostorden<<"[label=\""<<nodo->getNombreJugador()<<"\"];"<<endl;
        nodoPostorden++;
    }    
}

void arbolBinario::generarPNGPostorden()
{
    system("dot.exe -Tpng ArchivosDot\\ArbolPostorden.dot -o Reportes\\ArbolPostorden.png");
}

void arbolBinario::abrirPNGPostorden()
{
    system("Reportes\\ArbolPostorden.png");
}


void arbolBinario::generarDotPostorden()
{
    nodoArbol *auxRoot = root;//variable para recorrer el arbol si mover la raiz
    nodoPostorden = 0;
    if(estadoArbol() != true)
    {
        archivo.open("ArchivosDot\\ArbolPostorden.dot",ios::out);
        if(archivo.fail()){
            cout<<"no se puedo abrir el archivo"<<endl;
        }else{
            archivo<<"digraph arbolPostorden {"<<endl;
            archivo<<"node [shape=record];"<<endl;
            archivo<<"rankdir=LR;"<<endl;
            //creo los nodos con un sub indice de 0,1,2,3 etc
            Postorden(auxRoot);
            //anido los nodos ya creados segun el orden indicado 
            for (int numeroNodo = 0; numeroNodo < nodoPostorden; numeroNodo++)
            {
                archivo<<"nodo"<<numeroNodo;
                if(numeroNodo+1<nodoPostorden)
                {
                    archivo<<"->";
                }   
            }
            archivo<<";";
            archivo<<endl;
            archivo<<"label = \" Arbol Binario - PostOrden \" "<<endl;
            archivo<<"}"<<endl;
            archivo.close();
        }        
    }    
}



//-----------------prueba para mostrar en consola
void arbolBinario::impresionInorden(nodoArbol *nodo)
{
    if(nodo !=NULL)
    {        
        Inorden(nodo->getIzquierda());
        cout<<nodo->getNombreJugador()<<endl;
        Inorden(nodo->getDerecha());
    } 
}

arbolBinario::~arbolBinario(){}