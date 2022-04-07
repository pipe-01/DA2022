#include <fstream>
#include "File.h"

using namespace std;

File::File() {}

vector<Carrinha> File::readAndParseCar(string path) {
    int vol, peso, cost;
    ifstream readFile (path);
    if(!readFile){
        cout << "Can't open file"<< endl;
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

vector<Encomenda> File::readAndParseEnc(string path){
    int vol, peso, cost, dur;
    ifstream readFile (path);
    if(!readFile){
        cout << "Can't open file"<< endl;
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


vector<Carrinha> File::getCarrinhas() {
    return carrinhas;
}

vector<Encomenda> File::getEncomendas(){
    return encomendas;
}

//just for debug
void File::printCarrinhas(){
    for (auto aux : carrinhas) {
        cout << aux.volMax << '\t' << aux.pesoMax << '\t' << aux.custo << endl;
    }
}

//just for debug
void File::printEncomendas(){
    for (auto aux : encomendas) {
        cout << aux.volume << '\t' << aux.peso << '\t' << aux.recompensa << '\t' << aux.duracao << endl;
    }
}

