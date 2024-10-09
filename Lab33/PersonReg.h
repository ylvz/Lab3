#ifndef PERSONREG_H
#define PERSONREG_H

#include "Person.h"

class PersonReg {
private:
    Person* personer; // Pekare till arrayen med personer
    int maxStorlek; // Maximal storlek på registret
    int antal; // Antal personer i registret

public:
    PersonReg(int maxStorlek); // Konstruktor
    ~PersonReg(); // Destruktor
    bool LäggTill(const Person* const p);
    bool LäggTillTest(const std::string& namn, const std::string& adress); // Lägg till person med namn och adress
    void TaBortEntry(Person* ptr); // Ta bort person
    Person* SökNamn(const std::string& namn) const; // Sök efter person
    void Print() const; // Skriv ut alla personer
    void Töm(); // Töm registret
};

#endif // PERSONREG_H
