#include <iostream>
#include "estafeta.h"

using namespace std;

Estafeta::Estafeta(unsigned int eVol, unsigned int eWeight, unsigned int eCost){

    this->maxVolume = eVol;
    this->maxWeight = eWeight;
    this->cost = eCost;
}

unsigned int Estafeta::getVolume(){
    return this->maxVolume;
}

unsigned int Estafeta::getWeight(){
    return this->maxWeight;
}

unsigned int Estafeta::getCost(){
    return this->cost;
}