#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>

class Person
{
    std::string name;
    int age;
    std::vector<Person *> children;

public:
    Person(std::string name, int age);
    Person& operator <<=(const Person &b);
    bool operator <(const Person &b) const;
    Person& operator[](int b);
    std::string getName() const;
    size_t childrenCount() const;
};

#endif // PERSON_H
