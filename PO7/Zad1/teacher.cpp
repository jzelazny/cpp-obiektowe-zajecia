#include "teacher.h"

Teacher::Teacher(std::string name, std::string title) : Person(name)
{
    this->name=name;
    this->title=title;
}
std::string Teacher::ident(){
    return name + " " + title;
}
