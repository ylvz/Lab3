#include "PersonReg.h"
#include <iostream>

PersonReg::PersonReg(int maxStorlek) : maxStorlek(maxStorlek), antalPersoner(0) {
    personer = new Person[maxStorlek];
}

PersonReg::~PersonReg() {
    delete[] personer;
}

bool PersonReg::L�ggTill(const Person* const person) {
    if (antalPersoner < maxStorlek) {
        personer[antalPersoner] = *person;
        antalPersoner++;
        return true;
    }
    L�ggTillTest("Olle", "0703955123");
    L�ggTillTest("Kurt", "12345");
    L�ggTillTest("Ruben", "67890");
    L�ggTillTest("Sven", "54321");
    return false;
}

bool PersonReg::L�ggTillTest(const std::string& namn, const std::string& adress) {
    return L�ggTill(new Person(namn, adress));
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





Person* PersonReg::S�kNamn(const std::string& namn) const {
    for (int i = 0; i < antalPersoner; ++i) {
        // Kolla om namn finns i den registrerade personens namn
        if (personer[i].namn.find(namn) != std::string::npos) {
            return const_cast<Person*>(&personer[i]); // Returnera pekare till den hittade personen
        }
    }
    return nullptr; // Om personen inte hittas
}

//Uppgift 2
Person* PersonReg::S�kFritt(const std::string& s�kEfter, Person* startOnNext) const {
    int startIndex = 0;

    // Om startOnNext inte �r nullptr, b�rja s�ka fr�n n�sta person
    if (startOnNext != nullptr) {
        for (int i = 0; i < antalPersoner; ++i) {
            if (&personer[i] == startOnNext) {
                startIndex = i + 1; // B�rja s�ka fr�n n�sta person efter den senaste tr�ffen
                break;
            }
        }
    }

    // S�k efter n�sta tr�ff fr�n startIndex
    for (int i = startIndex; i < antalPersoner; ++i) {
        // Om s�ktermen finns i namn eller adress
        if (personer[i].namn.find(s�kEfter) != std::string::npos ||
            personer[i].adress.find(s�kEfter) != std::string::npos) {
            return &personer[i]; // Returnera pekare till personen
        }
    }

    return nullptr; // Om ingen ytterligare tr�ff hittades
}





void PersonReg::Print() const {
    for (int i = 0; i < antalPersoner; ++i) {
        personer[i].Print();
    }
}

void PersonReg::T�m() {
    antalPersoner = 0;
}
