#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
T getMin(vector<T> &v){
    vector<T> v2=v;
    sort(v2.begin(),v2.end());
    return v2.at(0);
}
bool comp(string a,string b){
    transform(a.begin(),a.end(),a.begin(),::toupper);
    transform(b.begin(),b.end(),b.begin(),::toupper);
    return (a<b)?true:false;
}
template<>
string getMin(vector<string> &v){
    vector<string> v2=v;
    sort(v2.begin(),v2.end(),comp);
    return v2.at(0);
}

int main()
{
    vector<int> v1={10,4,2,65,-2,-6,100};
    vector<string> v2={"ba","ZZ","asd"};
    vector<float> v3={2.4,5.2,-2.5,3.5};
    cout << getMin(v1) << endl << getMin(v2) << endl << getMin(v3) << endl;
    return 0;
}
