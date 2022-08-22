/*
 Kattis - Babelfish
 Date: 9/17/19
 By: Bailey Williams
 The solution to Kattis' Babelfish where a foreign word is given and
 the english version is found by programs and outputted.
 If a foreign word is not recognized by program then the
 output is "eh". User can input all foreign words and
 their corresponding english ones into dictionary
 and then begin use of the program.
 */
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <cassert>

using namespace std;

string answer(unordered_map<string, string> babel, string first, string second) //answer function finds the english version of the foreign word and outputs it
{
    string answer;
    first = babel[second];
    answer = (first == "" ? "eh" : first); //compares user input and outputs answer
    cout << answer << endl;
    return answer;
}

void test() //test fnuction that tests to see that the program works corrects
{
    string first;
    string second;
    //create unordered map
    unordered_map<string, string> test1;
    unordered_map<string, string> test2;
    unordered_map<string, string> test3;
    //inserts into the unordered map
    test1.insert({{"onkeymay", "monkey"}, {"onkeyday", "donkey"}, {"irdbay", "bird"}});
    test2.insert({{"orsehay", "horse"}, {"iraffegay", "giraffe"}, {"angarookay", "kangaroo"}});
    test3.insert({{"igertay", "tiger"}, {"ionlay", "lion"}, {"earbay", "bear"}});
    //set variable that would be user input so it can be tested
    second = "irdbay";
    //ensures that the program is finding the correct answer
    assert(answer(test1, first, second) == "bird");
    second = "angarookay";
    assert(answer(test2, first, second) == "kangaroo");
    second = "igertay";
    assert(answer(test3, first, second) == "tiger");
}

void babelfish()
{
    unordered_map <string, string> babel; //creation of unordered map
    string line;
    string first;
    string second;
    while(getline(cin,line) && line != "") //gets users input and enters it into unordered map
    {
        stringstream word(line);
        word >> first;
        word >> second;
        babel[second] = first;
    }
    while(cin >> second) //gets users input on foreign word
    {
        answer(babel, first, second); //gets the correspobding english word
    }
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) test();
    else babelfish();
    return 0;
}
