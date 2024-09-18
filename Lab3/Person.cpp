#include "Person.h"

// Standardkonstruktor
Person::Person() : namn(""), adress("") {}

Person::Person(const std::string& namn, const std::string& adress)
    : namn(namn), adress(adress) {}

void Person::Print() const {
    std::cout << "Namn: " << namn << ", Adress: " << adress << std::endl;
}
