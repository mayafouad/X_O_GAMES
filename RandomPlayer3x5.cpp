#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

// Set player symbol and name as Random Computer Player
RandomPlayer3x5::RandomPlayer3x5 (char symbol, int dimension , int dimension1):RandomPlayer(symbol,dimension)
{     //build constructor inherits from player and add new dimension as board has 2 different dimensions
    this->dimension1 = dimension1;//take extra dimension and board have 2 different dimension
}

// Generate a random move
void RandomPlayer3x5::get_move (int& x, int& y) {
    // while (true) {//looping until getting the right move
    x = (int) (rand() / (RAND_MAX + 1.0) * dimension);//chooses randon numbers but limited with dimension
    y = (int) (rand() / (RAND_MAX + 1.0) * dimension1);//chooses randon numbers but limited with dimension1
    if ((x == 0 and y == 2) || (x == 1 and y >= 1 and y <= 3) || (x == 2)){
        // break;//end loop if computer chooses correct random number inside my boundary
    }
    // }
}
