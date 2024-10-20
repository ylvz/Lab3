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

    bool L�ggTill(Person* person);
    bool L�ggTillTest(const std::string& namn, const std::string& adress); // F�r att l�gga till endast namn och adress
    void TaBortEntry(Person* ptr);
    Person* S�kNamn(const std::string& namn) const;
    Person* S�kFritt(const std::string& s�kEfter, Person* startOnNext) const;

    void Print() const;
    void T�m();
};
