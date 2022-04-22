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

    return entregas.size();
}