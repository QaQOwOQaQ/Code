#include <iostream>

using namespace std;

template<int size>
void print(int a[])
{
    for (int i = 0; i < size; i ++ )
        cout << a[i] << ' ';
    cout << endl;
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    print<5>(a);
} 
