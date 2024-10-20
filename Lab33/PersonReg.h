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

    bool L�ggTill(const Person& person);
    bool L�ggTillTest(const std::string& namn, const std::string& adress);
    void TaBortEntry(Person* ptr);
    Person* S�kNamn(const std::string& namn) const;
    void Print() const;
    void T�m();
};
