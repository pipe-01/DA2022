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

//just for testing
int main(){

    Pedido p1 = Pedido(50,30,20);
    Pedido p2 = Pedido(50,30,10);
    Pedido p3 = Pedido(50,30,30);

    vector<Pedido> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    // vector<Pedido> res = sortRequests(v);
    sortRequests(&v);

    for(auto i : v){
        cout << i.getPayment() << endl;
    }
}
