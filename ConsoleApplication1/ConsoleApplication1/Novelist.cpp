
#include "Novelist.h"
#include <iostream>

Novelist::Novelist(): name(""), lifeYears(""), works(nullptr), worksCount(0), bio("") {
    std::cout << "[Novelist] default constructor\n";
}

Novelist::Novelist(const std::string& name_, const std::string& lifeYears_, int worksCount_, const std::string& bio_)
: name(name_), lifeYears(lifeYears_), worksCount(worksCount_), bio(bio_) {
    std::cout << "[Novelist] param constructor\n";
    works = new std::string[worksCount];
    for (int i=0;i<worksCount;i++) works[i] = "";
}

Novelist::Novelist(const Novelist& other): name(other.name), lifeYears(other.lifeYears), worksCount(other.worksCount), bio(other.bio) {
    std::cout << "[Novelist] copy constructor\n";
    if (worksCount>0) {
        works = new std::string[worksCount];
        for (int i=0;i<worksCount;i++) works[i] = other.works[i];
    } else works = nullptr;
}

Novelist::~Novelist() {
    std::cout << "[Novelist] destructor for " << name << "\n";
    delete[] works;
}

void Novelist::inputFromConsole() {
    std::cout << "Enter novelist full name: ";
    std::getline(std::cin, name);
    std::cout << "Enter years of life (e.g. 1900-1950): ";
    std::getline(std::cin, lifeYears);
    std::cout << "How many works? ";
    std::string tmp; std::getline(std::cin, tmp); worksCount = std::stoi(tmp);
    delete[] works;
    works = new std::string[worksCount];
    for (int i=0;i<worksCount;i++) {
        std::cout << "Work " << i+1 << ": ";
        std::getline(std::cin, works[i]);
    }
    std::cout << "Short biography: ";
    std::getline(std::cin, bio);
}

void Novelist::print(std::ostream& os) const {
    os << "Novelist: " << name << " (" << lifeYears << ")\n";
    os << "Works (" << worksCount << "):\n";
    for (int i=0;i<worksCount;i++) os << "  - " << works[i] << "\n";
    os << "Bio: " << bio << "\n";
}

void Novelist::saveToStream(std::ostream& os) const {
    os << int(getType()) << '\n';
    os << name << '\n' << lifeYears << '\n' << worksCount << '\n';
    for (int i=0;i<worksCount;i++) os << works[i] << '\n';
    os << bio << '\n';
}

void Novelist::loadFromStream(std::istream& is) {
    std::getline(is, name);
    std::getline(is, lifeYears);
    std::string tmp; std::getline(is, tmp); worksCount = std::stoi(tmp);
    delete[] works;
    works = new std::string[worksCount];
    for (int i=0;i<worksCount;i++) std::getline(is, works[i]);
    std::getline(is, bio);
}
