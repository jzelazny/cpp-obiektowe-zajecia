#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> joinVectors(vector<int> v1, vector<int> v2){
    vector<int> temp;
    temp=v1;
    vector<int>::iterator it;
    for(it=v2.begin();it!=v2.end();it++)
        temp.push_back(*it);
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(),temp.end()),temp.end());
    return temp;
}

int main()
{
    vector<int> v1={2,2,4,2,5,6};
    vector<int> v2={1,3,9,7,5};
    vector<int> result =  joinVectors(v1,v2);
    for(vector<int>::iterator it=result.begin();it!=result.end();it++)
        cout<<*it;
    return 0;
}
