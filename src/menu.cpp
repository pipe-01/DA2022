#include "menu.h"
#include "carrinha.h"
#include "File.h"
#include "jobscheduling.h"
#include "knapsack.h"

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
    Carrinha carrinha;
    int numEstafetas;
    double tmpMedio;
    int profit;

    while(true){
        std::cout << "Selecione a opcao: ";
        std::cin >> choice;
        switch (choice) {
            case '1':
                numEstafetas = carrinha.minNumEstafetas(carrinhas, encomendas);
                std::cout << "Numero minimo de estafetas: " + std::to_string(numEstafetas) << std::endl;
                break;
            case '2':
                profit = cenario2(encomendas,carrinhas);
                std::cout << "profit: " << profit << std::endl;
                break;
            case '3':
                tmpMedio = cenario3(encomendas);
                std::cout << "Tempo medio minimo: " << tmpMedio << std::endl;
                break;
            case '4':
                exit(0);
        }
    }
}