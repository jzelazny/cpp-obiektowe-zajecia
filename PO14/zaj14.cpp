#include <iostream>
//#include <functional>
#include <vector>
//#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
//using namespace std;



////obiekty wywoływalne, funkcje lambda
////function nie chce działać


//int fun(int a, int b)
//{
//    return a+b;
//}

//int main()
//{
//  // std::function<int(int)> g = std::bind(fun,std::placeholders::_1, 5) ;
//function<int(int, int)> g = bind(fun,10,placeholders::_1,placeholders::_2) ; //tyle int w nawiasach ile placeholders
//   cout << g(1,10) << endl;
//    return 0;
//}


////zad1

//bool fun(int min, int max, int value)
//{
//    return (value > min && value <max);
//}
//int main()
//{
//    vector<int> a(5);
//    for(int i=0 ; i<5 ; ++i)
//    {
//        a[i]=i;
//    }

//    for(int q: a)
//    {
//        cout<<q<<endl;
//    }

//    std::function<bool(int)> g=std::bind(fun, 2,4,std::placeholders::_1);
//    std::replace_if(a.begin(), a.end(), g, 0);
//    for(int q: a)
//    {
//        cout<<q<<endl;
//    }
//    return 0;
//}


//////zad2




////void addTo(int &a, int b)
////{
////    a+=b;
////}
////int main()
////{
////    int a=5;
////    int b=10;
////   std::function<void(int &)> g = std::bind(addTo,std::placeholders::_1,b) ;
//////function<int(int, int)> g = bind(fun,10,placeholders::_1,placeholders::_2) ; //tyle int w nawiasach ile placeholders
////   g(a);


////   cout << a << endl;
////    return 0;
////}
//using namespace std;

//void capitalizeToStream(ostream &, string word)
//{
//    os<<(char)::toupper(word[0]);
//    for(int i=1 ; i<word.size() ; ++i)
//    {
//        os << (char)::tolower(word[i]);
//    }
//    os<<endl;
//}
//void showWordWithLetter(string text, char letter, function<void(string)>display)
//{
//    stringstream ss;
//    ss.str(text);
//    string word;
//    while(ss>>word)
//    {
//        for(int i =0 ; i<word.size() ; ++i)
//        {
//            if(word[i] == letter)
//            {
//                display(word);
//                break;
//            }
//        }
//    }

//}

//int main()
//{/*
//    string s="Ala ma kota a tola ma koleta";
//    function<void(string)> capitalizeToCount = bind(capitalizeToStream, std::ref(cout),placeholders::_1);
//    showWordWithLetter(s,'l',capitalizeToCount);

// */
//    //inna opcja
//    showWordWithLetter("Ala ma kota a tola ma koleta", 'l',bind(capitalizeToStream, std::ref(cout),placeholders::_1) );


//    return 0;
//}



//////funkcje lambda
//using namespace std;
//int main()
//{
//    function<int(int)> f = [](int a) ->int
//    {
//      return a+10;
//    };

//    cout<<f(5);

//    return 0;
//}


//////zad1 INNA OPCJA Z LAMBDA

////bool fun(int min, int max, int value)
////{
////    return (value > min && value <max);
////}
//int main()
//{
//    vector<int> a(5);
//    for(int i=0 ; i<5 ; ++i)
//    {
//        a[i]=i;
//    }

//    for(int q: a)
//    {
//        cout<<q<<endl;
//    }
//int min =2, max=5;

//std::replace_if(a.begin(), a.end(), [min,max](int value) ->bool{return !(value>min&&value<max);},0);
//    for(int q: a)
//    {
//        cout<<q<<endl;
//    }
//    return 0;
//}



////zad3 i 4 - to jest podobno proste
//using namespace std;
//struct Point
//{
//    float x,y;
//};
//void show(vector<Point> &a)
//{
//    for(Point i : a)
//    {
//        cout<<i.x<<" "<<i.y;
//    }
//}


//int main()
//{
//    vector<Point> vec;
//    vec.push_back({5.5,2});
//    vec.push_back({2.7,4});
//    vec.push_back({1.2,7});

//    Point center {10,10};

//    //std::sort(vec.begin(), vec.end(), [](Point a, Point b){return a.x<b.x;});


//    std::sort(vec.begin(), vec.end(), [center](Point a, Point b){
//        return hypot(a.x-center.x,a.y-center.y)< hypot(b.x-center.x, b.y - center.y);
//    });

//    show(vec);

//    return 0;
//}



//zad5
int main()
{
    int arr[5]={4,1,7,2,3};

    //nie chciało mi się pisać //std::for_each

    return 0;
}
