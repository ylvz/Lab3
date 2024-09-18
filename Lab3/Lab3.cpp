#include "PersonReg.h"
#include <iostream>
#include <fstream>

bool ReadReg(PersonReg& reg, const std::string& fileName) {
    std::string line;
    std::ifstream myfile(fileName);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            if (line.empty()) continue;
            std::string name = line;
            std::string adress;
            getline(myfile, adress);
            reg.L�ggTillTest(name, adress);
        }
        myfile.close();
        return true;
    }
    else {
        std::cout << "Unable to open file" << std::endl;
        return false;
    }
}

int main() {
    PersonReg reg(10); // Max 10 personer
    ReadReg(reg, "PersonExempel.txt");
    reg.Print();

    // Exempel p� att s�ka och ta bort
    Person* p = reg.S�kNamn("Olle");
    if (p) {
        std::cout << "Hittade: ";
        p->Print();
        reg.TaBortEntry(p);
    }

    reg.Print(); // Skriver ut registret efter borttagning

    return 0;
}
