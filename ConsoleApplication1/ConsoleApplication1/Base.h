
#ifndef BASE_H
#define BASE_H

#include <string>
#include <iostream>

class Base {
public:
    enum Type { POET=1, NOVELIST=2, SCIFI=3 };
    Base() { std::cout << "[Base] default constructor\n"; }
    Base(const Base&) { std::cout << "[Base] copy constructor\n"; }
    virtual ~Base() { std::cout << "[Base] destructor\n"; }

    virtual Type getType() const = 0;
    virtual void inputFromConsole() = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void saveToStream(std::ostream& os) const = 0;
    virtual void loadFromStream(std::istream& is) = 0;
    virtual Base* clone() const = 0;
};
#endif