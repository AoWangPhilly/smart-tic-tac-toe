#define CATCH_CONFIG_MAIN
#include <vector>
#include "catch.hpp"
#include "TicTacToe.h"

TEST_CASE("Position available ", "[isAvailable]")
{
    TicTacToe board;
    // Clean board
    REQUIRE(board.isAvailable('1') == true);

    // Filled in pos 1
    board.place('1', 'X');
    REQUIRE(board.isAvailable('1') == false);

    // Undo fill
    board.place('1', '1');
    REQUIRE(board.isAvailable('1') == true);

    // Test O mark
    board.place('5', 'O');
    REQUIRE(board.isAvailable('5') == false);
}

TEST_CASE("Check if any moves left", "[noMovesLeft]")
{
    TicTacToe board;
    // Clean board
    REQUIRE(board.noMovesLeft() == false);
    std::vector<std::vector<char>> vect{{'X', 'X', 'X'},
                                        {'O', 'X', 'O'},
                                        {'O', 'O', 'O'}};
    board.setBoard(vect);

    // No more moves left
    REQUIRE(board.noMovesLeft() == true);

    // Give one position back
    board.place('1', '1');
    REQUIRE(board.noMovesLeft() == false);
}

TEST_CASE("Placing markers", "[place]")
{
    TicTacToe board;

    // First space taken
    board.place('1', 'X');
    REQUIRE(board.getBoard()[0][0] == 'X');

    // Last space taken
    board.place('9', 'O');
    REQUIRE(board.getBoard()[2][2] == 'O');
}

TEST_CASE("Check if game is over", "[checkWin]")
{
    TicTacToe board;

    // Blank board, no winner
    REQUIRE(board.checkWin('X') == false);
    std::vector<std::vector<char>> vect{{'X', 'X', 'X'},
                                        {'O', 'X', 'O'},
                                        {'7', '8', '9'}};
    board.setBoard(vect);

    // First horizontal line X wins
    REQUIRE(board.checkWin('X') == true);

    vect = {{'O', 'X', '3'},
            {'O', 'O', 'O'},
            {'7', '8', 'O'}};
    board.setBoard(vect);
    // Left diagonal O wins
    REQUIRE(board.checkWin('O') == true);

    vect = {{'X', 'O', 'X'},
            {'O', 'O', 'X'},
            {'X', 'X', 'O'}};
    board.setBoard(vect);

    // Neither wins, draw!
    REQUIRE(board.checkWin('O') == false);
    REQUIRE(board.checkWin('X') == false);
}