#include "File.h"
#include "menu.h"

int main() {
    File file;

    std::vector<Carrinha> carrinhas = file.readAndParseCar("carrinhas.txt");
    std::vector<Encomenda> encomendas = file.readAndParseEnc("encomendas.txt");

    Menu menu;
    menu.showMenu();
    menu.takeInput(carrinhas, encomendas);
}
