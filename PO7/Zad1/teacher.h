#ifndef TEACHER_H
#define TEACHER_H
#include <iostream>
#include "person.h"

class Teacher : public Person
{
private:
    std::string title;
public:
    Teacher(std::string name, std::string title);
    std::string ident();
};

#endif // TEACHER_H
