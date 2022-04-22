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

    /**
    * este método fornece um vetor das carrinhas disponíveis
    *
    * @param path nome do ficheiro de texto com os dados das carrinhas
    * @return vetor de carrinhas
    */
    vector<Carrinha> readAndParseCar(string path);


    /**
    * este método fornece um vetor das encomendas a entregar
    *
    * @param path nome do ficheiro de texto com os dados das encomendas
    * @return vetor de encomendas
    */
    vector<Encomenda> readAndParseEnc(string path);

    /*vector<Carrinha> getCarrinhas();

    vector<Encomenda> getEncomendas();*/

    void printCarrinhas();

    void printEncomendas();
};


#endif