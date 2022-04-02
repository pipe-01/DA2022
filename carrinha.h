//
// Created by Filipe on 02/04/2022.
//

#ifndef DA2022_CARRINHA_H
#define DA2022_CARRINHA_H

struct Carrinha{
    int volMax;
    int pesoMax;
    int custo;


    Carrinha(int vol, int peso, int cost)
        : volMax(vol), pesoMax(peso), custo(cost) {}
    Carrinha()
            : volMax(0), pesoMax(0), custo(0) {}
};

#endif //DA2022_CARRINHA_H
