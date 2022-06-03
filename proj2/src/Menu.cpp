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
    File file;

    while(true){
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
                    file.buildGraphCap(graphCap);

                    std::cout << "Partida: ";
                    std::cin >> src;
                    std::cout << "Chegada: " ;
                    std::cin >> dest;
                    std::cout << std::endl;

                    graphCap.widestPath(src, dest);
                }
                else if (choice2 == "1.2") {

                    file.buildGraphCap(graphCap);

                    std::cout << "Partida: " ;
                    std::cin >> src;
                    std::cout << "Chegada: " ;
                    std::cin >> dest;
                    std::cout << std::endl;

                    graphCap.bfs(src, dest);
                }
                break;

            case '2':
                std::cout << "2.3- Cenario 2.3" << std::endl;
                std::cout << "2.4- Ceario 2.4" << std::endl;
                std::cout << std::endl;
                std::cout << "Selecione a opcao: ";
                std::cin >> choice2;

                if (choice2 == "2.3"){

                    file.buildGraphCap(graphCap);

                    std::cout << "Partida: " ;
                    std::cin >> src;
                    std::cout << "Chegada: ";
                    std::cin >> dest;
                    std::cout << std::endl;

                    graphCap.edmondKarpFlux(src, dest);
                }
                else if (choice2 == "2.4"){
                    file.buildGraphDur(graphDur);

                    int durMin = graphDur.cpmES();
                    std::cout << "Reunem-se novamente após " << durMin << " minutos" << std::endl;
                    std::cout << std::endl;
                }
                break;

            case '3':
                exit(0);
        }
    }
}
