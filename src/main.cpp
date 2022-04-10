#include <iostream>
#include "File.h"
#include "binpacking.h"

int main() {
    File file;
    file.readAndParseCar("carrinhas.txt");
    file.readAndParseEnc("encomendas.txt");
    //file.printCarrinhas();
    file.printEncomendas();
    return 0;
}
