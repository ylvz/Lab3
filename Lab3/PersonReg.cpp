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
    return false;
}

bool PersonReg::LäggTillTest(const std::string& namn, const std::string& adress) {
    return LäggTill(new Person(namn, adress));
}

void PersonReg::TaBortEntry(Person* ptr) {
    if (ptr) {
        for (int i = 0; i < antalPersoner; ++i) {
            if (&personer[i] == ptr) {
                for (int j = i; j < antalPersoner - 1; ++j) {
                    personer[j] = personer[j + 1];
                }
                antalPersoner--;
                break;
            }
        }
    }
}

Person* PersonReg::SökNamn(const std::string& namn) const {
    for (int i = 0; i < antalPersoner; ++i) {
        if (personer[i].namn == namn) {
            return const_cast<Person*>(&personer[i]);
        }
    }
    return nullptr;
}

void PersonReg::Print() const {
    for (int i = 0; i < antalPersoner; ++i) {
        personer[i].Print();
    }
}

void PersonReg::Töm() {
    antalPersoner = 0;
}
