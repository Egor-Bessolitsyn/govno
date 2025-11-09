
#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"

class Keeper {
    Base** items;
    int size;
    int capacity;

    void ensureCapacity();
public:
    Keeper();
    Keeper(const Keeper& other);
    ~Keeper();

    void add(Base* b); // takes ownership
    void removeAt(int index); // delete object
    void printAll() const;
    int getSize() const { return size; }

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    Base* getAt(int idx) const;
    void clear();
};

#endif
