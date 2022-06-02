//
// Created by ASUS on 30/05/2022.
//

#include "Menu.h"

Menu::Menu(){}

void Menu::showMenu(){
    std::cout << "Bem vindo ao sistema de pedidos para transporte!" << std::endl;
    std::cout << "Por favor, selecione o cenario que pretende simular:" << std::endl;
    std::cout << std::endl;
    std::cout << "1- Se nao pretender separar o seu grupo" << std::endl;
    std::cout << "2- Se pretender separar o seu grupo" << std::endl;
    std::cout << "3- Sair da plataforma" << std::endl;
    std::cout << std::endl;
    }

void Menu::takeInput(Graph<int> &graphCap, Graph<int> &graphDur){

    int src, dest;
    int a = 1, b = 50;

    while(true){
        std::cout << "Selecione a opcao (choice1): ";
        std::cin >> choice1;
        switch (choice1) {
            case '1':
                std::cout << "Partida: " << std::endl;
                std::cin >> src;
                std::cout << "Chegada: " << std::endl;
                std::cin >> dest;
                std::cout << std::endl;
                std::cout << "1- Minimo numero de transbordos, maximizando dimensão do grupo" << std::endl;
                std::cout << "2- Maxima dimensao do grupo (qualquer encaminhamento)" << std::endl;
                std::cout << std::endl;
                std::cout << "Selecione a opcao: ";
                std::cin >> choice2;

                if (choice2 == '1'){
                    graphCap.bfs(src, dest);
                }
                else if (choice2 == '2') {
                    graphCap.widestPath(src, dest);
                }
                break;

            case '2':
                //graphDur.cpmES();
                graphCap.edmondKarpFlux(a, b);
                break;

            case '3':
                exit(0);
        }
    }
}
