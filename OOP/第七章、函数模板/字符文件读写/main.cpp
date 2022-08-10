#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    vector<int> v;
    ifstream srcFile("TXT\\in.txt", ios::in); //srcFile是一个对象
    ofstream destFile("TXT\\out.txt", ios::app);

    int x;
    while(srcFile >> x) v.push_back(x);
    sort(v.begin(), v.end());

    destFile << "size: " << v.size() << endl;
    destFile << "array: ";
    for(auto &x : v)
        destFile << x << ' ';
    destFile << endl;

    srcFile.close();
    destFile.close();

    cout << "done" << endl;

    return 0;
}