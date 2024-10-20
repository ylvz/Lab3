#ifndef PERSONMEDTEL_H
#define PERSONMEDTEL_H

#include "Person.h"
#include <string>
#include <iostream>

class PersonMedTel : public Person {
private:
    std::string nummer; // Telefonnummer

public:
    // Konstruktor
    PersonMedTel(const std::string& name, const std::string& adress, const std::string& telefonnummer);

    // Override av Print
    void Print() const override;

    // Virtuell destruktor
    virtual ~PersonMedTel();
};

#endif // PERSONMEDTEL_H
