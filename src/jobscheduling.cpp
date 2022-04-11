#include "jobscheduling.h"

bool compareTime(Encomenda a, Encomenda b)
{
     return (a.duracao < b.duracao);
}

double cenario3(std::vector<Encomenda> encomendas){
    int totalTime = 0;

    sort(encomendas.begin(), encomendas.end(), compareTime);
 
    std::vector<Encomenda> entregas;
    std::vector<Encomenda> descartados;
 
    for(auto aux: encomendas){
        if(totalTime + aux.duracao <= MAXHOURS){
            entregas.push_back(aux);
            totalTime += aux.duracao;
        }
        else{
            descartados.push_back(aux);
        }
    }

    //printVector(entregas);

    //std::cout << totalTime << " " << entregas.size() << std::endl;

    return (double)totalTime/entregas.size();
}


void printVector(std::vector<Encomenda> array){
    for(auto aux: array){
        std::cout << "volume: " << aux.volume << " peso: " << aux.peso << " duracao: " << aux.duracao << std::endl;
    }

    std::cout << "tamanho " << array.size() << std::endl;
}