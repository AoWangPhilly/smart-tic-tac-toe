#include <iostream>
#include <vector>
#include <string>
#include "TicTacToe.h"
#include <math.h>

int minMax(TicTacToe board, int depth, bool isMaximizing);
char bestMove();

int main()
{
    std::cout << "\n\n\tTic Tac Toe\n\n";
    std::cout << "Player 1 (X)  -  Player 2 (O)\n\n";

    TicTacToe game;
    game.display();

    std::string winner;
    char pos;
    bool draw = true;

    /*  Loops through the game and will end under two conditions:
     *  - There aren't any moves left if the board is full => tie
     *  - A player wins
     */
    for (int turn = 0; turn < 9; ++turn)
    {
        // Breaks if won
        if (game.checkWin())
        {
            draw = false;
            winner = (turn - 1) % 2 == 0 ? "Player 1 (X)" : "Player 2 (O)";
            break;
        }

        // Even player (X), odd player (O)
        turn % 2 == 0
            ? std::cout << "Player 1 (X) make your move: \n"
            : std::cout << "Player 2 (O) make your move: \n";
        std::cin >> pos;

        // Loops continuously until player inputs unfilled space
        while (!game.isAvailable(pos))
        {
            std::cout << "Position taken, try another spot!\n";
            std::cin >> pos;
        }

        turn % 2 == 0 ? game.place(pos, 'X') : game.place(pos, 'O');
        game.display();
    }

    if (draw)
    {
        std::cout << "Tie Game! Try again?\n";
    }
    else
    {
        std::cout << "Congratulations " << winner << "!\n";
    }

    return 0;
}

int minMax(TicTacToe board, int depth, bool isMaximizing)
{
    if (!depth || board.checkWin())
    {
        return -1;
    }
    if (isMaximizing)
    {
        int maxEval = -INFINITY;
    }
    else
    {
        int minEval = INFINITY;
    }
    return 0;
}

char bestMove()
{
    return '1';
}