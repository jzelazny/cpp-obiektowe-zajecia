#include <iostream>
#include "user.h"
#include "student.h"
#include "subject.h"
using namespace std;

int main()
{
    Student st1=Student(1,"marcin","marcinhaslo");
    Student st2=Student(1,"kinga","kingahaslo");
    Student st3=Student(1,"andzelika","andzelikahaslo");
    Subject sub=Subject("Math",2);
    sub.addStudent(st1);
    sub.addStudent(st2);
    sub.addStudent(st3);
    bool check;
    cout << sub.checkStudent(2,check).getLogin();
    return 0;

    // metoda klasy User getLogin jest pomocnicza, nie ma jej w treści zadania
}
