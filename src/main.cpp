#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "TicTacToe.h"

char makeBestMove(TicTacToe board);
int miniMax(TicTacToe board, int depth, bool isMaximizing);

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
            pos = makeBestMove(game);
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

    if (game.noMovesLeft() && !game.checkWin('X') && !game.checkWin('O'))
    {
        std::cout << "Tie game! Try again?\n";
    }

    return 0;
}

/**
 * The implementation of the MiniMax algorithm with Alpha-Beta pruning
 * 
 * @param board is the current state of the game
 * @param depth is the depth of the TicTacToe tree
 * @param alpha initially -INF
 * @param beta initially INF
 * @param isMaximizing whether the player was maximizing win or minimizing loss
 * @returns the score of each move
 */
int miniMax(TicTacToe board, int depth, bool isMaximizing)
{
    if (board.checkWin('X'))
    {
        return 10;
    }
    else if (board.checkWin('O'))
    {
        return -10;
    }
    else if (board.noMovesLeft())
    {
        return 0;
    }
    if (isMaximizing)
    {
        int bestVal = -INFINITY;
        for (char pos = 49; pos < 58; ++pos)
        {
            if (board.isAvailable(pos))
            {
                board.place(pos, 'X');
                bestVal = std::max(bestVal, miniMax(board, depth + 1, !isMaximizing));
                board.place(pos, pos);
            }
        }
        return bestVal;
    }
    else
    {
        int bestVal = INFINITY;
        for (char pos = 49; pos < 58; ++pos)
        {
            if (board.isAvailable(pos))
            {
                board.place(pos, 'O');
                bestVal = std::min(bestVal, miniMax(board, depth + 1, !isMaximizing));
                board.place(pos, pos);
            }
        }
        return bestVal;
    }
}

/**
 * Returns the best move the AI should make
 * 
 * @param board is the current state of the board
 * @return the best move the AI can make
 */
char makeBestMove(TicTacToe board)
{
    int bestVal = -INFINITY;
    char bestMove;
    for (char pos = 49; pos < 58; ++pos)
    {
        if (board.isAvailable(pos))
        {
            board.place(pos, 'X');
            int moveVal = miniMax(board, 0, false);
            board.place(pos, pos);
            if (moveVal > bestVal)
            {
                bestMove = pos;
                bestVal = moveVal;
            }
        }
    }
    return bestMove;
}