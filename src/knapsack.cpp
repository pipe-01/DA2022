// Sort the jobs based on their deadlines.
// Iterate from the end and calculate the available slots between every two consecutive deadlines. Include the profit, deadline, and job ID of ith job in the max heap.
// While the slots are available and there are jobs left in the max heap, include the job ID with maximum profit and deadline in the result.
// Sort the result array based on their deadlines.

// Time complexity : O(nlog(n))
// Space complexity : O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include "pedido.cpp"
#include "estafeta.cpp"

// Estafeta = volume máximo, peso máximo e custo/percentagem
// Encomenda = Volume, peso e recompensa    


//ordenar os pagamentos dos estafetas por ordem crescente
// escolher o primeiro
// ordem decrescente de profit
// ver se e viavel
// se nao for exclui solução
// se for adiciona e passa ao seguinte

using namespace std;

bool comparePayment(Pedido x, Pedido y){
    return (x.getPayment()<y.getPayment());
}

bool compareCost(Estafeta x, Estafeta y){
    return (x.getCost()<y.getCost());
}

void sortRequests(vector<Pedido> *requests){

    sort(requests->begin(), requests->end(), comparePayment);
}

void sortWorkers(vector<Estafeta> *workers){

    sort(workers->begin(), workers->end(), compareCost);
}

vector<Pedido> testingReq(){

    Pedido p1 = Pedido(50,30,20);
    Pedido p2 = Pedido(50,30,10);
    Pedido p3 = Pedido(50,30,30);

    vector<Pedido> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    return v;
}

vector<Estafeta> testingWork(){

    Estafeta e1 = Estafeta(60,60,14);
    Estafeta e2 = Estafeta(20,30,17);
    Estafeta e3 = Estafeta(25,10,13);

    vector<Estafeta> v;
    v.push_back(e1);
    v.push_back(e2);
    v.push_back(e3);
    
    return v;
}

void cenario2(){

    vector<Pedido> requests = testingReq();
    vector<Estafeta> workers = testingWork();

    sortRequests(&requests);
    sortWorkers(&workers);

    //test sorting
    // for(auto i : workers){
    //     cout << i.getCost() << endl;
    // }

    for(auto request : requests){

    }
}

//just for testing
int main(){

    cenario2();
}
