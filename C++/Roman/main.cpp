#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
class romanType

{
private:

string roman;
int number;

public:
    romanType();
romanType(int n, string r);
    int getnumber();
string getroman();
    string convertroman();


};

romanType:: romanType()
{
    roman = "Q";
    number = 0;
}

romanType::romanType(int n, string r)
{
    number = n;
    roman = r;
}

int romanType::getnumber()
{
return number;
}
string romanType::getroman()
{
return roman;
}
string romanType::convertroman()
{
if (number == 1) roman = "I";
if (number == 2) roman = "II";
if (number == 3) roman = "III";
if (number == 4) roman = "IV";
if (number == 5) roman = "V";
if (number == 6) roman = "VI";
if (number == 7) roman = "VII";
if (number == 8) roman = "VIII";
if (number == 9) roman = "IX";
if (number == 10) roman = "X";
if (number == 11) roman = "XI";
if (number == 12) roman = "XII";
if (number == 13) roman = "XIII";
if (number == 14) roman = "XIV";
if (number == 15) roman = "XV";
if (number == 16) roman = "XVI";
if (number == 17) roman = "XVII";
if (number == 18) roman = "XVIII";
if (number == 19) roman = "XIX";
if (number == 20) roman = "XX";

return roman;
}

void read(romanType nums[])
{
int n;
string r;
int i=0;
string filename;
cout << "Enter filename: " << endl;
getline(cin, filename);
ifstream fin;
fin.open(filename);
while (!fin.eof())
{
fin >> n;
    romanType newRomanType(n, r);
    nums[i] = newRomanType;
    i++;
}
fin.close();
}

int main()
{
romanType nums[20];
read(nums);
    cout << nums[5].getnumber();
return 0;
}


