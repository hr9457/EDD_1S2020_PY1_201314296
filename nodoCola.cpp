#include "nodoCola.h"

nodoCola::nodoCola(int num,string arg, int num2){
    this->puntuacion = num;
    this->letra = arg;
    this->cantidad = num2;
    this->anterior = NULL;
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

nodoCola * nodoCola::getAnterior(){
    return anterior;
}

void nodoCola::setAnterior(nodoCola *puntero){
    this->anterior = puntero;
}

nodoCola::~nodoCola(){}