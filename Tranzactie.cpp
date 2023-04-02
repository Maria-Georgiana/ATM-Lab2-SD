//
// Created by Maria on 4/1/2023.
//

#include "Tranzactie.h"
#include <iostream>

using namespace std;

int Tranzactie::lastId = 0;

Tranzactie::Tranzactie(float suma, int bancnote, int numar_bancnote) {
    this->id = ++lastId;
    this->suma = suma;
    this->bancnote = bancnote;
    this->numar_bancnote = numar_bancnote;
    if (lastId > 100) {
        lastId = 1;
    }
}

int Tranzactie::getId() {
    return this->id;
}

int Tranzactie::getSuma() {
    return this->suma;
}

int Tranzactie::getBancnote() {
    return this->bancnote;
}

int Tranzactie::getNumarBancnote() {
    return this->numar_bancnote;
}

void Tranzactie::afisareTranzactie() {
    cout << "Tranzactie #" << this->id << ": " << this->suma << " lei platiti cu bancnote de " << this->bancnote << " lei x " << this->numar_bancnote << endl;
}

Tranzactie::~Tranzactie() {
    this->suma = 0;
    this->bancnote = 0;
    this->numar_bancnote = 0;
}