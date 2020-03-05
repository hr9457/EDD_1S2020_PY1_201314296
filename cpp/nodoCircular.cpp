#include "headers/nodoCircular.h"

//MEOTODOS

//contructor
nodoCircular::nodoCircular(string argumento){
    this->palabra = argumento;
    this->siguiente = NULL;
    this->anterior = NULL;
}

//metodos get y set de para informacion de la variable
string nodoCircular::getPalabra(){
    return palabra;
}

void nodoCircular::setPalabra(string argumento){
    this->palabra = argumento;
}

//metodos get y set siguiente
nodoCircular* nodoCircular::getSiguiente(){
    return siguiente;
}

void nodoCircular::setSiguiente(nodoCircular *puntero){
    siguiente = puntero;
}


//metodos get y set para anterior
nodoCircular* nodoCircular::getAnterior(){
    return anterior;
}

void nodoCircular::setAnterior(nodoCircular *puntero){
    anterior = puntero;
}


//metodo destructor
nodoCircular::~nodoCircular(){}