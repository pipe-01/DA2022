#ifndef DA2022_ENCOMENDA_H
#define DA2022_ENCOMENDA_H

class Encomenda{

private:
    int volume;
    int peso;
    int recompensa;
    int duracao;
    int tamanho; //volume + peso

public:
    Encomenda();
    Encomenda(int volume, int peso, int recompensa, int duracao, int tamanho);
    int getVolume() const;
    int getPeso() const;
    int getRecompensa() const;
    int getDuracao() const;
    int getTamanho() const;

};

#endif //DA2022_ENCOMENDA_H
