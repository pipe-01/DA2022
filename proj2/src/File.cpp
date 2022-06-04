#include <fstream>
#include "File.h"

File::File() {}


void File::buildGraphCap(Graph<int> &graphCap) {

    std::ifstream data;
    int fileNum;
    int nNodes, nEdges;
    std::string filename = "";
    int orig, dest, cap, dur;

    std::cout << "Selecione o ficheiro pretendido (1 <= x <= 12)" << std::endl;
    while(true){
        std::cin >> fileNum;
        if(!std::cin.fail()){
            break;
        }
        std::cin.clear();
        std::cin.ignore(100000,'\n');
        std::cout << "O número do ficheiro deve ser um inteiro entre 1 e 12" << std::endl;
    }
    if(fileNum < 10) {
        filename += "C:\\Users\\ASUS\\PROJETODA3\\in0" + std::to_string(fileNum) + ".txt";
    }
    else{
        filename += "C:\\Users\\ASUS\\PROJETODA3\\in" + std::to_string(fileNum) + ".txt";
    }

    //std::cout << filename << std::endl;

    data.open(filename, std::ios::in);
    if(!data){
        std::cout << "Ficheiro não aberto" << std::endl;
    }
    data >> nNodes >> nEdges;
    //std::cout << "Nodes: " << nNodes << " " << "Edges: " << nEdges << std::endl; //debug

    for (int i = 1; i <= nNodes; i++){
        graphCap.addVertex(i);
    }

    for (int i = 0; i < nEdges; i++){
        data >> orig >> dest >> cap >> dur;
        graphCap.addEdge(orig, dest, cap);
        //std::cout << "orig: " << orig << " Duraçao: " << dest << " Capacidade: " << cap << " Duração: " << dur << std::endl; //debug
    }
    data.close();
}

void File::buildGraphDur(Graph<int> &graphDur){
    std::ifstream data;
    int fileNum;
    int nNodes, nEdges;
    std::string filename = "";
    int orig, dest, cap, dur;

    std::cout << "Selecione o ficheiro pretendido (1 <= x <= 12)" << std::endl;
    while(true){
        std::cin >> fileNum;
        if(!std::cin.fail()){
            break;
        }
        std::cin.clear();
        std::cin.ignore(100000,'\n');
        std::cout << "O número do ficheiro deve ser um inteiro entre 1 e 12" << std::endl;
    }
    if(fileNum < 10) {
        filename += "C:\\Users\\ASUS\\PROJETODA3\\in0" + std::to_string(fileNum) + ".txt";
    }
    else if (fileNum >= 10){
        filename += "C:\\Users\\ASUS\\PROJETODA3\\in" + std::to_string(fileNum) + ".txt";
    }

    //std::cout << filename << std::endl;

    data.open(filename, std::ios::in);
    if(!data){
        std::cout << "Ficheiro não aberto" << std::endl;
    }
    data >> nNodes >> nEdges;
    //std::cout << "Nodes: " << nNodes << " " << "Edges: " << nEdges << std::endl; //debug


    for (int i = 1; i <= nNodes; i++){
        graphDur.addVertex(i);
    }

    for (int i = 0; i < nEdges; i++){
        data >> orig >> dest >> cap >> dur;
        graphDur.addEdge(orig, dest, dur);
        //std::cout << "orig: " << orig << " Duraçao: " << dest << " Capacidade: " << cap << " Duração: " << dur << std::endl; //debug
    }
    data.close();
}