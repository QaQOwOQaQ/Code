#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void func(int x)
{
    cout << x << endl;
}

int main()
{
    int a = 1, b = 2;
    func((a, b));
    
    return 0;
}