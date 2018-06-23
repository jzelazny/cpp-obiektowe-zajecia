#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
#include "student.h"
class Subject
{
    std::string subjectName;
    short max;
    short current;
    Student *studentArr[100];

public:
    Subject(std::string name, short max);
    bool addStudent(Student st);
    Student& checkStudent(short id, bool &ref);
};

#endif // SUBJECT_H

