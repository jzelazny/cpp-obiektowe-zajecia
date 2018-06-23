#include <iostream>
#include <list>
#include <fstream>
#include <iterator>
using namespace std;

void printString(list<string>::iterator it1, list<string>::iterator it2){
    while(it1!=it2){
        cout << *it1 << endl;
        it1++;
    }
}
int main()
{
    ifstream plik;
    plik.open("lorem.txt");
    list<string> List;
    string bufor;
    while(plik>>bufor)
        List.push_back(bufor);
   list<string>::iterator it1 = List.begin();
   list<string>::iterator it2 = List.end();
   advance(it1,15);
   advance (it2,-10);
   printString(it1,it2);
    return 0;
}
