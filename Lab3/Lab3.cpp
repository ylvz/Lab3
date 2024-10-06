#include "PersonRegTest.h"
#include <iostream>

int main() {
    PersonReg reg(10); // Max 10 personer


    /*Uppgift 1
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
    */
    /*Uppgift 2?
    if (ReadReg(reg, "PersonExempel.txt")) {
        std::string sökterm = "Ruben";

        Person* träff = reg.SökFritt(sökterm, nullptr);
        while (träff != nullptr) {
            träff->Print();

            träff = reg.SökFritt(sökterm, träff);
        }
    }*/

    if (ReadReg(reg, "PersonExempel.txt")) {
        // Första sökningen
        Person* x1 = reg.SökFritt("Ruben", nullptr); // Första träffen
        if (x1) {
            std::cout << "Första träffen:\n";
            x1->Print();
        }

        // Andra sökningen
        Person* x2 = reg.SökFritt("Ruben", x1); // Andra träffen
        if (x2) {
            std::cout << "Andra träffen:\n";
            x2->Print();
        }

        // Tredje sökningen
        Person* x3 = reg.SökFritt("Ruben", x2); // Tredje träffen
        if (x3) {
            std::cout << "Tredje träffen:\n";
            x3->Print();
        }

        // Sökning som börjar om efter den första träffen
        Person* y2 = reg.SökFritt("Ruben", x1); // Ytterligare en sökning efter x1
        if (y2) {
            std::cout << "Sökning från första träffen (andra träffen igen):\n";
            y2->Print();
        }
    }
    else {
        std::cout << "Misslyckades med att läsa in registret.\n";
    }


    return 0;
}
