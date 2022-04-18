#ifndef PROJETODA_FILE_H
#define PROJETODA_FILE_H
#include <vector>
#include <iostream>
#include "carrinha.h"
#include "encomenda.h"

using namespace std;

class File {
private:
    vector<Carrinha> carrinhas;
    vector<Encomenda> encomendas;


public:
    File();

    vector<Carrinha> readAndParseCar(string path);

    vector<Encomenda> readAndParseEnc(string path);

    /*vector<Carrinha> getCarrinhas();

    vector<Encomenda> getEncomendas();*/

    void printCarrinhas();

    void printEncomendas();
};


#endif