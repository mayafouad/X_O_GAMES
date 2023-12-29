#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;
// set Board
Board3x5::Board3x5 () {
    n_rows = 3;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
           if (i == 0 and j == 2){//set only avaliable place with zero
               board[i][j] = 0;
           }
        else if (i == 1 and j >= 1 and j <= 3){//set only avaliable place with zero
               board[i][j] = 0;
        }
        else if (i == 2){//set only avaliable place with zero
               board[i][j] = 0;
        }
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Board3x5::update_board (int x, int y, char mark){
    // Only update if move is valid
 if (((x == 0 and y == 2) || (x == 1 and y >=1 and y <= 3) || (x == 2)) and board[x][y] == 0){
        //check if move out of boundardies or not
        board[x][y] = toupper(mark);// if use put mark captilized
        n_moves++;//increment moves by one
        return true;
    }
    else {
        cout <<"\nInValid move, Please re-enter x and y\n";//else so there is a problem in inserted move
        return false;
    }
}

// Display the board and the pieces on it
void Board3x5::display_board() {
    for (int i: {0,1,2}) {
        if(i == 0){//as we have three rows
            cout <<"\n."<<setw(18) <<"|" ;//leave space to build top of pyramid of 0 and 2
        }
        else if(i == 1){
            cout <<"\n"<< setw(10) <<"|" ;//leave space
        }
        else if(i == 2){
            cout <<"\n" <<"|" ;//leave space
        }
        for (int j: {0,1,2,3,4}) {//iterating on coloumns
            if(i == 0 and j == 2){
                cout << "(" << i << "," << j << ")";
                cout <<setw(2)<<board [i][j] << " |";//printing board of the limited bounadary
            }
            else if(i == 1 and j >= 1 and j <= 3){//detecting which one to print
                cout << "(" << i << "," << j << ")";
                cout <<setw(2)<<board [i][j] << " |";//cout selected move
            }
            else if (i == 2){
                cout << "(" << i << "," << j << ")";
                cout << setw(2) <<board [i][j] << " |";
            }
        }
        cout << "\n-----------------------------------------------";
    }
    cout << endl;
}
//Returns True if there is a winner
bool Board3x5::is_winner() {
    // it is for checking if diagnoals , rows , coloumns are equal and board equal char X or O
    if(board[0][2] == board[1][2] and board[1][2] == board[2][2] and (board[0][2] =='X' or board[0][2] =='O')){
        return true;//first coloumn
    }
    else if (board[1][1] == board[1][2] and board[1][2] == board[1][3] and (board[1][1] =='X' or board[1][1] =='O')){
        return true;//first row
    }
    else if(board[0][2] == board[1][1] and board[1][1] == board[2][0] and (board[0][2] =='X' or board[0][2] =='O')){
        return true;//first diagnol
    }
    else if(board[0][2] == board[1][3] and board[1][3] == board[2][4] and (board[0][2] =='X' or board[0][2] =='O')){
        return true;//second diagnol
    }
    for(int i = 0 ; i <= 2 ; ++i){
        if(board[2][i] == board[2][i+1] and board[2][i+1] == board[2][i+2] and (board[2][i] =='X' or board[2][i] =='O')){
            return true;//iterates on last row
        }
    }
    return false;//not winner if we get to this point , so the game will be continued
}
// Return true if 9 moves are done and no winner
bool Board3x5::is_draw() {
    return (n_moves == 9 && !is_winner());//no one win if board is not empty and no winners
}

bool Board3x5::game_is_over () {
    return n_moves >= 9;//end game if my moves are out
}
