#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

int a[3] = {1, 2, 3};

int main()
{
    //.dat为二进制文件的后缀
    //将120写入some.dat
    ofstream fout("some.dat", ios::out | ios::binary);//创建一个对象fout，以读和二进制的方式打开文件some.dat

    int x = 120;
    fout.write((const char *)&x, sizeof(int));
    
    fout.close();

    //将120从some.dat中读出来
    ifstream fin("some.dat", ios::in | ios::binary);
    int y = 0;
    fin.read((char *)&y, sizeof(int));
    fin.close();
    cout << "date: " << y << endl;
    return 0;
}