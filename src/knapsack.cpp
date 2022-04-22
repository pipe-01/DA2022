// Time complexity : O(nlog(n))
// Space complexity : O(n)
#include "knapsack.h"


void sortRequests(std::vector<Encomenda> *requests){

    sort(requests->begin(), requests->end(), comparePayment);
    // sort(requests->begin(), requests->end(), compareSize);
}

void sortWorkers(std::vector<Carrinha> *workers){

    sort(workers->begin(), workers->end(), compareCost);
    // sort(workers->begin(), workers->end(), compareWorkerSize);
}


int cenario2(std::vector<Encomenda> requests, std::vector<Carrinha> workers){

    std::list<std::tuple<Encomenda,Carrinha>> solution;
    std::list<int> save;

    
    int profit = 0;
    bool clean = true;

    sortRequests(&requests);
    sortWorkers(&workers);

    // cout << "aqui" << std::endl;

    // test sorting
    // std::cout << "Encomenda ratio:" << std::endl;
    // for(auto i : requests){
    //     std::cout << ratio(i.getRecompensa(),i.getVolume(),i.getPeso()) << std::endl;
    // }
    // cout << "Custo Carrinhas:" << std::endl;
    // for(auto i : workers){
    //     cout << ratio(i.getaCusto(),i.getVolMax(),i.getPesoMax()) << std::endl;
    // }

    unsigned int i = 0, j = 0;
    int pesoLeft = 0, volLeft = 0;

    std::vector<std::vector<Encomenda>> sol;
    std::vector<Encomenda> aux;

    while(i < workers.size() && j < requests.size()){

        // std::cout << "Volume encomenda: " << requests[j].getVolume() << ", Volume Max: " << workers[i].getVolMax() << ", Recompensa: " << requests[j].getRecompensa() << std::endl;
        // std::cout << "Peso encomenda: " << requests[j].getPeso() << ", Peso Max: " << workers[i].getPesoMax() << std::endl;

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
            // std::cout << "i: " << i << ", j: " << j << std::endl;
            j++;
        }
        else{
            clean = true;
            sol.push_back(aux);
            i++;
        }
    }

    std::vector<int> nonProfit;

    // for(int i = 0; i<sol.size();i++){
    //     std::cout << "Encomendas Carinha " << i << ":" << std::endl;
    //     for(int j = 0; j<sol[i].size(); j++){
    //         std::cout << j << ", ";
    //     }
    //     std::cout << std::endl;
    // }

    // delete non profit workers
    for(int m = 0; m<sol.size(); m++){

        nonProfit.push_back(-workers[m].getCusto());

        // std::cout << "Worker Cost: " << workers[m].getCusto() << std::endl;
        // std::cout << "Current Profit: " << nonProfit[m] << std::endl;

        for(int n = 0; n<sol[m].size(); n++){
            nonProfit[m] += sol[m][n].getRecompensa();
        }

        // std::cout << "Current Profit2: " << nonProfit[m] << std::endl;
        
        if(nonProfit[m] < 0){
        //remove
            profit -= nonProfit[m];
        }
    }

    return profit;
}

