#ifndef SEM2_COLLECTION_ITERATOR_H
#define SEM2_COLLECTION_ITERATOR_H


#include "Collection.h"

class Iterator {
private:
    Collection collection;
    int position;
public:
    Iterator(Collection c);
    bool valid();
    void first();
    void next();
    int current();
    int getCurrentOccurrences();
};

#endif
