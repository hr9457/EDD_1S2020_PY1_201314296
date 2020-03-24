#include "nodoCola.h"

nodoCola::nodoCola(int num, string arg){
    this->puntuacion = num;
    this->letra = arg;
    this->siguiente = NULL;
}


int nodoCola::getPuntuacion(){
    return puntuacion;
}

void nodoCola::setPuntuacion(int num){
    this->puntuacion = num;
}

string nodoCola::getLetra(){
    return letra;
}

void nodoCola::setLetra(string arg){
    this->letra = arg;
}

int nodoCola::getCantidad(){
    return cantidad;
}

void nodoCola::setCantidad(int num){
    this->cantidad = num;
}

nodoCola * nodoCola::getSiguiente(){
    return siguiente;
}

void nodoCola::setSiguiente(nodoCola *puntero){
    this->siguiente = puntero;
}

nodoCola::~nodoCola(){}