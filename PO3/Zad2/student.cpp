#include "student.h"

Student::Student(short semester,std::string login, std::string password) : User(login, password)
{
    this->semester=semester;
}
