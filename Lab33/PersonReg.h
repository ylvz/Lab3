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

    bool LäggTill(const Person& person);
    bool LäggTillTest(const std::string& namn, const std::string& adress);
    void TaBortEntry(Person* ptr);
    Person* SökNamn(const std::string& namn) const;
    void Print() const;
    void Töm();
};
