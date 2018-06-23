#include <iostream>

using namespace std;

template<typename T>
T getMin(T* a, T* b){
    T result=*a;
    while(a!=b){
        if(*a<result)
            result=*a;
        a++;
    }
    return result;
}
int main()
{
    int n=7;
    int tab[n]={4,2,5,2,-5,6,-2};
    cout << getMin(tab,tab+n);
    return 0;
}
