#include "PersonReg.h"
#include "Person.h"
#include <fstream>
#include <iostream>
#include "PersonMedTel.h"

PersonReg::PersonReg(int maxStorlek) : maxStorlek(maxStorlek), antal(0) {
    personer = new Person[maxStorlek];
}

PersonReg::~PersonReg() {
    Töm();
    delete[] personer;
}

bool PersonReg::LäggTill(Person* person) {
    if (antal < maxStorlek) {
        personer[antal++] = *person; // Kopiera objektet till arrayen
        return true;
    }
    return false;
}



bool PersonReg::LäggTillTest(const std::string& namn, const std::string& adress) {
    Person newPerson(namn, adress);
    return LäggTill(&newPerson); // Lägger till en Person
}


void PersonReg::TaBortEntry(Person* ptr) {
    for (int i = 0; i < antal; ++i) {
        if (&personer[i] == ptr) { // Kontrollera om vi har hittat den post vi söker
            // Flytta alla efterföljande poster ett steg till vänster
            for (int j = i; j < antal - 1; ++j) {
                personer[j] = personer[j + 1];
            }
            antal--; // Minska antalet personer
            return; // Avsluta funktionen när posten har tagits bort
        }
    }
}

Person* PersonReg::SökFritt(const std::string& sökEfter, Person* startOnNext) const {
    // Logik för att söka fritt...
    Person* start = (startOnNext == nullptr) ? personer : startOnNext + 1;
    for (Person* ptr = start; ptr < personer + antal; ptr++) {
        // Om namn eller adress finns returnera personen
        if (ptr->Namn().find(sökEfter) != std::string::npos || ptr->Adress().find(sökEfter) != std::string::npos) {
            return ptr;
        }
    }
    // Om ingen hittad returnera nullptr
    return nullptr;
}

Person* PersonReg::SökNamn(const std::string& namn) const {
    for (int i = 0; i < antal; ++i) {
        if (personer[i].Namn() == namn) {
            return &personer[i];
        }
    }
    return nullptr;
}

void PersonReg::Print() const
{
    for (Person* ptr = personer; ptr != personer + antal; ptr++)
    {
        ptr->Print();

    }
}


void PersonReg::Töm() {
    // Om det finns ett specifikt minneshanteringsbehov, frigör resurser här.
    // I det här fallet behöver vi inte frigöra något särskilt minne eftersom vi använder en array av objekt.

    antal = 0;  // Återställ antalet till 0
}


