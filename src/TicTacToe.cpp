#include <iostream>
#include "TicTacToe.h"
#include <vector>

TicTacToe::TicTacToe()
{
    std::vector<std::vector<char>> vect{{'1', '2', '3'},
                                        {'4', '5', '6'},
                                        {'7', '8', '9'}};
    setBoard(vect);
};

std::vector<std::vector<char>> TicTacToe::getBoard()
{
    return board;
}

void TicTacToe::setBoard(std::vector<std::vector<char>> board)
{
    this->board = board;
}

void TicTacToe::display()
{
    int i = 0, j = 0;
    std::cout << "     |     |     \n";
    for (int i = 0, len = board.size(); i < len; ++i)
    {
        std::cout << "  " << board[i][j] << "  |  " << board[i][j + 1] << "  |  " << board[i][j + 2]
                  << "\n";
        if (i < 2)
        {
            std::cout << "_____|_____|_____\n";
            std::cout << "     |     |     \n";
        }
    }
    std::cout << "     |     |     \n\n";
}

bool TicTacToe::isAvailable(char pos)
{
    for (int i = 0, len = board.size(); i < len; ++i)
    {
        if (std::find(board[i].begin(), board[i].end(), pos) != board[i].end())
        {
            return true;
        }
    }
    return false;
}

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
    else
    {
        // Whenever spot is taken or not a position
        std::cout << "Position at square " << pos << " is taken!\n";
    }
}

bool TicTacToe::checkWin()
{
    int j = 0;
    for (int i = 0, len = board.size(); i < len; ++i)
    {
        // Checks horizontal
        if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
        {
            std::cout << "horizontal\n";
            return true;
        }
        // Checks vertical
        else if (board[j][i] == board[j + 1][i] && board[j][i] == board[j + 2][i])
        {
            std::cout << "vertical\n";
            return true;
        }
    }
    // Checks left diagonal
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        std::cout << "left diag\n";
        return true;
    }
    // Checks right diagonal
    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        std::cout << "right diag\n";
        return true;
    }
    return false;
}
