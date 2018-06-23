#include "user.h"
using namespace std;
User::User(string login, string password)
{
this->login=login;
this->password=password;
}
bool User::authorize(string str1, string str2){
    if(str1==this->login && str2==this->password)
        return true;
    else
        return false;
}

