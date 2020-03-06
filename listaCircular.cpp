#include "listaCircular.h"

//contructor
listaCircular::listaCircular(){
    this->primero = NULL;
    this->ultimo = NULL;
}


//estado de la lista
bool listaCircular::estadoLista(){
    if(primero == NULL && ultimo == NULL){
        return true;
    }else{
        return false;
    }
}

//metodo insertar
void listaCircular::insertar(string arg){
    nodoCircular *nodoTemporal = new nodoCircular(arg);
    if(estadoLista() == true){
        primero = nodoTemporal;
        ultimo = nodoTemporal;
        ultimo->setSiguiente(primero);
        primero->setAnterior(ultimo);
    }else{
        nodoTemporal->setAnterior(ultimo);
        ultimo->setSiguiente(nodoTemporal);
        ultimo = nodoTemporal;
        ultimo->setSiguiente(primero);
        primero->setAnterior(ultimo);
    }
}

//impresion de la lista
void listaCircular::imprimir(){    
    if(estadoLista() == true){
        cout<<"no hay elemento en la lista";
    }else{
        nodoCircular *nodoAuxiliar = primero;
        do{
            cout<<"<---"<<nodoAuxiliar->getPalabra()<<"--->"<<endl;
            nodoAuxiliar = nodoAuxiliar->getSiguiente();
        }while(nodoAuxiliar != primero);
    }    
}

//para genera archvio dot
void listaCircular::generarDot(){
    int numeroNodo = 0;//para colocacion de un indice a los nodos en .dot
    ofstream archivo("ArchivosDot\\ListaCircular.dot");//apertura de archivo
    archivo<<"digraph ListaDoble {"<<endl;
    archivo<<"rankdir=LR;"<<endl;
    archivo<<"splines=ortho;"<<endl;

    //para colocar los nodos
    if(estadoLista()==true){        
    }else{
        nodoCircular *nodoTemporal = primero;
        do{            
            archivo<<"Nodo"<<numeroNodo<<"[shape=record,label=\"{<pre>|"<<
            nodoTemporal->getPalabra()<<"|<next>}\"];"<<endl;
            nodoTemporal=nodoTemporal->getSiguiente();
            numeroNodo=numeroNodo+1;
        } while (nodoTemporal != primero);
    }
    //cout<<"fin de la declaracion de los nodos"<<endl;

    //anidacion de los nodos
    
    for (int i = 0; i < numeroNodo-1; i++){
        archivo<<"Nodo"<<i<<"->Nodo"<<i+1<<";"<<endl;
        archivo<<"Nodo"<<i+1<<"->Nodo"<<i<<";"<<endl;
    }    

    archivo<<"Nodo"<<numeroNodo-1<<"->Nodo0[constraint=false];"<<endl;
    archivo<<"Nodo0->Nodo"<<numeroNodo-1<<"[constraint=false];"<<endl;
    archivo<<"label = \" Lista Circular Simple\";"<<endl;
    archivo<<"}"<<endl;
    archivo.close();
}

//metodo para generar la imagen
void listaCircular::generarPNG(){
    system("dot.exe -Tpng ArchivosDot\\ListaCircular.dot -o Reportes\\ListaCircular.png");
}

//destructor
listaCircular::~listaCircular(){}
