#include "PersonRegTest.h"
#include <iostream>

int main() {
    PersonReg reg(10); // Max 10 personer


    /*Uppgift 1
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
    */
    /*Uppgift 2?
    if (ReadReg(reg, "PersonExempel.txt")) {
        std::string s�kterm = "Ruben";

        Person* tr�ff = reg.S�kFritt(s�kterm, nullptr);
        while (tr�ff != nullptr) {
            tr�ff->Print();

            tr�ff = reg.S�kFritt(s�kterm, tr�ff);
        }
    }*/

    if (ReadReg(reg, "PersonExempel.txt")) {
        // F�rsta s�kningen
        Person* x1 = reg.S�kFritt("Ruben", nullptr); // F�rsta tr�ffen
        if (x1) {
            std::cout << "F�rsta tr�ffen:\n";
            x1->Print();
        }

        // Andra s�kningen
        Person* x2 = reg.S�kFritt("Ruben", x1); // Andra tr�ffen
        if (x2) {
            std::cout << "Andra tr�ffen:\n";
            x2->Print();
        }

        // Tredje s�kningen
        Person* x3 = reg.S�kFritt("Ruben", x2); // Tredje tr�ffen
        if (x3) {
            std::cout << "Tredje tr�ffen:\n";
            x3->Print();
        }

        // S�kning som b�rjar om efter den f�rsta tr�ffen
        Person* y2 = reg.S�kFritt("Ruben", x1); // Ytterligare en s�kning efter x1
        if (y2) {
            std::cout << "S�kning fr�n f�rsta tr�ffen (andra tr�ffen igen):\n";
            y2->Print();
        }
    }
    else {
        std::cout << "Misslyckades med att l�sa in registret.\n";
    }


    return 0;
}
