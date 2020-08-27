'''

'''

from tictactoe import TicTacToe
import re
import sys


def miniMax(board, depth, isMaximizing):
    winner = board.checkWin()
    if winner == 'X':
        return 10
    elif winner == 'O':
        return -10
    elif winner == 'tie':
        return 0

    if isMaximizing:
        bestVal = -sys.maxsize - 1
        for pos in board.getFreeSpace():
            spot = board.getBoard()[pos[0]][pos[1]]
            board.place('X', pos)
            val = miniMax(board, depth + 1, False)
            board.place(spot, pos)

            bestVal = max(bestVal, val)
        return bestVal
    else:
        bestVal = sys.maxsize
        for pos in board.getFreeSpace():
            spot = board.getBoard()[pos[0]][pos[1]]
            board.place('O', pos)
            val = miniMax(board, depth + 1, True)
            board.place(spot, pos)

            bestVal = min(bestVal, val)
        return bestVal


def miniMaxAB(board, depth, isMaximizing, alpha=sys.maxsize, beta=-sys.maxsize - 1):
    pass


def getBestMove(board):
    bestVal = -sys.maxsize - 1
    
    for pos in board.getFreeSpace():
        spot = board.getBoard()[pos[0]][pos[1]]
        board.place('X', pos)
        moveVal = miniMax(board, 0, False)
        board.place(spot, pos)
        if moveVal > bestVal:
            bestMove = pos
            bestVal = moveVal

    return bestMove


def getBestMoveAB(board):
    pass


if __name__ == '__main__':
    game = TicTacToe()
    print(game)
    for turn in range(9):
        pos = '{} {}'.format(getBestMove(game)[0], getBestMove(game)[1]) if turn % 2 == 0 else input(
            'Make your move, Player 2 (O), i.e. "0 0": ')

        pos = tuple(map(int, pos.split(' '))) 

        while not game.isAvailable(pos):
            pos = input(
                '[Row: {}, Col: {}] is taken! Try again?, i.e. "0 0": '.format(pos[0], pos[1]))
            pos = tuple(map(int, pos.split(' ')))

        game.place('X', pos) if turn % 2 == 0 else game.place('O', pos)
        print(game)
        won = game.checkWin()
        if won:
            print('Congratulations Player 1 (X)') if won == 'X' else print(
                'Congratulations Player 2 (O)')
            break
    else:
        if not game.movesLeft():
            print('Tie game!! Try again? :D')
