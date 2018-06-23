#include <iostream>
#include <clocale>
#include <fstream>
#include "villager.h"
#include "household.h"
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Polish");
    Villager *v1= new Villager("Jan",12,30,1);
    Villager *v2= new Villager("Milena",16,40,0);
    Household hs= Household(v1,5);
    hs.addDweller(v2);
    while(!hs.empty()){
        hs.showDwellers();
        hs.controller();
        cout << endl;
        Sleep(1000);
    }
    return 0;
}
