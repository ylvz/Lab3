#ifndef PERSONREG_H
#define PERSONREG_H

#include "Person.h"
#include <string>

class PersonReg {
public:
    PersonReg(int maxStorlek);
    ~PersonReg();

    bool LäggTill(const Person* const person);
    bool LäggTillTest(const std::string& namn, const std::string& adress);
    void TaBortEntry(Person* ptr);
    Person* SökNamn(const std::string& namn) const;
    void Print() const;
    void Töm();

private:
    Person* personer;
    int maxStorlek;
    int antalPersoner;
};

#endif // PERSONREG_H
