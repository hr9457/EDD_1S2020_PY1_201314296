#ifndef NODOCOLA_H
#define NODOCOLA_H

#include "iostream"
using namespace std;

class nodoCola
{
    private:
        int puntuacion;
        string letra;
        int cantidad;
        nodoCola *siguiente;
        
    public:
        nodoCola(int num, string arg);
        
        int getPuntuacion();
        void setPuntuacion(int num);
        
        string getLetra();
        void setLetra(string arg);
        
        int getCantidad();
        void setCantidad(int num);
        
        nodoCola * getSiguiente();
        void setSiguiente(nodoCola *puntero);

        ~nodoCola();
};

#endif