#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <tuple>
#include <list>
#include "encomenda.h"
#include "carrinha.h"
#include "utils.h"

/**
* este método ordena um vetor de encomendas por ordem decrescente de recompensa / (peso + volume)
*
* @param *requests pointer para um vetor de encomendas
* @return void
*/

void sortRequests(std::vector<Encomenda> *requests);

/**
* este método ordena um vetor de carrinhas por ordem crescente de custo / (peso máximo + volume máximo)
*
* @param *workers pointer para um vetor de carrinhas
* @return void
*/
void sortWorkers(std::vector<Carrinha> *workers);

/**
* este método fornece o máximo de lucro que é possível obter para um certo conjunto de encomendas
*
* @param requests vetor de encomendas
* @param workers vetor de carrinhas
* @return int lucro máximo
*/
int cenario2(std::vector<Encomenda> requests, std::vector<Carrinha> workers);