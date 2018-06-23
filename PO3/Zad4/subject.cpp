#include "subject.h"
#include <iostream>
Subject::Subject(std::string name, short max){
    this->subjectName=name;
    this->max=max;
    this->current=-1;
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
Student& Subject::checkStudent(short id, bool &ref){
    if(id>current){
        ref=false;
        return *studentArr[0];
    }
    else{
        ref=true;
        return *studentArr[id];
    }
}
