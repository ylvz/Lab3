#include "PersonRegTest.h"
#include <iostream>
#include <fstream>

void Init(PersonReg& tr) {
    tr.T�m();
    tr.L�ggTillTest("Olle", "0703955123");
    tr.L�ggTillTest("Kurt", "12345");
    tr.L�ggTillTest("Ruben", "67890");
    tr.L�ggTillTest("Sven", "54321");
}

bool ReadReg(PersonReg& reg, const std::string& fileName) {
    std::string line;
    std::ifstream myfile(fileName);

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            if (!line.empty()) {
                std::string name = line;
                std::string adress;
                getline(myfile, adress);
                reg.L�ggTill(new Person(name, adress));
            }
        }
        myfile.close();
        return true;
    }
    else {
        std::cout << "Unable to open file\n";
        return false;
    }
}

void TestS�kningOchBorttagning(PersonReg& reg, const std::string& namn) {
    Person* found = reg.S�kNamn(namn);
    if (found) {
        std::cout << namn << " hittades: " << found->adress << std::endl;
        reg.TaBortEntry(found);
        std::cout << namn << " har tagits bort.\n";
    }
    else {
        std::cout << namn << " hittades inte.\n";
    }
}

void TestUtskrift(const PersonReg& reg) {
    std::cout << "Personer i registret:\n";
    reg.Print();
}
