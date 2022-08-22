/*
 Hangman Program
 By: Bailey Williams
 
 Algoritm Steps:
 1.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

//function prints title and layout of hangman
void printLayout(string title, bool top = true, bool bottom = true)
{
    bool front = true;
    if(top)
    {
        cout << "*<>*<>*<>*<>*<>*>*<*<>*<>*<>*<>*<>*" << endl;
        cout << "|";
    }
    else
    {
        cout << "|";
    }
    for(int i = title.length(); i < 33; i++)
    {
        if(front)
        {
            title = " " + title;
        }
        else
        {
            title = title + " ";
        }
        front = !front;
    }
    cout << title.c_str();
    
    if(bottom)
    {
        cout << "|" << endl;
        cout << "*<>*<>*<>*<>*<>*>*<*<>*<>*<>*<>*<>*" << endl;
    }
    else
    {
        cout << "|" << endl;
    }
}

void drawHangman(int guessCount = 0)
{
    if(guessCount >= 1)
    {
        printLayout("|", false, false);
    }
    else
    {
        printLayout("", false, false);
    }
    if(guessCount >= 2)
    {
        printLayout("|", false, false);
    }
    else
    {
        printLayout("", false, false);
    }
    if(guessCount >= 3)
    {
        printLayout("O", false, false);
    }
    else
    {
        printLayout("", false, false);
    }
    if(guessCount == 4)
    {
        printLayout("/  ", false, false);
    }
    if(guessCount == 5)
    {
        printLayout("/| ", false, false);
    }
    if(guessCount >= 6)
    {
        printLayout("/|\\", false, false);
    }
    else
    {
        printLayout("", false, false);
    }
    if(guessCount >= 7)
    {
        printLayout("|", false, false);
    }
    else
    {
        printLayout("", false, false);
    }
    if(guessCount == 8)
    {
        printLayout("/", false, false);
    }
    if(guessCount >= 9)
    {
        printLayout("/ \\", false, false);
    }
    else
    {
        printLayout("", false, false);
    }
}

void printLetters(string input, char from , char to)
{
    string s;
    for(char i = from; i <= to; i ++)
    {
        if(input.find(i) == string::npos)
        {
            s += i;
            s += " ";
        }
        else
        {
            s += " ";
        }
    }
    printLayout(s, false, false);
}

void printAvailableLetters(string taken)
{
    printLayout("Available Letters");
    printLetters(taken, 'A', 'M');
    printLetters(taken, 'N', 'Z');
}

bool printWordAndCheckWin(string word, string guessed)
{
    bool won = true;
    string s;
    for(int i = 0; i < word.length(); i++)
    {
        if(guessed.find(word[i]) == string::npos)
        {
            won = false;
            s += "_ ";
        }
        else
        {
            s += word[i];
            s += " ";
        }
    }
    printLayout(s, false);
    return won;
}

string loadRandomWord(string path)
{
    string word;
    vector<string> v;
    ifstream reader(path);
    if(reader.is_open())
    {
        while(std::getline(reader, word))
        {
            v.push_back(word);
        }
        
        int randomLine = rand() % v.size();
        word = v.at(randomLine);
        reader.close();

    }
    return word;
}

int triesLeft(string word, string guessed)
{
    int error = 0;
    for(int i = 0; i < guessed.length(); i++)
    {
        if(word.find(guessed[i]) == string::npos)
        {
            error++;
        }
    }
    return error;
}

int main ()
{
    srand(time(0));
    string guesses;
    string wordToGuess;
    wordToGuess = loadRandomWord("words.txt");
    int tries = 0;
    bool win = false;
    do
    {
        system("clear");
        printLayout("HANGMAN");
        drawHangman(tries);
        printAvailableLetters(guesses);
        printLayout("Guess the word");
        win = printWordAndCheckWin(wordToGuess, guesses);
        
        if(win)
        {
            break;
        }
        
        char x;
        cout << ">"; cin >> x;
        if(guesses.find(x) == string::npos)
        {
            guesses += x;
        }
        tries = triesLeft(wordToGuess, guesses);

    }
    while(tries < 10);
    
    if(win)
    {
        printLayout("YOU WON!");
    }
    else
    {
        printLayout("GAME OVER");
    }
    cin.get();
    cin.get();
    cin.ignore(1000, '\n');
    return 0;
}
