#include <fstream>
#include "File.h"

using namespace std;

File::File() {}

vector<Carrinha> File::readAndParseCar(std::string path) {
    int vol, peso, cost;
    ifstream readFile (path);
    if(!readFile){
        cout << "Can't open file"<< std::endl;
    }
    else {
        while (readFile.good()) {
            readFile.ignore(256, '\n');
            readFile >> vol >> peso >> cost;
            carrinhas.emplace_back(vol, peso, cost);
        }
    }
    readFile.close();
    return carrinhas;
}

std::vector<Encomenda> File::readAndParseEnc(std::string path){
    int vol, peso, cost, dur;
    std::ifstream readFile (path);
    if(!readFile){
        std::cout << "Can't open file"<< std::endl;
    }
    else {
        while (readFile.good()) {
            readFile.ignore(256, '\n');
            readFile >> vol >> peso >> cost >> dur;
            encomendas.emplace_back(vol, peso, cost, dur);
        }
    }
    readFile.close();
    return encomendas;
}


std::vector<Carrinha> File::getCarrinhas() {
    return carrinhas;
}

std::vector<Encomenda> File::getEncomendas(){
    return encomendas;
}

//just for debug
void File::printCarrinhas(){
    for (auto aux : carrinhas) {
        std::cout << aux.volMax << '\t' << aux.pesoMax << '\t' << aux.custo << std::endl;
    }
}

//just for debug
void File::printEncomendas(){
    for (auto aux : encomendas) {
        std::cout << aux.volume << '\t' << aux.peso << '\t' << aux.recompensa << '\t' << aux.duracao << std::endl;
    }
}

