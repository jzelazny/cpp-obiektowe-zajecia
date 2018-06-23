#include <iostream>
#include <memory> to do pointerów

#include <random> do zad3 lepsze opcje niż srand()
#include <chrono> do zad3
#include <vector>
#include <string>
using namespace std;

//SMART POINTERY
struct Point {float x,y;};

template <typename T>
class SmartPointer
{
  T *value;
public:
  SmartPointer(T *value) { this->value=value; }
  ~SmartPointer() { delete value; }
  T &operator *(){ return *value; }
  T *operator ->() { return value;}
};

int main()
{
    SmartPointer<Point> ptr(new Point{1,2} );
    *ptr = 10;
    cout<<ptr->x<<endl;

    return 0;
}



//unique_ptr
//zad1

struct Point {float x,y;};
int main()
{
    unique_ptr<Point> ptr(new Point{1,2});
    cout<<ptr->x<<endl; mozna tak ale też za pomocą metod;

    unique_ptr<Point> ptr2;

    cout<<(ptr!=nullptr)<<endl;
    cout<<(ptr2!=nullptr)<<endl; pierwsza opcja


    cout<<(!ptr)<<endl;
    cout<<(!ptr2)<<endl; druga opcja

    unique_ptr<Point> ptr3(move(ptr)); przekazywanie wartości zabiera z jednego a dodaje do drugiego (1 ptr będzie wyczyszczony)

    Point *raw= ptr3.get(); przekazywanie danych nie usuwa chyba z ptr3
    ptr3.reset(); usuwanie tego co jest w ptr3

    Point *raw= ptr3.release();  inna opcja z tą opcją tego ptr3 już nie będzie





    cout<<raw->x<<endl;



    return 0;
}





//zad 2

class Triangle
{
    float a,b,c;
public:
    Triangle(float a, float b, float c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    friend float circumference(unique_ptr<Triangle> &t); aby funkcja mogła używac pól prywatcnych
};

float circumference(unique_ptr<Triangle> &t)
{
    return t->a+t->b+t->c;
}

int main()
{
    unique_ptr<Triangle> t(new Triangle(3,4,5)); tak w cpp11


    auto t = make_unique<Triangle>(3,4,5);nowa wersja od cpp14

    cout<<circumference(t)<<endl; tak nie można bo nie ma konstruktowa kopiującego

     cout<<circumference(std::move(t))<<endl;
     cout<<circumference(std::move(t))<<endl; drugi raz juz ie zadziała bo w t nie ma już wratości

    cout<<circumference(t)<<endl; eby nie uzywac move ani nić takiego przekatujemy referencje (& na górze sie pojawiło )
    return 0;
}





//zadanie3

    class WordBag
    {
        vector<unique_ptr<string>> bag;
        default_random_engine generator;
       function<int(void)> dice;

        void UpdateDistribution();


    public:
        WordBag();

        void add(unique_ptr<string> p);
        unique_ptr<string> take();

    };
    WordBag::WordBag()
    {
        random_device r; urządzenie w systemie zwracające wartość losową
       generator = default_random_engine( r());

        UpdateDistribution();
    }
    void WordBag::UpdateDistribution()
    {
        uniform_int_distribution<int> distribution(0,bag.size()-1);
         dice  = std::bind (distribution,generator);

    }

    void WordBag::add(unique_ptr<string> p)
    {
        bag.push_back(move(p));
        UpdateDistribution();
    }

    unique_ptr<string> WordBag::take()
    {


        int index = dice();
        unique_ptr<string> value(move(bag[index]));
        bag.erase(bag.begin()+index);
        UpdateDistribution();
        return value;
    }

int main()
{
    WordBag w;
    w.add(make_unique<string>("Ala"));
    w.add(make_unique<string>("ma"));
    w.add(make_unique<string>("kota"));


    cout<<*w.take()<<endl;
    cout<<*w.take()<<endl;
    cout<<*w.take()<<endl;
    return 0;
}


//zadanie 4

class Triangle
{
public:
    float a,b,c;
public:
    Triangle(float a, float b, float c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    friend float circumference(shared_ptr<Triangle> &t); aby funkcja mogła używac pól prywatcnych
    friend float circumferenceCopy(shared_ptr<Triangle> &t);
};

float circumference(shared_ptr<Triangle> &t)
{
    return t->a+t->b+t->c;
}
float circumferenceCopy(shared_ptr<Triangle> &t)
{
    return t->a+t->b+t->c;
}
int main()
{
   shared_ptr<Triangle> t(new Triangle(3,4,5));
   cout<<t->a<<endl;

   druga metoda
   auto t = make_shared<Triangle>(2,3,4);
   cout<<t->a;
   shared_ptr<Triangle> t2(t);
   cout<<t2->a<<endl;

wskazują na ten sam obiekt, naweet jak jeden beDzie np t.reset() to drugi będzie wskazywał
   cout<<!t<<endl;
   cout<<!t2<<endl;


    auto t = make_shared<Triangle>(3,4,5);
    cout<<t.use_count()<<endl;

    shared_ptr <Triangle> t2(t);
    cout<<t.use_count()<<endl;

    t.reset();
    cout<<t2.use_count()<<endl;

 return 0;
}






