#include "nodoArbol.h"

//metoodo contructor inicializa el nodo el arbol
nodoArbol::nodoArbol(string arg, int num){
    this->nombreJugador = arg;
    this->puntaje = num;
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

//metodos set  y ge para puntuajes 
int nodoArbol::getPuntaje()
{
    return puntaje;
}

void nodoArbol::setPuntaje(int numero)
{
    this->puntaje = numero;
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

void nodoArbol::insertarEnNodo(string nombre,int puntaje)
{
    this->lista.insertarUltimo(nombre,puntaje);
}

void nodoArbol::mostarPuntajesOrdenados()
{
    this->lista.ordenamientoBurbuja();
    this->lista.generarDOTINDIVIDUAL();
}

//destructor
nodoArbol::~nodoArbol(){}