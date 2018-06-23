#include "household.h"
#include <clocale>
#include <cstdio>
using namespace std;
Household::Household(Villager* villager, int houseCap){
    this->houseCap=houseCap;
    dwellersArr = new Villager*[houseCap];
    for(int i=0;i<houseCap;i++)
        dwellersArr[i]=nullptr;
    husbandId=0;
    dwellersArr[0]=villager;
    cout << villager->getName() << " zak³ada rodzinê." << endl;
}
Household::~Household(){
    delete[] dwellersArr;
    for(int i=0;i<houseCap;i++)
        delete dwellersArr[i];
    cout << "Ród umar³" << endl;
}
void Household::addDweller(Villager *vill){
    for(int i=0;i<houseCap;i++)
        if(dwellersArr[i]==nullptr){
            dwellersArr[i]=vill;
            break;
        }
}
void Household::controller(){
    for(int i=0;i<houseCap;i++){
        if(dwellersArr[i]!=nullptr){
            dwellersArr[i]->increaseAge();

            if(dwellersArr[i]->reachedMaxAge()){        //dying
                delete dwellersArr[i];
                dwellersArr[i]=nullptr;

                if(i==wifeId)
                    wifeId=-1;
                else if(i==husbandId)
                    husbandId=-1;

                continue;
            }
            if(wifeId==-1 && !dwellersArr[i]->getSex())
                wifeId=i;
            if(husbandId==-1 && dwellersArr[i]->getSex())
                husbandId=i;
        }
    }
    if(wifeId!=-1 && husbandId!=-1)
        familyStatus();
}
void Household::familyStatus(){
   int freeRoomId;
   babie=false, grownHusband=false, grownWife=false, room=false;
    for(int i=0;i<houseCap;i++){
        if(dwellersArr[i]!=nullptr){
            if(dwellersArr[i]->getAge()<=5)
                babie=true;
            if(dwellersArr[wifeId]->getAge()>=18 && dwellersArr[wifeId]->getAge()<=45)
                grownWife=true;
            if(dwellersArr[husbandId]->getAge()>=18 && dwellersArr[husbandId]->getAge()<=45)
                grownHusband=true;
        }
        else if(!room && dwellersArr[i]==nullptr){
            room=true;
            freeRoomId=i;
        }

    }
    if(room && !babie && grownHusband && grownWife){
        dwellersArr[freeRoomId]=new Villager();
    }
}
bool Household::empty(){
    for(int i=0;i<houseCap;i++)
        if(dwellersArr[i]!=nullptr)
            return false;
    return true;
}
void Household::showDwellers(){
    for(int i=0;i<houseCap;i++){
        if(dwellersArr[i]!=nullptr)
            cout << dwellersArr[i]->getName() << " " << dwellersArr[i]->getAge() << endl;
    }
}
