
// Konstruktorn som tar emot namn, adress och telefonnummer
#include "PersonMedTel.h"

PersonMedTel::PersonMedTel(const std::string& name, const std::string& adress, const std::string& telefonnummer)
    : Person(name, adress), nummer(telefonnummer) {}

// �ndrad Print-metod f�r att skriva ut utan radbrytningar
void PersonMedTel::Print() const {
    std::cout << "Namn: " << Namn() << ", Adress: " << Adress() << ", Telefonnummer: " << nummer;
}

PersonMedTel::~PersonMedTel() {
    // Eventuell st�dning om det beh�vs
}

