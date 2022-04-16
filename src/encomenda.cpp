#include "encomenda.h"

Encomenda::Encomenda(): volume(0), peso(0), recompensa(0), duracao(0), tamanho(0) {}

Encomenda::Encomenda(int volume, int peso, int recompensa, int duracao, int tamanho) {
    this->volume = volume;
    this->peso = peso;
    this->recompensa = recompensa;
    this->duracao = duracao;
    this->tamanho = peso+volume;
}

int Encomenda::getVolume() const{
    return volume;
}

int Encomenda::getPeso() const{
    return peso;
}

int Encomenda::getRecompensa() const{
    return recompensa;
}

int Encomenda::getDuracao() const{
    return duracao;
}

int Encomenda::getTamanho() const{
    return tamanho;
}