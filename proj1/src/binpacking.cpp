#include "binpacking.h"

int cenario1(std::vector<Carrinha> carrinhas, std::vector<Encomenda> encomendas) {
    int pesoCarrinhas, volCarrinhas;
    int numEstafetas = 0;
    sort(carrinhas.begin(), carrinhas.end(), cmpCarrinhas);
    sort(encomendas.begin(), encomendas.end(), cmpEncomenda);
    for (unsigned int i = 0; i < carrinhas.size(); i++){
        pesoCarrinhas = carrinhas[i].getPesoMax();
        volCarrinhas = carrinhas[i].getVolMax();
        if (encomendas.empty()){
            return numEstafetas;
        }
        numEstafetas++;
        for (unsigned int j = 0; j < encomendas.size(); j++){
            if (encomendas[j].getPeso() > pesoCarrinhas || encomendas[j].getVolume() > volCarrinhas){
                continue;
            }
            else{
                pesoCarrinhas -= encomendas[j].getPeso();
                volCarrinhas -= encomendas[i].getVolume();
                encomendas.erase(encomendas.begin() + j);
                j--;
            }
        }
    }

    return numEstafetas;
}