
#ifndef SCIFI_H
#define SCIFI_H

#include "Base.h"
#include <string>

class Scifi : public Base {
    std::string name;
    std::string *works;
    int worksCount;
    bool filmsByBooks;
public:
    Scifi();
    Scifi(const std::string& name, int worksCount, bool filmsByBooks);
    Scifi(const Scifi& other);
    ~Scifi();

    Type getType() const override { return SCIFI; }
    void inputFromConsole() override;
    void print(std::ostream& os) const override;
    void saveToStream(std::ostream& os) const override;
    void loadFromStream(std::istream& is) override;
    Base* clone() const override { return new Scifi(*this); }
};

#endif
