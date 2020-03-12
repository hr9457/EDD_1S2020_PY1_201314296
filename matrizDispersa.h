#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

#include "nodoMatriz.h"
#include "iostream"
#include "string"
using namespace std;

class matrizDispersa
{
    private:
        nodoMatriz *root;
        
    public:
        matrizDispersa();
        ~matrizDispersa();
};

#endif