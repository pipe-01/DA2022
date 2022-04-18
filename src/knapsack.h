#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <tuple>
#include <list>
#include "encomenda.h"
#include "carrinha.h"

// using namespace std;

double ratio(int cost, int vol, int weight);

bool comparePayment(Encomenda x, Encomenda y);

bool compareCost(Carrinha x, Carrinha y);

void sortRequests(std::vector<Encomenda> *requests);

void sortWorkers(std::vector<Carrinha> *workers);

int cenario2(std::vector<Encomenda> requests, std::vector<Carrinha> workers);
