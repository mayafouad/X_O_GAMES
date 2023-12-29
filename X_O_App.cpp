#include <iostream>
#include"../include/BoardGame_Classes.hpp"
using namespace std;
//-----------------------------------------------Game1----------------------------------------------
void game1(){
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer, or press 0 ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        // 3x5
        players[1] = new RandomPlayer3x5 ('o', 3 , 5);
    GameManager x_o_game (new Board3x5(), players);
    x_o_game.run();
}
//----------------------------------------------Game 2---------------------------------------------------
void game2()
{
    int choice;
    Player* players[2];
    ConnectFourBoard connectFourBoard;
    players[0] = new ConnectFourPlayer(1, 'x', connectFourBoard);
    cout << "Welcome to Connect Four Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new ConnectFourPlayer(2, 'o', connectFourBoard);
    else
        players[1] = new RandomPlayer ('o', 7);
    GameManager connect_four_game( &connectFourBoard, players);
    connect_four_game.run();
    system("pause");
}
//-------------------------------------------- --Game 3---------------------------------------------------
void game3(){
    Player* players[2];
    players[0] = new Player (1, 'x');
    int choice;
    cout << "Press 1 if you want to play with computer, or press 0 ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        players[1] = new RandomPlayer ('o', 5);
    Game x_o_game (new X_O_Board, players);
    x_o_game.run();
    system ("pause");
}
//---------------------------------------------Game 4------------------------------------------------
void game4(){
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');
    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);
    GameManager x_o_game (new ConnectFourBoard, players);
    x_o_game.run();
    system ("pause");
}
int main() {
    int game;
    cout << "Welcome To our Game Station, Press :\n";
    cout << "1- Pyramic Tic-Tac-Toe\n2- Four-in-a-row\n3- 5 x 5 Tic Tac Toe\n4- X_O\n";
    cin >> game;
    switch (game) {
        case 1:{
            game1();
            break;
        }
        case 2:{
            game2();
            break;
        }
        case 3:{
            game3();
            break;
        }
        case 4:{
            game4();
            break;
        }

    }


}
