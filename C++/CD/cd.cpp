/*
 Kattis - CD
 By Bailey Williams
 9/24/19
 This is a solution to Kattis' problem named CD where Jack and Jill each have a certain number
 of cds. Each cd they own has a catalog number which is entered into the in ascending order.
 The catalog numbers are then compared with eachother and if there are any duplicates it means
 that Jack and Jill need to sell one of the cds. The program will them tell the user how many
 cds they should sell so together they have one copy of each cd.
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

//function gets the number of cds that Jack and Jill need to sell
int answer(vector<int> jack, vector<int> jill, vector<int> ans)
{
    set_intersection(jack.begin(), jack.end(), jill.begin(), jill.end(), back_inserter(ans));
    //the size of ans is the number of cds they need to sell
    return ans.size();
}

//function gets users input, enters the data into vectors, and then outputs answer
void cd()
{
    int a, b, temp; //
    while(cin >> a >> b && a != 0 && b != 0)
    {
        vector<int> jack, jill, ans;
        for(int i = 0; i < a; i++)
        {
            cin >> temp;
            jack.push_back(temp); //puts Jack's cds into a vector
        }
        for(int i = 0; i < b; i++)
        {
            cin >> temp;
            jill.push_back(temp); //puts Jill's cds into a vector
        }
        cout << answer(jack, jill, ans) << endl; //outputs the number of cds jack and Jill need to sell
    }
}

//test function ensures that the output given is correct
void test()
{
    vector<int> test1 = {1, 2, 5, 7};
    vector<int> test2 = {2, 5, 6};
    vector<int> test3 = {4, 5, 6, 7};
    vector<int> test4 = {5, 6, 7, 9, 12};
    vector<int> testans;
    assert(answer(test1, test2,testans) == 2);
    assert(answer(test2, test3, testans) == 2);
    assert(answer(test3, test4, testans) == 3);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) test();
    else cd();
    return 0;
}

