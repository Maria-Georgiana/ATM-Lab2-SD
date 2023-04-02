//
// Created by Maria on 4/1/2023.
//

#ifndef ATM_LAB2_SD_TRANZACTIE_H
#define ATM_LAB2_SD_TRANZACTIE_H

#include <map>
#include <vector>

class Tranzactie {
private:
    static int lastId;
    int id;
    int suma;
    int bancnote;
    int numar_bancnote;
public:
    Tranzactie(float suma, int bancnote, int numar_bancnote);
    ~Tranzactie();
    int getId();
    int getSuma();
    int getBancnote();
    int getNumarBancnote();
    void afisareTranzactie();
};

#endif //ATM_LAB2_SD_TRANZACTIE_H
