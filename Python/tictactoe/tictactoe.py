import os
import time
import random

def printBoard(board):  #board made out of strings
    print('   |   |')
    print(' ' + board[1] + ' | ' + board[2] + ' | ' + board[3] + ' ')
    print('   |   |')
    print('-------------')
    print('   |   |')
    print(' ' + board[4] + ' | ' + board[5] + ' | ' + board[6] + ' ')
    print('   |   |')
    print('-------------')
    print('   |   |')
    print(' ' + board[7] + ' | ' + board[8] + ' | ' + board[9] + ' ')
    print('   |   |')

def printTitle():
    print("""
    🅃🄷🄸🅂 🄸🅂...
    ████████╗██╗░█████╗░  ████████╗░█████╗░░█████╗░  ████████╗░█████╗░███████╗
    ╚══██╔══╝██║██╔══██╗  ╚══██╔══╝██╔══██╗██╔══██╗  ╚══██╔══╝██╔══██╗██╔════╝      
    ░░░██║░░░██║██║░░╚═╝  ░░░██║░░░███████║██║░░╚═╝  ░░░██║░░░██║░░██║█████╗░░     
    ░░░██║░░░██║██║░░██╗  ░░░██║░░░██╔══██║██║░░██╗  ░░░██║░░░██║░░██║██╔══╝░░      
    ░░░██║░░░██║╚█████╔╝  ░░░██║░░░██║░░██║╚█████╔╝  ░░░██║░░░╚█████╔╝███████╗     
    ░░░╚═╝░░░╚═╝░╚════╝░  ░░░╚═╝░░░╚═╝░░╚═╝░╚════╝░  ░░░╚═╝░░░░╚════╝░╚══════╝      

                                   1 | 2 | 3
                                   ---------
                                   4 | 5 | 6
                                   ---------
                                   7 | 8 | 9

    🄸🄽🅂🅃🅁🅄🄲🅃🄸🄾🄽🅂:
    To play Tic-Tac-Toe, you must get 3 in a row! You may choose a number from 
    1-9 on each turn which will be your placement of your character. You will
    be X and the AI will be O. Good luck!
    """)

#Check for player X win
def winner(board, player, wins, losses):
    if(board[1] == player and board[2] == player and board[3] == player) or \
    (board[4] == player and board[5] == player and board[6] == player) or \
    (board[7] == player and board[8] == player and board[9] == player) or \
    (board[1] == player and board[4] == player and board[7] == player) or \
    (board[2] == player and board[5] == player and board[8] == player) or \
    (board[3] == player and board[6] == player and board[9] == player) or \
    (board[1] == player and board[5] == player and board[9] == player) or \
    (board[3] == player and board[5] == player and board[7] == player):
        if player == "X":
            wins += 1
        else:
            losses += 1
        return True 
    else:
        return False

#Check if board is full (tie)
def boardFull(board):
    if " " in board:
        return False
    else:
        return True

#Creates AI move
def aiMove(board, player):
    #Goes for center of board
    if board[5] == " ":
        return 5
    if board[1] == " ":
        return 1
    if board[9] == " ":
        return 9
    while True:
        move = random.randint(1, 9)
        if board[move] == " ":
            return move
            break

#Prints players stats
def playerStats(wins, losses, ties, games):
    print("Total Wins: ", wins)
    print("Total Losses: ", losses)
    print("Total Ties: ", ties)
    print("Total Games: ", games)
    

def main(wins, losses):
    while True:
        moves = 0
        os.system("clear")
        printTitle()
        printBoard(board)

        #Gets player X input
        choice = input("Choose an empty space to place an X.  ")
        choice = int(choice)

        if board[choice] == " ":
            board[choice] = "X"
        else:
            print("That space is not empty")
            time.sleep(1)

        #Check player X
        if winner(board, "X", wins, losses):
            os.system("clear")
            printTitle()
            printBoard(board)
            print("X WINS!")
            break

        os.system("clear")
        printTitle()
        printBoard(board)

        #Check tie
        if boardFull(board) == True:
            print("Tie!")
            break
    

        #Gets AI input
        choice = aiMove(board, "O")
        choice = int(choice)

        if board[choice] == " ":
            board[choice] = "O"
        else:
            print("That space is not empty")
            time.sleep(1)

        #Check player O
        if winner(board, "O", wins, losses):
            os.system("clear")
            printTitle()
            printBoard(board)
            print("AI WINS!")
            break
    
        #Check tie
        if boardFull(board) == True:
            print("Tie!")
            break

wins = 0
wins = int(wins)
losses = 0
losses = int(losses)
ties = 0
ties = int(ties)
games = 0
games = int(games)

while True:
    answer = input("Do you want to play? (yes or no) ")
    if answer == "yes":
        #Board is a list
        board = ["", " ", " ", " ", " ", " ", " ", " ", " ", " "]
        main(wins, losses)
        if winner(board, "X", wins, losses):
            wins += 1
        if winner(board, "O", wins, losses):
            losses += 1
        if boardFull(board):
            ties +=1
        games += 1
        playerStats(wins, losses, ties, games)
    elif answer == "no":
        break
    










    