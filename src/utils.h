#ifndef PROJETODA_UTILS_H
#define PROJETODA_UTILS_H

/**
 * @brief
 *
 * @param a
 * @param b
 * @return true
 * @return false
 */

// double ratio(int cost, int vol, int weight);

bool compareTime(const Encomenda &e1, const Encomenda &e2);

bool cmpEncomenda(const Encomenda &e1, const Encomenda &e2);

bool cmpCarrinhas(const Carrinha &c1, const Carrinha &c2);

bool comparePayment(Encomenda x, Encomenda y);

bool compareCost(Carrinha x, Carrinha y);

#endif 
