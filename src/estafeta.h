#ifndef ESTAFETA_H
#define ESTAFETA_H

using namespace std;

class Estafeta{

    public:

        Estafeta(unsigned int eVol, unsigned int eWeight, unsigned int eCost);
        unsigned int getVolume();
        unsigned int getWeight();
        unsigned int getCost();
        
    private:
        unsigned int maxVolume;
        unsigned int maxWeight;
        unsigned int cost;
};

#endif