#ifndef PROJETODA_MENU_H
#define PROJETODA_MENU_H

#include <iostream>
#include <string>
#include "File.h"
#include "jobscheduling.h"
#include "knapsack.h"
#include "binpacking.h"
#include "utils.h"

class Menu {

private:
    char choice;

public:
    Menu();
    void showMenu();
    void takeInput(std::vector<Carrinha> carrinhas, std::vector<Encomenda> encomendas);
};

#endif
