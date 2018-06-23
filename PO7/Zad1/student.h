#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "person.h"

class Student : public Person
{
public:
    Student(std::string name, int semester);
    int semester;
    std::string ident();
};

#endif // STUDENT_H
