// Sort the jobs based on their deadlines.
// Iterate from the end and calculate the available slots between every two consecutive deadlines. Include the profit, deadline, and job ID of ith job in the max heap.
// While the slots are available and there are jobs left in the max heap, include the job ID with maximum profit and deadline in the result.
// Sort the result array based on their deadlines.

// Time complexity : O(nlog(n))
// Space complexity : O(n)

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <tuple>
#include <list>
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

//ratio = custo/(vol+peso)
using namespace std;

double ratio(int cost, int vol, int weight){
    return (double)cost/(vol+weight);
}

bool comparePayment(Encomenda x, Encomenda y){

    double xAux = ratio(x.getRecompensa(),x.getVolume(),x.getPeso());
    double yAux = ratio(y.getRecompensa(),y.getVolume(),y.getPeso());

    return (xAux>yAux);
}

bool compareCost(Carrinha x, Carrinha y){


    double xAux = ratio(x.getCusto(),x.getVolMax(),x.getPesoMax());
    double yAux = ratio(y.getCusto(),y.getVolMax(),y.getPesoMax());

    return (xAux<yAux);
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

list<tuple<Encomenda,Carrinha>> cenario2(){

    vector<Encomenda> requests = testingReq();
    vector<Carrinha> workers = testingWork();

    list<tuple<Encomenda,Carrinha>> solution;

    sortRequests(&requests);
    sortWorkers(&workers);

    // cout << "aqui" << endl;

    // test sorting
    // cout << "Encomenda ratio:" << endl;
    // for(auto i : requests){
    //     cout << ratio(i.getRecompensa(),i.getVolume(),i.getPeso()) << endl;
    // }
    // cout << "Custo Carrinhas:" << endl;
    // for(auto i : workers){
    //     cout << ratio(i.getCusto(),i.getVolMax(),i.getPesoMax()) << endl;
    // }

    unsigned int i = 0, j = 0;
    while(i != workers.size() || j != requests.size()){

        cout << "Volume encomenda: " << requests[j].getVolume() << ", Volume Max: " << workers[i].getVolMax() << ", Recompensa: " << requests[j].getRecompensa() << endl;
        cout << "Peso encomenda: " << requests[j].getPeso() << ", Peso Max: " << workers[i].getPesoMax() << endl;

        if(requests[j].getVolume() <= workers[i].getVolMax() && requests[j].getPeso() <= workers[i].getPesoMax()){
            tuple<Encomenda,Carrinha> tup = make_tuple(requests[j], workers[i]);
            solution.push_back(tup);
        }

        i++;
        j++;
    }

    return solution;
}

//just for testing
int main(){

    list<tuple<Encomenda,Carrinha>> sol = cenario2();

    // cout << sol.size() << endl;

    cout << "Solução" << endl;
    for(auto elem : sol){
        cout << "Encomenda: "<< get<0>(elem).getRecompensa() << ", Carrinha:" << get<1>(elem).getCusto() << endl;
    }
}
