#ifndef PERSONREG_H
#define PERSONREG_H

#include "Person.h"
#include <string>

class PersonReg {
public:
    PersonReg(int maxStorlek);
    ~PersonReg();

    bool L�ggTill(const Person* const person);
    bool L�ggTillTest(const std::string& namn, const std::string& adress);
    void TaBortEntry(Person* ptr);
    Person* S�kNamn(const std::string& namn) const;
    void Print() const;
    void T�m();

private:
    Person* personer;
    int maxStorlek;
    int antalPersoner;
};

#endif // PERSONREG_H
