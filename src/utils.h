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
bool compareTime(const Encomenda &e1, const Encomenda &e2);

bool cmpEncomenda(const Encomenda &e1, const Encomenda &e2);

bool cmpCarrinhas(const Carrinha &c1, const Carrinha &c2);

bool comparePayment(const Encomenda &e1, const Encomenda &e2);

bool compareCost(const Carrinha &c1, const Carrinha &c2);

#endif //PROJETODA_UTILS_H
