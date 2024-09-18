#include "PersonRegTest.h"
#include <iostream>

int main() {
    PersonReg reg(10); // Max 10 personer

    // Anropa ReadReg från PersonRegUtils
    if (ReadReg(reg, "PersonExempel.txt")) {
        reg.Print(); // Visa alla personer

        // Exempel på att söka och ta bort
        std::string namnAttSöka = "Ruben"; // Namn du vill söka efter
        Person* p = reg.SökNamn(namnAttSöka);

        if (p) {
            std::cout << "Hittade: ";
            p->Print(); // Visa information om personen
            reg.TaBortEntry(p); // Ta bort personen
            std::cout << "Efter borttagning:\n";
            reg.Print(); // Visa listan efter borttagning
        }
        else {
            std::cout << "Personen \"" << namnAttSöka << "\" hittades inte.\n";
        }
    }
    else {
        std::cout << "Misslyckades med att läsa in registret.\n";
    }

    return 0;
}
