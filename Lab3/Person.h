#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
public:
    Person(); // Standardkonstruktor
    Person(const std::string& namn, const std::string& adress);
    void Print() const;

    std::string namn;
    std::string adress;
};




#endif // PERSON_H
