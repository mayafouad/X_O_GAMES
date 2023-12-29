// File name: ConnectFourBoard
// Purpose: class for Connect Four Board
// Author: Laila Waleed Dawood Soliman
// ID: 20220261
// Section: S20
// Date: 15/12/2023
// Version: 1

#include <iostream>
#include <random>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"

// Constructor for ConnectFourBoard
ConnectFourBoard::ConnectFourBoard()
{
    // Initialize the number of rows and columns
    n_rows = 6;
    n_cols = 7;
    // Dynamically allocate memory for the board
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];

        // Initialize each cell to 0
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Function to update the Connect Four board with a move
bool ConnectFourBoard::update_board(int x, int y, char mark)
{
    // Only update if the move is valid
    if (!(x < 0 || x > n_rows - 1 || y < 0 || y > n_cols) && board[x][y] == 0)
    {
        // Check if the move is on top of an existing piece
        if (x != 5 && !(board[x + 1][y] == 0))
        {
            board[x][y] = toupper(mark);
            n_moves++;
            return true;
        }
            // Check if the move is in the last row
        else if (x == 5)
        {
            board[x][y] = toupper(mark);
            n_moves++;
            return true;
        }
        else
        {
            return false; // Return false if the move is not valid
        }
    }
}

// Function to check if a player has won the game
bool ConnectFourBoard::is_winner()
{
    // Check for Connect Four winning conditions
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            char currentSymbol = board[i][j];
            if (currentSymbol != 0)
            {
                // Check horizontally
                if (j + 3 < n_cols &&
                    currentSymbol == board[i][j + 1] &&
                    currentSymbol == board[i][j + 2] &&
                    currentSymbol == board[i][j + 3]) {
                    return true;
                }
                // Check vertically
                if (i + 3 < n_rows &&
                    currentSymbol == board[i + 1][j] &&
                    currentSymbol == board[i + 2][j] &&
                    currentSymbol == board[i + 3][j]) {
                    return true;
                }
                // Check diagonally (up-right)
                if (i - 3 >= 0 && j + 3 < n_cols &&
                    currentSymbol == board[i - 1][j + 1] &&
                    currentSymbol == board[i - 2][j + 2] &&
                    currentSymbol == board[i - 3][j + 3]) {
                    return true;
                }
                // Check diagonally (up-left)
                if (i - 3 >= 0 && j - 3 >= 0 &&
                    currentSymbol == board[i - 1][j - 1] &&
                    currentSymbol == board[i - 2][j - 2] &&
                    currentSymbol == board[i - 3][j - 3]) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Function to get the value of a cell at a specific position
char ConnectFourBoard::getCellValue(int x, int y)
{
    // Ensure indices are within bounds
    if (x >= 0 && x < 6 && y >= 0 && y < 7)
    {
        return board[x][y];
    }
}

// Function to display the Connect Four board
void ConnectFourBoard::display_board() {
    // Display the Connect Four board
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            cout << "| (" << i << "," << j << ") " << board[i][j] ;
        }
        cout << "|\n";
        for (int j = 0; j < n_cols; ++j) {
            cout << "---------";
        }
        cout << "\n";
    }
}

// Function to check if the game is a draw
bool ConnectFourBoard::is_draw() {
    return (n_moves == 42 && !is_winner());
}

// Function to check if the game is over
bool ConnectFourBoard::game_is_over ()
{
    return n_moves >= 42;
}


