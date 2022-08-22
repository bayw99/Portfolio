/*
 Kattis - Apaxiaaans
 By: Bailey Williams
 10/17/18
 
 This program takes a word with an extensive amount of the same letter repeated and
 simplifies it to only one of that letter.
 Algorithm Steps:
 1. Create variables to store the input and output.
 2. Get users input adn store it into variable.
 3. Create function that takes input and puts it into a loop that rids it of any
    repeated letters in a row.
 4. Create a test function that makes sure everything works properly.
 5. Output the simplified input.
 */


#include <iostream>
#include <string>
#include <cassert>

using namespace std;

//function to get rid of repeated letters in a row
string fixApax(string input){
    string output;
    
    output = "";
    output += input[0];
    
    //loop to chack through the input
    for(int i = 1; i < input.length(); ++i){
        if(input[i] != input[i - 1])
            output += input[i];
    }
    return output;
}

// function to test fixApax
void test(){
    string output;
    output = fixApax("bob");
    assert(output == "bob");
    output = fixApax("bobby");
    assert(output == "boby");
}

int main(){
    //variables to store the input and output in
    string input;
    string output;
    
    //loop gets input and puts it into function
    while(cin >> input){
        output = fixApax(input);
    //outputs the fixed input
        cout << output << endl;
    }
    return 0;
}
