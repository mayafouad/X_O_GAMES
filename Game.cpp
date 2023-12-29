// Author:  Maya Fouad Fathy

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

Game::Game(FiveXFive_Board* bPtr, Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void Game::run() {
    int x, y;
    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i = 0; i < 2; i++) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
        }
    }
    int n1 = boardPtr->wins(toupper(players[0]->get_symbol())), n2 = boardPtr->wins(toupper(players[1]->get_symbol())) ;
    cout << players[0]->get_symbol() << " make  " << n1  << endl;
    cout << players[1]->get_symbol() << " make  " << n2 << endl;
    if (n1 == n2){
        cout << "Draw!\n";
    }
    else if(n1 > n2){
        cout << players[0]->get_symbol() << " wins";
    }
    else cout << players[1]->get_symbol() << " wins";
}
