#include <iostream>
#include "TicTacToe.h"
#include <vector>

/**
 * TicTacToe board class
 */
TicTacToe::TicTacToe()
{
    std::vector<std::vector<char>> vect{{'1', '2', '3'},
                                        {'4', '5', '6'},
                                        {'7', '8', '9'}};
    setBoard(vect);
}

std::vector<std::vector<char>> TicTacToe::getBoard()
{
    return board;
}

void TicTacToe::setBoard(std::vector<std::vector<char>> board)
{
    this->board = board;
}

// Formats the board
void TicTacToe::display()
{

    std::cout << "     |     |     \n";
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "  " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2]
                  << "\n";
        if (i < 2)
        {
            std::cout << "_____|_____|_____\n";
            std::cout << "     |     |     \n";
        }
    }
    std::cout << "     |     |     \n\n";
}

/**
 * Checks to see if the position on board is available
 * 
 * @param pos is the position of the board 1-9
 * @return whether position is available (true) or not (false)
 */
bool TicTacToe::isAvailable(char pos)
{
    int row = (pos - 49) / 3;
    int col = (pos - 49) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        return true;
    }
    return false;
}

bool TicTacToe::noMovesLeft()
{
    for (char pos = 49; pos < 58; ++pos)
    {
        if (isAvailable(pos))
        {
            return false;
        }
    }
    return true;
}
/**
 * Places a mark on a position of the board
 * 
 * @param pos is the position of the board 1-9
 * @param mark is the mark on the board 'X' or 'O'
 */
void TicTacToe::place(char pos, char mark)
{
    int row = (pos - 49) / 3;
    int col = (pos - 49) % 3;
    board[row][col] = mark;
}

bool TicTacToe::checkThree(char a, char b, char c, char mark)
{
    return a == b && b == c && a == mark;
}

/**
 * Checks to see if a player won
 * 
 * @return if the game should/should not go on
 */
bool TicTacToe::checkWin(char mark)
{
    for (int i = 0; i < 3; ++i)
    {
        // Checks horizontal
        if (checkThree(board[i][0], board[i][1], board[i][2], mark))
        {
            return true;
        }

        // Checks vertical
        if (checkThree(board[0][i], board[1][i], board[2][i], mark))
        {
            return true;
        }
    }
    // Checks left diagonal

    if (checkThree(board[0][0], board[1][1], board[2][2], mark))
    {
        return true;
    }

    // Checks right diagonal

    if (checkThree(board[0][2], board[1][1], board[2][0], mark))
    {
        return true;
    }

    return false;
}