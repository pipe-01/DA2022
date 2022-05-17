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

double ratio(int cost, int vol, int weight){
    return (double)cost/(vol+weight);
}

bool comparePayment(Encomenda x, Encomenda y){

    double xAux = ratio(x.getRecompensa(),x.getVolume(),x.getPeso());
    double yAux = ratio(y.getRecompensa(),y.getVolume(),y.getPeso());

    return (xAux>yAux);
}


bool compareCost(Carrinha x, Carrinha y){

    double xAux = ratio(x.getCusto(),x.getVolMax(),x.getPesoMax());
    double yAux = ratio(y.getCusto(),y.getVolMax(),y.getPesoMax());

    return (xAux<yAux);
}