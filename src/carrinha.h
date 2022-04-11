#ifndef DA2022_CARRINHA_H
#define DA2022_CARRINHA_H

#include<string>
#include <vector>
#include <algorithm>
#include "encomenda.h"

class Carrinha{

private:
    //std::string matrícula;
    int volMax;
    int pesoMax;
    int custo;
    int capacidade; //volMax + pesoMax

public:
    Carrinha();
    Carrinha(/*std::string matrícula, */int volMax, int pesoMax, int custo, int capacidade);
    //std::string getMatrícula() const;
    int getCapacidade() const;
    int getVolMax() const;
    int getPesoMax() const;
    int getCusto() const;
    int minNumEstafetas(std::vector<Carrinha> carrinhas, std::vector<Encomenda> encomendas);
};

#endif //DA2022_CARRINHA_H
