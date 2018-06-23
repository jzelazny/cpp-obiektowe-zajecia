#include <iostream>
#include "student.h"
#include "teacher.h"
using namespace std;

int main()
{
    Teacher *t = new Teacher("Maria","Asystent");
    Student *s = new Student("Pawel", 3);

    cout << t->ident() << endl << s->ident() << endl;
    delete t;
    delete s;

    return 0;
}
