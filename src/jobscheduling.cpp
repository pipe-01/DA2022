#include "jobscheduling.h"

double cenario3(std::vector<Encomenda> encomendas){
    int totalTime = 0;

    sort(encomendas.begin(), encomendas.end(), compareTime);
 
    std::vector<Encomenda> entregas;
    std::vector<Encomenda> descartados;
 
    for(auto aux: encomendas){
        if(totalTime + aux.getDuracao() <= MAXHOURS){
            entregas.push_back(aux);
            totalTime += aux.getDuracao();
        }
        else{
            descartados.push_back(aux);
        }
    }

    //printVector(entregas);

    return (double)totalTime/entregas.size();
}


void printVector(std::vector<Encomenda> array){
    for(auto aux: array){
        std::cout << "volume: " << aux.getVolume() << " peso: " << aux.getPeso() << " duracao: " << aux.getDuracao() << std::endl;
    }

    std::cout << "tamanho " << array.size() << std::endl;
}