//
// Created by Maria on 4/1/2023.
//

#include "ATM.h"

ATM::ATM(const Collection &colection) {
    this->Colectie = colection;
    for (int i = 1; i < 100; i++)
        this->Tranzactii[i] = nullptr;
}

void ATM::afisare_bancnote_disponibile() {
    this->Colectie.afis();
}

void ATM::afisare_tranzactii() {
    for (int i = 0; i < 100; i++) {
        Tranzactie* tranzactie = Tranzactii[i];
        if (tranzactie && tranzactie->getId() > 0 && tranzactie->getSuma() > 0
            && tranzactie->getBancnote() > 0 && tranzactie->getNumarBancnote() > 0) {
            tranzactie->afisareTranzactie();
        }
    }
}

bool ATM::adaugare_tranzactie(float suma, int bancnote, int numar_bancnote) {
//    for (int i = 0; i < 100; i++) {
//        if (this->Tranzactii[i] == nullptr) {
//            if (suma > 0 && numar_bancnote > 0 && bancnote > 0) {
//                this->Tranzactii[i] = new Tranzactie(suma, bancnote, numar_bancnote);
//                Colectie.set_occurrences(bancnote, numar_bancnote);
//                return true;
//            }
//        }
//    }
//    return false;
    if (suma <= 0 || bancnote <= 0 || numar_bancnote <= 0) {
        return false;
    }
    if (!Colectie.search(bancnote) || Colectie.nrOccurrences(bancnote) < numar_bancnote) {
        return false;
    }
    for (int i = 0; i < 100; i++) {
        if (this->Tranzactii[i] == nullptr) {
            this->Tranzactii[i] = new Tranzactie(suma, bancnote, numar_bancnote);
            Colectie.set_occurrences(bancnote, numar_bancnote); // scădem numărul de bancnote din colecție
            return true;
        }
    }
    return false;
}

ATM::~ATM() {
    for (int i = 0; i < 100; i++) {
        if (Tranzactii[i] != nullptr) {
            delete Tranzactii[i];
        }
    }
}
