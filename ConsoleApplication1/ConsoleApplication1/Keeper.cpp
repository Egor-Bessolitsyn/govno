
#include "Keeper.h"
#include "Exceptions.h"
#include "Poet.h"
#include "Novelist.h"
#include "Scifi.h"
#include <iostream>
#include <fstream>

Keeper::Keeper(): items(nullptr), size(0), capacity(0) {
    std::cout << "[Keeper] default constructor\n";
}

Keeper::Keeper(const Keeper& other): items(nullptr), size(0), capacity(0) {
    std::cout << "[Keeper] copy constructor\n";
    if (other.size>0) {
        capacity = other.size;
        items = new Base*[capacity];
        for (int i=0;i<other.size;i++) items[i] = other.items[i]->clone();
        size = other.size;
    }
}

Keeper::~Keeper() {
    std::cout << "[Keeper] destructor\n";
    clear();
    delete[] items;
}

void Keeper::ensureCapacity() {
    if (capacity==0) {
        capacity = 4;
        items = new Base*[capacity];
    } else if (size>=capacity) {
        int newcap = capacity * 2;
        Base** tmp = new Base*[newcap];
        for (int i=0;i<size;i++) tmp[i] = items[i];
        delete[] items;
        items = tmp;
        capacity = newcap;
    }
}

void Keeper::add(Base* b) {
    ensureCapacity();
    items[size++] = b;
    std::cout << "[Keeper] added item, new size = " << size << "\n";
}

void Keeper::removeAt(int index) {
    if (index<0 || index>=size) throw IndexException("Index out of range in removeAt");
    delete items[index];
    for (int i=index;i<size-1;i++) items[i]=items[i+1];
    size--;
    std::cout << "[Keeper] removed item at " << index << ", new size = " << size << "\n";
}

void Keeper::printAll() const {
    for (int i=0;i<size;i++) {
        std::cout << "Item #" << i << ":\n";
        items[i]->print(std::cout);
        std::cout << "----------------------\n";
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream ofs(filename.c_str());
    if (!ofs) throw FileException(std::string("Cannot open file for writing: ")+filename);
    ofs << size << '\n';
    for (int i=0;i<size;i++) items[i]->saveToStream(ofs);
    ofs.close();
    std::cout << "[Keeper] saved to " << filename << "\n";
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream ifs(filename.c_str());
    if (!ifs) throw FileException(std::string("Cannot open file for reading: ")+filename);
    clear();
    std::string tmp; std::getline(ifs, tmp);
    int newSize = std::stoi(tmp);
    for (int i=0;i<newSize;i++) {
        std::getline(ifs, tmp);
        int t = std::stoi(tmp);
        Base* obj = nullptr;
        if (t==Base::POET) obj = new Poet();
        else if (t==Base::NOVELIST) obj = new Novelist();
        else if (t==Base::SCIFI) obj = new Scifi();
        else throw FileException("Unknown type tag in file");
        obj->loadFromStream(ifs);
        add(obj);
    }
    ifs.close();
    std::cout << "[Keeper] loaded from " << filename << "\n";
}

Base* Keeper::getAt(int idx) const {
    if (idx<0 || idx>=size) throw IndexException("Index out of range in getAt");
    return items[idx];
}

void Keeper::clear() {
    for (int i=0;i<size;i++) delete items[i];
    size = 0;
}
