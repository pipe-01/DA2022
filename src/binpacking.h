#ifndef PROJETODA_BINPACKING_H
#define PROJETODA_BINPACKING_H

#include "carrinha.h"
#include "encomenda.h"
#include "utils.h"

/**
* este método fornece o número mínimo de estafetas necessário para entregar certo número de encomendas
* @param carrinhas vetor de carrinhas disponíveis para entregar as encomendas
* @param encomendas vetor de encomendas a serem entregues
* @return int número de encomendas
*/

int cenario1(std::vector<Carrinha> carrinhas, std::vector<Encomenda> encomendas);


#endif
