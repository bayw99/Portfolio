/*
 Kattis - Putovanje
 10/4/19
 By Bailey Williams
 This is a solution to a Kattis problem called Putovanje where a guy named Mislav has a group of fruits
 with a certain cap and he can only eat up to a certain weight. When he starts eatting he tries to eat
 every next fruit if it is possible and he does not overeat, if he cannot eat the next fruit without
 overeatting then Mislav will move on to the next.
 */
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

//answer function takes vector of fruits and finds the max amount of fruit possible to eat
int answer(vector<int> fruits, int c, int f)
{
    int types = 0;
    int max = 0;
    for (auto i = 0; i < f; i++)
    {
        int weight = 0;
        int j = i;
        int eaten = 0;
        for (auto j = i; j < f; j++)
        {
            if (weight + fruits[j] <= c) //makes sure the cap amount of weight hasn'y been met
            {
                weight += fruits[j];
                eaten++; //adds to the amouhnt of fruits eaten
            }
        }
        max = std::max(max, eaten); //finds the max amount possble to eat
    }
    return max;
}

//putovanje function takes input and returns the answer to user
void putovanje()
{
    int c, f, temp;
    cin >> f >> c;
    vector<int> fruits;
    for (auto i = 0; i < f; i++)
    {
        cin >> temp;
        fruits.push_back(temp);
    }
    int ans;
    ans = answer(fruits, c, f);
    cout << ans << endl;
}

//test function makes sure that program is working correctly
void test()
{
    int ans;
    vector<int> test1 = {6, 2, 5, 4, 3, 1, 1, 2};
    ans = answer(test1, 8, 10);
    assert(ans = 6);
    vector<int> test2 = {5, 5 , 8, 2, 4, 1, 1};
    ans = answer(test2, 7, 16);
    assert(ans = 11);
    vector<int> test3 = {4, 3, 3, 1, 4};
    ans = answer(test3, 5, 8);
    assert(ans = 2);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) test();
    else putovanje();
    return 0;
}
