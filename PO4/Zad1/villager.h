#ifndef VILLAGER_H
#define VILLAGER_H
#include <iostream>

class Villager
{

    static bool randomized;
    static std::string femaleName[5];
    static std::string maleName[5];
    unsigned int age, maxAge;
    bool sex;
    // True - Male, False - Female
    std::string name;
public:
    Villager();
    Villager(std::string name, unsigned int age, unsigned int maxAge, bool sex);
    ~Villager();
    void increaseAge();
    void printPersonalData();

};

#endif // VILLAGER_H
