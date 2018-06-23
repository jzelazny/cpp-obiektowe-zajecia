#include "person.h"

std::string Person::getName() const
{
    return name;
}

Person::Person(std::string name, int age)
{
    this->name=name;
    this->age=age;
}

Person &Person::operator <<=(const Person &b)
{
    children.push_back(const_cast<Person*>(&b));
    return *this;
}

bool Person::operator <(const Person &b) const
{
    if(this->age<b.age) return true;
    else if(this->age>b.age) return false;
    else return this->name<b.name;
}

Person &Person::operator[](int b)
{
    return *children[b];
}

size_t Person::childrenCount() const {
    return children.size();
}
