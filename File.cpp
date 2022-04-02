//
// Created by Filipe on 02/04/2022.
//

#include <fstream>
#include "File.h"

File::File(std::string path) {
    this->path = path;
}

std::vector<Carrinha> File::readAndParse(std::string path) {
    int vol, peso, cost;
    std::ifstream readFile (path);
    if(!readFile){
        std::cout << "Can't open file"<< std::endl;
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

void File::setPath(std::string path) {
    this->path = path;
}


std::string File::getPath() {
    return path;
}


std::vector<Carrinha> File::getCarrinhas() {
    return carrinhas;
}

//just for debug
void File::printCarrinhas(){
    for (auto aux : carrinhas) {
        std::cout << aux.volMax << '\t' << aux.pesoMax << '\t' << aux.custo << std::endl;
    }
}
