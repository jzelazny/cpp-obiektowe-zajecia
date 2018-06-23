#ifndef VILLAGER_H
#define VILLAGER_H
#include <iostream>
class Villager
{
private:
    static bool randomized;
    unsigned int age, maxAge;
    bool sex; // true - Male, false - Female
    std::string name;
public:
    virtual ~Villager();
    Villager();
    Villager(std::string name, unsigned int age, unsigned int maxAge, bool sex);
    std::string chooseName(std::string path);
    void increaseAge();
    bool reachedMaxAge();
 // GETTERS
    std::string getName();
    bool getSex();
    int getAge();
};

#endif // VILLAGER_H
