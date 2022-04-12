// Sort the jobs based on their deadlines.
// Iterate from the end and calculate the available slots between every two consecutive deadlines. Include the profit, deadline, and job ID of ith job in the max heap.
// While the slots are available and there are jobs left in the max heap, include the job ID with maximum profit and deadline in the result.
// Sort the result array based on their deadlines.

// Time complexity : O(nlog(n))
// Space complexity : O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include "encomenda.cpp"
#include "carrinha.cpp"

// Estafeta = volume máximo, peso máximo e custo/percentagem
// Encomenda = Volume, peso e recompensa    


//ordenar os pagamentos dos estafetas por ordem crescente
// escolher o primeiro
// ordem decrescente de profit
// ver se e viavel
// se nao for exclui solução
// se for adiciona e passa ao seguinte

using namespace std;

bool comparePayment(Encomenda x, Encomenda y){
    return (x.getRecompensa()>y.getRecompensa());
}

bool compareCost(Carrinha x, Carrinha y){
    return (x.getCusto()<y.getCusto());
}

void sortRequests(vector<Encomenda> *requests){

    sort(requests->begin(), requests->end(), comparePayment);
}

void sortWorkers(vector<Carrinha> *workers){

    sort(workers->begin(), workers->end(), compareCost);
}

vector<Encomenda> testingReq(){

    Encomenda p1 = Encomenda(50,30,20,1);
    Encomenda p2 = Encomenda(50,30,10,1);
    Encomenda p3 = Encomenda(50,30,30,1);

    vector<Encomenda> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    return v;
}

vector<Carrinha> testingWork(){

    Carrinha e1 = Carrinha(60,60,14);
    Carrinha e2 = Carrinha(20,30,17);
    Carrinha e3 = Carrinha(25,10,13);

    vector<Carrinha> v;
    v.push_back(e1);
    v.push_back(e2);
    v.push_back(e3);
    
    return v;
}

void cenario2(){

    vector<Encomenda> requests = testingReq();
    vector<Carrinha> workers = testingWork();

    sortRequests(&requests);
    sortWorkers(&workers);

    //test sorting
    // for(auto i : workers){
    //     cout << i.getCusto() << endl;
    // }
    for(auto i : requests){
        cout << i.getRecompensa() << endl;
    }

    for(auto request : requests){

    }
}

//just for testing
int main(){

    cenario2();
}
