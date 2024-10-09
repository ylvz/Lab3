#include "PersonReg.h"
#include <iostream>

PersonReg::PersonReg(int maxStorlek) : maxStorlek(maxStorlek), antal(0) {
    personer = new Person[maxStorlek]; // Allokera minne för personer
}

PersonReg::~PersonReg() {
    delete[] personer; // Frigör minnet
}

bool PersonReg::LäggTill(const Person* const p) {
    if (antal < maxStorlek) {
        personer[antal] = *p; // Kopiera personen till arrayen
        antal++;
        return true;
    }
    return false; // Fullt register
}


bool PersonReg::LäggTillTest(const std::string& namn, const std::string& adress) {
    cout << "Lägger till: " << namn << ", " << adress << endl; // Debuggingutskrift
    Person* p = new Person(namn, adress); // Allokera en ny Person på heapen
    bool result = LäggTill(p); // Lägg till personen i registret
    if (!result) {
        delete p; // Frigör om det inte gick att lägga till
    }
    return result;
}



void PersonReg::TaBortEntry(Person* ptr) {
    for (int i = 0; i < antal; ++i) {
        if (&personer[i] == ptr) {
            for (int j = i; j < antal - 1; ++j) {
                personer[j] = personer[j + 1]; // Flytta ner personer
            }
            antal--;
            return; // Avsluta metoden efter borttagning
        }
    }
}


Person* PersonReg::SökNamn(const string& name) const {
    for (int i = 0; i < antal; ++i) {
        cout << "Jämför med: " << personer[i].namn << endl; // Debuggingutskrift
        if (personer[i].namn == name) {
            return &personer[i]; // Returnera pekare till personen
        }
    }
    return nullptr; // Ej hittad
}



void PersonReg::Print() const {
    for (int i = 0; i < antal; ++i) {
        personer[i].Print(); // Anropa Print för varje person
    }
}

void PersonReg::Töm() {
    antal = 0; // Sätt antal till 0
}
