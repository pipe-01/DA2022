#ifndef CARRINHA_H
#define CARRINHA_H
#include<string>
#include <vector>
#include <algorithm>
#include "encomenda.h"

class Carrinha{

private:
    int volMax;
    int pesoMax;
    int custo;

public:
    Carrinha();
    Carrinha(int volMax, int pesoMax, int custo);
    int getVolMax() const;
    int getPesoMax() const;
    int getCusto() const;
};

#endif
