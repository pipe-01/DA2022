#include <iostream>
#include "carrinha.h"
#include "utils.h"


Carrinha::Carrinha(): volMax(0), pesoMax(0), custo(0){}

Carrinha::Carrinha(int volMax, int pesoMax, int custo) {
    this->volMax = volMax;
    this->pesoMax = pesoMax;
    this->custo = custo;
}

int Carrinha::getCusto() const {
    return custo;
}

int Carrinha::getPesoMax() const{
    return pesoMax;
}

int Carrinha::getVolMax() const{
    return volMax;
}