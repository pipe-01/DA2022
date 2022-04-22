#ifndef PROJETODA_UTILS_H
#define PROJETODA_UTILS_H

// double ratio(int cost, int vol, int weight);

/**
* este método fornece uma relação entre um valor e a soma de outros dois valores
*
* @param cost dividendo da relação
* @param vol uma das parcelas do divisor da relação
* @param weight outra das parcelas do divisor da relação
* @return double valor da relação cost / (vol + peso)
*/
double ratio(int cost, int vol, int weight);

/**
* este método permite estabelecer uma comparação de encomendas por ordem crescente com base no tempo estimado de duração da entrega
*
* @param e1 referência de uma encomenda que entra na comparação
* @param e2 referência de outra encomenda que entra na comparação
* @return TRUE se e1 é demora menos tempo a entregar que e2
* @return FALSE se se verificar o contrário
*/
bool compareTime(const Encomenda &e1, const Encomenda &e2);

/**
* este método permite estabelecer uma comparação de encomendas por ordem decrescente com base na soma peso da encomenda + volume da encomenda
*
* @param e1 referência de uma encomenda que entra na comparação
* @param e2 referência de outra encomenda que entra na comparação
* @return TRUE se e2 tem peso + volume menor que e1
* @return FALSE se se verificar o contrário
*/
bool cmpEncomenda(const Encomenda &e1, const Encomenda &e2);

/**
* este método permite estabelecer uma comparação de carrinhas por ordem decrescente com base no seu peso
*
* @param e1 referência de uma encomenda que entra na comparação
* @param e2 referência de outra encomenda que entra na comparação
* @return TRUE se c2 tem uma capacidade de peso máxima menor que c1
* @return FALSE se se verificar o contrário
*/
bool cmpCarrinhas(const Carrinha &c1, const Carrinha &c2);

/**
* este método permite estabelecer uma comparação de encomendas por ordem decrescente com base na relação estabelecida no método ratio
*
* @param x referência de uma encomenda que entra na comparação
* @param y referência de outra encomenda que entra na comparação
* @return TRUE se a encomenda y tem um valor de ratio menor que a encomenda x
* @return FALSE se se verificar o contrário
*/
bool comparePayment(Encomenda x, Encomenda y);

/**
* este método permite estabelecer uma comparação de carrinhas por ordem crescente com base na relação estabelecida no método ratio
*
* @param x referência de uma encomenda que entra na comparação
* @param y referência de outra encomenda que entra na comparação
* @return TRUE se a carrinha y tem um valor de ratio menor que a carrinha x
* @return FALSE se se verificar o contrário
*/
bool compareCost(Carrinha x, Carrinha y);

#endif 
