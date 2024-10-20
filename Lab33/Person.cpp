#include "Person.h"
#include <iostream>
#include <string>

std::string name, adress;

Person::Person() : name(""), adress("") {}

Person::Person(const std::string& name, const std::string& adress) : name(name), adress(adress) {}

std::string Person::Namn() const {
    return name;
}

std::string Person::Adress() const {
    return adress;
}

void Person::Print() const {
    std::cout << "Namn: " << name << " Adress: " << adress << std::endl;
}

Person::~Person() {}
