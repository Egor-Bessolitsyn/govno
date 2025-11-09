
#include <iostream>
#include "Keeper.h"
#include "Poet.h"
#include "Novelist.h"
#include "Scifi.h"
#include "Exceptions.h"
#include <limits>

void printMenu() {
    std::cout << "----- Menu -----\n";
    std::cout << "1. Add Poet\n2. Add Novelist\n3. Add Sci-Fi author\n4. Remove item\n5. Print all\n6. Save to file\n7. Load from file\n8. Exit\n";
}

int main() {
    Keeper keeper;
    while (true) {
        printMenu();
        std::cout << "Choose option: ";
        int opt;
        if (!(std::cin >> opt)) {
            std::cin.clear();
            std::string dummy; std::getline(std::cin, dummy);
            continue;
        }
        std::string tmp; std::getline(std::cin, tmp); // consume endline
        try {
            if (opt==1) {
                Poet* p = new Poet();
                p->inputFromConsole();
                keeper.add(p);
            } else if (opt==2) {
                Novelist* n = new Novelist();
                n->inputFromConsole();
                keeper.add(n);
            } else if (opt==3) {
                Scifi* s = new Scifi();
                s->inputFromConsole();
                keeper.add(s);
            } else if (opt==4) {
                std::cout << "Index to remove: ";
                int idx; std::cin >> idx; std::getline(std::cin, tmp);
                keeper.removeAt(idx);
            } else if (opt==5) {
                keeper.printAll();
            } else if (opt==6) {
                std::cout << "Filename to save: ";
                std::string fname; std::getline(std::cin, fname);
                keeper.saveToFile(fname);
            } else if (opt==7) {
                std::cout << "Filename to load: ";
                std::string fname; std::getline(std::cin, fname);
                keeper.loadFromFile(fname);
            } else if (opt==8) {
                std::cout << "Exiting\n";
                break;
            } else {
                std::cout << "Unknown option\n";
            }
        } catch (const std::exception& ex) {
            std::cout << "Exception: " << ex.what() << "\n";
        }
    }
    return 0;
}
