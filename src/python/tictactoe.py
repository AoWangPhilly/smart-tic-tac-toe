'''
description: tictactoe.py
author: ao wang
date: 08/27/2020
'''
class TicTacToe():
    '''TicTacToe class used for the mechanics of the game, 
       like checking the winner, if the space is available,
       and getting free spaces.
    
    Attributes
    ==========
        board (list): the tictactoe gameboard
    '''
    def __init__(self):
        self.board = [list(range(i, i+3)) for i in range(1, 10, 3)]

    def __str__(self):
        '''Prints out the board'''
        board = '     |     |     \n'
        for i in range(3):
            board += '  {}  |  {}  |  {}\n'.format(   
                self.board[i][0], self.board[i][1], self.board[i][2])
            if i < 2:
                board += '_____|_____|_____\n     |     |     \n'
        return board + '     |     |     \n\n'

    def getBoard(self):
        return self.board

    def setBoard(self, board):
        self.board = board

    def isAvailable(self, pos):
        '''Checks to see if the position on board is available

        Parameter
        =========
            pos (tuple): row-col position on the board
        
        Return
        ======
            bool: whether the position is available
        '''
        for i in range(3):
            for j in range(3):
                if str(self.board[pos[0]][pos[1]]) not in 'XO':
                    return True
        return False

    def place(self, mark, pos):
        '''Places the mark on the position of board

        Parameters
        ==========
            mark (str): the player's mark, i.e. 'X' or 'O'
            pos (tuple): the row-col position of the gameboard
        '''
        self.board[pos[0]][pos[1]] = mark

    def movesLeft(self):
        '''Checks to see if there are moves left on the board
        
        Return
        ======
            bool: checks if there are any positions left
        '''
        for i in range(3):
            for j in range(3):
                if type(self.board[i][j]) == int:
                    return True
        return False

    def getFreeSpace(self):
        '''Returns list of tuples of available positions

        Return
        ======
            list (tuples): list of tuples of available positions
        '''
        return [(i, j) for i in range(3) for j in range(3) if type(self.board[i][j]) == int]

    def checkWin(self):
        '''Checks to see is there is a winner

        Return:
            str: the mark of the player if there is a winner, else returns 'tie'
        '''
        for i in range(3):
            # Rows
            if self.board[0][i] == self.board[1][i] == self.board[2][i]:
                return self.board[0][i]
            #Columns
            elif self.board[i][0] == self.board[i][1] == self.board[i][2]:
                return self.board[i][0]

        # Right Diag
        if self.board[0][0] == self.board[1][1] == self.board[2][2]:
            return self.board[0][0]

        # Left Diag
        if self.board[0][2] == self.board[1][1] == self.board[2][0]:
            return self.board[0][2]

        if not self.movesLeft():
            return 'tie'
