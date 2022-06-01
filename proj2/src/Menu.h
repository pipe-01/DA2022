#ifndef PROJETODA3_MENU_H
#define PROJETODA3_MENU_H

#include "graph.h"

class Menu {

private:
    char choice1, choice2;

public:
    Menu();
    void showMenu();
    void takeInput(Graph<int> &graphCap, Graph<int> &graphDur);

};


#endif //PROJETODA3_MENU_H
