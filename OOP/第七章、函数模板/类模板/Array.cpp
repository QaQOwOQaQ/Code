#include <iostream>
#include <cstring>

using namespace std;

template <class T, int size>
class Array
{
    public:
        T array[size];
        void print(){
            for (int i = 0; i < size; i ++ )
                cout << array[i] << ' ';
            cout << endl;
        }
};

int main()
{
    Array<int, 3> a;
    Array<double, 5> b;

    for (int i = 0; i < 3; i ++ )    a.array[i] = i;
    for (int i = 0; i < 5; i ++ )
        b.array[i] = (double)i / 50;

    a.print();
    b.print();

    return 0;
}