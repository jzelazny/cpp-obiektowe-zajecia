#include <iostream>
#include <array.h>
using namespace std;

    


int main(int argc, char *argv[])
{
    Array<int> arr(5);
    for(int i=0;i<5;i++)
        cout << arr[i] << endl;
    
    cout << endl<< endl;
    Array<int>::iterator it=arr.end ();
    for(;it!=arr.end ();++it)
        cout << *it << endl;
    return 0;
}
