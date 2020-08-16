#include <iostream>
#include <vector>
#include <string>
#include "TicTacToe.h"
#include <math.h>

int scoring(TicTacToe board, char ai, char hu);
int miniMax(TicTacToe board, int depth, int alpha, int beta, bool isMaximizing);
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

/**
 * Determines the score of the end result of the game
 * 
 * @param board is the current state of the game
 * @param ai is the mark the AI player uses
 * @param hu is the mark of the human player uses
 * @returns the score of 10 when the AI wins, -10 when the human wins, and 0 for a tie
 */
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
    if (board.checkWin('O') || board.checkWin('X') || !board.movesLeft())
    {
        return scoring(board, 'X', 'O');
    }

    if (isMaximizing)
    {
        int bestVal = -INFINITY;

        // Loops through characters 1-9
        for (char i = 49; i < 58; ++i)
        {
            if (board.isAvailable(i))
            {
                board.place(i, 'X');
                int score = miniMax(board, depth + 1, alpha, beta, !isMaximizing);
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

        // Loops through characters 1-9
        for (char i = 49; i < 58; ++i)
        {
            if (board.isAvailable(i))
            {
                board.place(i, 'O');
                int score = miniMax(board, depth + 1, alpha, beta, !isMaximizing);
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
            int score = miniMax(board, 0, -INFINITY, INFINITY, false);
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