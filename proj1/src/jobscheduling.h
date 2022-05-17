#include <iostream>
#include <algorithm>
#include <vector>
#include "File.h"
#include "encomenda.h"
#include "utils.h"

#define MAXHOURS 28800

/**
 * este método fornece as encomendas expresso que foram possíveis entregar tendo em conta a limitação de tempo
 *
 * @param encomendas vetor de encomendas
 * @return double número de encomendas
 */

double cenario3(std::vector<Encomenda> encomendas);

/**
 * @brief
 *
 * @param array
 */

void printVector(std::vector<Encomenda> array);