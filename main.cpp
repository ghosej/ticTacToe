//
//  main.cpp
//  ticTacToe
//
//  Created by Ghose, Jenny on 8/6/18.
//  Copyright © 2018 Ghose, Jenny. All rights reserved.
//

#include <iostream>
using namespace std;

void drawBoard(char board[]);
int checkWin(char board[]);

int main() {
    char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    cout << "Welcome to My Ultra Amazing Tic Tac Toe Game!" << endl << endl;
    
    int gameStatus = -1, player = 0, decision;
    char mark;
    
    while (gameStatus == -1) {
        player++;
        
        drawBoard(board);
        
        player = (player % 2) ? 1 : 2;
        
        cout << "Player " << player << ", enter a number: ";
        cin >> decision;
        
        mark = (player == 1) ? 'X' : 'O';
        
        if (board[decision] == 'X' || board[decision] == 'O') {
            cout << "Invalid move. You cannot change this square." << endl;
            break;
        } else {
            board[decision] = mark;
        }
        
        gameStatus = checkWin(board);
    }
    drawBoard(board);
    if (gameStatus == 1) {
        cout << "Player " << player << " has won the game. Congrats!" << endl;
    } else {
        cout << "Game over. Better luck next time!" << endl;
    }
    
    return 0;
}

void drawBoard(char board[]) {

    cout << endl << "Player 1 (X) -- Player 2 (O)" << endl << endl;
    // first row
    cout << "     |     |     " << endl;
    cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    // second row
    cout << "     |     |     " << endl;
    cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    // third row
    cout << "     |     |     " << endl;
    cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << endl;
}

// returns 1: game won
// returns 0: game over; draw
// returns -1: game in progress
int checkWin(char board[]) {
    if (board[1] == board[2] && board[2] == board[3]) {
        return 1;
    } else if (board[4] == board[5] && board[5] == board[6]) {
        return 1;
    } else if (board[7] == board[8] && board[8] == board[9]) {
        return 1;
    } else if (board[1] == board[4] && board[4] == board[7]) {
        return 1;
    } else if (board[2] == board[5] && board[5] == board[8]) {
        return 1;
    } else if (board[3] == board[6] && board[6] == board[9]) {
        return 1;
    } else if (board[1] == board[5] && board[5] == board[9]) {
        return 1;
    } else if (board[3] == board[5] && board[5] == board[7]) {
        return 1;
    } else if (board[1] != '1' && board[2] != '2' && board[3] != '3'
               && board[4] != '4' && board[5] != '5' && board[6] != '6'
               && board[7] != '7' && board[8] != '8' && board[9] != '9') {
        return 0;
    }
    return -1;
}
