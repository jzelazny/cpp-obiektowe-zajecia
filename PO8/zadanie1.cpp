#include <iostream>

using namespace std;

int function(char **&arr, int size){
    int newSize=0;

    for(int i=0;i<size;i++){
        if(arr[i]!=nullptr){
            newSize++;
        }
    }
    char **tmp=new char*[newSize];
    int j=0;

    for(int i=0;i<size;i++){
        if(arr[i]!=nullptr){
            tmp[j++]=arr[i];
        }
    }
    delete arr;
    arr=tmp;
    return newSize;

}

int main()
{
    int size=8;
    char **arr= new char*[size];
    for(int i=0;i<5;i++)
        arr[i]=nullptr;
    arr[5]=new char; *(arr[5])='A';
    arr[6]=new char; *(arr[6])='X';
    arr[7]=new char; *(arr[7])='A';

    for(int i=0;i<size;i++)
        cout<<*(arr[i])<<endl;

    int newSize=function(arr, size);

    for(int i=0;i<newSize;i++)
        cout<<*arr[i]<<endl;
    return 0;
}
