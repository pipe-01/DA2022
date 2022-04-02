//
// Created by Filipe on 02/04/2022.
//

#ifndef DA2022_ENCOMENDA_H
#define DA2022_ENCOMENDA_H

struct Encomenda{
    int volume;
    int peso;
    int recompensa;
    int duracao;


    Encomenda(int vol, int peso, int custo, int dur)
        : volume(vol), peso(peso), recompensa(custo), duracao(dur) {}
    Encomenda()
            : volume(0), peso(0), recompensa(0), duracao(0) {}
};

#endif //DA2022_ENCOMENDA_H
