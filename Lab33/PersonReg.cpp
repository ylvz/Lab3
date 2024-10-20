#include "PersonReg.h"
#include "Person.h"
#include <fstream>
#include <iostream>

PersonReg::PersonReg(int maxStorlek) : maxStorlek(maxStorlek), antal(0) {
    personer = new Person[maxStorlek];
}

PersonReg::~PersonReg() {
    T�m();
    delete[] personer;
}

bool PersonReg::L�ggTill(const Person& person) {
    if (antal < maxStorlek) {
        personer[antal++] = person;
        return true;
    }
    return false;
}

bool PersonReg::L�ggTillTest(const std::string& namn, const std::string& adress) {
    Person newPerson(namn, adress);
    return L�ggTill(newPerson);
}

void PersonReg::TaBortEntry(Person* ptr) {
    for (int i = 0; i < antal; ++i) {
        if (&personer[i] == ptr) { // Kontrollera om vi har hittat den post vi s�ker
            // Flytta alla efterf�ljande poster ett steg till v�nster
            for (int j = i; j < antal - 1; ++j) {
                personer[j] = personer[j + 1];
            }
            antal--; // Minska antalet personer
            return; // Avsluta funktionen n�r posten har tagits bort
        }
    }
}


Person* PersonReg::S�kNamn(const std::string& namn) const {
    for (int i = 0; i < antal; ++i) {
        if (personer[i].getName() == namn) {
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


void PersonReg::T�m() {
    // Om det finns ett specifikt minneshanteringsbehov, frig�r resurser h�r.
    // I det h�r fallet beh�ver vi inte frig�ra n�got s�rskilt minne eftersom vi anv�nder en array av objekt.

    antal = 0;  // �terst�ll antalet till 0
}


