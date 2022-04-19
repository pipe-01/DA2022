// Sort the jobs based on their deadlines.
// Iterate from the end and calculate the available slots between every two consecutive deadlines. Include the profit, deadline, and job ID of ith job in the max heap.
// While the slots are available and there are jobs left in the max heap, include the job ID with maximum profit and deadline in the result.
// Sort the result array based on their deadlines.

// Time complexity : O(nlog(n))
// Space complexity : O(n)

#include "knapsack.h"
// #include <unistd.h>

// Estafeta = volume máximo, peso máximo e custo/percentagem
// Encomenda = Volume, peso e recompensa    


//ordenar os pagamentos dos estafetas por ordem crescente
// escolher o primeiro
// ordem decrescente de profit
// ver se e viavel
// se nao for exclui solução
// se for adiciona e passa ao seguinte

//ratio = custo/(vol+peso)

double ratio(int cost, int vol, int weight){
    return (double)cost/(vol+weight);
}

bool comparePayment(Encomenda x, Encomenda y){

    double xAux = ratio(x.getRecompensa(),x.getVolume(),x.getPeso());
    double yAux = ratio(y.getRecompensa(),y.getVolume(),y.getPeso());

    return (xAux>yAux);
}

bool compareSize(Encomenda x, Encomenda y){
    return x.getPeso()+x.getVolume()<y.getPeso()+y.getVolume();
}

bool compareWorkerSize(Carrinha x, Carrinha y){
    return x.getPesoMax()+x.getVolMax()>y.getPesoMax()+y.getVolMax();
}

bool compareCost(Carrinha x, Carrinha y){


    double xAux = ratio(x.getCusto(),x.getVolMax(),x.getPesoMax());
    double yAux = ratio(y.getCusto(),y.getVolMax(),y.getPesoMax());

    return (xAux<yAux);
}

void sortRequests(std::vector<Encomenda> *requests){

    sort(requests->begin(), requests->end(), comparePayment);
    // sort(requests->begin(), requests->end(), compareSize);
}

void sortWorkers(std::vector<Carrinha> *workers){

    sort(workers->begin(), workers->end(), compareCost);
    // sort(workers->begin(), workers->end(), compareWorkerSize);
}

// std::vector<Encomenda> testingReq(){

//     Encomenda p1 = Encomenda(50,30,20,1);
//     Encomenda p2 = Encomenda(50,30,10,1);
//     Encomenda p3 = Encomenda(50,30,30,1);

//     std::vector<Encomenda> v;
//     v.push_back(p1);
//     v.push_back(p2);
//     v.push_back(p3);

//     return v;
// }

// std::vector<Carrinha> testingWork(){

//     Carrinha e1 = Carrinha(60,60,14);
//     Carrinha e2 = Carrinha(20,30,17);
//     Carrinha e3 = Carrinha(25,10,13);

//     std::vector<Carrinha> v;
//     v.push_back(e1);
//     v.push_back(e2);
//     v.push_back(e3);
    
//     return v;
// }

// int forceCenario2(std::vector<Encomenda> requests, std::vector<Carrinha> workers){

//     std::list<std::list<Encomenda>> sol;

//     for()
    
// }

int cenario2(std::vector<Encomenda> requests, std::vector<Carrinha> workers){

    // std::vector<Encomenda> requests = testingReq();
    // std::vector<Carrinha> workers = testingWork();

    std::list<std::tuple<Encomenda,Carrinha>> solution;
    std::list<int> save;

    // int left =
    
    int profit = 0;
    bool clean = false;

    sortRequests(&requests);
    sortWorkers(&workers);

    // cout << "aqui" << std::endl;

    // test sorting
    // std::cout << "Encomenda ratio:" << std::endl;
    // for(auto i : requests){
    //     std::cout << "ola?" << std::endl;
    //     std::cout << ratio(i.getRecompensa(),i.getVolume(),i.getPeso()) << std::endl;
    // }
    // cout << "Custo Carrinhas:" << std::endl;
    // for(auto i : workers){
    //     cout << ratio(i.getaCusto(),i.getVolMax(),i.getPesoMax()) << std::endl;
    // }

    unsigned int i = 0, j = 0;
    int pesoLeft = 0, volLeft = 0;

    //when a request is impossible to carry:
    int count = 0;

    while(i < workers.size() && j < requests.size()){

        // std::cout << "Volume encomenda: " << requests[j].getVolume() << ", Volume Max: " << workers[i].getVolMax() << ", Recompensa: " << requests[j].getRecompensa() << std::endl;
        // std::cout << "Peso encomenda: " << requests[j].getPeso() << ", Peso Max: " << workers[i].getPesoMax() << std::endl;

        if(clean){
            volLeft = workers[i].getVolMax();
            pesoLeft = workers[i].getPesoMax();
            profit -= workers[i].getCusto();
            clean = false;
            count++;
        }

        if(requests[j].getVolume() <= volLeft && requests[j].getPeso() <= pesoLeft){
            count = 0;
            std::tuple<Encomenda,Carrinha> tup = std::make_tuple(requests[j], workers[i]);
            profit += requests[j].getRecompensa();
            solution.push_back(tup);
            pesoLeft -= requests[j].getPeso();
            volLeft -= requests[j].getVolume();
            // std::cout << "i: " << i << ", j: " << j << std::endl;
            j++;
        }
        else{
            if(count == 2){
                count = 0;
                j++;
            }
            else{
                clean = true;
                i++;
            }
        }
        // sleep(1);
    }

    return profit;
}

//just for testing
// int main(){

//     std::list<std::tuple<Encomenda,Carrinha>> sol = cenario2();

//     // cout << sol.size() << std::endl;

//     cout << "Solução" << std::endl;
//     for(auto elem : sol){
//         cout << "Encomenda: "<< get<0>(elem).getRecompensa() << ", Carrinha:" << get<1>(elem).getCusto() << std::endl;
//     }
// }
