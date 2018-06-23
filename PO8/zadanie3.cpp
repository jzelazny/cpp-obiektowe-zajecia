#include <iostream>
#include<string>
using namespace std;
class Stworek{
public:
    virtual void powiedz(string &)=0;
};
class StworekJakajacy :public Stworek{
    void powiedz (string &napis){
        if(napis[0]>='A' && napis[0]<='Z') {
            cout << napis[0];
            cout << (char)(napis[0]+32);
            cout << (char)(napis[0]+32);
            cout << napis.substr(1);
        }
        else
            cout << napis[0] << napis[0] << napis;
    }
};
class StworekBezR :public Stworek{
    void powiedz(string &napis){
//        for(int i=0;i<napis.length();i++){
//            if(napis[i]=='r')
//                cout << "l";
//            else cout << napis[i];
//        }
        for(string::iterator it=napis.begin();it!=napis.end();it++) {
            if(*it=='r')
                cout << "l";
            else
                cout << *it;
        }
    }
};

class StworekUsuwajacy : public Stworek
{
private:
    void powiedz (string &napis)
    {
        int begin=0;
        int pos=napis.find(usun);

        while(pos!=string::npos)
        {
            cout<<napis.substr(begin,pos-begin);
            begin=pos+usun.size();
            pos=napis.find(usun,begin);
        }

        cout<<napis.substr(begin);
    }

    string usun;

public:
    StworekUsuwajacy(string usun)
    {
        this->usun=usun;
    }

};

int main(int argc, char *argv[])
{
    Stworek *wsk;
    Stworek *wsk1;
    Stworek *wsk2;

    wsk=new StworekJakajacy;
    wsk1=new StworekBezR;
    wsk2=new StworekUsuwajacy("ko");

    string napis2="Ala ma kota i kogut i kotleta";
    wsk->powiedz(napis2);
    cout << endl;
    wsk1->powiedz(napis2);
    cout <<endl;
    wsk2->powiedz(napis2);
    cout<<endl;
    return 0;
}
