#include "knapsack.h"

void sortRequests(std::vector<Encomenda> *requests){

    sort(requests->begin(), requests->end(), comparePayment);
}

void sortWorkers(std::vector<Carrinha> *workers){

    sort(workers->begin(), workers->end(), compareCost);
}

int cenario2(std::vector<Encomenda> requests, std::vector<Carrinha> workers){

    std::list<std::tuple<Encomenda,Carrinha>> solution;
    std::list<int> save;

    
    int profit = 0;
    bool clean = true;

    sortRequests(&requests);
    sortWorkers(&workers);

    unsigned int i = 0, j = 0;
    int pesoLeft = 0, volLeft = 0;

    std::vector<std::vector<Encomenda>> sol;
    std::vector<Encomenda> aux;

    while(i < workers.size() && j < requests.size()){

        if(clean){
            aux.clear();
            volLeft = workers[i].getVolMax();
            pesoLeft = workers[i].getPesoMax();
            profit -= workers[i].getCusto();
            clean = false;
        }

        if(requests[j].getVolume() <= volLeft && requests[j].getPeso() <= pesoLeft){
            aux.push_back(requests[j]);
            profit += requests[j].getRecompensa();
            pesoLeft -= requests[j].getPeso();
            volLeft -= requests[j].getVolume();
            j++;
        }
        else{
            clean = true;
            sol.push_back(aux);
            i++;
        }
        if(j+1 == requests.size()){
            sol.push_back(aux);
        }
    }


    std::vector<int> nonProfit;

    for(unsigned int m = 0; m<sol.size(); m++){

        nonProfit.push_back(-workers[m].getCusto());

        for(unsigned int n = 0; n<sol[m].size(); n++){
            nonProfit[m] += sol[m][n].getRecompensa();
        }
        
        if(nonProfit[m] < 0){
            profit -= nonProfit[m];
        }
    }

    return profit;
}

