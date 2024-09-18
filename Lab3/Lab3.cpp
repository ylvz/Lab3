#include "PersonRegTest.h"
#include <iostream>

int main() {
    PersonReg reg(10); // Max 10 personer

    // Anropa ReadReg fr�n PersonRegUtils
    if (ReadReg(reg, "PersonExempel.txt")) {
        reg.Print(); // Visa alla personer

        // Exempel p� att s�ka och ta bort
        std::string namnAttS�ka = "Ruben"; // Namn du vill s�ka efter
        Person* p = reg.S�kNamn(namnAttS�ka);

        if (p) {
            std::cout << "Hittade: ";
            p->Print(); // Visa information om personen
            reg.TaBortEntry(p); // Ta bort personen
            std::cout << "Efter borttagning:\n";
            reg.Print(); // Visa listan efter borttagning
        }
        else {
            std::cout << "Personen \"" << namnAttS�ka << "\" hittades inte.\n";
        }
    }
    else {
        std::cout << "Misslyckades med att l�sa in registret.\n";
    }

    return 0;
}
