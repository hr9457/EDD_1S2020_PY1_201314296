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
            nodoArbol *nodoTemporal = new nodoArbol(arg);
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
            nodoArbol *nodoTemporal = new nodoArbol(arg);
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
        nodoArbol *nodoTemporal = new nodoArbol(arg);
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



//metodo para genera la imgen del archivo dot
void arbolBinario::generarPNG(){
    	system("dot.exe -Tpng ArchivosDot\\Arbol.dot -o Reportes\\Arbol.png");
}


arbolBinario::~arbolBinario(){}