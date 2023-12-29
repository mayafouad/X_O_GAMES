// Author:  Maya Fouad Fathy

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set the board
FiveXFive_Board::FiveXFive_Board () {
    n_rows = 5;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool FiveXFive_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void FiveXFive_Board::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            if(!board[i][j]){
            cout << "(" << i << "," << j << ")";
            cout <<   board [i][j] << " |";}
            else cout <<  "   " << board [i][j] << "   |";
        }
        cout << "\n-------------------------------------------------------";
    }
    cout << endl;
}

// Returns number of connected 3
int FiveXFive_Board::wins(char c) {
    int count = 0;
    // Check rows
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_rows - 2; ++j) { // will loop 3 times over columns
            if (board[i][j] == c && board[i][j + 1] == c && board[i][j + 2] == c) {
                count++;
            }
        }
    }
    // Check columns
    for (int i = 0; i < n_rows - 2; ++i) { // will loop 3 times over rows
        for (int j = 0; j < n_rows; ++j) {
            if (board[i][j] == c && board[i + 1][j] == c && board[i + 2][j] == c) {
                count++;
            }
        }
    }
    // Check diagonals
    for (int i = 0; i < n_rows - 2; ++i) {
        for (int j = 0; j < n_rows - 2; ++j) {
            if (board[i][j] == c && board[i + 1][j + 1] == c && board[i + 2][j + 2] == c) {
                count++;      // for main diagonal
            }
            if (board[i][j + 2] == c && board[i + 1][j + 1] == c && board[i + 2][j] == c) {
                count++;    // for anti diagonal
            }
        }
    }
    return count;
}
// i don't need this
bool FiveXFive_Board::is_winner() {
    return false;
}
// Return true if number of connected 3 for X = number of connected 3 for O
bool FiveXFive_Board:: is_draw() {
    return (wins( 'x') == wins( 'o') );
}

bool FiveXFive_Board::game_is_over () {
    return n_moves >= 24;
}
