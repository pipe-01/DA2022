#ifndef ESTAFETA_H
#define ESTAFETA_H

class Estafeta{
private:
    std::string matricula;
    unsigned int volumeMax;
    unsigned int pesoMax;
    unsigned int custo;

public:
     Estafeta();
     Estafeta(std::string matricula, unsigned int volumeMax, unsigned int pesoMax, unsigned int custo);
     unsigned int getVolumeMax() const;
     unsigned int getPesoMax() const;
     unsigned int getCusto() const;
     std::string getMatricula() const;

};

#endif