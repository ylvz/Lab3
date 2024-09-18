#ifndef PERSONREGTEST_H
#define PERSONREGTEST_H

#include "PersonReg.h"
#include <string>

void Init(PersonReg& tr);
bool ReadReg(PersonReg& reg, const std::string& fileName); // Endast deklaration
void TestSökningOchBorttagning(PersonReg& reg, const std::string& namn);
void TestUtskrift(const PersonReg& reg);

#endif // PERSONREGTEST_H
