/*
 Guess the Number Program
 By: Bailey Williams
 Date: 10/1/18
 This program finds a random number between 1 and 20 and allows the user to enter up to six guesses. The user is informed whether they won the game by guessing the number or lost the game by using up all of their guesses.
 Algorithm Steps:
1. Ask players name and greet player.
2. Explain the rules of the game.
3. Create function that will find a random number between 1 and 20.
4. Ask player to guess a number and store the input.
5. Run input through loop which tells user if their guess is too low or too high.
6. Allow user up to 6 attempts to guess the number.
7. Inform user if they have won or lost.
8. Loop program until user wishes to quit.
9. When user quits display number of games played, wins, and losses.
 */
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

int main() {
    srand((unsigned int)time(NULL)); // so it doesn't repeat the same number
    
    cout << "Welcome to the -- Guess the Number -- game!" << endl;
    
    string name;
    cout << " What is your name? ";
    cin >> name;
    cout << "Hello " << name << ".";
    
    int number = rand() % 20 + 2; //stores the random number
    int guess; //stores player's guesses
    int tries; //stores how many guesses player has had
    char again;//stores players answer to continue playing
    int gamewinner=0;//stores if game was won or lost
    int lossCount=0;//stores number of games lost
    int winCount=0;//stores number of games won
    int gameCount=1;//stores number of games played
    
    while(true){ //get users guess loop
    
        tries = 0;
        cout << "I am thinking of a number between 1 and 20." << endl;
        
        while(true){
            cout << "Enter your guess: ";
            cin >> guess; //stores users guess
            cout << "You have " << 5 - tries << " guesses left." << endl;
            
            if(tries >= 5){ // check if guesses are taken up
                break;
            }
            // checks number
            if(guess > number){
                cout << "Your guess is too high!" << endl;
            }
            else if(guess < number){
                cout << "Your guess is too low!" << endl;
            }
            else{
                break;
            }
            tries++; //increments the number of guesses
        }
        if(tries >= 5){ //checking total guesses
            cout << "You ran out of guesses!" << endl;
            gamewinner=0;
            if(gamewinner == 0)
                lossCount++;//increments losses
        }
        else{ //user won
            cout << "Congrats " << name << ". You WIN!" << endl;
            cout << "You guessed my number in " << tries << " guesses." << endl;
            gamewinner=1;
            if(gamewinner == 1)
                winCount++;//increments wins
        }
    while(true){//loop for if player would like to play again
        cout << "Would you like to play again? [Y/y] for yes, anything else to quit." << endl;
        cin >> again;// stores users response
        //checks input and allows user to play again or exit
        if(again == 'y' || again == 'Y'){
            gameCount++;// increments games played
            break;
        }
        else{ //displays users stats when exiting
            cout << "Thanks for playing! Good bye!" << endl;
            cout << "Total games played: " << gameCount << endl;
            cout << "Total wins: " << winCount << endl;
            cout << "Total losses: " << lossCount << endl;
        }
        cin.ignore(1000, '\n');
        cin.get();
        return 0;
        }
    }
}

