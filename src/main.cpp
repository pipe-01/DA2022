#include "File.h"
#include "menu.h"

int main() {
    File file;
    std::vector<Carrinha> carrinhas = file.readAndParseCar("C:\\Users\\ASUS\\PROJETODA\\DA2022\\src\\carrinhas.txt");
    std::vector<Encomenda> encomendas = file.readAndParseEnc("C:\\Users\\ASUS\\PROJETODA\\DA2022\\src\\encomendas.txt");
    //file.printCarrinhas();
    //file.printEncomendas();
    Menu menu;
    menu.showMenu();
    menu.takeInput(carrinhas, encomendas);
}