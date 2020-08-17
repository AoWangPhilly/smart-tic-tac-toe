#include <iostream>
#include <vector>
#include <string>
#include "TicTacToe.h"
#include <math.h>

char bestMove(TicTacToe board);
int miniMax(TicTacToe board, int depth, int alpha, int beta, bool isMaximizing);

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
int miniMax(TicTacToe board, int depth, int alpha, int beta, bool isMaximizing)
{
    // Ends recursion when there's a victor or a tie
    if (board.checkWin('X'))
        return 10;
    else if (board.checkWin('O'))
        return -10;
    else if (board.noMovesLeft())
        return 0;

    if (isMaximizing)
    {
        int bestVal = -INFINITY;

        // Loops through characters 1-9
        for (char i = 49; i < 58; ++i)
        {
            // Checks to see if space is free
            if (board.isAvailable(i))
            {
                // Places the AI mark
                board.place(i, 'X');

                // Calls miniMax recursively and choose max value
                int val = miniMax(board, depth + 1, alpha, beta, false);
                bestVal = std::max(val, bestVal);
                alpha = std::max(alpha, val);

                // Breaks if next nodes didn't need to be checked
                if (alpha >= beta)
                    break;

                // Reverse placement
                board.place(i, i);
            }
        }
        return bestVal;
    }
    else
    {
        int bestVal = INFINITY;

        // Loops through characters 1-9
        for (char i = 49; i < 58; ++i)
        {
            // Checks to see if space is free
            if (board.isAvailable(i))
            {
                // Places the opponent mark
                board.place(i, 'O');

                // Calls miniMax recursively and choose min value
                int val = miniMax(board, depth + 1, alpha, beta, true);
                bestVal = std::min(val, bestVal);
                beta = std::min(beta, val);

                // Breaks if next notes didn't need to be checked
                if (beta <= alpha)
                    break;

                // Reverse placement
                board.place(i, i);
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
char bestMove(TicTacToe board)
{
    int bestVal = -INFINITY;
    char move;

    // Loops through characters 1-9
    for (char i = 49; i < 58; ++i)
    {
        if (board.isAvailable(i))
        {
            board.place(i, 'X');
            int val = miniMax(board, 0, -INFINITY, INFINITY, false);
            if (val > bestVal)
            {
                bestVal = val;
                move = i;
            }
            board.place(i, i);
        }
    }
    return move;
}