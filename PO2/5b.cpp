#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void findSum(ifstream &file){
    bool isNegative=false;
   string temp;
   unsigned int sum=0;
   unsigned int counter=0;
   string bufor;
   cout << "Row\tSum" <<endl;
   while(file.peek()!=EOF){
     getline(file, bufor);
     counter++;
     for(string::iterator i=bufor.begin();i!=bufor.end();i++){
         if(*i=='-')
             isNegative=true;
         else if(isdigit(*i))
             temp+=*i;
         else if(isNegative==true && !isdigit(*i)){
             sum-=stoi(temp);
             temp.clear();
             isNegative=false;
         }
         else if(*i=='+');
         else {
             sum+=stoi(temp);
             temp.clear();
         }
    }
     int result;
     if(isNegative)
         result=sum-stoi(temp);
     else
         result=sum+stoi(temp);
     cout << counter << "\t" << result << endl;
     temp.clear();
     isNegative=false;
     sum=0;
   }

}

int main(){
    string path="sum.txt";
    ifstream file;
    file.open(path);
    findSum(file);
    file.close();
    return 0;
}
