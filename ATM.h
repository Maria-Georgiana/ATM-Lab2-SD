//
// Created by Maria on 4/1/2023.
//

#ifndef ATM_LAB2_SD_ATM_H
#define ATM_LAB2_SD_ATM_H

#include "Collection.h"
#include "Tranzactie.h"
#include <vector>

class ATM {
private:
    Collection Colectie;
    Tranzactie *Tranzactii[100];
public:
    ATM(const Collection &colection);
    ~ATM();
    void afisare_bancnote_disponibile();
    void afisare_tranzactii();
    bool adaugare_tranzactie(float suma, int tip, int numarBancnote);
};


#endif //ATM_LAB2_SD_ATM_H
