#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string path = "plik.txt";
    string str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus quis enim et orci mattis elementum sit amet quis est. Praesent leo tortor, dignissim mattis ex ac, laoreet sagittis leo. Integer dapibus vel ligula in viverra. Vivamus dictum pellentesque nisl id convallis. Maecenas at enim et felis euismod consequat.";
    ofstream file;
    unsigned int firstPos=0;
    unsigned int lastPos=20;
    unsigned int rowlength=20;
    file.open(path);
    if(str.length()>20){
        while(lastPos<str.length()){
            while(str[lastPos-1]!=' '){
                lastPos--;
                rowlength--;
            }
            file << str.substr(firstPos,rowlength) << endl;
            firstPos=lastPos;
            lastPos+=20;
            if(lastPos>str.length())
                file << str.substr(firstPos);
            else
                rowlength=20;
        }
    }
    else
        file << str;
    file.close();
    return 0;
}
