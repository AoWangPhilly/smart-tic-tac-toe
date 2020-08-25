class TicTacToe():
    def __init__(self):
        self.board = [list(range(i, i+3)) for i in range(1, 10, 3)]

    def __str__(self):
        board = '     |     |     \n'
        for i in range(3):
            board += '  {}  |  {}  |  {}\n'.format(self.board[i][0], self.board[i][1], self.board[i][2])
            if i < 2:
                board += '_____|_____|_____\n     |     |     \n'
        return board + '     |     |     \n\n'

    def getBoard(self):
        return self.board

    def setBoard(self, board):
        self.board = board

    def isAvailable(self, pos):
        for i in range(3):
            for j in range(3):
                if self.board[pos.x][pos.y] not in 'XO':
                    return True
        return False

    def place(self, pos, mark):
        self.board[pos.x][pos.y] = mark

    def movesLeft(self):
        for i in range(3):
            for j in range(3):
                if type(self.board[i][j]) == int:
                    return True
        return False

    def getFreeSpace(self):
        return [Move(i, j) for i in range(3) for j in range(3) if type(self.board[i][j]) == int]

    def checkWin(self):
        for i in range(3):
            if self.board[0][i] == self.board[1][i] == self.board[2][i]:
                return self.board[0][i]
            elif self.board[i][0] == self.board[i][1] == self.board[i][2]:
                return self.board[i][0]

        if self.board[0][0] == self.board[1][1] == self.board[2][2]:
            return self.board[0][0]

        if self.board[0][2] == self.board[1][1] == self.board[2][0]:
            return self.board[0][2]

        if not self.movesLeft():
            return 'tie'


class Move():
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return '({}, {})'.format(self.x, self.y)

    def getMove(self):
        return Move(self.x, self.y)

    def setMove(self, x, y):
        self.Move = Move(x, y)
