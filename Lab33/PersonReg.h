#pragma once
#include "Person.h"
#include <string>

class PersonReg {
private:
    Person* personer;
    int maxStorlek;
    int antal;

public:
    PersonReg(int maxStorlek);
    ~PersonReg();

    bool LäggTill(Person* person);
    bool LäggTillTest(const std::string& namn, const std::string& adress); // För att lägga till endast namn och adress
    void TaBortEntry(Person* ptr);
    Person* SökNamn(const std::string& namn) const;
    Person* SökFritt(const std::string& sökEfter, Person* startOnNext) const;

    void Print() const;
    void Töm();
};
