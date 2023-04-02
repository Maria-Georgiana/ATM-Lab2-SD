#include <iostream>
#include "Collection.h"
#include "ATM.h"

using namespace std;

int main() {
    Collection colectie = Collection();
    colectie.add(10, 100);
    colectie.add(20, 40);
    colectie.add(50, 30);
    colectie.add(100, 20);
    colectie.add(200, 10);
    colectie.add(500, 5);
    ATM atm = ATM(colectie);
    int optiune = 0;
    float suma = 0;
    int id, bancnota, numar_bancnote;

    while (optiune != 3) {
        cout << "Meniu:" << endl;
        cout << "1. Afisare bancnote disponibile" << endl;
        cout << "2. Adaugare tranzactie" << endl;
        cout << "3. Iesire" << endl;
        cout << "Introduceti optiunea: \n";
        cin >> optiune;

        switch (optiune) {
            case 1:
                atm.afisare_bancnote_disponibile();
                break;
            case 2:
                cout << "Introduceti suma:\n";
                cin >> suma;
                cout << "Introduceti tipul bancnotei:\n";
                cin >> bancnota;
                cout << "Introduceti numarul de bancnote:\n";
                cin >> numar_bancnote;
                atm.adaugare_tranzactie(suma, bancnota, numar_bancnote);
                cout << "Tranzactia cu suma: " << suma << " lei platita cu bancnote de " << bancnota << " lei x " << numar_bancnote << " a fost realizata cu succes." << endl;
                cout << "Doriti sa vedeti toate tranzactiile efectuate?\n";
                cout << "Introduceti 1 (daca doriti sa vedeti toate tranzactiile efectuate) sau 0 in caz contrar: \n";
                int opt;
                cin >> opt;
                if (opt == 1)
                    atm.afisare_tranzactii();
                break;
            case 3:
                cout << "La revedere!" << endl;
                break;
            default:
                cout << "Optiunea introdusa nu este valida. Va rugam incercati din nou." << endl;
                break;
        }
    }
    return 0;
}
