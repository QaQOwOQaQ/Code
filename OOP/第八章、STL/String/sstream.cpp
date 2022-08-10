#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    //
    cout << "测试输入流" << endl;
    string input("Hello test 1230 3.1415926 A");
    cout << "input: " << input << endl;
    istringstream Input(input);
    string s1, s2;
    int i;
    double d;
    char c;
    Input >> s1 >> s2 >> i >> d >> c;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << i << endl;
    cout << d << endl;
    cout << c << endl;

    //
    cout << "测试输出流" << endl;
    ostringstream Output;
    int a = 10;
    Output << "This number is: " << a << endl;
    cout << Output.str();

    cout << endl;
}