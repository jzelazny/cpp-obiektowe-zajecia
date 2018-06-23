#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str=string();
    cout << "Podaj napis: " << endl;
    cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    char min = str[0];
    char max = str[1];
    for(int i=0;i<str.length();i++){
        if(min>str[i]) min=str[i];
        if(max<str[i]) max=str[i];
    }
    cout << min << "\t" << max << endl;
    return 0;
}
