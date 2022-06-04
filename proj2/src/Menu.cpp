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

    File file;

    while(true){
        int src, dest, cap, trans;
        std::vector<int> path;
        std::cout << "Selecione a opcao (choice1): ";
        std::cin >> choice1;
        switch (choice1) {
            case '1':

                std::cout << "1.1- Cenario 1.1" << std::endl;
                std::cout << "1.2- Cenario 1.2" << std::endl;
                std::cout << std::endl;
                std::cout << "Selecione a opcao: ";
                std::cin >> choice2;


                if (choice2 == "1.1"){

                    Graph<int> graphCap;

                    file.buildGraphCap(graphCap);

                    std::cout << "Partida: " << std::endl;
                    std::cin >> src;
                    std::cout << "Chegada: " << std::endl;
                    std::cin >> dest;
                    std::cout << std::endl;

                    path = graphCap.widestPath(src, dest);
                    graphCap.printPath(path);
                    cap = graphCap.pathCap(path);

                    std::cout << "Maximum number of people in this path: " << cap << std::endl;
                    std::cout << std::endl;
                }
                else if (choice2 == "1.2") {

                    Graph<int> graphCap;

                    file.buildGraphCap(graphCap);

                    std::cout << "Partida: " << std::endl;
                    std::cin >> src;
                    std::cout << "Chegada: " << std::endl;
                    std::cin >> dest;
                    std::cout << std::endl;

                    path = graphCap.bfs(src, dest);
                    trans = graphCap.pathTrans(path);

                    std::cout << "Numero de transbordos do caminho: " << trans << std::endl;

                }
                break;

            case '2':
                std::cout << "2.3- Cenario 2.3" << std::endl;
                std::cout << "2.4- Ceario 2.4" << std::endl;
                std::cout << std::endl;
                std::cout << "Selecione a opcao: ";
                std::cin >> choice2;

                if (choice2 == "2.3"){

                    Graph<int> graphCap;

                    file.buildGraphCap(graphCap);

                    std::cout << "Partida: " << std::endl;
                    std::cin >> src;
                    std::cout << "Chegada: " << std::endl;
                    std::cin >> dest;
                    std::cout << std::endl;

                    graphCap.edmondKarpFlux(src, dest);
                }
                else if (choice2 == "2.4"){

                    Graph<int> graphDur;

                    file.buildGraphDur(graphDur);

                    int durMin = graphDur.cpmES();
                    std::cout << "Reunem-se novamente apos " << durMin << " minutos" << std::endl;
                    std::cout << std::endl;
                }
                break;

            case '3':
                exit(0);
        }
    }
}