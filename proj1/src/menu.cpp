#include "menu.h"


Menu::Menu(){}

void Menu::showMenu(){
    std::cout << "Bem vindo a plataforma de crowdsourcing!" << std::endl;
    std::cout << "Por favor, selecione o cenario que pretende simular:" << std::endl;
    std::cout << std::endl;
    std::cout << "1- Minimizacao do numero de estafetas" << std::endl;
    std::cout << "2- Maximizacao do lucro da empresa" << std::endl;
    std::cout << "3- Otimizacao das entregas expresso" << std::endl;
    std::cout << "4- Sair da plataforma" << std::endl;
    std::cout << std::endl;
}

void Menu::takeInput(std::vector<Carrinha> carrinhas, std::vector<Encomenda> encomendas){
    int numEstafetas;
    double numEncomendasExpresso;
    int profit;

    while(true){
        std::cout << "Selecione a opcao: ";
        std::cin >> choice;
        switch (choice) {
            case '1':
                numEstafetas = cenario1(carrinhas, encomendas);
                std::cout << "Foram usados um total de " << numEstafetas << " estafetas para a entrega das " << encomendas.size() << " encomendas" << std::endl;
                break;
            case '2':
                profit = cenario2(encomendas,carrinhas);
                std::cout << "Lucro maximizado para a entrega das " << encomendas.size() << " corresponde a um valor de " << profit << std::endl;
                break;
            case '3':
                numEncomendasExpresso = cenario3(encomendas);
                std::cout << "Foram alocadas " << numEncomendasExpresso << " encomendas numa carrinha" << std::endl;
                break;
            case '4':
                exit(0);
        }
    }
}