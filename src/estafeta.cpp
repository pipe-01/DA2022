#include <iostream>
#include "estafeta.h"

using namespace std;

Estafeta::Estafeta(): matricula(""), volumeMax(0), pesoMax(0), custo(0) {}

Estafeta::Estafeta(std::string matricula, unsigned int volumeMax, unsigned int pesoMax, unsigned int custo){

    this->volumeMax = volumeMax;
    this->pesoMax = pesoMax;
    this->custo = custo;
}

unsigned int Estafeta::getVolumeMax() const{
    return volumeMax;
}

unsigned int Estafeta::getPesoMax() const{
    return pesoMax;
}

unsigned int Estafeta::getCusto() const{
    return custo;
}