#include "PersonMedTel.h"
#include <iostream>

PersonMedTel::PersonMedTel(const std::string& namn, const std::string& adress, const std::string& nummer)
    : Person(namn, adress), nummer(nummer) {}

void PersonMedTel::Print() const {
    Person::Print(); // Anropa basklassens Print
    std::cout << "Telefonnummer: " << nummer << std::endl;
}
