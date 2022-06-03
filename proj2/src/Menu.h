#ifndef PROJETODA3_MENU_H
#define PROJETODA3_MENU_H

#include "graph.h"
#include "File.h"

class Menu {

private:
    std::string choice2;
    char choice1;

public:
    Menu();
    /**
    * este método mostra o menu da aplicação
    * @return void
    */
    void showMenu();
    /**
    * este método recebe input do utilizador, o que lhe permite escolher uma opção do menu
    * @param graphCap grafo que representa as viagens e cujo peso de cada aresta corresponde à capacidade de cada veículo
    * @param graphDur grafo que representa as viagens e cujo peso de cada aresta corresponde ao tempo que demora a chegar de um nó ao outro
    * @return void
    */
    void takeInput(Graph<int> &graphCap, Graph<int> &graphDur);

};


#endif //PROJETODA3_MENU_H
