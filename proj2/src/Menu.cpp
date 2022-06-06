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
    std::set<int> nodes;

    while(true){
        int src, dest, cap, trans, dimen;
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
                std::cout << "2.1 - Cenario 2.1" << std::endl;
                std::cout << "2.2 - Cenario 2.2" << std::endl;
                std::cout << "2.3 - Cenario 2.3" << std::endl;
                std::cout << "2.4 - Cenario 2.4" << std::endl;
                std::cout << "2.5-  Cenario 2.5" << std::endl;
                std::cout << std::endl;
                std::cout << "Selecione a opcao: ";
                std::cin >> choice2;

                if(choice2 == "2.1"){

                    std::vector<std::vector<int>> paths;
                    Graph<int> graphCap;
                    file.buildGraphCap(graphCap);
                    
                    std::cout << "Partida: " << std::endl;
                    std::cin >> src;
                    std::cout << "Chegada: " << std::endl;
                    std::cin >> dest;
                    std::cout << "Dimensao do grupo: " << std::endl;
                    std::cin >> dimen;
                    std::cout << std::endl;

                    paths = graphCap.dfs(src, dest);
                    int unallocated = dimen;
                    
                    for(auto path: paths){
                        if(unallocated>0){
                            int flux = graphCap.getFlux(path);
                            std::cout << "Path: ";
                            graphCap.printPath(path);
                            std::cout << "Path's Flux: " << flux << std::endl;
                            int allocated = unallocated;
                            if(unallocated > flux){
                                allocated = flux;
                            }
                            std::cout << "Passengers allocated to this path: " << allocated << std::endl;
                            unallocated -= flux;
                            if(unallocated < 0) unallocated = 0;
                            std::cout << "Free spots for this path: " << flux - allocated << std::endl;
                            std::cout << "Passegers to still allocate to a path: " << unallocated << std::endl << std::endl;
                        }
                    }

                }
                else if(choice2 == "2.2"){
                    std::vector<std::vector<int>> paths;
                    Graph<int> graphCap;
                    file.buildGraphCap(graphCap);
                    std::cout << "Partida: " << std::endl;
                    std::cin >> src;
                    std::cout << "Chegada: " << std::endl;
                    std::cin >> dest;
                    std::cout << "Dimensao do grupo: " << std::endl;
                    std::cin >> dimen;
                    std::cout << std::endl;

                    paths = graphCap.dfs(src, dest);

                    std::vector<std::vector<int>> aux(paths);
                    int unallocated = dimen;

                    while(unallocated > 0){
                        int maxIndex = 0;
                        int fluxMax = 0;
                        for(unsigned int i = 0; i < aux.size(); i++){
                            int flux = graphCap.getFlux(aux.at(i));
                            if(flux > fluxMax){
                                fluxMax = flux;
                                maxIndex = i;
                            }
                        }
                        std::cout << "Path: ";
                        graphCap.printPath(aux.at(maxIndex));
                        std::cout << "Path's Flux: " << fluxMax << std::endl;
                        int allocated = unallocated;
                        if(allocated > fluxMax){
                            allocated = fluxMax;
                        }
                        std::cout << "Passengers allocated to this path: " << allocated << std::endl;
                        unallocated -= fluxMax;
                        if(unallocated < 0) unallocated = 0;
                        std::cout << "Free spots for this path: " << fluxMax - allocated << std::endl;
                        std::cout << "Passegers to still allocate to a path: " << unallocated << std::endl << std::endl;
                        aux.erase(aux.begin()+maxIndex);

                        //Case all paths were filled and there are still unallocated people
                        if(aux.empty()){
                            if(unallocated>0){
                                std::cout << "All paths were filled, but there are still " << unallocated << " unallocated  people" << std::endl;
                            }
                            else{
                                std::cout << "Everyone allocated to a path!" << std::endl;
                            }
                            break;
                        }
                    }
                }
                else if (choice2 == "2.3"){

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

                else if (choice2 == "2.5"){
                    Graph<int> graphDur;

                    file.buildGraphDur(graphDur);

                    std::cout << "Partida: " << std::endl;
                    std::cin >> src;
                    std::cout << std::endl;

                    graphDur.biggestWaitingTime(src);
                }
                break;

            case '3':
                exit(0);
        }
    }
}