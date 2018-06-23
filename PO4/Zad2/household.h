#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H
#include "villager.h"

class Household
{
private:
    bool grownHusband, grownWife, babie,room, incest=false;
    Villager **dwellersArr;
    int houseCap, wifeId=-1, husbandId=-1, rooms;
public:
    Household(Villager* villager, int houseCap);
    ~Household();

    void addDweller(Villager* vill);
    void controller();
    void familyStatus();
    bool empty();
    void showDwellers();
};

#endif // HOUSEHOLD_H
