'''

'''

from tictactoe import TicTacToe
import sys


def miniMax(board, depth, isMaximizing):
    winner = board.checkWin()
    if winner == 'X': return 10
    elif winner == 'O': return -10
    elif winner == 'tie': return 0

    if isMaximizing:
        bestVal = float('-inf')
        for pos in board.getFreeSpace():
            spot = board.getBoard()[pos[0]][pos[1]]
            board.place('X', pos)
            val = miniMax(board, depth + 1, False)
            board.place(spot, pos)

            bestVal = max(bestVal, val)
        return bestVal
    else:
        bestVal = float('inf')
        for pos in board.getFreeSpace():
            spot = board.getBoard()[pos[0]][pos[1]]
            board.place('O', pos)
            val = miniMax(board, depth + 1, True)
            board.place(spot, pos)

            bestVal = min(bestVal, val)
        return bestVal


def miniMaxAB(board, depth, isMaximizing, alpha=float('-inf'), beta=float('inf')):
    winner = board.checkWin()
    if winner == 'X': return 10
    elif winner == 'O': return -10
    elif winner == 'tie': return 0

    if isMaximizing:
        bestVal = float('-inf')
        for pos in board.getFreeSpace():
            spot = board.getBoard()[pos[0]][pos[1]]
            board.place('X', pos)
            val = miniMaxAB(board, depth + 1, False, alpha, beta)
            bestVal = max(bestVal, val)
            board.place(spot, pos)

            alpha = max(bestVal, alpha)
            if alpha >= beta: break
        return bestVal
    else:
        bestVal = float('inf')
        for pos in board.getFreeSpace():
            spot = board.getBoard()[pos[0]][pos[1]]
            board.place('O', pos)
            val = miniMaxAB(board, depth + 1, True, alpha, beta)
            bestVal = min(bestVal, val)
            board.place(spot, pos)

            beta = min(bestVal, beta)
            if alpha >= beta: break

        return bestVal


def getBestMove(board, ab=False):
    bestVal = float('-inf')
    
    for pos in board.getFreeSpace():
        spot = board.getBoard()[pos[0]][pos[1]]
        board.place('X', pos)
        moveVal = miniMaxAB(board, 0, False) if ab else miniMax(board, 0, False)
        board.place(spot, pos)
        if moveVal > bestVal:
            bestMove = pos
            bestVal = moveVal

    return bestMove



if __name__ == '__main__':
    game = TicTacToe()
    print(game)
    for turn in range(9):
        bestPos = getBestMove(game, ab=True)
        pos = '{} {}'.format(bestPos[0], bestPos[1]) if turn % 2 == 0 else input(
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
            if won == 'X':
                print('Congratulations Player 1 (X)') 
            elif won == 'O': 
                print('Congratulations Player 2 (O)')
            break

    if game.checkWin() == 'tie':
        print('Tie game!! Try again? :D')
