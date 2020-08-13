#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <vector>

class TicTacToe
{
public:
    TicTacToe();
    std::vector<std::vector<char>> getBoard();
    void setBoard(std::vector<std::vector<char>> board);
    void display();
    bool isAvailable(char pos);
    void place(char pos, char mark);
    bool checkWin();

private:
    std::vector<std::vector<char>> board;
};

#endif