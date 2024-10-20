#pragma once
#include <string>

class Person {
private:
    std::string name;
    std::string adress;

public:
    Person();
    Person(const std::string& name, const std::string& adress);

    std::string getName() const;
    std::string getAdress() const;
    void Print() const;

    ~Person();
};
