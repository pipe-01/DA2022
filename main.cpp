 #include <iostream>
#include "File.h"

int main() {
    //no clion temos de usar o full path se nao nao conseguimos abrir o ficheiro ---> tenho de mudar
    File file("C:\\Users\\Filipe Pinto\\Desktop\\FEUP\\DA2022\\carrinhas.txt");
    file.readAndParse("C:\\Users\\Filipe Pinto\\Desktop\\FEUP\\DA2022\\carrinhas.txt");
    file.printCarrinhas();
    return 0;
}
