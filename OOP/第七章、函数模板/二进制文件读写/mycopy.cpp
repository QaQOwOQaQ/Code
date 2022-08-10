/*
实现：memcpy src.dat dest.dat

缓冲区：在我们读取字符的时候，需要从外存（硬盘）中读取
如果我们每次只读取一个字符，那我们肯定不会为了读取一个字符就启动一次硬盘
因为硬盘的IO是很慢的
所以我们读取一个字符的时候，操作系统会把整个扇区甚至多个扇区的内容全部读取到缓冲区中
这样就减少了访问磁盘的次数

测试：./mycopy a.dat b.dat //a文件必须存在,b可以不存在
*/
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])   //命令行的形式
{
    if(argc != 3)
    {
        cout << "File name missing!" << endl;
        return 0;
    }

    ifstream inFile(argv[1], ios::binary | ios::in);
    if(!inFile)
    {
        cout << "Source file open error!" << endl;
        return 0;
    }

    ofstream outFile(argv[2], ios::binary | ios::out);
    if(!outFile)
    {
        //由于可以进行到这一步,所以源文件肯定打开了
        //因此我们还需要关闭源文件
        inFile.close();
        cout << "Dest file open error!" << endl;
        return 0;
    }

    char ch;
    while(inFile.get(ch)) // 每次读入一个字符
        outFile.put(ch);    // 每次写入一个字符
 
    outFile.close();
    inFile.close();

    return 0;
}