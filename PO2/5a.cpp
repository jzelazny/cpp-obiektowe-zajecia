#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void findSum(ifstream &file){
   string temp;
   unsigned int sum=0;
   unsigned int counter=0;
   string bufor;
   cout << "Row\tSum" <<endl;
   while(file.peek()!=EOF){
     getline(file, bufor);
     counter++;
     for(char c: bufor){
         if(isdigit(c))
            temp+=c;
         else{
             sum+=stoi(temp);
             temp.clear();
         }
      }
     cout << counter << "\t" << sum+stoi(temp) << endl;
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
