#include <iostream>
#include <algorithm>
#include <vector>
#include "File.h"
#include "encomenda.h"

#define MAXHOURS 28800

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool compareTime(Encomenda a, Encomenda b);

/**
 * @brief 
 * 
 * @param encomendas 
 * @return double 
 */
double cenario3(std::vector<Encomenda> encomendas);

/**
 * @brief 
 * 
 * @param array 
 */
void printVector(std::vector<Encomenda> array);