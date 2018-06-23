#include <iostream>
#include <fstream>

using namespace std;
int main(){
    string path = "tekst.txt";
    string str = "ala";
    string bufor;
    unsigned int newPos=0, result=0;
    ifstream file;
    file.open(path);
     while(file.peek()!=EOF){
           getline(file,bufor);
           while(true){
                 newPos=bufor.find(str,newPos);
                 if(newPos==string::npos)
                     break;
                 result++;
                 newPos+=str.length();
            }
           newPos=0;
}
file.close();
     cout<<"Slowo "<<str<<" wystepuje w pliku "<<result<<" razy." << endl;
    return 0;
}
