#include <iostream>
#include <algorithm>
using namespace std;

template<typename T> T getMin(T* a, T* b){
    T result=*a;
    while(a!=b){
        if(*a<result)
            result=*a;
        a++;
    }
    return result;
}

bool comp(string a, string b){
    transform(a.begin(),a.end(),a.begin(),::tolower);
    transform(b.begin(),b.end(),b.begin(),::tolower);
    return (a<b)?true:false;
}
template<> string getMin(string *a, string *b){

    sort(a,b,comp);
    return *a;
}
int main()
{
    int n=4;
    int tab[n]={4,2,5,-2};
    cout << getMin(tab,tab+n);
    string str[n]={"AbA","Ab","CD","CX"};
    cout << getMin(str,str+n);
    return 0;
}
