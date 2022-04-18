#ifndef PROJETODA_MENU_H
#define PROJETODA_MENU_H

#include <iostream>
#include <string>
#include "File.h"

class Menu {

private:
    char choice;

public:
    Menu();
    void showMenu();
    void takeInput(std::vector<Carrinha> carrinhas, std::vector<Encomenda> encomendas);
};

#endif
