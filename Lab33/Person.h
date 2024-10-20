#pragma once
#include <string>

class Person {
private:
    std::string name;
    std::string adress;

public:
    Person();
    Person(const std::string& name, const std::string& adress);

    std::string Namn() const;
    std::string Adress() const;

    //Uppgift 1-2
    //void Print() const;

    //~Person();

    virtual void Print() const;
    virtual ~Person();
};
