#include "student.h"

Student::Student(std::string name, int semester):Person(name)
{
    this->name=name;
    this->semester=semester;
}
std::string Student::ident(){
    return name + " " + std::to_string(semester);
}
