#include "nodoArbol.h"

//metoodo contructor inicializa el nodo el arbol
nodoArbol::nodoArbol(string arg){
    this->nombreJugador = arg;
    this->derecha = NULL;
    this->izquierda = NULL;
}

//metodo get y set nombre jugador
string nodoArbol::getNombreJugador(){
    return nombreJugador;
}

void nodoArbol::setNombreJugador(string arg){
    this->nombreJugador = arg;
}

//metodo get y se para apuntadores de derecha y izquierda
nodoArbol * nodoArbol::getDerecha(){
    return derecha;
}

void nodoArbol::setDerecha(nodoArbol *puntero){
    this->derecha = puntero;
}

nodoArbol * nodoArbol::getIzquierda(){
    return izquierda;
}

void nodoArbol::setIzquierda(nodoArbol *puntero){
    this->izquierda = puntero;
}

//destructor
nodoArbol::~nodoArbol(){}