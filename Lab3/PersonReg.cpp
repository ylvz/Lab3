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
    return false;
}

bool PersonReg::L�ggTillTest(const std::string& namn, const std::string& adress) {
    return L�ggTill(new Person(namn, adress));
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

Person* PersonReg::S�kNamn(const std::string& namn) const {
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

void PersonReg::T�m() {
    antalPersoner = 0;
}
