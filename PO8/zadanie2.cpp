#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class WordReplacer {
    string *wordArray;
    unsigned int size;

public:
    WordReplacer(string);
    ~WordReplacer();
    void replace(unsigned int, unsigned int);
    string text();
    unsigned int getSize() const;
};


unsigned int WordReplacer::getSize() const
{
    return size;
}

WordReplacer::WordReplacer(string path) {
    ifstream ifs(path);
    size=0;

    if(!ifs.is_open()) {
        wordArray=NULL;
        return;
    }
    string word;
    while(ifs>>word) size++;
    wordArray=new string[size];

    ifs.seekg(0,ios_base::beg);

    for(int i=0; i<size; i++)
        ifs>>wordArray[i];
    ifs.close();
}

WordReplacer::~WordReplacer() {
    delete [] wordArray;
}

void WordReplacer::replace(unsigned int i, unsigned int j) {
    if(i==0 || j==0 || i>size || j>size) return;
    string temp=wordArray[i-1];
    wordArray[i-1]=wordArray[j-1];
    wordArray[j-1]=temp;
}

string WordReplacer::text() {
    string result;
    for(int i=0; i<size; i++)
        result+=wordArray[i]+" ";
    return result;
}

int main() {
    WordReplacer wr("file.txt");
    cout<<wr.getSize();
    //wr.replace(2,4);
    //cout<<wr.text()<<endl;
    return 0;
}
