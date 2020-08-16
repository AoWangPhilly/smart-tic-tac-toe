#include <iostream>
#include <vector>
#include <string>
#include "TicTacToe.h"
#include <math.h>

int scoring(TicTacToe board, char ai, char hu);
int minMax(TicTacToe board, int depth, int alpha, int beta, bool isMaximizing);
char bestMove(TicTacToe board);

int main()
{
    std::cout << "\n\n\tTic Tac Toe\n\n";
    std::cout << "Player 1 (X)  -  Player 2 (O)\n\n";

    TicTacToe game;
    game.display();

    char pos;
    /*  Loops through the game and will end under two conditions:
     *  - There aren't any moves left if the board is full => tie
     *  - A player wins
     */
    for (int turn = 0; turn < 9; ++turn)
    {

        // Even player (X), odd player (O)
        turn % 2 == 0
            ? std::cout << "Player 1 (X) make your move: \n"
            : std::cout << "Player 2 (O) make your move: \n";

        // std::cin >> pos;
        if (turn % 2 != 0)
        {
            std::cin >> pos;
        }
        else
        {
            pos = bestMove(game);
        }

        // Loops continuously until player inputs unfilled space
        while (!game.isAvailable(pos))
        {
            std::cout << "Position taken, try another spot!\n";
            std::cin >> pos;
        }

        turn % 2 == 0 ? game.place(pos, 'X') : game.place(pos, 'O');
        game.display();

        // Breaks if won
        if (game.checkWin('X'))
        {
            std::cout << "Congratulations Player 1 (X)!\n";
            break;
        }
        else if (game.checkWin('O'))
        {
            std::cout << "Congratulations Player 2 (O)!\n";
            break;
        }
    }

    if (!game.movesLeft() && !game.checkWin('X') && !game.checkWin('O'))
    {
        std::cout << "Tie game! Try again?";
    }

    return 0;
}

int scoring(TicTacToe board, char ai, char hu)
{
    if (board.checkWin(ai))
    {
        return 10;
    }
    else if (board.checkWin(hu))
    {
        return -10;
    }
    return 0;
}

int minMax(TicTacToe board, int depth, int alpha, int beta, bool isMaximizing)
{
    if (board.checkWin('O') || board.checkWin('X') || !board.movesLeft())
    {
        return scoring(board, 'X', 'O');
    }

    if (isMaximizing)
    {
        int bestVal = -INFINITY;
        for (char i = 49; i < 58; ++i)
        {
            if (board.isAvailable(i))
            {
                board.place(i, 'X');
                int score = minMax(board, depth + 1, alpha, beta, !isMaximizing);
                bestVal = std::max(score, bestVal);
                alpha = std::max(alpha, score);
                if (beta <= alpha)
                {
                    break;
                }
                board.place(i, i);
            }
        }
        return bestVal;
    }
    else
    {
        int bestVal = INFINITY;
        for (char i = 49; i < 58; ++i)
        {
            if (board.isAvailable(i))
            {
                board.place(i, 'O');
                int score = minMax(board, depth + 1, alpha, beta, !isMaximizing);
                bestVal = std::min(score, bestVal);
                beta = std::min(beta, score);
                if (beta <= alpha)
                {
                    break;
                }
                board.place(i, i);
            }
        }
        return bestVal;
    }
}

char bestMove(TicTacToe board)
{
    int bestVal = -INFINITY;
    char move;
    for (char i = 49; i < 58; ++i)
    {
        if (board.isAvailable(i))
        {
            board.place(i, 'X');
            int score = minMax(board, 0, -INFINITY, INFINITY, false);
            board.place(i, i);
            if (score > bestVal)
            {
                bestVal = score;
                move = i;
            }
        }
    }
    return move;
}