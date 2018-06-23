#include <iostream>
#include <set>
#include <algorithm>
#include "person.h"
using namespace std;

class Family {
    Person *head;
    bool isDescendant(Person *checked, Person *lookedFor) {
        if(checked == lookedFor) return true;
        for(size_t i=0; i<checked->getsize(); i++)
            return isDescendant(&(checked[i]),lookedFor);
        return false;
    }

public:
    Family(Person *head) { this->head=head; }
    bool operator()(Person p) {
        return isDescendant(head,&p);
    }
};

int main() {
    set<Person> s;

    pair<set<Person>::iterator,bool> ret;
    ret=s.insert(Person("me",52));

    Person &a=const_cast<Person &>(*ret.first);
    Person &b=const_cast<Person &>(*(s.insert(Person("you",12)).first));

    a<<=b;
    s.insert(Person("they",20));

    Family familyChecker(&a);
    cout << count_if(s.begin(),s.end(),familyChecker) << endl;
//    for(const Person &p : s)
//        cout << p.getname() << p.getsize() << endl;


    return 0;
}
