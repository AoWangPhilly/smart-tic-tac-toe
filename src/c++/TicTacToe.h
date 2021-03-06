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
    bool noMovesLeft();
    void place(char pos, char mark);
    bool checkWin(char mark);

private:
    std::vector<std::vector<char>> board;
    bool checkThree(char a, char b, char c, char mark);
};

#endif