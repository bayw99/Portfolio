
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout("copy.jpg");
    ifstream fin("old.jpg",ios::binary);
    char ch;
    while(fin.read((char *)&ch,sizeof(ch)))
           fout.write((char *)&ch,sizeof(ch));
    return 0;
}
