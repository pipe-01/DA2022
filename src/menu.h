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
    /**
    * este método mostra o menu da aplicação
    * @return void
    */
    void showMenu();
    /**
    * este método recebe input de um inteiro que permite escolher uma opção do menu
    * @return void
    */
    void takeInput(std::vector<Carrinha> carrinhas, std::vector<Encomenda> encomendas);
};

#endif
