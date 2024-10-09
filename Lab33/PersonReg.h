#ifndef PERSONREG_H
#define PERSONREG_H

#include "Person.h"

class PersonReg {
private:
    Person* personer; // Pekare till arrayen med personer
    int maxStorlek; // Maximal storlek p� registret
    int antal; // Antal personer i registret

public:
    PersonReg(int maxStorlek); // Konstruktor
    ~PersonReg(); // Destruktor
    bool L�ggTill(const Person* const p);
    bool L�ggTillTest(const std::string& namn, const std::string& adress); // L�gg till person med namn och adress
    void TaBortEntry(Person* ptr); // Ta bort person
    Person* S�kNamn(const std::string& namn) const; // S�k efter person
    void Print() const; // Skriv ut alla personer
    void T�m(); // T�m registret
};

#endif // PERSONREG_H
