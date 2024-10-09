#include "Person.h"

Person::Person() : namn(""), adress("") {} // Implementera standardkonstruktor

Person::Person(const string& namn, const string& adress) : namn(namn), adress(adress) {} // Konstruktor med parametrar

void Person::Print() const {
    cout << "Namn: " << namn << ", Adress: " << adress << endl; // Skriver ut namnet och adressen
}
