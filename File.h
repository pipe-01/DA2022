#ifndef DA2022_FILE_H
#define DA2022_FILE_H
#include <vector>
#include <iostream>
#include "carrinha.h"
#include "encomenda.h"


class File {
private:
    std::vector<Carrinha> carrinhas;
    std::vector<Encomenda> encomendas;


public:
    File();

    std::vector<Carrinha> readAndParseCar(std::string path);

    std::vector<Encomenda> readAndParseEnc(std::string path);

    std::vector<Carrinha> getCarrinhas();

    std::vector<Encomenda> getEncomendas();

    void printCarrinhas();

    void printEncomendas();
};


#endif //DA2022_FILE_H
