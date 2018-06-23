#ifndef STUDENT_H
#define STUDENT_H
#include <user.h>

class Student : public User
{
    short semester;
public:
    Student(short semester);
    Student(short semester,std::string login, std::string password);
};

#endif // STUDENT_H
