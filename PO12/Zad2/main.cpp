#include <iostream>
#include "lista.h"
using namespace std;

int main()
{
    Lista<int> lista;
    for(int i=0;i<5;i++)
        lista.push_back(i);
    lista.printList();

    return 0;
}
