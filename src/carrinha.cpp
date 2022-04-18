#include <iostream>
#include "carrinha.h"
#include "encomenda.h"


Carrinha::Carrinha(): /*matrícula(""), */volMax(0), pesoMax(0), custo(0)/*, capacidade(0)*/{}

Carrinha::Carrinha(/*std::string matrícula, */int volMax, int pesoMax, int custo/*, int capacidade*/) {
    //this->matrícula = matrícula;
    this->volMax = volMax;
    this->pesoMax = pesoMax;
    this->custo = custo;
    //this->capacidade = capacidade;
}

/*std::string Carrinha::getMatrícula() const{
    return matrícula;
}*/

int Carrinha::getCusto() const {
    return custo;
}

int Carrinha::getPesoMax() const {
    return pesoMax;
}

int Carrinha::getVolMax() const {
    return volMax;
}

/*int Carrinha::getCapacidade() const {
    return capacidade;
}*/

/*bool cmpCarrinhas(const Carrinha &c1, const Carrinha &c2){
    return c2.getCapacidade() < c1.getCapacidade();
}
*/
bool cmpEncomenda(const Encomenda &e1, const Encomenda &e2){
    return e2.getTamanho() < e1.getTamanho();
}

bool cmpCarrinhas(const Carrinha &c1, const Carrinha &c2){
    return c2.getPesoMax() < c1.getPesoMax();
}

int Carrinha::minNumEstafetas(std::vector<Carrinha> carrinhas, std::vector<Encomenda> encomendas) {
    int numEstafetas = 0;
    sort(carrinhas.begin(), carrinhas.end(), cmpCarrinhas);
    sort(encomendas.begin(), encomendas.end(), cmpEncomenda);
    for (unsigned int i = 0; i < carrinhas.size(); i++){
        if (encomendas.empty()){
            return numEstafetas;
        }
        numEstafetas++;
        for (unsigned int j = 0; j < encomendas.size(); j++){
            if (encomendas[j].getPeso() > carrinhas[i].pesoMax || encomendas[j].getVolume() > carrinhas[i].volMax){
                continue;
            }
            else{
                carrinhas[i].pesoMax -= encomendas[j].getPeso();
                carrinhas[i].volMax -= encomendas[i].getVolume();
                encomendas.erase(encomendas.begin() + j);
                j--;
            }
        }
    }

    return numEstafetas;
}