#include "Collection.h"
#include <fstream>
#include "iostream"

using namespace std;

Collection::Collection() {
    elements = new TElem[5];
    occurrences = new int[5];
    distinctelements = 0;
    capacity = 5;
}

void Collection::add(TElem elem, int nr_bancnote) {
    bool exist = false;
    int position;
    for (int i = 0; i < distinctelements; i++)
        if (elem == elements[i]) {
            exist = true;
            position = i;
        }

    if (exist)
        occurrences[position] = occurrences[position] + 1;
    else {
        if(distinctelements + 1 > capacity){
            capacity *= 2;
            TElem *tmp = new TElem[capacity];
            for(int i=0; i<distinctelements;++i){
                tmp[i] = elements[i];
            }
            delete [] elements;
            elements = tmp;
            int *tmp2 = new int[capacity];
            for(int i=0; i<distinctelements;++i){
                tmp2[i] = occurrences[i];
            }
            delete [] occurrences;
            occurrences = tmp2;

        }
        elements[distinctelements] = elem;
        occurrences[distinctelements] = nr_bancnote;
        distinctelements++;
    }
}

bool Collection::remove(TElem elem) {
    bool exist = false;
    int position;
    for (int i = 0; i < distinctelements; i++) {
        if (elem == elements[i]) {
            exist = true;
            position = i;
        }
    }

    if (exist) {
        if (occurrences[position] > 1) {
            occurrences[position]--;
        } else {
            for (int i = position; i < distinctelements-1; i++) {
                elements[i] = elements[i + 1];
                occurrences[i] = occurrences[i + 1];
            }
            distinctelements--;
        }
        return true;
    }
    return false;
}

bool Collection::search(TElem elem) {
    for (int i = 0; i < distinctelements; i++)
        if (elem == elements[i])
            return true;
    return false;
}

int Collection::size() {
    return distinctelements;
}

int Collection::nrOccurrences(TElem elem) {
    for (int i = 0; i<distinctelements; i++)
        if (elements[i] == elem)
            return occurrences[i];
    return 0;
}

void Collection::destroy() {
    delete[] elements;
    delete[] occurrences;
    distinctelements=0;
}

int Collection::getAt(int position) {
    return elements[position];
}

void Collection::afis() {
    for (int i = 0; i < size(); i++) {
        if (nrOccurrences(getAt(i)) > 0)
            cout << "Bancnota: " << getAt(i) << " => numar bancnote: " << nrOccurrences(getAt(i)) << endl;
    }
}

void Collection::set_occurrences(TElem bancnota, int nr_bancnote) {
    for (int i = 0; i < distinctelements; i++) {
        if (elements[i] == bancnota) {
            occurrences[i] -= nr_bancnote;
        }
    }
}