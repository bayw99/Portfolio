// Write a program that performs basic math operations on two numbers
/*
    Calculator Program
    This program performs basic math operations on two numbers
    By: Bailey Williams
    8/29/18
 
    Algorithm Steps:
    1. Get tow numbers
        i. Hard coded values, literal constants are ok
    2. Add the two numbers
    3. Subtract two numbers
    4. Multiply two numbers
    5. Divide the first by second and print the quotient
    6. Divide the the first by second and print the remainder
 
 pythontutor.com -goes over code
 
 */

#include <iostream>
using namespace std;

// 1. function definition
// voidfunction that doesn't return any value and doesn't take any argument
void hello() {
    cout << "Hello World" << endl;
}

// sum function takes 2 arguments and prints the sum of those arguments
void sum(int num1, int num2) {
    int total = num1 + num2;
    cout << "sum = " << total << endl;
}

int sum1(float num1, float num2) {
    float total = num1 + num2;
    return total;
}

int main() {
    // 2. call your function
    hello();
    sum(10, 20);
    cout << sum1(15.8, 3453.25);
    float s = sum1(12.3434, 34.565);
    s += s*0.6; // s = s + s * 0.6
    cout << "total = " << s;
}
    
 int main() {
    int num1, num2, result;
    num1 = 500;
    num2 = 55;
    result = num1 + num2;
    cout << "sum of " << num1 << " and " << num2 << " = " << result << endl;
    result = num1 - num2;
    cout << "difference of " << num1 << " and " << num2 << " = " << result << endl;
    result = num1 * num2;
    cout << "product of " << num1 << " and " << num2 << " = " << result << endl;
    result = num1 / num2;
    cout << "quotient of " << num1 << " and " << num2 << " = " << result << endl;
    result = num1 % num2;
    cout << "remainder of " << num1 << " and " << num2 << " = " << result << endl;
    cin.ignore(1000,'\n');
    cin.get();
    return 0;
}


