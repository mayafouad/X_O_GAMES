// File name: ConnectFourPlayer
// Purpose: Class for Connect Four Player
// Author: Laila Waleed Dawood Soliman
// ID: 20220261
// Section: S20
// Date: 15/12/2023
// Version: 1

#include <iostream>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"  
using namespace std;

// Constructor for ConnectFourPlayer
ConnectFourPlayer::ConnectFourPlayer(int order, char symbol, ConnectFourBoard& gameBoard) : Player(order, symbol), board(gameBoard) {
}

// Function to get the player's move
void ConnectFourPlayer::get_move(int &x, int &y) {
    // allow the user to enter the column for the move
    cout << "\nPlease enter your move column (0 to 6): ";
    cin >> y;

    // Check if the column is within the valid range
    while (y < 0 || y > 6) {
        cout << "Invalid column. Please enter a column between 0 and 6: ";
        cin >> y;
    }

    // Find the first available row in the chosen column
    x = -1;
    for (int i = 5; i >= 0; --i) {
        if (board.getCellValue(i, y) == 0) {
            x = i;
            break;
        }
    }

    // If the column is full, ask for a new column
    while (x == -1) {
        cout << "Column is full. Please choose another column: ";
        cin >> y;

        // Check if the new column is within the valid range
        while (y < 0 || y > 6) {
            cout << "Invalid column. Please enter a column between 0 and 6: ";
            cin >> y;
        }

        // Find the first available row in the new chosen column
        for (int i = 5; i >= 0; --i) {
            if (board.getCellValue(i, y) == 0) {
                x = i;
                break;
            }
        }
    }
}
