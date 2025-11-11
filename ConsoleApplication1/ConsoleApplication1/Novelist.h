
#ifndef NOVELIST_H
#define NOVELIST_H

#include "Base.h"
#include <string>

class Novelist : public Base {
    std::string name;
    std::string lifeYears;
    std::string *works;
    int worksCount;
    std::string bio;
public:
    Novelist();
    Novelist(const std::string& name, const std::string& lifeYears, int worksCount, const std::string& bio);
    Novelist(const Novelist& other);
    ~Novelist();

    Type getType() const override { return NOVELIST; }
    void inputFromConsole() override;
    void print(std::ostream& os) const override;
    void saveToStream(std::ostream& os) const override;
    void loadFromStream(std::istream& is) override;
    Base* clone() const override { return new Novelist(*this); }
};

#endif
