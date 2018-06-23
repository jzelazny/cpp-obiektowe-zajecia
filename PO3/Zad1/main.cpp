#include <iostream>
#include "user.h"
using namespace std;

int main()
{
    User user1=User("user", "userpassword");
    cout << user1.authorize("user", "userpassword");
    return 0;
}
