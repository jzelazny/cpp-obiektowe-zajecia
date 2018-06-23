#ifndef USER_H
#define USER_H
#include <iostream>
class User
{
protected:
    std::string login, password;
public:
    User(std::string login, std::string password);
    bool authorize(std::string str1, std::string str2);
};

#endif // USER_H
