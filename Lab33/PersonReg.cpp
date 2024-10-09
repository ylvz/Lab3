#include "PersonReg.h"
#include <iostream>

PersonReg::PersonReg(int maxStorlek) : maxStorlek(maxStorlek), antal(0) {
    personer = new Person[maxStorlek]; // Allokera minne f�r personer
}

PersonReg::~PersonReg() {
    delete[] personer; // Frig�r minnet
}

bool PersonReg::L�ggTill(const Person* const p) {
    if (antal < maxStorlek) {
        personer[antal] = *p; // Kopiera personen till arrayen
        antal++;
        return true;
    }
    return false; // Fullt register
}


bool PersonReg::L�ggTillTest(const std::string& namn, const std::string& adress) {
    cout << "L�gger till: " << namn << ", " << adress << endl; // Debuggingutskrift
    Person* p = new Person(namn, adress); // Allokera en ny Person p� heapen
    bool result = L�ggTill(p); // L�gg till personen i registret
    if (!result) {
        delete p; // Frig�r om det inte gick att l�gga till
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


Person* PersonReg::S�kNamn(const string& name) const {
    for (int i = 0; i < antal; ++i) {
        cout << "J�mf�r med: " << personer[i].namn << endl; // Debuggingutskrift
        if (personer[i].namn == name) {
            return &personer[i]; // Returnera pekare till personen
        }
    }
    return nullptr; // Ej hittad
}



void PersonReg::Print() const {
    for (int i = 0; i < antal; ++i) {
        personer[i].Print(); // Anropa Print f�r varje person
    }
}

void PersonReg::T�m() {
    antal = 0; // S�tt antal till 0
}
