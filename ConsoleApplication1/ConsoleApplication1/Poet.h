
#ifndef POET_H
#define POET_H

#include "Base.h"
#include <vector> // only for internal dynamic arrays allocation; we will avoid using STL containers in Keeper
#include <string>

class Poet : public Base {
    std::string name;
    std::string lifeYears;
    std::string *works;
    int worksCount;
public:
    Poet();
    Poet(const std::string& name, const std::string& lifeYears, int worksCount);
    Poet(const Poet& other);
    ~Poet();

    Type getType() const override { return POET; }
    void inputFromConsole() override;
    void print(std::ostream& os) const override;
    void saveToStream(std::ostream& os) const override;
    void loadFromStream(std::istream& is) override;
    Base* clone() const override { return new Poet(*this); }

    // setters/getters
    void setName(const std::string& n) { name = n; }
    std::string getName() const { return name; }
};

#endif
