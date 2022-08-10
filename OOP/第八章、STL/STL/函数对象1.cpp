#include <iostream>
#include <algorithm>
#include <deque>
#include <list>

using namespace std;

class MyAverage
{
    public:
        double operator() (int a1, int a2, int a3){
            return (double)(a1 + a2 + a3) / 3;
        }
};

int main()
{
    MyAverage avg;
    //avg(3,2,3)就相当于avg.operator(3,2,3)
    cout << "avg:" << avg(3, 2, 3) << endl;
}