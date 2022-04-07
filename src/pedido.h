#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido{

    public:

        Pedido(unsigned int pVol, unsigned int pWeight, unsigned int pPayment);
        unsigned int getVolume();
        unsigned int getWeight();
        unsigned int getPayment();

    private:
        unsigned int volume;
        unsigned int weight;
        unsigned int payment;
};

#endif