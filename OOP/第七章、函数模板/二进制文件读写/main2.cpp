/*
使用二进制文件较与文本文件，查找方便，节省存储空间

windows下文本格式换行符在保持为文本格式时会0a变为0d0a
这样文本方式就本2进制方式每行多1个字节。
UNIX/LINUX 文本和2进制没有区别一样大小
理论上2进制比文本节约50%的存储空间
对于一个数字，存储在文本文件是以字符串的形式，而存储在2进制文件就是以int形式

并且2进制文件存储的字节是固定大小的
也即所有数据都是排好序的
而经过排序的数据查找方便（二分查找）
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

struct Student{
    char name[30];
    int score;
};

vector<int> v;

int main()
{
    //输入学生信息到Student.dat
    // CTRL+Z结束输入
    Student s;
    ofstream outFile("Student.dat", ios::out | ios::binary);
    while(cin >> s.name >> s.score)
        outFile.write((char *)&s, sizeof (s));
    outFile.close();

    cout << "输入结束，信息为：" << endl;

    //输出Student.dat中的学生信息到终端
    ifstream inFile("Student.dat", ios::in | ios::binary);
    if(!inFile)
    {
        cout << "Error" << endl;
        return 0;
    }
    while(inFile.read((char *)&s, sizeof (s)))
    {
        v.push_back(inFile.gcount());
        cout << s.name << ' ' << s.score << endl;
    }
    inFile.close();

    cout << "输出结束" << endl;

    // 将Jack改为Xjy
    fstream ioFile("Student.dat", ios::in | ios::out | ios::binary);
    if(!ioFile)
    {
        cout << "Error!" << endl;
        return 0;
    }
    //seekp <=> seek put 操纵写指针
    //seekg <=> seek get 操纵读指针
    ioFile.seekp(2 * sizeof(s), ios::beg);
    ioFile.write("Xjy", strlen("Xjy") + 1);// +1是有一个结束标志'\0'
    ioFile.seekg(0, ios::beg);

    cout << "修改之后: " << endl;
    while(ioFile.read((char *)&s, sizeof (s)))
    {
        cout << s.name << ' ' << s.score << endl;
    }
    return 0;
}
/*
Tom 100
Mike 90
Jack 80
*/