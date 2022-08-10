#include <iostream>
#include <cstring>

using namespace std;

int a[5] = {1, 2, 3, 4, 5}, b[5];
double d[5] = {1.1, 2.2, 3.3, 4.4, 5.5}, c[5];

int Cube(int x)
{
    return x * x * x;
}

double Square(double x)
{
    return x * x;
}

template <class T, class pred>
void Map(T s, T e, T x, pred op)
{
    for (; s != e; s++, x++ )
        *x = op(*s);
}

template <class T>
void out(T array[])
{
    for (int i = 0; i < 5; i ++ )
        cout << array[i] << ' ';
    cout << endl;
}

int main()
{
    cout << "b: " << endl;
    out(b);
    Map(a, a + 5, b, Cube);
    out(b);
    Map(a, a + 5, b, Square);
    out(b);

    cout << "c: " << endl;
    out(c);
    Map(d, d + 5, c, Square);
    out(c);

    return 0;
}