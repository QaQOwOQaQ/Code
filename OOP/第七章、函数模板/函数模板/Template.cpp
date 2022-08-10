#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

template <class T>
void Swap(T &a, T &b)
{
    int t = a;
    a = b;
    b = t;
}

template <class T>
T Add(T n)
{
    return n + 1;
}

template <class T>
T MaxElement(T a[], int size)
{
    T tmpMax = a[0];
    for (int i = 0; i < size; i ++ )
        if(a[i] > tmpMax)
            tmpMax = a[i];
    return tmpMax;
}

int main()
{
    int a = 3;
    double b = 10.123;
    Swap(a, b);
    cout << a << ' ' << b << endl;
}