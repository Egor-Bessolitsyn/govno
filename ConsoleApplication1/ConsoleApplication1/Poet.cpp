
#include "Poet.h"
#include <iostream>

Poet::Poet(): name(""), lifeYears(""), works(nullptr), worksCount(0) {
    std::cout << "[Poet] default constructor\n";
}

Poet::Poet(const std::string& name_, const std::string& lifeYears_, int worksCount_)
: name(name_), lifeYears(lifeYears_), worksCount(worksCount_) {
    std::cout << "[Poet] param constructor\n";
    works = new std::string[worksCount];
    for (int i=0;i<worksCount;i++) works[i] = "";
}

Poet::Poet(const Poet& other) : name(other.name), lifeYears(other.lifeYears), worksCount(other.worksCount) {
    std::cout << "[Poet] copy constructor\n";
    if (worksCount>0) {
        works = new std::string[worksCount];
        for (int i=0;i<worksCount;i++) works[i] = other.works[i];
    } else works = nullptr;
}

Poet::~Poet() {
    std::cout << "[Poet] destructor for " << name << "\n";
    delete[] works;
}

void Poet::inputFromConsole() {
    std::cout << "Enter poet full name: ";
    std::getline(std::cin, name);
    std::cout << "Enter years of life (e.g. 1900-1950): ";
    std::getline(std::cin, lifeYears);
    std::cout << "How many main works? ";
    std::string tmp; std::getline(std::cin, tmp); worksCount = std::stoi(tmp);
    delete[] works;
    works = new std::string[worksCount];
    for (int i=0;i<worksCount;i++) {
        std::cout << "Work " << i+1 << ": ";
        std::getline(std::cin, works[i]);
    }
}

void Poet::print(std::ostream& os) const {
    os << "Poet: " << name << " (" << lifeYears << ")\n";
    os << "Works (" << worksCount << "):\n";
    for (int i=0;i<worksCount;i++) os << "  - " << works[i] << "\n";
}

void Poet::saveToStream(std::ostream& os) const {
    os << int(getType()) << '\n';
    os << name << '\n' << lifeYears << '\n' << worksCount << '\n';
    for (int i=0;i<worksCount;i++) os << works[i] << '\n';
}

void Poet::loadFromStream(std::istream& is) {
    std::getline(is, name);
    std::getline(is, lifeYears);
    std::string tmp; std::getline(is, tmp); worksCount = std::stoi(tmp);
    delete[] works;
    works = new std::string[worksCount];
    for (int i=0;i<worksCount;i++) std::getline(is, works[i]);
}
