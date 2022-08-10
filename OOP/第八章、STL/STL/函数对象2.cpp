#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

template <class T>
void print(T first, T last)
{
    for (; first != last; ++ first)
        cout << *first << ' ';
    cout << endl;
}

int SumSquares(int total, int value)
{
    return total + value * value;
}

template <class T, class Init, class Pred>
T Accumulate(Init first, Init last, T init, Pred op)// op只能是函数指针或函数对象
{
    for(; first != last; ++ first)
        init = op(init, *first);
    return init;
}

template<class T>
class SumPowers
{
    private:
        int power;
    public:
        SumPowers(int p) : power(p) {}
        // 计算value的power次方,加到total上去
        const T operator()(const T &total, const T &value){
            T v = 1;
            for (int i = 0; i < power; i ++ )
                v = v * value;
            return total + v;
        }
};

int main()
{
    int result = 0;
    const int SIZE = 10;
    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v(a1, a1 + SIZE);
    cout << "1) ";
    print(v.begin(), v.end());
    result = Accumulate(v.begin(), v.end(), 0, SumSquares);
    cout << "2) " << result << endl;
    result = Accumulate(v.begin(), v.end(), 0, SumPowers<int>(3)); //SumPowers<int>(3)就是sumPowers<int>类的一个临时对象
    cout << "3) " << result << endl;
    result = Accumulate(v.begin(), v.end(), 0, SumPowers<int>(4));
    cout << "4) " << result << endl;
    result = Accumulate(v.begin(), v.end(), 0, SumPowers<int>(5));
    cout << "5) " << result << endl;

    // 如果我们不写一个函数对象，那么对于面上的例3,4,5，每一个都需要单独写一个函数
    // 但如果我们有函数对象，只需要每次调用函数对象就行了

    return 0;
}