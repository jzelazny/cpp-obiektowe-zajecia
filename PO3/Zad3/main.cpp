#include <iostream>
#include "user.h"
#include "student.h"
#include "subject.h"
using namespace std;

int main()
{
    Student st1=Student(2);
    Student st2=Student(2);
    Subject sub=Subject("History of the English language", 1); // 1 miejsce na przedmiocie
    cout <<sub.addStudent(st1)<<endl;
    cout <<sub.addStudent(st2);         // ten student juz sie nie miesci, metoda zwraca 0
    return 0;
}
