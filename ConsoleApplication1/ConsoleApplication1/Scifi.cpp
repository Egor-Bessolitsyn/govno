
#include "Scifi.h"
#include <iostream>

Scifi::Scifi(): name(""), works(nullptr), worksCount(0), filmsByBooks(false) {
    std::cout << "[Scifi] default constructor\n";
}

Scifi::Scifi(const std::string& name_, int worksCount_, bool filmsByBooks_)
: name(name_), worksCount(worksCount_), filmsByBooks(filmsByBooks_) {
    std::cout << "[Scifi] param constructor\n";
    works = new std::string[worksCount];
    for (int i=0;i<worksCount;i++) works[i] = "";
}

Scifi::Scifi(const Scifi& other): name(other.name), worksCount(other.worksCount), filmsByBooks(other.filmsByBooks) {
    std::cout << "[Scifi] copy constructor\n";
    if (worksCount>0) {
        works = new std::string[worksCount];
        for (int i=0;i<worksCount;i++) works[i] = other.works[i];
    } else works = nullptr;
}

Scifi::~Scifi() {
    std::cout << "[Scifi] destructor for " << name << "\n";
    delete[] works;
}

void Scifi::inputFromConsole() {
    std::cout << "Enter scifi author full name: ";
    std::getline(std::cin, name);
    std::cout << "How many works? ";
    std::string tmp; std::getline(std::cin, tmp); worksCount = std::stoi(tmp);
    delete[] works;
    works = new std::string[worksCount];
    for (int i=0;i<worksCount;i++) {
        std::cout << "Work " << i+1 << ": ";
        std::getline(std::cin, works[i]);
    }
    std::cout << "Were films made from these books? (1 - yes, 0 - no): ";
    std::getline(std::cin, tmp);
    filmsByBooks = (tmp == "1");
}

void Scifi::print(std::ostream& os) const {
    os << "Sci-Fi author: " << name << "\n";
    os << "Works (" << worksCount << "):\n";
    for (int i=0;i<worksCount;i++) os << "  - " << works[i] << "\n";
    os << "Films based on books: " << (filmsByBooks ? "Yes" : "No") << "\n";
}

void Scifi::saveToStream(std::ostream& os) const {
    os << int(getType()) << '\n';
    os << name << '\n' << worksCount << '\n';
    for (int i=0;i<worksCount;i++) os << works[i] << '\n';
    os << (filmsByBooks ? "1" : "0") << '\n';
}

void Scifi::loadFromStream(std::istream& is) {
    std::getline(is, name);
    std::string tmp; std::getline(is, tmp); worksCount = std::stoi(tmp);
    delete[] works;
    works = new std::string[worksCount];
    for (int i=0;i<worksCount;i++) std::getline(is, works[i]);
    std::getline(is, tmp); filmsByBooks = (tmp == "1");
}
