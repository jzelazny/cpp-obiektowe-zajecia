#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1("Ptaki lataja kluczem");
    string str2("lataja");
    string str3("otwieraja drzwi");
    if(str1.find(str2)==string::npos)
        cout << "Drugi napis nie wystepuje w napisie pierwszym" << endl;
    else{
        str1.replace(str1.find(str2),str2.length(),str3);
    }
    cout<<str1<<endl;
    return 0;
}
