/*
 Kattis - ICPC Tutorial
 By Bailey Williams
 10/20/19
 This is a solution to Kattis' ICPC Tutorial where a user inputs the number of operations that the
 computer used (m), input size (n), and a type of algorithm (t) and the program will calculate if
 an algorithm will be within the time limit of one second. If algoritm is within one second the
 output will be AC and if the time limit is exceeded then the output will be TLE.
 */

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cassert>

using namespace std;

//function finds out if algorithm is within one second and returns the answer using 0 or 1 (TLE or AC)
int accepted(int m, int n, int t)
{
    int MAX_FACTORIAL = 12;
    int EPSILON = 1E-6;
    int factorials[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};
    return t == 1 ? (n > MAX_FACTORIAL || factorials[n] > m) ? 0 : 1 :
    t == 2 ? n <= log2(m) + EPSILON :
    t == 3 ? n <= pow(m, 0.25) + EPSILON :
    t == 4 ? n <= pow(m, 1/3) + EPSILON :
    t == 5 ? n <= pow(m, 0.5) + EPSILON :
    t == 6 ? n * log2(n) <= m + EPSILON :
    n <= m;
}

//function tests that program is working correctly
void test()
{
    assert(accepted(100000000, 800, 4) == 0);
    assert(accepted(19931562, 200, 1) == 0);
    assert(accepted(100000000, 80, 5) == 1);
}
int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    int m,n,t;
    scanf("%d %d %d",&m,&n,&t); //gets user input & stores it into variables
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) test();
    else printf(accepted(m,n,t) ? "AC\n" : "TLE\n"); //prints if algorithm was AC or TLE
    return 0;
}
