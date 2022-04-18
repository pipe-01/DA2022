#include "encomenda.h"
#include "carrinha.h"
#include "knapsack.h"

bool compareTime(const Encomenda &e1, const Encomenda &e2)
{
    return (e1.getDuracao() < e2.getDuracao());
}

bool cmpEncomenda(const Encomenda &e1, const Encomenda &e2){
    return e2.getTamanho() < e1.getTamanho();
}

bool cmpCarrinhas(const Carrinha &c1, const Carrinha &c2){
    return c2.getPesoMax() < c1.getPesoMax();
}

bool comparePayment(const Encomenda &e1, const Encomenda &e2){

    double e1Aux = ratio(e1.getRecompensa(),e1.getVolume(),e1.getPeso());
    double e2Aux = ratio(e2.getRecompensa(),e2.getVolume(),e2.getPeso());

    return (e1Aux>e2Aux);
}

bool compareCost(const Carrinha &c1, const Carrinha &c2){

    double c1Aux = ratio(c1.getCusto(),c1.getVolMax(),c1.getPesoMax());
    double c2Aux = ratio(c2.getCusto(),c2.getVolMax(),c2.getPesoMax());

    return (c1Aux<c2Aux);
}