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
    for (int i = 0; i < 3; ++i)
    {
        if (std::find(board[i].begin(), board[i].end(), pos) != board[i].end())
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe::movesLeft()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return true;
            }
        }
    }
    return false;
}
/**
 * Places a mark on a position of the board
 * 
 * @param pos is the position of the board 1-9
 * @param mark is the mark on the board 'X' or 'O'
 */
void TicTacToe::place(char pos, char mark)
{
    if (isAvailable(pos))
    {
        switch (pos)
        {
        case '1':
            board[0][0] = mark;
            break;
        case '2':
            board[0][1] = mark;
            break;
        case '3':
            board[0][2] = mark;
            break;
        case '4':
            board[1][0] = mark;
            break;
        case '5':
            board[1][1] = mark;
            break;
        case '6':
            board[1][2] = mark;
            break;
        case '7':
            board[2][0] = mark;
            break;
        case '8':
            board[2][1] = mark;
            break;
        case '9':
            board[2][2] = mark;
            break;
        }
    }
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

        if (board[i][0] == mark && board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return true;
        }
        // Checks vertical

        if (board[0][i] == mark && board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return true;
        }
    }
    // Checks left diagonal

    if (board[0][0] == mark && board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return true;
    }

    // Checks right diagonal

    if (board[0][2] == mark && board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return true;
    }

    return false;
}