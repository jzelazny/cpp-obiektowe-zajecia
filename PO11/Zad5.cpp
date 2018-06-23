#include <iostream>
#include <vector>
using namespace std;

template<typename T, int n>
class Array{
private:
  T arr[n];
public:
  Array(const int tab[]){
      for(int i=0;i<n;i++)
          arr[i]=tab[i];
  }
  T operator [](const int& i){
      return arr[i];
  }
  template<typename R>
  void addToAll(R t){
      for(int i=0;i<n;i++)
          arr[i]+=t;
  }
};

int main()
{
    const int n=8;
    int tab[n]={1,56,2,7,2,8,-10,-2};
    Array<int, n> array = Array<int, n>(tab);
    array.addToAll(n);
    cout << "Przed dodaniem 8: \t" << "Po dodaniu 8: " <<endl;
    for (int i=0;i<n;i++){
        cout << tab[i] << "\t\t\t" << array[i] << endl;
    }
    return 0;
}
