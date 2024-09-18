#include "PersonRegTest.h"
#include <iostream>
#include <fstream>

void Init(PersonReg& tr) {
    tr.Töm();
    tr.LäggTillTest("Olle", "0703955123");
    tr.LäggTillTest("Kurt", "12345");
    tr.LäggTillTest("Ruben", "67890");
    tr.LäggTillTest("Sven", "54321");
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
                reg.LäggTill(new Person(name, adress));
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

void TestSökningOchBorttagning(PersonReg& reg, const std::string& namn) {
    Person* found = reg.SökNamn(namn);
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
