#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <fstream>
#include "Graph.h"
#include "queue"


int main(){
    std::ifstream data;
    int fileNum;
    int nNodes, nEdges;
    std::string filename = "Tests/in";
    int orig, dest, dur;
    double cap;

    std::cout << "Please select the file you want to test (1 <= x <= 10)" << std::endl;
    while(true){
        std::cin >> fileNum;
        if(!std::cin.fail()){
            break;
        }
        std::cin.clear();
        std::cin.ignore(100000,'\n');
        std::cout << "The file number must be between 1 and 10" << std::endl;
    }
    if(fileNum < 10){
        filename += "0";
    }
    filename += std::to_string(fileNum) + ".txt";

    data.open(filename, std::ios::in);
    if(!data){
        std::cout << "Can't open file" << std::endl;
    }
    data >> nNodes >> nEdges;
    std::cout << "Nodes: " << nNodes << " " << "Edges: " << nEdges << std::endl; //debug
    //Graph graph(nNodes, true);
    Graph<int> graph;
    
    for (int i = 1; i <= nNodes; i++){
        graph.addVertex(i);
    }
    
    for (int i = 0; i < nEdges; i++){
        data >> orig >> dest >> cap >> dur;
        graph.addEdge(orig, dest, cap);
        //cout << "orig: " << orig << " Duraçao: " << dest << " Capacidade: " << cap << " Duração: " << dur << std::endl; //debug
    }

    int origem, destino;
    std::cout << "Enter origem and destino" << std::endl;
    std::cin >> origem >> destino;

    

    return 0;
}
