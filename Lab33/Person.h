#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string namn;
    string adress;

    Person(); // Standardkonstruktor
    Person(const string& namn, const string& adress); // Konstruktor med parametrar
    void Print() const; // Funktion för att skriva ut information om personen
};

#endif // PERSON_H
