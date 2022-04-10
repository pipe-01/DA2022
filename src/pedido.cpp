#include <iostream>
#include "pedido.h"

using namespace std;

Pedido::Pedido(unsigned int pVol, unsigned int pWeight, unsigned int pPayment){
    
    this->volume = pVol;
    this->weight = pWeight;
    this->payment = pPayment;
}

unsigned int Pedido::getVolume(){
    return this->volume;
}

unsigned int Pedido::getWeight(){
    return this->weight;
}

unsigned int Pedido::getPayment(){
    return this->payment;
}