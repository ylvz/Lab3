#include "PersonReg.h"
#include <iostream>

PersonReg::PersonReg(int maxStorlek) : maxStorlek(maxStorlek), antalPersoner(0) {
    personer = new Person[maxStorlek];
}

PersonReg::~PersonReg() {
    delete[] personer;
}

bool PersonReg::LäggTill(const Person* const person) {
    if (antalPersoner < maxStorlek) {
        personer[antalPersoner] = *person;
        antalPersoner++;
        return true;
    }
    LäggTillTest("Olle", "0703955123");
    LäggTillTest("Kurt", "12345");
    LäggTillTest("Ruben", "67890");
    LäggTillTest("Sven", "54321");
    return false;
}

bool PersonReg::LäggTillTest(const std::string& namn, const std::string& adress) {
    return LäggTill(new Person(namn, adress));
}

#include "PersonReg.h"

// Implementeringen av TaBortEntry
void PersonReg::TaBortEntry(Person* ptr) {
    if (ptr) {
        for (int i = 0; i < antalPersoner; ++i) {
            if (&personer[i] == ptr) {
                for (int j = i; j < antalPersoner - 1; ++j) {
                    personer[j] = personer[j + 1]; // Flytta upp resterande personer
                }
                antalPersoner--; // Minska antalet personer
                return; // Avsluta efter borttagning
            }
        }
    }
}





Person* PersonReg::SökNamn(const std::string& namn) const {
    for (int i = 0; i < antalPersoner; ++i) {
        // Kolla om namn finns i den registrerade personens namn
        if (personer[i].namn.find(namn) != std::string::npos) {
            return const_cast<Person*>(&personer[i]); // Returnera pekare till den hittade personen
        }
    }
    return nullptr; // Om personen inte hittas
}

//Uppgift 2
Person* PersonReg::SökFritt(const std::string& sökEfter, Person* startOnNext) const {
    int startIndex = 0;

    // Om startOnNext inte är nullptr, börja söka från nästa person
    if (startOnNext != nullptr) {
        for (int i = 0; i < antalPersoner; ++i) {
            if (&personer[i] == startOnNext) {
                startIndex = i + 1; // Börja söka från nästa person efter den senaste träffen
                break;
            }
        }
    }

    // Sök efter nästa träff från startIndex
    for (int i = startIndex; i < antalPersoner; ++i) {
        // Om söktermen finns i namn eller adress
        if (personer[i].namn.find(sökEfter) != std::string::npos ||
            personer[i].adress.find(sökEfter) != std::string::npos) {
            return &personer[i]; // Returnera pekare till personen
        }
    }

    return nullptr; // Om ingen ytterligare träff hittades
}





void PersonReg::Print() const {
    for (int i = 0; i < antalPersoner; ++i) {
        personer[i].Print();
    }
}

void PersonReg::Töm() {
    antalPersoner = 0;
}
