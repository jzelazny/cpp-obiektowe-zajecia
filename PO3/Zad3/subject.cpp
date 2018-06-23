#include "subject.h"

Subject::Subject(std::string name, short max){
    this->subjectName=name;
    this->max=max;
    this->current=0;
}
bool Subject::addStudent(Student st){
    if(current<max){
        current++;
        studentArr[current]=&st;
        return true;
    }
    else
        return false;
}
