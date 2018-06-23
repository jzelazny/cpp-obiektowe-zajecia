#include <iostream>
#include "villager.h"
using namespace std;

int main()
{
    Villager *vill1 = new Villager();
    Villager *vill2 = new Villager();
    Villager *vill3 = new Villager("Janek",14,40,1);
    delete vill1;
    delete vill2;
    delete vill3;
    return 0;
}
