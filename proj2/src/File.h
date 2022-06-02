#ifndef PROJETODA3_FILE_H
#define PROJETODA3_FILE_H


#include "graph.h"

class File {

public:
    File();
    /**
    * este método permite ler os ficheiros de texto do dataset e construir os grafos correspondentes com esses dados
    *
    * @param graphCap grafo de inteiros, passado por referência, que vai receber o grafo do ficheiro de texto correspondente e cujo peso corresponde à capacidade de cada veículo
    * @return void
    */
    void buildGraphCap(Graph<int> &graphCap);
    /**
    * este método permite ler os ficheiros de texto do dataset e construir os grafos correspondentes com esses dados
    *
    * @param graphDur grafo de inteiros, passado por referência, que vai receber o grafo do ficheiro de texto correspondente e cujo peso corresponde o tempo que demora a chegar de um nó ao outro
    * @return void
    */
    void buildGraphDur(Graph<int> &graphDur);

};


#endif //PROJETODA3_FILE_H
