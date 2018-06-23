#include "villager.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
string Villager::femaleName[5]={"Maria","Goslawa","Celina","Jagna","Misla"};
string Villager::maleName[5]={"Gniewko","Siemil","Drogowit","Siemowit","Jamurlak"};
bool Villager::randomized=false;
Villager::Villager()
{
    if(!randomized) {
        srand(time(0));
        randomized=true;
    }
    maxAge=rand()%100+1;
    age=0;
    sex=rand()%2;
    name = sex ? maleName[rand()%5] : femaleName[rand()%5];

    cout << "Narodzil sie nowy czlowiek w osadzie: " << name << "." << endl;
}
Villager::Villager(string name, unsigned int age, unsigned int maxAge, bool sex)
{
    this->age=age;
    this->maxAge=maxAge;
    this->sex=sex;
    this->name=name;
    cout << "Do osady przybywaja ludzie! Do wioski dolacza " << name << "." << endl;
}
void Villager::increaseAge(){
    age++;
    if(age>=maxAge)
        this->~Villager();
}
Villager::~Villager(){
    cout << "W wieku " << age << " lat umiera " << name << endl;
}
void Villager::printPersonalData()
{
    cout << "Imie: " << name << endl << "Max wiek: " << maxAge << endl;
}
