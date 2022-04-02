//
// Created by Filipe on 02/04/2022.
//

#ifndef DA2022_FILE_H
#define DA2022_FILE_H
#include <vector>
#include <iostream>
#include "carrinha.h"


class File {
private:
    std::string path;
    std::vector<Carrinha> carrinhas;


public:
    File(std::string path);

    std::vector<Carrinha> readAndParse(std::string path);

    void setPath(std::string path);

    std::string getPath();

    std::vector<Carrinha> getCarrinhas();

    void printCarrinhas();
};


#endif //DA2022_FILE_H
