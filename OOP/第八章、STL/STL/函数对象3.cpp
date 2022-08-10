#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
void print(T first, T last)
{
    for (; first != last; first ++ )
        cout << *first << ' ';
    cout << endl;
}

class A
{
    public:
        int v;
        A(int n) : v(n) {}
};

bool operator < (const A &a1, const A &a2) 
{
    return a1.v < a2.v;
}

bool GreaterA(const A &a1, const A &a2)
{
    return a1.v < a2.v;
}

struct lessA
{
    bool operator() (const A &a1, const A &a2)
    {
        return (a1.v % 10) < (a2.v % 10);
    }
};

ostream & operator << (ostream &o, const A &a)
{
    o << a.v;
    return o;
}

int main()
{
    int a1[4] = {5, 2, 4, 1};
    A a2[5] = {13, 12, 9, 8, 16};

    sort(a1, a1 + 4);
    cout << "1) ";
    print(a1, a1 + 4);

    // 2例, 3, 4需要输出对象A，所以我们要重载<<
    sort(a2, a2 + 5);
    cout << "2) ";
    print(a2, a2 + 5);
    
    sort(a2, a2 + 5, GreaterA);
    cout << "3) ";
    print(a2, a2 + 5);
    sort(a2, a2 + 5, lessA());
    cout << "4) ";
    print(a2, a2 + 5);

    cout << "done!" << endl;
    return 0;
}