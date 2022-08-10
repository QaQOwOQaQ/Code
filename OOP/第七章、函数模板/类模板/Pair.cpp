#include <iostream>
#include <cstring>

using namespace std;

template <class T1, class T2>
class Pair
{
    public:
        T1 key;
        T2 value;
        Pair(T1 x, T2 y) : key(x), value(y){};
        bool operator < (const Pair<T1, T2> &p) const;
        template <class T3, class T4>
        friend ostream &operator<<(ostream &o, const Pair<T3, T4> &p);
};

template <class T1, class T2>
bool Pair<T1, T2>::operator <(const Pair<T1, T2> &p) const
{
    return key < p.key;
}

template <class T1, class T2>
ostream & operator<< (ostream &o, const Pair<T1, T2> &p)
{
    o << '(' << p.key << ',' << p.value << ')';
    return o;
}

class A
{
    public:
        template <class T>
        void func(T t) {
            cout << t << endl;
        }
};

int main()
{
    //class1
    cout << "begin!" << endl;
    Pair<string, int> Tom("汤姆", 100);
    cout << Tom.key << endl;
    cout << "end!" << endl;
    cout << Tom << endl;

    //class2
    A a;
    a.func("Hello");
    a.func(1000);
    a.func('K');

    return 0;
}