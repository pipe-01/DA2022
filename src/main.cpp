#include <iostream>
#include "File.h"
#include "jobscheduling.h"

int main() {
    File file;
    file.readAndParseCar("carrinhas.txt");
    file.readAndParseEnc("encomendas.txt");
    //file.printCarrinhas();
    //file.printEncomendas();

    double tm = cenario3(file.getEncomendas());
    std::cout << "duracao media: " << tm << std::endl;
    return 0;
}
