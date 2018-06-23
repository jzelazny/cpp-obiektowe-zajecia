#include "villager.h"
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;
bool Villager::randomized=false;
Villager::Villager()
{
    if(!randomized){
        srand(time(0));
        randomized=true;
    }
    string path;
    sex = rand()%2;
    age=0;
    maxAge = rand()%101;
    if(sex)
        path="maleNames.txt";
    else
        path="femaleNames.txt";
    name=chooseName(path);
    cout << "W wiosce rodzi siê " << name <<  endl;
}
Villager::~Villager(){
    if(age>=maxAge)
        cout << "Umiera " << name << endl;
    else
        cout << "Z wioski odchodzi " << name <<endl;

}

Villager::Villager(string name, unsigned int age, unsigned int maxAge, bool sex){
    this->name=name;
    this->age=age;
    this->maxAge=maxAge;
    this->sex=sex;
    cout << "Do wioski do³¹cza " << name << endl;
}
string Villager::chooseName(string path){
    string bufor[50];
    ifstream file(path);
    int counter=0;
    while(file.peek()!=EOF){
        if(counter<50){
            getline(file,bufor[counter]);
            counter++;
        }
        else
            break;
    }
    file.close();
    return bufor[rand()%50];
}
void Villager::increaseAge(){
    age++;
}
bool Villager::reachedMaxAge(){
    if(age==maxAge)   return true;
                      return false;
}

//GETTERS

string Villager::getName(){
    return name;
}
bool Villager::getSex(){
    return sex;
}
int Villager::getAge(){
    return age;
}
