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
            carrinhas.emplace_back(vol, peso, cost, vol+peso);
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
            encomendas.emplace_back(vol, peso, cost, dur, vol+peso);
        }
    }
    readFile.close();
    return encomendas;
}


/*vector<Carrinha> File::getCarrinhas() {
    return carrinhas;
}

vector<Encomenda> File::getEncomendas(){
    return encomendas;
}*/

//just for debug
void File::printCarrinhas(){
    for (auto aux : carrinhas) {
        cout << aux.getVolMax() << '\t' << aux.getPesoMax() << '\t' << aux.getCusto() << endl;
    }
}

//just for debug
void File::printEncomendas(){
    for (auto aux : encomendas) {
        cout << aux.getVolume() << '\t' << aux.getPeso() << '\t' << aux.getRecompensa() << '\t' << aux.getDuracao() << endl;
    }
}

