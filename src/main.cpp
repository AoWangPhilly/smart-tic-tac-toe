#include <iostream>
#include <vector>
#include "TicTacToe.h"

int main()
{
    TicTacToe game;
    game.display();
    game.place('1', 'X');
    game.place('4', 'X');
    game.place('7', 'X');
    game.display();
    std::cout << game.checkWin();
    return 0;
}