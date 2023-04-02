#include "Iterator.h"

Iterator::Iterator(Collection c) {
    this->collection = c;

    if(collection.size()!=0)
        this->position = 1;
    else
        this->position = 0;
}

bool Iterator::valid() {
    return (position > 0 && position <= collection.size());
}

void Iterator::first() {
    if(collection.size()!=0)
        this->position = 1;
}

void Iterator::next(){
    position++;
}

int Iterator::current() {
    return collection.getAt(position-1);
}

int Iterator::getCurrentOccurrences() {
    return collection.nrOccurrences(current());
} 