#include <iostream>
#include <vector>
#include "TicTacToe.h"

int main()
{
    std::cout << "\n\n\tTic Tac Toe\n\n";
    std::cout << "Player 1 (X)  -  Player 2 (O)\n\n";

    TicTacToe game;
    game.display();

    int turns = 0;
    char pos;
    while (!game.checkWin())
    {
        turns % 2 == 0
            ? std::cout << "Player 1 (X) make your move: \n"
            : std::cout << "Player 2 (O) make your move: \n";
        std::cin >> pos;
        while (!game.isAvailable(pos))
        {
            std::cout << "Position taken, try another spot!\n";
        }
        turns % 2 == 0 ? game.place(pos, 'X') : game.place(pos, 'O');
        game.display();
        ++turns;
    }

    turns % 2 == 0
        ? std::cout << "Congratulations Player 1 (O)!\n"
        : std::cout << "Congratulations Player 2 (X)!\n";

    return 0;
}